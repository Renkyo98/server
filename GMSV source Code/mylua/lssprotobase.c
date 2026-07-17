#include <string.h>
#include <stdio.h>
#include <math.h>
#include "char.h"
#include "char_base.h"
#include "mylua/base.h"
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#include "lssproto_serv.h"

#ifdef _ALLBLUES_LUA   


#define		WINDOW_BUTTONTYPE_NONE		(0)
#define		WINDOW_BUTTONTYPE_OK		(1 << 0)
#define		WINDOW_BUTTONTYPE_CANCEL	(1 << 1)
#define		WINDOW_BUTTONTYPE_YES		(1 << 2)
#define		WINDOW_BUTTONTYPE_NO		(1 << 3)
#define		WINDOW_BUTTONTYPE_PREV		(1 << 4)
#define		WINDOW_BUTTONTYPE_NEXT		(1 << 5)

#define		WINDOW_BUTTONTYPE_OKCANCEL	(WINDOW_BUTTONTYPE_OK | WINDOW_BUTTONTYPE_CANCEL)
#define		WINDOW_BUTTONTYPE_YESNO	(WINDOW_BUTTONTYPE_YES | WINDOW_BUTTONTYPE_NO)


static CharBase CharBaseWindow[] = {
	{{"对话框"}, 					WINDOW_MESSAGETYPE_MESSAGE}
	,{{"输入框"}, 				WINDOW_MESSAGETYPE_MESSAGEANDLINEINPUT}
	,{{"选择框"},					WINDOW_MESSAGETYPE_SELECT}
	,{{"宠物框"}, 				WINDOW_MESSAGETYPE_PETSELECT}
	,{{"卖道具框"}, 			WINDOW_MESSAGETYPE_ITEMSHOPMENU}
	,{{"买道具框"}, 			WINDOW_MESSAGETYPE_ITEMSHOPMAIN}
	,{{"学技能框"}, 				WINDOW_MESSAGETYPE_PETSKILLSHOP}
#ifdef _NEW_MANOR_LAW
	,{{"十大气势家族"}, 	WINDOW_FMMESSAGETYPE_10_MEMONTUM}
	,{{"家族气势列表"}, 	WINDOW_FMMESSAGETYPE_FM_MEMONTUM}
#endif
	,{{"家族成员列表"}, 	WINDOW_FMMESSAGETYPE_DENGON}
	,{{"庄园列表"}, 			WINDOW_FMMESSAGETYPE_POINTLIST}
	,{{"前三大列表"}, 		WINDOW_FMMESSAGETYPE_TOP30DP}
	,{{"银行框"}, 				WINDOW_MESSAGETYPE_BANK}
	,{{"宽对话框"}, 			WINDOW_MESSAGETYPE_WIDEMESSAGE}
	,{{"宽输入框"}, 			WINDOW_MESSAGETYPE_WIDEMESSAGEANDLINEINPUT}
	,{{"拍卖框"}, 				WINDOW_MESSAGETYPE_AUCTIONNEW}
	,{{"拍卖买框"}, 			WINDOW_MESSAGETYPE_AUCTIONLIST_BUY}
	,{{"拍卖查看框"}, 		WINDOW_MESSAGETYPE_AUCTIONSURVEY}
	,{{"拍卖修改框"}, 		WINDOW_MESSAGETYPE_AUCTIONMODIFY}
	,{{"拍卖列表修改框"}, WINDOW_MESSAGETYPE_AUCTIONLIST_MODIFY}
	,{{"拍卖输入框"}, 		WINDOW_MESSAGETYPE_WIDEMESSAGEANDLINEINPUT}
	,{{"融合宠框"}, 			WINDOWS_MESSAGETYPE_PETFUSION}
}; 

static CharBase CharBaseButton[] = {
	{{"无按钮"}, 					WINDOW_BUTTONTYPE_NONE}
	,{{"确定"}, 					WINDOW_BUTTONTYPE_OK}
	,{{"取消"},						WINDOW_BUTTONTYPE_CANCEL}
	,{{"YES"}, 						WINDOW_BUTTONTYPE_YES}      
	,{{"NO"}, 						WINDOW_BUTTONTYPE_NO}
	,{{"上一页"}, 				WINDOW_BUTTONTYPE_PREV|WINDOW_BUTTONTYPE_CANCEL}
	,{{"下一页"}, 				WINDOW_BUTTONTYPE_NEXT|WINDOW_BUTTONTYPE_CANCEL}
}; 

static CharBase CharBaseSeqNo[] = {
	{{""}, 								-1}
#ifdef _PETSKILL_CANNEDFOOD
	,{{"宠物技能选择"}, 	ITEM_WINDOWTYPE_SELECTPETSKILL_SELECT}
#endif
	,{{"道具人物宠物"}, 	CHAR_WINDOWTYPE_ITETOPLAYERPET}
#ifdef _ITEM_PET_LOCKED
	,{{"安全锁"}, 	CHAR_WINDOWTYPE_ITEM_PET_LOCKED}
#endif
}; 


static int windows_validation(lua_State *L) 
{
	size_t l;
	const int index = luaL_checkint(L, 1);
	if(CHAR_CHECKINDEX(index) == FALSE) return 0;
	int fd = getfdFromCharaIndex( index);
  const int windowtype = getCharBaseValue(L, 2, CharBaseWindow, arraysizeof(CharBaseWindow),1);
  const int buttontype = getCharBaseValue(L, 3, CharBaseButton, arraysizeof(CharBaseButton),1);
  const int seqno = getCharBaseValue(L, 4, CharBaseSeqNo, arraysizeof(CharBaseSeqNo),1);
  const int objindex=luaL_checkint(L, 5);
  char *data=luaL_checklstring(L, 6, &l);
  char *validation=luaL_checklstring(L, 7, &l);
  
/*
  char *str=luaL_checklstring(L, 7, &l);
  
	int validation = 0;
	int i;
	for(i=0; i < strlen(str); i ++){
		validation += (((str[i] - 'A') + 1) * pow(26, i));
	}
	
	validation = validation << 4;
*/
	lssproto_CAPTCHA_send(fd,validation);
	lssproto_WN_send(fd, windowtype, buttontype + 2048, seqno, objindex, data);
	return 1;
}

static int windows_send(lua_State *L) 
{
	size_t l;
	const int index = luaL_checkint(L, 1);
	if(CHAR_CHECKINDEX(index) == FALSE) return 0;
	int fd = getfdFromCharaIndex( index);
  const int windowtype = getCharBaseValue(L, 2, CharBaseWindow, arraysizeof(CharBaseWindow),1);
  const int buttontype = getCharBaseValue(L, 3, CharBaseButton, arraysizeof(CharBaseButton),1);
  const int seqno = getCharBaseValue(L, 4, CharBaseSeqNo, arraysizeof(CharBaseSeqNo),1);
  const int objindex=luaL_checkint(L, 5);
  char *data=luaL_checklstring(L, 6, &l);


	lssproto_WN_send(fd, windowtype, buttontype, seqno, objindex, data);
	return 1;
}

static int show(lua_State *L) 
{
	size_t l;
	const int index = luaL_checkint(L, 1);
	if(CHAR_CHECKINDEX(index) == FALSE) return 0;
	int fd = getfdFromCharaIndex( index);
  char *data=luaL_checklstring(L, 2, &l);
	lssproto_C_send(fd, data);
	return 1;
}

static int FM(lua_State *L) 
{
	size_t l;
	const int index = luaL_checkint(L, 1);
	if(CHAR_CHECKINDEX(index) == FALSE) return 0;
	int fd = getfdFromCharaIndex( index);
  char *data=luaL_checklstring(L, 2, &l);
  
	lssproto_FM_send(fd, data);
	return 1;
}
#ifdef _ADD_STATUS_2
static int S2(lua_State *L) 
{
	size_t l;
	const int index = luaL_checkint(L, 1);
	if(CHAR_CHECKINDEX(index) == FALSE) return 0;
	int fd = getfdFromCharaIndex( index);
  char *data=luaL_checklstring(L, 2, &l);
  
	lssproto_S2_send(fd, data);
	return 1;
}
#endif

static int dengon(lua_State *L) 
{
	size_t l;
	const int index = luaL_checkint(L, 1);
	if(CHAR_CHECKINDEX(index) == FALSE) return 0;
	int fd = getfdFromCharaIndex( index);
  char *data=luaL_checklstring(L, 2, &l);
  const int color=luaL_checkint(L, 3);
  const int num=luaL_checkint(L, 4);
  
	lssproto_DENGON_send(fd, data, color, num);
	return 1;
}

static int CharList(lua_State *L) 
{
	size_t l;
	const int fd = luaL_checkint(L, 1);
  char *data=luaL_checklstring(L, 2, &l);

	lssproto_CharList_send(fd, FAILED, data);
	return 1;
}

static int ClientLogin(lua_State *L) 
{
	size_t l;
	const int fd = luaL_checkint(L, 1);
  char *data=luaL_checklstring(L, 2, &l);

	lssproto_ClientLogin_send(fd, data);
	return 1;
}

static int SaMenu(lua_State *L) 
{
	const int charaindex = luaL_checkint(L, 1);
	if(CHAR_CHECKINDEX(charaindex) == FALSE) return 0;
	int fd = getfdFromCharaIndex( charaindex);
	size_t l;
  char *data=luaL_checklstring(L, 2, &l);
	lssproto_SAMENU_send(fd, data);
	return 1;
}

static int W2(lua_State *L) 
{
	const int charaindex = luaL_checkint(L, 1);
	if(CHAR_CHECKINDEX(charaindex) == FALSE) return 0;
	int fd = getfdFromCharaIndex( charaindex);
  const int x = luaL_checkint(L, 2);
  const int y = luaL_checkint(L, 3);
	size_t l;
  char *direction=luaL_checklstring(L, 4, &l);
	lssproto_W2_recv(fd, x, y, direction);
	return 1;
}

static int B(lua_State *L) 
{
	size_t l;
	const int charaindex = luaL_checkint(L, 1);
	if(CHAR_CHECKINDEX(charaindex) == FALSE) return 0;
	int fd = getfdFromCharaIndex( charaindex);
  char *data=luaL_checklstring(L, 2, &l);
	lssproto_B_recv(fd, data);
	
	return 1;
}

static int MI(lua_State *L) 
{
	size_t l;
	const int charaindex = luaL_checkint(L, 1);
	const int fromid = luaL_checkint(L, 2);
	const int toid = luaL_checkint(L, 3);
	if(CHAR_CHECKINDEX(charaindex) == FALSE) return 0;
	int fd = getfdFromCharaIndex( charaindex);
	lssproto_MI_recv(fd, fromid,toid);
	
	return 1;
}
static int GetInfoSend(lua_State *L) 
{
	const int charaindex = luaL_checkint(L, 1);
	if(CHAR_CHECKINDEX(charaindex) == FALSE) return 0;
	int fd = getfdFromCharaIndex( charaindex);
	size_t l;
	lssproto_GetInfo_send(fd);
	return 1;
}

#ifdef _NB_FAMILYBADGE
int FamilyBadgeData[200];
int FamilyBadgeDataNum;
int FamilyBadgePrice;

static int GetFBData(lua_State *L)
{
	FamilyBadgeDataNum=-1;
	int len = luaL_getn(L, 1);
	if(len>0){
		int i=1;
		for(i;i<=len;i++){
			FamilyBadgeDataNum++;
			lua_rawgeti(L, 1, i);
			FamilyBadgeData[FamilyBadgeDataNum]=(int)lua_tointeger(L, -1);
			lua_pop(L, 1);
		}
	}
	FamilyBadgePrice = luaL_checkint(L, 2);
	return 1;
}
#endif

static const luaL_Reg lssprotolib[] = {
	{"windows", 			windows_send},
	{"show", 					show},
	{"FM", 						FM},
#ifdef _ADD_STATUS_2
	{"S2", 						S2},
#endif
	{"dengon", 				dengon},
	{"CharList", 			CharList},
	{"ClientLogin", 	ClientLogin},
	{"SaMenu", 				SaMenu},
	{"W2", 						W2},
	{"B", 						B},
	{"MI", 						MI},
	{"windows_validation", 		windows_validation},
	{"GetInfoSend", 			GetInfoSend},
#ifdef _NB_FAMILYBADGE
	{"GetFBData",			GetFBData},
#endif
  {NULL, 						NULL}
};

LUALIB_API int luaopen_Lssproto (lua_State *L) {
  luaL_register(L, "lssproto", lssprotolib);
  return 1;
}

#endif

