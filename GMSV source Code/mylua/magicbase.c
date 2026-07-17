#include <string.h>
#include "common.h"
#include "char_talk.h"
#include "mylua/base.h"
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#include "mylua/ablua.h"
#include "magic_base.h"
#include "lssproto_serv.h"
#ifdef _ALLBLUES_LUA_1_2
#include "mylua/mylua.h"
extern MY_Lua MYLua;

static CharBase MagicBaseInt[] = {
	{{"ID"}, 					MAGIC_ID}
	,{{"字段"}, 			MAGIC_FIELD}
	,{{"目标"}, 			MAGIC_TARGET}
	,{{"死亡目标"}, 	MAGIC_TARGET_DEADFLG}
#ifdef _ATTACK_MAGIC 
	,{{"攻击精灵"}, 	MAGIC_IDX}
#endif
};


static CharBase MagicBaseChar[] = {
	{{"名字"}, 		MAGIC_NAME}
	,{{"注释"}, 	MAGIC_COMMENT}
	,{{"函数名"}, MAGIC_FUNCNAME}
	,{{"选项"}, 	MAGIC_OPTION}
};


static int addLUAListFunction(lua_State *L) 
{
	size_t l;
	char *luafuncname = luaL_checklstring(L, 1, &l);
  char *luafunctable = luaL_checklstring(L, 2, &l);
	char *luafunctablepath = luaL_checklstring(L, 3, &l);
	const int gmlevel = luaL_checkint(L, 4);
	char *usestring = luaL_checklstring(L, 5, &l);
	
	
	if(strlen(luafunctablepath) > 0){
		MY_Lua *mylua = &MYLua;
	  while(mylua->next != NULL){
	  	if(strcmp(mylua->luapath, luafunctablepath) == 0){
				return MAGIC_addLUAListFunction( mylua->lua, luafuncname, luafunctable, gmlevel, usestring );
	  	}
	  	mylua = mylua->next;
	  }
	}else{
		return MAGIC_addLUAListFunction( L, luafuncname, luafunctable, gmlevel, usestring );
	}
	return 1;
	
}

static int getChar(lua_State *L) 
{
	const int magicid = luaL_checkint(L, 1);
	const int element = getCharBaseValue(L, 2, MagicBaseChar, arraysizeof(MagicBaseChar),1);
	int marray = MAGIC_getMagicArray( magicid);
	if( marray != -1 ){
		lua_pushstring(L, MAGIC_getChar( marray, element));
	}else{
		lua_pushstring(L, "");
	}
	return 1;
}

static int getInt(lua_State *L) 
{
	const int magicid = luaL_checkint(L, 1);
	const int element = getCharBaseValue(L, 2, MagicBaseInt, arraysizeof(MagicBaseInt),1);
	int marray = MAGIC_getMagicArray( magicid);
	if( marray != -1 ){
		lua_pushinteger(L, MAGIC_getInt( marray, element));
	}else{
		lua_pushinteger(L, -1);
	}
	return 1;
}


static const luaL_Reg magiclib[] = {
	{"addLUAListFunction", 			addLUAListFunction},
	{"getInt", 									getInt},
	{"getChar", 								getChar},
  {NULL, 											NULL}
};

LUALIB_API int luaopen_Magic (lua_State *L) {
  luaL_register(L, "magic", magiclib);
  return 1;
}

#endif

