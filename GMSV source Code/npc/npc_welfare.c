#include "version.h"

#ifdef _NPC_WELFARE
#ifdef _PROFESSION_SKILL			// WON ADD 人物职业技能

#include <string.h>
#include "char.h"
#include "object.h"
#include "char_base.h"
#include "npcutil.h"
#include "lssproto_serv.h"
#include "pet_skill.h"
#include "readmap.h"
#include "battle.h"
#include "profession_skill.h"
#include "chatmagic.h"
#include "npc_welfare.h"
#include "npc_exchangeman.h"

static void NPC_Welfare_selectWindow(int meindex, int toindex, int num, int select);



#ifdef _PRO3_ADDSKILL
void delprosk( int talkerindex, int delskid )
{
	CHAR_HaveSkill* hskill;
	int i,skill_level = -1;
	int count = 0;
	int skill_id[CHAR_SKILLMAXHAVE] = {0};
	int skill_temp[CHAR_SKILLMAXHAVE] = {0};
		
	// 取熟练度
	for( i=0; i<CHAR_SKILLMAXHAVE; i++ ){
		int skillid = -1;
		skillid = CHAR_getCharSkill( talkerindex, i);// 技能ID
		if( skillid <= 0 || skillid == delskid ) continue;//不储存需遗忘的技能
		hskill = CHAR_getCharHaveSkill( talkerindex, i );// 技能等级
		skill_level = SKILL_getInt( &hskill->skill, SKILL_LEVEL);
		skill_id[count] = skillid;
		skill_temp[count] = skill_level;
		count++;
	}
	CHAR_CHAT_DEBUG_delsk( talkerindex, "all" );// 删除所有技能
	for( i=0; i<count; i++ )// 还原技能
		PROFESSION_SKILL_ADDSK( talkerindex, skill_id[i], skill_temp[i] );
}
#endif

//载入好康NPC的初始化
BOOL NPC_WelfareInit( int meindex )
{
    CHAR_setInt( meindex , CHAR_WHICHTYPE , CHAR_TYPEWELFARE);
    //print("名称:%s\n",CHAR_getChar( meindex, CHAR_NAME));
    return TRUE;
}

//对话时的处理
void NPC_WelfareTalked( int meindex , int talkerindex , char *szMes ,int color )
{
    if( CHAR_getInt( talkerindex , CHAR_WHICHTYPE ) != CHAR_TYPEPLAYER ) {
    	return;
    }
	if(NPC_Util_isFaceToFace(talkerindex,meindex,2 )==FALSE){
		if( NPC_Util_CharDistance( talkerindex, meindex ) > 1) return;
	}
	NPC_Welfare_selectWindow( meindex, talkerindex,0,-1);
}

static void NPC_Welfare_selectWindow( int meindex, int toindex, int num,int select)
{
	switch(num){
	  case 0:
		  //free
		NPC_WelfareMakeStr(meindex, toindex, select);
		break;
	  case 1:
		break;
	}
}

void NPC_WelfareWindowTalked( int meindex, int talkerindex, 
		int seqno, int select, char *data)
{
	int skill, i, j;
	int cost;
	int skillID=0;
	char buf[64];
	char argstr[NPC_UTIL_GETARGSTR_BUFSIZE];
	char msg[512];
	char message[64];
	int fd = getfdFromCharaIndex( talkerindex );
	double rate= 1.0;
	int skillarray;
	int p_class=0, need_class=0;
	int profession_skill_point;

	memset( message, -1, sizeof(message) );

	if( NPC_Util_CharDistance( talkerindex, meindex ) > 2) {
		return;
	}

	if(NPC_Util_GetArgStr( meindex, argstr, sizeof(argstr))==NULL){
		print("GetArgStrErr");
		return;
	}

	makeStringFromEscaped( data);
	getStringFromIndexWithDelim(data,"|",1,buf,sizeof(buf));
	skill=atoi(buf);
	getStringFromIndexWithDelim(data,"|",2,buf,sizeof(buf));
	cost=atoi(buf);
	
	if( NPC_Util_GetStrFromStrWithDelim( argstr, "profession_skill", msg, sizeof( msg)) != NULL){
		getStringFromIndexWithDelim(msg,",",skill,buf,sizeof(buf));
		skillID=atoi(buf);
	}


	if(skillID < 0) return ;

	if( CHAR_getWorkInt( CONNECT_getCharaindex(fd), CHAR_WORKBATTLEMODE) != BATTLE_CHARMODE_NONE) return ;

	if( NPC_Util_GetStrFromStrWithDelim( argstr, "skill_rate", msg, sizeof( msg)) != NULL){
		rate = atof( msg);
	}

	skillarray = PROFESSION_SKILL_getskillArray( skillID );

	if(skillarray == -1){
		CHAR_send_P_StatusString( talkerindex, CHAR_P_STRING_GOLD);
		return ;
	}

	// 判断职业
	{
		if( NPC_Util_GetStrFromStrWithDelim( argstr, "profession_class", msg, sizeof(msg) ) == NULL){
			return ;
		}else{
			p_class = atoi(msg);	
		}
		
		// 技能所需职业
		need_class = PROFESSION_SKILL_getInt( skillarray, PROFESSION_SKILL_PROFESSION_CLASS );

		if( CHAR_getInt( talkerindex, PROFESSION_CLASS ) == 0 ){
			char token[256];
			memset(token, -1, sizeof(token) );
			sprintf( token, "您尚未就职!" );
			CHAR_talkToCli( talkerindex, meindex, token, CHAR_COLORYELLOW);
			CHAR_send_P_StatusString( talkerindex, CHAR_P_STRING_GOLD);
			return;

		}

		if( CHAR_getInt( talkerindex, PROFESSION_CLASS ) != need_class && need_class != 4 ){
			char token[256];
			memset(token, -1, sizeof(token) );
			sprintf( token, "此技能你不能学喔!" );
			CHAR_talkToCli( talkerindex, meindex, token, CHAR_COLORYELLOW);
			CHAR_send_P_StatusString( talkerindex, CHAR_P_STRING_GOLD);
			return;
		}
		

	}

	// 判断剩余点数
	{
		profession_skill_point = CHAR_getInt( talkerindex, PROFESSION_SKILL_POINT );
		if( profession_skill_point <= 0 ){
			char token[256];
			memset(token, -1, sizeof(token) );
			sprintf( token, "你目前没有学习点数!" );
			CHAR_talkToCli( talkerindex, meindex, token, CHAR_COLORYELLOW);
			CHAR_send_P_StatusString( talkerindex, CHAR_P_STRING_GOLD);
			return;
		}
	}

	// 判断是否达成学习的条件
	{
		int temp[4] = {0}, count = 0, flag = -1 , need_percent = -1, need_count = 0;

		for( i=0; i<4; i++){
			int limit = -1;
			flag = -1;
			limit = PROFESSION_SKILL_getInt( skillarray, PROFESSION_SKILL_LIMIT1+i*2 );
			need_percent = PROFESSION_SKILL_getInt( skillarray, PROFESSION_SKILL_LIMIT1+i*2 + 1 );
					
			if( limit!= 0  && need_percent == 0 ) need_count++;

			if( limit == 0 ){
				continue;
			}else if( limit == -1 ){
				for( j=0; j<PROFESSION_MAX_LEVEL; j++ ){
					if( CHAR_getCharSkill( talkerindex, j) > 0 ) break;
				}
				if( j >=  PROFESSION_MAX_LEVEL ){
					char token[256];	
					sprintf( token, "需先学会任１种战斗技能才能学习！");
					CHAR_talkToCli( talkerindex, meindex, token, CHAR_COLORYELLOW);
					CHAR_send_P_StatusString( talkerindex, CHAR_P_STRING_GOLD);
					return;
				}
			}else{
				flag = -1;
				for( j=0; j<PROFESSION_MAX_LEVEL; j++ ){
					// 判断技能
					if( CHAR_getCharSkill( talkerindex, j) == limit ){
						int skill_level = -1;
						CHAR_HaveSkill* hskill;
						flag = -2;
						hskill = CHAR_getCharHaveSkill( talkerindex, j );
						skill_level = SKILL_getInt( &hskill->skill, SKILL_LEVEL);	
						
						// 判断熟练度
						if( skill_level >= need_percent ){
							flag = 1;	break;
						}					
					}
				}
				
				// 未达成条件
				if( flag == -1 && need_percent == 0 ){
						temp[count] = limit;
						count ++;					
				}else if( flag == -1 ){
					char token[256];	
					memset(token, -1, sizeof(token) );
					sprintf( token, "尚未学会%s!", PROFESSION_SKILL_getChar( limit, PROFESSION_SKILL_NAME) );
					CHAR_talkToCli( talkerindex, -1, token, CHAR_COLORYELLOW);
					CHAR_send_P_StatusString( talkerindex, CHAR_P_STRING_GOLD);
					return;
				}else if( flag == -2 ){
					char token[256];	
					memset(token, -1, sizeof(token) );
					sprintf( token, "%s熟练度不足%d!", PROFESSION_SKILL_getChar( limit, PROFESSION_SKILL_NAME), need_percent );
					CHAR_talkToCli( talkerindex, -1, token, CHAR_COLORYELLOW);
					CHAR_send_P_StatusString( talkerindex, CHAR_P_STRING_GOLD);
					return;
				}
			}
		}
	
		if( count == need_count &&  need_count != 0 ){
			char msg[256] = {0};
		
			sprintf( msg, "需先学会 " );
			for( i = 0; i< count; i++ ){
				if( temp[i] != 0 ){
					char token[50] = {0};
					sprintf( token, "%s ", PROFESSION_SKILL_getChar( temp[i], PROFESSION_SKILL_NAME) );
					strcat( msg, token );
				}
			}
			sprintf( msg, "%s 任一种技能", msg );
			CHAR_talkToCli( talkerindex, -1, msg, CHAR_COLORYELLOW);
			CHAR_send_P_StatusString( talkerindex, CHAR_P_STRING_GOLD);

			return;
		}

	}

	// 判断金钱	
	{
		cost = PROFESSION_SKILL_getInt( skillarray, PROFESSION_SKILL_COST );
		cost = cost * rate;

		if(CHAR_getInt(talkerindex,CHAR_GOLD) < cost){
			CHAR_send_P_StatusString( talkerindex, CHAR_P_STRING_GOLD);
			return;
		}
	}

#ifdef _NPC_ProfessionTrans
	//判断转生
	{
		if( NPC_Util_GetStrFromStrWithDelim( argstr, "trans", msg, sizeof(msg) ) != NULL){
		    int trans = atoi(msg);
			//print("\n转生要求:%d,%d",CHAR_getInt( talkerindex, CHAR_TRANSMIGRATION),trans);
			if( CHAR_getInt( talkerindex, CHAR_TRANSMIGRATION) < trans){ 
				if( NPC_Util_GetStrFromStrWithDelim( argstr, "trans_msg", msg, sizeof(msg) ) != NULL){
                    CHAR_talkToCli( talkerindex, meindex, msg, CHAR_COLORYELLOW);
				    return;
				}
				else{
                    CHAR_talkToCli( talkerindex, meindex, "您的转生次数不够哦。", CHAR_COLORYELLOW);
				    return;
				}
			}
		}
	}
#endif

	// 增加技能
	{
		int skill_level = 0;

		// 共通技能熟练度给50，其余给10
		if( (skillID == 63) || (skillID == 64) || (skillID == 65)  ){
			int	Pskillid = -1;
			skill_level = 50;
			Pskillid = PROFESSION_SKILL_getskillArray( skillID );
		}else{
			skill_level = 10;
		}

		if( PROFESSION_SKILL_ADDSK( talkerindex, skillID, skill_level ) == -1 )	return;

		CHAR_DelGold( talkerindex, cost );

		CHAR_sendStatusString( talkerindex , "S");

		NPC_Welfare_selectWindow( meindex, talkerindex,0,-1);
	}

	// 传送讯息
	{
		char token[256];
		int next_profession_skill_point = profession_skill_point-1;
		
		CHAR_setInt( talkerindex, PROFESSION_SKILL_POINT, next_profession_skill_point );
		
		memset(token, -1, sizeof(token) );
		sprintf( token, "您学习了 %s，剩余学习点数 %d"
				,PROFESSION_SKILL_getChar( skillarray, PROFESSION_SKILL_NAME )
				,next_profession_skill_point );
		CHAR_talkToCli( talkerindex, -1, token, CHAR_COLORYELLOW);
    
		CHAR_sendCToArroundCharacter( CHAR_getWorkInt( talkerindex , CHAR_WORKOBJINDEX ));
	}

}             

void NPC_WelfareMakeStr(int meindex,int toindex,int select)
{
	char argstr[NPC_UTIL_GETARGSTR_BUFSIZE];
	char msg[256];
	double rate=1.0;
	int i=0;
	char token[65530];
	int fd = getfdFromCharaIndex( toindex);

	if(select==0){
		sprintf(token,"0|0");
		lssproto_WN_send( fd, WINDOW_MESSAGETYPE_PETSKILLSHOP, 
			WINDOW_BUTTONTYPE_NONE, 
			CHAR_WINDOWTYPE_WINDOWPETSKILLSHOP,
			CHAR_getWorkInt( meindex, CHAR_WORKOBJINDEX),
			token);
		
	}

	if(NPC_Util_GetArgStr( meindex, argstr, sizeof(argstr))==NULL){
		print("GetArgStrErr");
		return;
	}

	if( NPC_Util_GetStrFromStrWithDelim( argstr, "main_msg", msg, sizeof( msg)) == NULL){
		print("mainERR");
		return ;
	}

	sprintf(token,"1|%s|%s", CHAR_getChar(meindex,CHAR_NAME), msg);
		
	if( NPC_Util_GetStrFromStrWithDelim( argstr, "skill_rate", msg, sizeof( msg)) != NULL){
		rate=atof(msg);
	}

		
	if( NPC_Util_GetStrFromStrWithDelim( argstr, "profession_skill", msg, sizeof( msg) ) != NULL){
		int skillarray;
		int skillID;
		int cost;
		char token2[265];
		char buf[64];

		i=1;
	    while( getStringFromIndexWithDelim(msg,",",i,buf,sizeof(buf)) !=FALSE ){
			i++;
			skillID=atoi(buf);

			skillarray = PROFESSION_SKILL_getskillArray( skillID );

			if( PROFESSION_SKILL_CHECKINDEX( skillarray ) == FALSE )		continue;

			cost = PROFESSION_SKILL_getInt( skillarray, PROFESSION_SKILL_COST );

			cost = (int)cost*rate;

			sprintf(token2,"|%s|%d|%s|%d",
				PROFESSION_SKILL_getChar( skillarray, PROFESSION_SKILL_NAME ),	// 技能名称
				cost,															// 金额
				PROFESSION_SKILL_getChar( skillarray, PROFESSION_SKILL_TXT ),	// 说明
				PROFESSION_SKILL_getInt( skillarray, PROFESSION_SKILL_ICON )	// 图示
			);
			strcat(token,token2);
		} 
	}

	lssproto_WN_send( fd, WINDOW_MESSAGETYPE_PROFESSIONSHOP, 
				WINDOW_BUTTONTYPE_NONE, 
				WINDOW_MESSAGETYPE_PROFESSIONSHOP,
				CHAR_getWorkInt( meindex, CHAR_WORKOBJINDEX),
				token);

	return;
}


#endif
#endif


