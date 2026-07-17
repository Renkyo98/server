#include <string.h>
#include "common.h"
#include "version.h"
#include "profession_skill.h"
#include "mylua/base.h"
#include "char.h"
#include "item.h"
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#include "lssproto_serv.h"

#ifdef _PROFESSION_SKILL			// WON ADD 人物职业技能
#ifdef _ALLBLUES_LUA_1_8 
#include "mylua/mylua.h"
extern MY_Lua MYLua;

static CharBase ProfessionSkillBaseInt[] = {
	{{"编号"},							PROFESSION_SKILL_ID}
	,{{"职业"},							PROFESSION_SKILL_PROFESSION_CLASS}
	,{{"目标"},							PROFESSION_SKILL_TARGET}
	,{{"耗费MP"},						PROFESSION_SKILL_COST_MP}
	,{{"旗标"},							PROFESSION_SKILL_USE_FLAG}
	,{{"种类"},							PROFESSION_SKILL_KIND}
	,{{"图号"},							PROFESSION_SKILL_ICON}
	,{{"攻击前图号"},				PROFESSION_SKILL_IMG_1}
	,{{"攻击图号"},					PROFESSION_SKILL_IMG_2}
	,{{"金额"},							PROFESSION_SKILL_COST}
	,{{"升级数值"},					PROFESSION_SKILL_FIX_VALUE}
	,{{"必修1"},						PROFESSION_SKILL_LIMIT1}
	,{{"必修熟练度1"},			PROFESSION_SKILL_PERCENT1}
	,{{"必修2"},						PROFESSION_SKILL_LIMIT2}
	,{{"必修熟练度2"},			PROFESSION_SKILL_PERCENT2}
	,{{"必修3"},						PROFESSION_SKILL_LIMIT3}
	,{{"必修熟练度3"},			PROFESSION_SKILL_PERCENT3}
	,{{"必修4"},						PROFESSION_SKILL_LIMIT4}
	,{{"必修熟练度4"},			PROFESSION_SKILL_PERCENT4}
}; 

static CharBase ProfessionSkillBaseChar[] = {
	{{"名称"},					PROFESSION_SKILL_NAME}
	,{{"注释"},					PROFESSION_SKILL_TXT}
	,{{"函数"},					PROFESSION_SKILL_FUNCNAME}
	,{{"选项"},					PROFESSION_SKILL_OPTION}
}; 

static int getInt(lua_State *L) 
{
	const int index = luaL_checkint(L, 1);
	const int element = getCharBaseValue(L, 2, ProfessionSkillBaseInt, arraysizeof(ProfessionSkillBaseInt),1);

	lua_pushinteger(L, PROFESSION_SKILL_getInt(index, element));
	return 1;
}

static int setInt(lua_State *L) 
{
	const int index = luaL_checkint(L, 1);
	const int element = getCharBaseValue(L, 2, ProfessionSkillBaseInt, arraysizeof(ProfessionSkillBaseInt),1);
	const int data = luaL_checkint(L, 3);
	
  if(PROFESSION_SKILL_setInt(index, element, data) == -1){
  	return 0;
  }else{
  	return 1;
  }
}

static int getChar(lua_State *L) 
{
	const int index = luaL_checkint(L, 1);
	const int element = getCharBaseValue(L, 2, ProfessionSkillBaseChar, arraysizeof(ProfessionSkillBaseChar),1);

	lua_pushstring(L, PROFESSION_SKILL_getChar(index, element));
	return 1;
}

static int setChar(lua_State *L) 
{
	size_t l;
	const int index = luaL_checkint(L, 1);
	const int element = getCharBaseValue(L, 2, ProfessionSkillBaseChar, arraysizeof(ProfessionSkillBaseChar),1);
	char *data = luaL_checklstring(L, 3, &l);
	
  if(PROFESSION_SKILL_setChar(index, element, data) == -1){
  	return 0;
  }else{
  	return 1;
  }
}

static int getProfessionskillArray(lua_State *L) 
{
	const int index = luaL_checkint(L, 1);

	lua_pushinteger(L, PROFESSION_SKILL_getskillArray(index));
	return 1;
}

static const luaL_Reg Professionskilllib[] = {
	{"getInt", 									getInt},
	{"setInt", 									setInt},
	{"getChar", 								getChar},
	{"setChar", 								setChar},
	{"getProfessionskillArray", getProfessionskillArray},
  {NULL, 						NULL}
};
/*
LUALIB_API int luaopen_ProfessionSkill (lua_State *L) {
  luaL_register(L, "Professionskill", Professionskilllib);
  return 1;
}*/
#endif
#endif

