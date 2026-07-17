#include "version.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifdef _REDHAT_V9
#include <errno.h>
#endif
#include "autil.h"
#include "title.h"
#include "char.h"
#include "char_base.h"
#include "item.h"
#include "skill.h"
#include "buf.h"
#include "util.h"
#include "configfile.h"


/*====================惫寞  ====================*/
static int TITLE_IntCheck( int charaindex,int elem, int *data, int flg);
static int TITLE_WorkIntCheck( int charaindex,int elem, int *data, int flg);
static int TITLE_ItemCheck( int charaindex,int elem, int *data, int flg);
static int TITLE_ItemEquipCheck( int charaindex,int elem, int *data, int flg);
static int TITLE_SkillCheck( int charaindex,int elem, int *data, int flg);
static int TITLE_SexCheck( int charaindex,int elem, int *data, int flg);

typedef enum
{
	TITLE_FUNCTYPENONE,     /*  楮醒戏岳仄卅中  */
	TITLE_FUNCTYPEUSERFUNC, /* definefunction 毛银匀化  蟆毛综月
							 * 楮醒及娄醒反
							 *  int     平乓仿奶件犯永弁旦
							 *  buf       蟆尺及田永白央
							 *  buflen  公及田永白央及赢今
							 */
	TITLE_USEFUNCTYPENUM
}TITLE_USEFUNCTYPE;

typedef struct tagTITLE_Table
{
	int                 index;      /* 蛙犯□正午询晶毛潸月凶户［
									 * 仇及  寞匹手匀化addtitle午井支月 
									 */
	char               name[32];
	TITLE_USEFUNCTYPE   functype;
	void                (*definefunction)(int,char* buf,int buflen);
}TITLE_Table;

/* 银尹月由仿丢□正
 * STR,TGH,MAXMP］ATK,DEF
 * LEVEL,CLASS,SKILL,ITEM,FIREREG,ICEREG,THUNDERREG
 * KANJILV,TALKCNT,WALKCNT,DEADCNT,LOGINCNT,BASEIMAGENUMBER
 * GOLD
*/
typedef struct tagTITLE_Compare {
	char    compare[8];;
} TITLE_COMPARE;

TITLE_COMPARE TITLE_compare[] = { {"<="}, {">="},{"<>"}, {">"},{"<"},{"="}};

typedef struct tagTITLE_PARAM
{
	int     element;
	int     (*checkfunc)( int charaindex,int elem, int *data, int flg );
	char    *paramname;
}TITLE_PARAM;

TITLE_PARAM TITLE_param[] = 
{
	/**** 仇仇井日 ****/
	{ -1,                     TITLE_ItemCheck,     "ITEM"         },
	{ -1,                     TITLE_ItemEquipCheck,"EQUIPITEM"    },
	{ -1,                     NULL,                "EQUIPEVENT"   },
	/**** 仇仇引匹反  凳仄卅中匹仁分今中［ ****/
	{ -1,                     TITLE_SkillCheck,    "SKILL"        },
	{ CHAR_STR,               TITLE_IntCheck,      "STR"           },
	{ CHAR_TOUGH,             TITLE_IntCheck,      "TGH"           },
	{ CHAR_MAXMP,             TITLE_IntCheck,      "MAXMP"         },
	{ CHAR_WORKFIXSTR,        TITLE_WorkIntCheck,  "ATK"           },
	{ CHAR_WORKFIXTOUGH,      TITLE_WorkIntCheck,  "DEF"           },
	{ CHAR_LV,                TITLE_IntCheck,      "LEVEL"         },
	{ CHAR_TALKCOUNT,         TITLE_IntCheck,      "TALKCNT"       },
	{ CHAR_WALKCOUNT,         TITLE_IntCheck,      "WALKCNT"       },
	{ CHAR_DEADCOUNT,         TITLE_IntCheck,      "DEADCNT"       },
	{ CHAR_LOGINCOUNT,        TITLE_IntCheck,      "LOGINCNT"      },
	{ CHAR_BASEBASEIMAGENUMBER,TITLE_IntCheck,      "BASEIMAGENUMBER" },
	{ CHAR_GOLD,              TITLE_IntCheck,      "GOLD"          },
	{ -1,                     TITLE_SexCheck,      "SEX"           },
};

#define     TITLE_PARAMSIZE     20
typedef struct tagTITLE_configTable
{
	int     paramindex[20];         /* TITLE_param尺及骄侬 */
	int     param[20][TITLE_PARAMSIZE];              /*   笠袄 */
	int     compareflg[20];         /* ><=羁升丹允月井 */
	int     title;
	BOOL    equipcheckflg;          /* 
									 *  失奶  丞啖  奶矛件玄匹反仇及白仿弘及  匀化中月
									 *  手及仄井腹绸仄卅中［
									 */
}TITLE_CONFIGTABLE;

typedef struct tagTITLE_configbuf
{
	int     title;
	int     flg;
}TITLE_CONFIGBUF;

static TITLE_CONFIGTABLE    *TITLE_ConfigTable;
static TITLE_Table          *TITLE_table;
static TITLE_CONFIGBUF      *TITLE_configbuf;
static int                  TITLE_titlenum;
static int                  TITLE_titlecfgnum;

/*------------------------------------------------------------
 * index  寞井日TITLE_table及骄侬毛  月
 ------------------------------------------------------------*/
int TITLE_getTitleIndex( int index)
{
	int i;
	if( index < 0 ) return -1;
	for( i = 0; i < TITLE_titlenum; i ++ ) {
		if( TITLE_table[i].index == index ) {
			return( i);
		}
	}
	return -1;
}

/*  田永白央及扔奶术    */
#define TITLESTRINGBUFSIZ   256
/*  弁仿奶失件玄卞苇六月旦平伙犯□正及  侬  及田永白央    */
static char    TITLE_statusStringBuffer[TITLESTRINGBUFSIZ];
/*------------------------------------------------------------
 * 弁仿奶失件玄卞苇六月惫寞及  侬  毛综月
 * 娄醒
 *  title       Title*      旦平伙
 *  charaindex  int         仇及惫寞毛  匀化中月平乓仿及奶件犯永弁旦
 * 忒曰袄
 *  char*
 ------------------------------------------------------------*/
char* TITLE_makeTitleStatusString( int charaindex,int havetitleindex )
{
	int     attach;
	int     index;
	/*  楮醒  尺及奶件犯永弁旦井日犯□正毛综岳允月  */
	index = CHAR_getCharHaveTitle( charaindex,havetitleindex );

	attach = TITLE_getTitleIndex( index);
	if( attach == -1 ) {
		TITLE_statusStringBuffer[0] = '\0';
		return TITLE_statusStringBuffer;
	}
	switch( TITLE_table[attach].functype ){
	case TITLE_FUNCTYPENONE:
		snprintf( TITLE_statusStringBuffer,
				  sizeof(TITLE_statusStringBuffer ),"%s" ,
				  TITLE_table[attach].name );
		break;
	
	case TITLE_FUNCTYPEUSERFUNC:
	{
		char    string[256]={""};
		void    (*function)(int,char* buf,int buflen);
		function = TITLE_table[attach].definefunction;
		if( function )
			function( charaindex,string,sizeof(string) );

		strcpysafe( TITLE_statusStringBuffer,
					sizeof(TITLE_statusStringBuffer ),string );
	}
	break;
	default:
		TITLE_statusStringBuffer[0] = '\0';
		return TITLE_statusStringBuffer;
		break;
	}
	return TITLE_statusStringBuffer;
}

/*------------------------------------------------------------
 * 卅中惫寞及  侬  犯□正毛忒允
 * 娄醒
 *  卅仄
 * 忒曰袄
 *  char*
 ------------------------------------------------------------*/
char* TITLE_makeSkillFalseString( void )
{
	TITLE_statusStringBuffer[0]= '\0';
	return TITLE_statusStringBuffer;
}


/*------------------------------------------------------------
 * 隙烂今木凶  寞及惫寞毛馨笛允月［褐今卅匀化中凶日｝馨笛仄卅中
 * 娄醒
 *  charaindex      int     平乓仿奶件犯永弁旦
 *  titleindex      int     惫寞奶件犯永弁旦
 * 忒曰袄
 *  馨笛仄凶index       
 *  馨笛仄卅井匀凶      FALSE(0)
 ------------------------------------------------------------*/
BOOL TITLE_addtitle( int charaindex, int titleindex )
{
	int i;
	int firstfindempty=-1;

	if( CHAR_CHECKINDEX(charaindex)  == FALSE )return FALSE;
	/*if( TITLE_CHECKTABLEINDEX(titleindex) == FALSE )return FALSE;*/
	if( TITLE_getTitleIndex( titleindex) == -1 ) return FALSE;

	for( i=0 ; i < CHAR_TITLEMAXHAVE ; i++ ){
		if( CHAR_getCharHaveTitle( charaindex,i ) == titleindex )
			/*  允匹卞  匀化中月井日窒手仄卅中  */
			return FALSE;
		if( firstfindempty == -1
			&& CHAR_getCharHaveTitle(charaindex,i) == -1 ){
			firstfindempty = i;
		}
	}
	return CHAR_setCharHaveTitle( charaindex,firstfindempty,titleindex );
}


/*------------------------------------------------------------
 * 隙烂今木凶  寞及惫寞互丐匀凶日绰轮允月［卅井匀凶日窒手仄卅中［
 *   醒蜊丐匀凶日蝈  壅允［
 * 娄醒
 *  charaindex      int     平乓仿奶件犯永弁旦
 *  titleindex      int     惫寞奶件犯永弁旦
 * 忒曰袄
 *  绰轮仄凶            TRUE(1)
 *  绰轮仄卅井匀凶      FALSE(0)
 ------------------------------------------------------------*/
BOOL TITLE_deltitle( int charaindex, int titleindex )
{
	int i;
	BOOL    del=FALSE;
	int     index;
	if( CHAR_CHECKINDEX(charaindex)  == FALSE )return FALSE;
	/*if( TITLE_CHECKTABLEINDEX(titleindex) == FALSE )return FALSE;*/
	index = TITLE_getTitleIndex( titleindex);
	if(  index == -1 ) return FALSE;

	for( i=0 ; i < CHAR_TITLEMAXHAVE ; i++ )
		if( CHAR_getCharHaveTitle( charaindex,i ) == titleindex ){
			/*  愤坌互银匀化中凶支勾卅日壬｝公木手卅仄卞允月    */
			if( CHAR_getInt(charaindex, CHAR_INDEXOFEQTITLE) == i ){
				CHAR_setInt(charaindex, CHAR_INDEXOFEQTITLE, -1 );
			}
			/*    匀化中月井日壅允  */
			CHAR_setCharHaveTitle( charaindex,i,-1);
			
			del = TRUE;
		}

	return del;
}
/*------------------------------------------------------------
 * 惫寞及赓渝祭毛允月［
 * 娄醒
 *  filename        char*       涩烂白央奶伙  
 * 忒曰袄
 *  岳      TRUE(1)
 *  撩      FALSE(0)
 *------------------------------------------------------------*/
BOOL TITLE_initTitleName( char* filename )
{
	FILE*   f;
	char    line[256];
	int     linenum=0;
	int     title_readlen=0;

	f = fopen(filename,"r");
	if( f == NULL ){
		errorprint;
		return FALSE;
	}

	TITLE_titlenum=0;

	/*  引内  躲卅垫互窒垫丐月井升丹井譬屯月    */
	while( fgets( line, sizeof( line ), f ) ){
		linenum ++;
		if( line[0] == '#' )continue;        /* comment */
		if( line[0] == '\n' )continue;       /* none    */
		chomp( line );

		TITLE_titlenum++;
	}

	if( fseek( f, 0, SEEK_SET ) == -1 ){
		fprint( "寻找错误\n" );
		fclose(f);
		return FALSE;
	}

	TITLE_table = allocateMemory( sizeof(struct tagTITLE_Table)
								   * TITLE_titlenum );
	if( TITLE_table == NULL ){
		fprint( "无法分配内存 %d\n" ,
				sizeof(TITLE_table)*TITLE_titlenum);
		fclose( f );
		return FALSE;
	}
	/* 赓渝祭 */
{
	int     i;
	for( i = 0; i < TITLE_titlenum; i ++ ) {
		TITLE_table[i].index = -1;
		TITLE_table[i].name[0] = '\0';
		TITLE_table[i].functype = TITLE_FUNCTYPENONE;
		TITLE_table[i].definefunction = NULL;
	}
	
}

	/*  引凶  心  允    */
	linenum = 0;
	while( fgets( line, sizeof( line ), f ) ){
		linenum ++;
		if( line[0] == '#' )continue;        /* comment */
		if( line[0] == '\n' )continue;       /* none    */
		chomp( line );

		/*  垫毛帮溥允月    */
		/*  引内 tab 毛 " " 卞  五晶尹月    */
		replaceString( line, '\t' , ' ' );
		/* 燮  及旦矢□旦毛潸月［*/
{
		int     i;
		char    buf[256];
		for( i = 0; i < strlen( line); i ++) {
			if( line[i] != ' ' ) {
				break;
			}
			strcpy( buf, &line[i]);
		}
		if( i != 0 ) {
			strcpy( line, buf);
		}
}
{
		char    token[256];
		int     ret;

		/*  夫午勾户及玄□弁件毛苇月    */
		ret = getStringFromIndexWithDelim( line,",",1,token,
										   sizeof(token));
		if( ret==FALSE ){
			fprint("文件语法错误:%s 第%d行\n",filename,linenum);
			continue;
		}
		TITLE_table[title_readlen].index = atoi(token);

		/*  2勾户及玄□弁件毛苇月    */
		ret = getStringFromIndexWithDelim( line,",",2,token,
										   sizeof(token));
		if( ret==FALSE ){
			fprint("文件语法错误:%s 第%d行\n",filename,linenum);
			continue;
		}
		if( strlen( token) > sizeof( TITLE_table[title_readlen].name)-1) {
			fprint("警告! 头衔名称结束文件:%s 第%d行\n",
					filename, linenum);
		}
		strcpysafe( TITLE_table[title_readlen].name, 
					sizeof( TITLE_table[title_readlen].name),
					token);

		title_readlen ++;
}
	}
	fclose(f);

	TITLE_titlenum = title_readlen;

	print( "有效头衔名称数是 %d...", TITLE_titlenum );

#ifdef DEBUG

	{
		int i;
		for( i=0; i <TITLE_titlenum ; i++ )
			print( "头衔索引[%d] 名称[%s] \n",
				   TITLE_table[i].index,
				   TITLE_table[i].name);
	}
#endif
	return TRUE;
}
/*------------------------------------------------------------
 * 惫寞及疯赓渝祭毛允月［
 * 娄醒
 *  filename        char*       涩烂白央奶伙  
 * 忒曰袄
 *  岳      TRUE(1)
 *  撩      FALSE(0)
 *------------------------------------------------------------*/
BOOL TITLE_reinitTitleName( void)
{
	freeMemory( TITLE_table);
	return(TITLE_initTitleName( getTitleNamefile()));
}
/*------------------------------------------------------------
 * 惫寞涩烂及赓渝祭毛允月［
 * 娄醒
 *  filename        char*       涩烂白央奶伙  
 * 忒曰袄
 *  岳      TRUE(1)
 *  撩      FALSE(0)
 *------------------------------------------------------------*/
static void TITLE_initTitleData( int array)
{
	int j,k;
	for( j = 0; j < arraysizeof( TITLE_ConfigTable[array].paramindex); j ++) {
		for( k = 0; k < TITLE_PARAMSIZE; k++) {
			TITLE_ConfigTable[array].param[j][k] = -1;
		}
		TITLE_ConfigTable[array].paramindex[j] = -1;
		TITLE_ConfigTable[array].compareflg[j] = -1;
	}
	TITLE_ConfigTable[array].title = -1;
	TITLE_ConfigTable[array].equipcheckflg = FALSE;
	
}
/*------------------------------------------------------------
 *   醒垫涩烂毛引午户化ㄠ垫卞仄化支月［  戈及手仇仇匹允月［
 *------------------------------------------------------------*/
static int TITLE_getConfigOneLine( FILE *fp, char *line, int linelen)
{
	char    buf[1024];
	int     startflg = FALSE;
	int     linenum=0;
	line[0] = '\0';
	
	while( fgets( buf, sizeof( buf ), fp )){
		linenum ++;
		if( buf[0] == '#' )continue;        /* comment */
		if( buf[0] == '\n' )continue;       /* none    */
		/*  垫毛帮溥允月    */
		/*  引内 tab 毛 " " 卞  五晶尹月    */
		replaceString( buf, '\t' , ' ' );
		/* 旦矢□旦绰轮 */
		deleteCharFromString( buf, " ");

		if( buf[0] == '{' ) {
			if( startflg == TRUE ) {
				print( "titleconfig:明明没有关闭「{」却出现了: %d \n",linenum);
				/* } */
				return -1;
			}
			startflg = TRUE;
		}
		else if( buf[0] == '}' ) {
			if( startflg == FALSE) {
				print( "titleconfig:明明没有关闭「{」却出现了: %d \n",linenum);
				/* } */
				return -1;
			}
			return 1;
		}
		else {
			/* "{"匹湃卞铵引匀化中凶日 }*/
			if( startflg == TRUE ) {
				if( strlen( line) != 0 ) {
					if( line[strlen(line) -1] != ',' ) {
						strcatsafe( line, linelen, ",");
					}
				}
				/* ㄠ垫卞引午户化中仁*/
				chompex( buf );
				strcatsafe( line,linelen,  buf);
			}
			/*   躲垫分互"{"匹反元引匀化卅中桦宁反公及引引ㄠ垫匹忒允 }*/
			else {
				chompex( buf );
				strcatsafe( line,linelen,  buf);
				return 1;
			}
		}
	}
	/* 仇仇卞仁月午蜕丹仪反EOF   驯五元扎卅中戊□玉分   */
	return 0;
}
static int TITLE_getParamData( int readarray, int array,char *src)
{
	int cnt;
	int ret;
	char    wk[64];
	
	
	for( cnt = 1; ; cnt ++ ) {
		ret = getStringFromIndexWithDelim( src,"|",cnt,wk, sizeof(wk));
		if( ret ) {
			TITLE_ConfigTable[readarray].param[array][cnt-1] = atoi(wk);
		}
		else {
			break;
		}
	}
	if( cnt == 1 )  {
		return FALSE;
	}
	return TRUE;
}

/*------------------------------------------------------------
 * 惫寞涩烂及赓渝祭毛允月［
 * 娄醒
 *  filename        char*       涩烂白央奶伙  
 * 忒曰袄
 *  岳      TRUE(1)
 *  撩      FALSE(0)
 *------------------------------------------------------------*/
BOOL TITLE_initTitleConfig( char* filename )
{
	FILE*   f;
	char    line[1024];
	int     linenum=0;
	int     titlecfg_readlen=0;
	{
		f = fopen(filename,"r");
	}
	if( f == NULL ){
		errorprint;
		return FALSE;
	}

	TITLE_titlecfgnum=0;

	/*  引内  躲卅垫互窒垫丐月井升丹井譬屯月    */
	/*while( fgets( line, sizeof( line ), f ) ){}*/
	while( 1 ) {
		int rc;
		rc = TITLE_getConfigOneLine( f, line, sizeof(line));
		if( rc == 0 ) break;
		if( rc == -1 ) continue;

		TITLE_titlecfgnum++;
	}

	if( fseek( f, 0, SEEK_SET ) == -1 ){
		fprint( "Seek Error\n" );
		fclose(f);
		return FALSE;
	}

	TITLE_ConfigTable = allocateMemory( sizeof(struct tagTITLE_configTable)
								   * TITLE_titlecfgnum );
	if( TITLE_ConfigTable == NULL ){
		fprint( "Can't allocate Memory %d\n" ,
				sizeof(TITLE_ConfigTable)*TITLE_titlecfgnum);
		fclose( f );
		return FALSE;
	}
	/* 赓渝祭 */
	{
		int     i;
		for( i = 0; i < TITLE_titlecfgnum; i ++ ) {
			TITLE_initTitleData( i);
		}
	}
	TITLE_configbuf = allocateMemory( sizeof(TITLE_CONFIGBUF) * TITLE_titlecfgnum );
	if( TITLE_configbuf == NULL ){
		fprint( "Can't allocate Memory %d\n" ,
				sizeof(TITLE_CONFIGBUF)*TITLE_titlecfgnum);
		fclose( f );
		return FALSE;
	}
	
	/*  引凶  心  允    */
	linenum = 0;
	/*while( fgets( line, sizeof( line ), f ) ){}*/
	while( 1) {
		int rc;
		rc = TITLE_getConfigOneLine( f, line, sizeof(line));
		if( rc == 0 ) break;
		if( rc == -1 ) continue;

		linenum ++;

{
		char    token[256];
		int     ret;
		int     i , j ;
		int     comppos;
		BOOL    errflg =FALSE;
		for( i = 1; ; i ++ ){
			/*  玄□弁件毛苇月    */
			ret = getStringFromIndexWithDelim( line,",",i,token,
											   sizeof(token));
			if( ret == FALSE ){
				break;
			}
			/*     侬卞  晶 */
			for( j = 0; j < strlen( token); j ++ ) {
				token[j] = toupper( token[j]);
			}
			/* 惫寞隙烂毛譬屯月 */
			if( strncmp( "TITLE", token, 5) == 0 ) {
				char    buf[64];
				ret = getStringFromIndexWithDelim( token,"=",2,buf,
												   sizeof(buf));
				if( ret == FALSE) {
					fprint("文件语法错误:%s 第%d行\n",filename,linenum);
					TITLE_initTitleData( titlecfg_readlen);
					errflg = TRUE;
					break;
				}
				TITLE_ConfigTable[titlecfg_readlen].title = atoi( buf);
			}
			else {
				/* 由仿丢□正隙烂毛  戈 */
				for( j = 0; j < arraysizeof( TITLE_param); j ++ ) {
					if( strncmp( TITLE_param[j].paramname, 
								token, 
								strlen( TITLE_param[j].paramname)) 
						== 0 )
					{
						TITLE_ConfigTable[titlecfg_readlen].paramindex[i-1] = j;
						/* 隶  奶矛件玄匹惫寞毛民尼永弁允月白仿弘毛  化月［ */
						if( j == 0 || j == 1 || j == 2) {
							TITLE_ConfigTable[titlecfg_readlen].equipcheckflg = TRUE;
						}
						break;
					}
				}
				/* 由仿丢□正互  卅及毛隙烂今木凶 */
				if( j == arraysizeof( TITLE_param) ) {
					fprint("文件语法错误:%s 第%d行\n",
							filename,linenum);
					TITLE_initTitleData( titlecfg_readlen);
					errflg = TRUE;
					break;
				}
				/* 羁寞］尕羁寞互绣箕允月井譬屯月 */
				comppos = charInclude( token, "<>=");
				if( comppos == -1 ) {
					fprint("文件语法错误:%s 第%d行\n",filename,linenum);
					TITLE_initTitleData( titlecfg_readlen);
					errflg = TRUE;
					break;;
				}
				/* 羁寞］尕羁寞互ㄡ勾动晓  月午五 */
				if( charInclude( &token[comppos+1], "<>=") != -1 ) {
					/* 升氏卅  胜井毛  戈 */
					for( j = 0; j < 3;  j ++ ) {
						if( memcmp( TITLE_compare[j].compare, &token[comppos], 2 ) == 0 ) {
							break;
						}
					}
					if( j == 3 ) {
						fprint("文件语法错误:%s 第%d行\n",filename,linenum);
						TITLE_initTitleData( titlecfg_readlen);
						errflg = TRUE;
						break;
					}
					else {
						ret = TITLE_getParamData( titlecfg_readlen,i-1,&token[comppos+2]);
						if( !ret ) {
							fprint("文件语法错误:%s 第%d行\n",filename,linenum);
							TITLE_initTitleData( titlecfg_readlen);
							errflg = TRUE;
							break;
						}

						/*TITLE_ConfigTable[titlecfg_readlen].param[i-1] 
								= atoi( &token[comppos+2]);*/
						TITLE_ConfigTable[titlecfg_readlen].compareflg[i-1] = j;
					}
				}
				else {
					ret = TITLE_getParamData( titlecfg_readlen,i-1,&token[comppos+1]);
					if( !ret ) {
						fprint("文件语法错误:%s 第%d行\n",filename,linenum);
						TITLE_initTitleData( titlecfg_readlen);
						errflg = TRUE;
						break;
					}
					/*TITLE_ConfigTable[titlecfg_readlen].param[i-1] 
							= atoi( &token[comppos+1]);*/
					/* 升氏卅  胜井毛  戈 */
					for( j = 3; j < 6;  j ++ ) {
						if( memcmp( TITLE_compare[j].compare, &token[comppos], 1 ) == 0 ) {
							TITLE_ConfigTable[titlecfg_readlen].compareflg[i-1] = j;
							break;
						}
					}
				}
			}
		}
		/* 惫寞  隙烂互  井匀凶 or 卅氏井仄日及巨仿□*/
		if( errflg || TITLE_ConfigTable[titlecfg_readlen].title == -1 ) {
			fprint("文件语法错误:%s 第%d行\n",filename,linenum);
			TITLE_initTitleData( titlecfg_readlen);
		}
		else {
			titlecfg_readlen ++;
		}
}
	}
	fclose(f);

	TITLE_titlecfgnum = titlecfg_readlen;

	print( "有效头衔配置数是 %d...", TITLE_titlecfgnum );

	return TRUE;
}
/*------------------------------------------------------------
 * 惫寞涩烂卞宁丹井譬屯化惫寞毛芨尹月［
 * 娄醒
 *  charaindex        int   平乓仿奶件犯永弁旦
 *  mode              BOOL  TRUE:item=及手及及心譬屯月 FALSE:蝈  
 * 忒曰袄
 *  TRUE: 惫寞卞  祭  曰［
 *  FALSE:窒手  井匀凶［
 *------------------------------------------------------------*/
static BOOL TITLE_TitleCheck_Main( int charaindex, BOOL mode, int *addcnt, int *delcnt)
{
	int     i, j,k, ret;
	
	/* 赓渝祭 */
{
	int     i;
	for( i = 0; i < TITLE_titlecfgnum && TITLE_configbuf[i].title != -1; i ++ ) {
		TITLE_configbuf[i].title = -1;
		TITLE_configbuf[i].flg = 0;
	}
}
	*addcnt = 0;
	*delcnt = 0;
	
	for( i = 0; i < TITLE_titlecfgnum; i ++ ) {
		int rc = TRUE;
		int title = TITLE_ConfigTable[i].title;
		if( mode == TRUE ) {
			if( TITLE_ConfigTable[i].equipcheckflg != TRUE ) {
				continue;
			}
		}
		for( j = 0; 
			j < arraysizeof( TITLE_ConfigTable[i].param) && 
			TITLE_ConfigTable[i].param[j][0] != -1 ; 
			j ++ ) 
		{
			int index = TITLE_ConfigTable[i].paramindex[j];
			if( TITLE_param[index].checkfunc != NULL ) {
				rc = TITLE_param[index].checkfunc( 
						charaindex,
						TITLE_param[index].element, 
						TITLE_ConfigTable[i].param[j],
						TITLE_ConfigTable[i].compareflg[j]
						);
				if( rc != TRUE ) break;
			}
		}
		/*   醒椭瘀卞  元惫寞互喃曰癫化日木化中月凛及啃卞］
		 * 域绎田永白央卞霪户化公及瑛绊井日add,deltile允月
		 */
		for( k = 0; k < TITLE_titlecfgnum; k ++ ) {
			if( TITLE_configbuf[k].title == title ) { 
				if( rc ) {
					TITLE_configbuf[k].flg = 1;
				}
				break;
			}
			else if( TITLE_configbuf[k].title == -1 ) {
				TITLE_configbuf[k].title = title;
				TITLE_configbuf[k].flg = rc ? 1: -1;
				break;
			}
		}
	}
	ret = FALSE;
	for( i = 0; i < TITLE_titlecfgnum && TITLE_configbuf[i].title != -1; i ++ ) {
		if( TITLE_configbuf[i].flg == -1 ) {
			*delcnt += TITLE_deltitle( charaindex, TITLE_configbuf[i].title);
		}
		else {
			*addcnt += TITLE_addtitle( charaindex, TITLE_configbuf[i].title) ? 1:0;
		}
	}
	if( *delcnt > 0 || *addcnt > 0) {
		ret = TRUE;
	}
	return ret;
	
}
/*------------------------------------------------------------
 * 惫寞涩烂卞宁丹井譬屯化惫寞毛芨尹月［
 * 娄醒
 *  charaindex        int   平乓仿奶件犯永弁旦
 *  mode              BOOL  TRUE:item=及手及及心譬屯月 FALSE:蝈  
 * 忒曰袄
 *  TRUE: 惫寞卞  祭  曰［
 *  FALSE:窒手  井匀凶［
 *------------------------------------------------------------*/
BOOL TITLE_TitleCheck( int charaindex, BOOL mode)
{
#define     TITLE_MSGUNIT1      "TSU"
#define     TITLE_MSGUNIT2      "KO"
	int     addcnt,delcnt;
	BOOL    rc;
	char    msgbuf[64];
	rc = TITLE_TitleCheck_Main( charaindex, mode, &addcnt,&delcnt);
	if( rc ) {
		if( delcnt > 0 ) {
			snprintf( msgbuf, sizeof( msgbuf), 
						"失去%d%s 称号！", delcnt,
						delcnt < 10 ?  TITLE_MSGUNIT1:TITLE_MSGUNIT2);
			CHAR_talkToCli( charaindex, -1, msgbuf,  CHAR_COLORYELLOW);
		}
		if( addcnt > 0 ) {
			snprintf( msgbuf, sizeof( msgbuf), 
						"获得%d%s 称号！", addcnt,
						addcnt < 10 ?  TITLE_MSGUNIT1:TITLE_MSGUNIT2);
			CHAR_talkToCli( charaindex, -1, msgbuf,  CHAR_COLORYELLOW);
		}
	}
	return rc;
}
/*------------------------------------------------------------
 * 惫寞涩烂卞宁丹井譬屯化惫寞毛芨尹月［
 * 娄醒
 *  charaindex        int   平乓仿奶件犯永弁旦
 *  mode              BOOL  TRUE:item=及手及及心譬屯月 FALSE:蝈  
 * 忒曰袄
 *  TRUE: 惫寞卞  祭  曰［
 *  FALSE:窒手  井匀凶［
 *------------------------------------------------------------*/
BOOL TITLE_TitleCheck_Nomsg( int charaindex, BOOL mode, int *addcnt, int *delcnt)
{
	return( TITLE_TitleCheck_Main( charaindex, mode, addcnt,delcnt));
}


static int TITLE_IntCheck( int charaindex, int elem, int *data, int flg)
{
	int     rc = FALSE;
	int     i;
	for( i = 0; i < TITLE_PARAMSIZE && *(data+i) != -1; i ++ ) {
		switch( flg) {
		  case 0:       /* "<=" */
			if( CHAR_getInt( charaindex, elem) <= *(data+i) ) rc = TRUE;
			break;
		  case 1:       /* ">=" */
			if( CHAR_getInt( charaindex, elem) >= *(data+i) ) rc = TRUE;
			break;
		  case 2:       /* "<>" */
			if( CHAR_getInt( charaindex, elem) != *(data+i) ) rc = TRUE;
			break;
		  case 3:       /* ">" */
			if( CHAR_getInt( charaindex, elem) > *(data+i) ) rc = TRUE;
			break;
		  case 4:       /* "<"  */
			if( CHAR_getInt( charaindex, elem) < *(data+i) ) rc = TRUE;
			break;
		  case 5:       /* "=" */
			if( CHAR_getInt( charaindex, elem) == *(data+i) ) rc = TRUE;
			break;
		  default:
		  rc= FALSE;
		  break;
		}
		if( rc) break;
	}
	return rc;
}
static int TITLE_WorkIntCheck( int charaindex,int elem, int *data, int flg)
{
	int     rc = FALSE;
	int i;
	for( i = 0; i < TITLE_PARAMSIZE && *(data+i) != -1; i ++ ) {
		switch( flg) {
		  case 0:       /* "<=" */
			if( CHAR_getWorkInt( charaindex, elem) <= *(data+i) ) rc = TRUE;
			break;
		  case 1:       /* ">=" */
			if( CHAR_getWorkInt( charaindex, elem) >= *(data+i) ) rc = TRUE;
			break;
		  case 2:       /* "<>" */
			if( CHAR_getWorkInt( charaindex, elem) != *(data+i) ) rc = TRUE;
			break;
		  case 3:       /* ">" */
			if( CHAR_getWorkInt( charaindex, elem) > *(data +i)) rc = TRUE;
			break;
		  case 4:       /* "<"  */
			if( CHAR_getWorkInt( charaindex, elem) < *(data+i) ) rc = TRUE;
			break;
		  case 5:       /* "=" */
			if( CHAR_getWorkInt( charaindex, elem) == *(data+i) ) rc = TRUE;
			break;
		  default:
		  rc= FALSE;
		  break;
		}
		if( rc ) break;
	}
	return rc;
}
/* --------------------------------------
 * 隙烂今木凶data午  匀化中月失奶  丞毛  胜允月［
 * -------------------------------------*/
static int TITLE_ItemCheckMain( int charaindex, int itemhaveindex, int *data, int flg)
{
	int i,j;
	int rc = FALSE;
	
	if( flg == 2 ) rc = TRUE;

	for( j = 0; j < TITLE_PARAMSIZE && *(data+j) != -1; j ++ ) {
		for( i =0; i < itemhaveindex; i ++ ) {
			int     itemindex = CHAR_getItemIndex(charaindex,i);
			if( ITEM_CHECKINDEX(itemindex) ) {
				switch( flg) {
				  case 0:       /* "<=" */
					if( ITEM_getInt( itemindex, ITEM_ID) <= *(data+j) ) rc = TRUE;
					break;
				  case 1:       /* ">=" */
					if( ITEM_getInt( itemindex, ITEM_ID) >= *(data+j) ) rc = TRUE;
					break;
				  case 3:       /* ">" */
					if( ITEM_getInt( itemindex, ITEM_ID) > *(data +j)) rc = TRUE;
					break;
				  case 4:       /* "<"  */
					if( ITEM_getInt( itemindex, ITEM_ID) < *(data +j)) rc = TRUE;
					break;
				  case 5:       /* "=" */
					if( ITEM_getInt( itemindex, ITEM_ID) == *(data +j)) rc = TRUE;
					break;
				  /* 仇木分仃    健中［
				   * 失奶  丞蝈  毛苇化公木毛  匀化中卅井匀凶日蕞午允月［
				   * 仇仇匹反  匀化中月仪毛絮午仄化民尼永弁
				   */
				  case 2:       /* "<>" */
					if( ITEM_getInt( itemindex, ITEM_ID) == *(data +j)) rc = FALSE;
					break;
				  default:
				  rc= FALSE;
				  break;
				}
				if( rc && flg != 2) break;
			}
		}
		if( rc) break;
	}
	return rc;
}


static int TITLE_ItemCheck( int charaindex,int elem, int *data, int flg)
{
	return( TITLE_ItemCheckMain( charaindex, CHAR_getMaxInventory( charaindex ),data,flg));
}

static int TITLE_ItemEquipCheck( int charaindex,int elem, int *data, int flg)
{
	return( TITLE_ItemCheckMain( charaindex, CHAR_EQUIPPLACENUM,data,flg));
}

static int TITLE_SkillCheck( int charaindex,int elem, int *data, int flg)
{
	int i;
	int rc = FALSE;
	CHAR_HaveSkill* hskill;

	for( i = 0 ; i < CHAR_SKILLMAXHAVE ; i ++ ){
		hskill = CHAR_getCharHaveSkill( charaindex, i );
		if( hskill != NULL && hskill->use == TRUE ) {

			if( *(data + 1) != -2 ) {
				if( SKILL_getInt( &hskill->skill, SKILL_IDENTITY) == *data) {
					rc = TRUE;
					break;
				}
			}

			else {
				if( SKILL_getInt( &hskill->skill, SKILL_IDENTITY) == *data) {
					rc = FALSE;
					break;
				}
				else {
					rc = TRUE;
				}
			}
		}
	}
	if( rc ) {

		if( *(data+1) != -1 && *(data+1) != -2) {
			rc = FALSE;
			switch( flg) {
			  case 0:       /* "<=" */
				if( SKILL_getInt( &hskill->skill, SKILL_LEVEL) <= *(data+1) ) rc = TRUE;
				break;
			  case 1:       /* ">=" */
				if( SKILL_getInt( &hskill->skill, SKILL_LEVEL) >= *(data+1) ) rc = TRUE;
				break;
			  case 2:       /* "<>" */
				if( SKILL_getInt( &hskill->skill, SKILL_LEVEL) != *(data+1) ) rc = TRUE;
				break;
			  case 3:       /* ">" */
				if( SKILL_getInt( &hskill->skill, SKILL_LEVEL) > *(data +1)) rc = TRUE;
				break;
			  case 4:       /* "<"  */
				if( SKILL_getInt( &hskill->skill, SKILL_LEVEL) < *(data+1) ) rc = TRUE;
				break;
			  case 5:       /* "=" */
				if( SKILL_getInt( &hskill->skill, SKILL_LEVEL) == *(data+1) ) rc = TRUE;
				break;
			  default:
			  rc= FALSE;
			  break;
			}
		}
	}
	return rc;
}
/* --------------------------------------
 * 裆平乓仿井辉平乓仿井民尼永弁允月［
 * -------------------------------------*/
static int TITLE_SexCheck( int charaindex,int elem, int *data, int flg)
{
	int     i,j;
	struct {
		int sex[25];
	}s_sex[] =
	{ { { 30008,30009,30010,30011,30012,30013,30014,30015,
		30020,30021,30022,30023,30024,30025,30026,30027,
		30028,30029,30030,30031,30032,30033,30034,30035,-1}
	  },
	  { {30000,30001,30002,30003,30004,30005,30006,30007,
		30016,30017,30018,30019,30036,30037,30038,30039,
		-1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  -1}
	  }
	};
	for( i = 0; i < 2; i ++ ) {
		for( j = 0; s_sex[i].sex[j] != -1 ; j ++ ) {
			if( CHAR_getInt( charaindex, CHAR_BASEBASEIMAGENUMBER ) 
				== s_sex[i].sex[j] ) 
			{
				if( i == *data ) return TRUE;
				else            return FALSE;
			}
		}
	}
	return FALSE;
}


