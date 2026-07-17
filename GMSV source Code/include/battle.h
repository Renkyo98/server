#ifndef __BATTLE_H__
#define __BATTLE_H__
#include "net.h"
#ifdef _TRADE_PK
#include "trade.h"
#endif
#ifdef _ALLBLUES_LUA_1_4
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#endif

#define	BATTLE_ENTRY_MAX 10
#define	BATTLE_PLAYER_MAX 5
#define SIDE_OFFSET 	10

#define BATTLE_STRING_MAX	4096
#define BATTLE_TIME_LIMIT	(60*60)


#define DUELPOINT_RATE	(0.1)

enum{
	BATTLE_MODE_NONE = 0,	// 无战斗状态
	BATTLE_MODE_INIT,		// 战斗初始化
	BATTLE_MODE_BATTLE,		// 战斗中
	BATTLE_MODE_FINISH,		// 战斗结束
	BATTLE_MODE_STOP,		// 战斗结束(未使用)
	BATTLE_MODE_WATCHBC,	// 观战初始化
	BATTLE_MODE_WATCHPRE,	// 观战(没作用)
	BATTLE_MODE_WATCHWAIT,	// 观战(没作用)
	BATTLE_MODE_WATCHMOVIE, // 观战(没作用)
	BATTLE_MODE_WATCHAFTER, // 观战(没作用)
	BATTLE_MODE_END
};


enum{
	BATTLE_TYPE_NONE = 0,
	BATTLE_TYPE_P_vs_E = 1,
	BATTLE_TYPE_P_vs_P = 2,
	BATTLE_TYPE_E_vs_E = 3,
	BATTLE_TYPE_WATCH = 4,
	BATTLE_TYPE_DP_BATTLE = 5,
	BATTLE_TYPE_BOSS_BATTLE = 6,
	BATTLE_TYPE_END
};


enum{
	BATTLE_CHARMODE_NONE = 0,		// 无战斗状态
	BATTLE_CHARMODE_INIT,			// 战斗初始化
	BATTLE_CHARMODE_C_WAIT,			// 等待战斗指令
	BATTLE_CHARMODE_C_OK,			// 已输入战斗指令
	BATTLE_CHARMODE_BATTLE,			// 未使用
	BATTLE_CHARMODE_RESCUE,			// 由help状态进入的
	BATTLE_CHARMODE_FINAL,			// 战斗结束
	BATTLE_CHARMODE_WATCHINIT,		// 观战初始化
	BATTLE_CHARMODE_COMMAND,		// 未使用
	BATTLE_CHARMODE_END
};




typedef enum{
	BATTLE_ERR_NONE = 0,
	BATTLE_ERR_NOTASK,
	BATTLE_ERR_NOUSE,
	BATTLE_ERR_PARAM,
	BATTLE_ERR_ENTRYMAX,
	BATTLE_ERR_TYPE,
	BATTLE_ERR_CHARAINDEX,
	BATTLE_ERR_BATTLEINDEX,
	BATTLE_ERR_NOENEMY,
	BATTLE_ERR_ALREADYBATTLE,
	BATTLE_ERR_SAMEPARTY,
	BATTLE_ERR_END
}BATTLE_ERR;


enum{
	BATTLE_S_TYPE_PLAYER = 0,
	BATTLE_S_TYPE_ENEMY,
	BATTLE_S_TYPE_END
};


typedef enum{
	BATTLE_COM_NONE,
	BATTLE_COM_ATTACK,
	BATTLE_COM_GUARD,
	BATTLE_COM_CAPTURE,
	BATTLE_COM_ESCAPE,
	BATTLE_COM_PETIN,
	BATTLE_COM_PETOUT,
	BATTLE_COM_ITEM,
	BATTLE_COM_BOOMERANG,
	BATTLE_COM_COMBO,
	BATTLE_COM_COMBOEND,
	BATTLE_COM_WAIT,

	BATTLE_COM_SEKIBAN = 1000,
	BATTLE_COM_S_RENZOKU,
	BATTLE_COM_S_GBREAK,
	BATTLE_COM_S_GUARDIAN_ATTACK,
	BATTLE_COM_S_GUARDIAN_GUARD,
	BATTLE_COM_S_CHARGE,
	BATTLE_COM_S_MIGHTY,
	BATTLE_COM_S_POWERBALANCE,
	BATTLE_COM_S_STATUSCHANGE,
	BATTLE_COM_S_EARTHROUND0,
	BATTLE_COM_S_EARTHROUND1,
	BATTLE_COM_S_LOSTESCAPE,
	BATTLE_COM_S_ABDUCT,
	BATTLE_COM_S_STEAL,
	BATTLE_COM_S_NOGUARD,
	BATTLE_COM_S_CHARGE_OK,
	BATTLE_COM_JYUJYUTU = 2000,

	BATTLE_COM_COMPELESCAPE, //强制离开

#ifdef _ATTACK_MAGIC
  BATTLE_COM_S_ATTACK_MAGIC,		// 宠物魔法
#endif

#ifdef _PSKILL_FALLGROUND
	BATTLE_COM_S_FALLRIDE,			//落马术
#endif
#ifdef _PETSKILL_RIDE//上马术
	BATTLE_COM_S_RIDE,
#endif
#ifdef _PETSKILL_PROVOKEFIGHT//挑衅反击
	BATTLE_COM_S_PROVOKEFIGHT,
#endif
#ifdef _PETSKILL_EXPLODE
	BATTLE_COM_S_EXPLODE,
#endif
#ifdef _PETSKILL_TIMID
	BATTLE_COM_S_TIMID,
#endif
#ifdef _PETSKILL_2TIMID
	BATTLE_COM_S_2TIMID,
#endif
#ifdef _PETSKILL_ANTINTER
	BATTLE_COM_S_ANTINTER,
#endif
#ifdef _PETSKILL_PROPERTY
	BATTLE_COM_S_PROPERTYSKILL,
#endif
#ifdef _PETSKILL_TEAR
	BATTLE_COM_S_PETSKILLTEAR,
#endif
#ifdef _BATTLE_LIGHTTAKE
	BATTLE_COM_S_LIGHTTAKE,
#endif
#ifdef _BATTLE_ATTCRAZED		// ANDY 疯狂暴走
	BATTLE_COM_S_ATTCRAZED,
#endif
#ifdef _SHOOTCHESTNUT			// Syu ADD 宠技：丢栗子
	BATTLE_COM_S_ATTSHOOT,
#endif
#ifdef _BATTLESTEAL_FIX
	BATTLE_COM_S_STEALMONEY,
#endif
#ifdef _PRO_BATTLEENEMYSKILL
	BATTLE_COM_S_ENEMYRELIFE,		//NPC ENEMY 复活技能
	BATTLE_COM_S_ENEMYREHP,			//NPC ENEMY 补血技能
	BATTLE_COM_S_ENEMYHELP,			//NPC ENEMY 招人
#endif
#ifdef _SKILL_DAMAGETOHP
	BATTLE_COM_S_DAMAGETOHP,		//嗜血技
#endif
#ifdef _Skill_MPDAMAGE
	BATTLE_COM_S_MPDAMAGE,			//MP伤害
#endif
#ifdef _SKILL_WILDVIOLENT_ATT
    BATTLE_COM_S_WILDVIOLENTATTACK, //狂暴攻击  vincent add 2002/05/16
#endif

#ifdef _SKILL_SPEEDY_ATT
    BATTLE_COM_S_SPEEDYATTACK,		//疾速攻击  vincent add 2002/05/20
#endif
#ifdef _SKILL_GUARDBREAK2
    BATTLE_COM_S_GBREAK2,			//破除防御2 vincent add 2002/05/20
#endif
#ifdef _SKILL_SACRIFICE
    BATTLE_COM_S_SACRIFICE,			//救援		vincent add 2002/05/30
#endif
#ifdef _SKILL_WEAKEN  
	    BATTLE_COM_S_WEAKEN,		//虚弱		vincent add 2002/07/11
#endif
#ifdef _SKILL_DEEPPOISON  
	    BATTLE_COM_S_DEEPPOISON,	//剧毒		vincent add 2002/07/16
#endif
#ifdef _SKILL_BARRIER  
	    BATTLE_COM_S_BARRIER,		//魔障		vincent add 2002/07/16
#endif
#ifdef _SKILL_NOCAST 
	    BATTLE_COM_S_NOCAST,		//沉默		vincent add 2002/07/16
#endif
#ifdef _SKILL_ROAR 
    BATTLE_COM_S_ROAR,			    //大吼		vincent add 2002/07/11
#endif
#ifdef _BATTLENPC_WARP_PLAYER
	BATTLE_COM_WARP,                // npc warp player
#endif
#ifdef _SKILL_TOOTH
	BATTLE_COM_S_TOOTHCRUSHE,
#endif
#ifdef _PSKILL_MODIFY
	BATTLE_COM_S_MODIFYATT,
#endif
#ifdef _PSKILL_MDFYATTACK
	BATTLE_COM_S_MDFYATTACK,
#endif
#ifdef _MAGIC_SUPERWALL
	BATTLE_COM_S_SUPERWALL,
#endif
#ifdef _SKILL_REFRESH
    BATTLE_COM_S_REFRESH,
#endif
#ifdef _VARY_WOLF
	BATTLE_COM_S_VARY,
#endif
#ifdef _PETSKILL_SETDUCK
	BATTLE_COM_S_SETDUCK,
#endif
#ifdef _MAGICPET_SKILL
	BATTLE_COM_S_SETMAGICPET,
#endif
#ifdef _PROFESSION_SKILL			// WON ADD 人物职业技能

// 巫师
	BATTLE_COM_S_VOLCANO_SPRINGS,	// 火山泉	
	BATTLE_COM_S_FIRE_BALL,			// 火星球
	BATTLE_COM_S_FIRE_SPEAR,		// 火龙枪
	BATTLE_COM_S_SUMMON_THUNDER,	// 召雷术
	BATTLE_COM_S_CURRENT,			// 电流术
	BATTLE_COM_S_STORM,				// 暴风雨
	BATTLE_COM_S_ICE_ARROW,			// 冰箭术
	BATTLE_COM_S_ICE_CRACK,			// 冰爆术
	BATTLE_COM_S_ICE_MIRROR,		// 冰镜术
	BATTLE_COM_S_DOOM,				// 世界末日
	BATTLE_COM_S_BLOOD,				// 嗜血成性
	BATTLE_COM_S_BLOOD_WORMS,		// 嗜血蛊
	BATTLE_COM_S_SIGN,				// 一针见血
	BATTLE_COM_S_FIRE_ENCLOSE,		// 火附体	
	BATTLE_COM_S_ICE_ENCLOSE,		// 冰附体
	BATTLE_COM_S_THUNDER_ENCLOSE,	// 雷附体
	BATTLE_COM_S_ENCLOSE,			// 附身术
	BATTLE_COM_S_TRANSPOSE,			// 移形换位
// 勇士
	BATTLE_COM_S_BRUST,				// 爆击			
	BATTLE_COM_S_CHAIN_ATK,			// 连环攻击
	BATTLE_COM_S_AVOID,				// 回避
	BATTLE_COM_S_RECOVERY,			// 补血
	BATTLE_COM_S_WEAPON_FOCUS,		// 武器专精
	BATTLE_COM_S_REBACK,			// 状态回复
	BATTLE_COM_S_CHAIN_ATK_2,		// 双重攻击
	BATTLE_COM_S_SCAPEGOAT,			// 舍已为友
	BATTLE_COM_S_ENRAGE,			// 激化攻击
	BATTLE_COM_S_COLLECT,			// 能量聚集
	BATTLE_COM_S_FOCUS,				// 专注战斗
	BATTLE_COM_S_SHIELD_ATTACK,		// 盾击
	BATTLE_COM_S_DUAL_WEAPON,		// 二刀流
	BATTLE_COM_S_DEFLECT,			// 格档
	BATTLE_COM_S_THROUGH_ATTACK,	// 贯穿攻击
	BATTLE_COM_S_CAVALRY,			// 座骑攻击
	BATTLE_COM_S_DEAD_ATTACK,		// 濒死攻击
	BATTLE_COM_S_CONVOLUTE,			// 回旋攻击
	BATTLE_COM_S_CHAOS,				// 混乱攻击
// 猎人
	BATTLE_COM_S_TRAP,				// 陷阱			
	BATTLE_COM_S_TRACK,				// 追寻敌踪
	BATTLE_COM_S_DOCILE,			// 驯伏宠物	
	BATTLE_COM_S_ENRAGE_PET,		// 激怒宠物	
	BATTLE_COM_S_DRAGNET,			// 天罗地网
	BATTLE_COM_S_ENTWINE,			// 树根缠绕
	BATTLE_COM_S_AUTARKY,			// 自给自足
	BATTLE_COM_S_PLUNDER,			//   体掠夺
	BATTLE_COM_S_TOXIN_WEAPON,		// 毒素武器
	BATTLE_COM_S_RESIST_FIRE,		// 火抗性提升
	BATTLE_COM_S_RESIST_ICE,		// 冰抗性提升
	BATTLE_COM_S_RESIST_THUNDER,	// 雷抗性提升
	BATTLE_COM_S_G_RESIST_FIRE,		// 团体火抗性提升
	BATTLE_COM_S_G_RESIST_ICE,		// 团体冰抗性提升
	BATTLE_COM_S_G_RESIST_THUNDER,	// 团体雷抗性提升
	BATTLE_COM_S_ATTACK_WEAK,		// 弱点攻击
	BATTLE_COM_S_INSTIGATE,			// 挑拨
	BATTLE_COM_S_OBLIVION,			// 遗忘
#ifdef _PROFESSION_ADDSKILL
	BATTLE_COM_S_RESIST_F_I_T,      // 自然威能
	BATTLE_COM_S_CALL_NATURE,       // 号召自然
  BATTLE_COM_S_BOUNDARY,          // 四属性结界
#endif
#endif
#ifdef _PRO_KILLME
	BATTLE_COM_S_KILLME,						//舍身诱敌
#endif
#ifdef _PRO_ABSOLUTE_DEFENSE
	BATTLE_COM_S_ABSOLUTE_DEFENSE,	//绝对防御
#endif
#ifdef _PETSKILL_ISULTIMATE
	BATTLE_COM_S_ISULTIMATE,
#endif
#ifdef _PRO3_ADDSKILL
	BATTLE_COM_S_CRACK_BONE,		//裂骨断筋
	BATTLE_COM_S_POISON_DRAGNET,	//毒素之网
	BATTLE_COM_S_PACIFY,			//抚慰心灵
	BATTLE_COM_S_DARK_SEAL,			//?灵封印
	BATTLE_COM_S_RESTATE,			//斗气导引,神灵之赐
	BATTLE_COM_S_DEMON_SPEECH,		//恶魔诅咒
	BATTLE_COM_S_FIRST_AID,			//战场急救
	BATTLE_COM_S_PROAR,				//战狼怒吼
	BATTLE_COM_S_MEDICATION,		//制药学
#endif
#ifdef _PET_SKILL_SARS				// WON ADD 毒煞蔓延
	BATTLE_COM_S_SARS,
#endif
#ifdef _SONIC_ATTACK				// WON ADD 音波攻击
	BATTLE_COM_S_SONIC,
	BATTLE_COM_S_SONIC2,
#endif
#ifdef _PETSKILL_REGRET
	BATTLE_COM_S_REGRET,
	BATTLE_COM_S_REGRET2,
#endif
#ifdef _PETSKILL_GYRATE
    BATTLE_COM_S_GYRATE,
#endif
#ifdef _PETSKILL_ACUPUNCTURE
    BATTLE_COM_S_ACUPUNCTURE,
#endif
#ifdef _PETSKILL_RETRACE
	BATTLE_COM_S_RETRACE,
#endif
#ifdef _PETSKILL_HECTOR
	BATTLE_COM_S_HECTOR,
#endif
#ifdef _PETSKILL_FIREKILL
    BATTLE_COM_S_FIREKILL,
#endif
#ifdef _PETSKILL_DAMAGETOHP
	BATTLE_COM_S_DAMAGETOHP2, //暗月狂狼(嗜血技的变体) 
#endif
#ifdef _PETSKILL_BECOMEFOX
    BATTLE_COM_S_BECOMEFOX,
#endif
#ifdef _PETSKILL_BECOMEPIG
    BATTLE_COM_S_BECOMEPIG,
#endif
#ifdef _PETSKILL_SHOWMERCY
    BATTLE_COM_S_SHOWMERCY,
#endif
#ifdef _PETSKILL_LER
		BATTLE_COM_S_BAT_FLY,					// 雷尔技 - 群蝠四窜
		BATTLE_COM_S_DIVIDE_ATTACK,		// 雷尔技 - 分身地裂
#endif
#ifdef _PETSKILL_BATTLE_MODEL
		BATTLE_COM_S_BATTLE_MODEL,		// 宠物技能战斗模组
#endif

#ifdef _MASSAGE_PETSKILL
		BATTLE_COM_S_MASSAGE,		// 马杀鸡技能
#endif

#ifdef _STRENGTH_PETSKILL
		BATTLE_COM_S_STRENGTH,		// 元气技能
#endif
#ifdef _RESURRECTION_PETSKILL
	BATTLE_COM_S_RESURRECTION,
#endif
#ifdef _LOSTLOST_PETSKILL
	BATTLE_COM_S_LOSTLOST,
#endif
#ifdef _GRAPPLING_PETSKILL
	BATTLE_COM_S_GRAPPLING,
#endif
#ifdef _PETOUT_PETSKILL
	BATTLE_COM_S_PETOUT,
#endif
#ifdef _OFFLINE_SYSTEM
	BATTLE_COM_S_OFFLINE_RECOVERY,
#endif
#ifdef _INVERSION_PETSKILL
	BATTLE_COM_S_INVERSION, // 反转技能
#endif
	BATTLE_COM_JYUJYUTU2,
#ifdef _PETSKILL_PLUS1
	BATTLE_COM_S_PLUS1,			//增强技能	shen add 2012/07/10
#endif
	BATTLE_COM_END
}BATTLE_COM;


enum{
	BATTLE_RET_NORMAL,
	BATTLE_RET_CRITICAL,
	BATTLE_RET_MISS,
	BATTLE_RET_DODGE,
	BATTLE_RET_ALLGUARD,
#ifdef _EQUIT_ARRANGE
	BATTLE_RET_ARRANGE,
#endif
	BATTLE_RET_END
}BATTLE_RET;


#define BC_FLG_NEW			(1<<0)
#define BC_FLG_DEAD			(1<<1)
#define BC_FLG_PLAYER		(1<<2)
#define BC_FLG_POISON		(1<<3)
#define BC_FLG_PARALYSIS	(1<<4)
#define BC_FLG_SLEEP		(1<<5)
#define BC_FLG_STONE		(1<<6)
#define BC_FLG_DRUNK		(1<<7)
#define BC_FLG_CONFUSION	(1<<8)
#define BC_FLG_HIDE			(1<<9)
#define BC_FLG_REVERSE		(1<<10)
#ifdef _MAGIC_WEAKEN
#define BC_FLG_WEAKEN		(1<<11) // 虚弱
#endif
#ifdef _MAGIC_DEEPPOISON
#define BC_FLG_DEEPPOISON	(1<<12) // 剧毒
#endif
#ifdef _MAGIC_BARRIER
#define BC_FLG_BARRIER		(1<<13) // 魔障
#endif
#ifdef _MAGIC_NOCAST
#define BC_FLG_NOCAST		(1<<14) // 沉默
#endif

#ifdef _PET_SKILL_SARS			// WON ADD 毒煞蔓延
#define BC_FLG_SARS			(1<<15) // 毒煞
#endif

#ifdef _PROFESSION_SKILL			// WON ADD 人物职业技能
#define BC_FLG_DIZZY		(1<<16)	// 晕眩	
#define BC_FLG_ENTWINE		(1<<17)	// 树根缠绕
#define BC_FLG_DRAGNET		(1<<18)	// 天罗地网	
#define BC_FLG_ICECRACK	    (1<<19)	// 冰爆术	
#define BC_FLG_OBLIVION  	(1<<20)	// 遗忘
#define BC_FLG_ICEARROW		(1<<21)	// 冰箭
#define BC_FLG_BLOODWORMS 	(1<<22)	// 嗜血蛊
#define BC_FLG_SIGN 		(1<<23)	// 一针见血
#define BC_FLG_CARY			(1<<24) // 挑拨
#define BC_FLG_F_ENCLOSE	(1<<25) // 火附体
#define BC_FLG_I_ENCLOSE	(1<<26) // 冰附体
#define BC_FLG_T_ENCLOSE	(1<<27) // 雷附体
#ifdef _PROFESSION_ADDSKILL
#define BC_FLG_WATER	    (1<<28) // 水附体
#define BC_FLG_FEAR			(1<<29) // 恐惧
#endif
#ifdef _PETSKILL_LER
#define BC_FLG_CHANGE			(1<<30) // 雷尔变身
#endif
#ifdef _PRO_KILLME
#define BC_FLG_ANGER			(1<<31) // 舍身诱敌
#endif
#endif




#define BP_FLG_JOIN					(1<<0)
#define BP_FLG_PLAYER_MENU_OFF		(1<<1)
#define BP_FLG_BOOMERANG			(1<<2)
#define BP_FLG_PET_MENU_OFF			(1<<3)
#define BP_FLG_ENEMY_SURPRISAL		(1<<4)
#define BP_FLG_PLAYER_SURPRISAL		(1<<5)


#define CHAR_BATTLEFLG_ULTIMATE		(1<<0)
#define CHAR_BATTLEFLG_AIBAD		(1<<1)
#define CHAR_BATTLEFLG_REVERSE		(1<<2)
#define CHAR_BATTLEFLG_GUARDIAN		(1<<3)
#define CHAR_BATTLEFLG_NORETURN		(1<<4)
#define CHAR_BATTLEFLG_RECOVERY		(1<<5)
#define CHAR_BATTLEFLG_ABIO			(1<<6)
#define CHAR_BATTLEFLG_NODUCK		(1<<7)

#define GETITEM_MAX	3
typedef struct
{
	int attacker;
}INVADER;

typedef struct
{
	int		charaindex;
	int		bid;
	int		escape;
	int		flg;
	int		guardian;
	int		duelpoint;
	int		getitem[GETITEM_MAX];
#ifdef BOSS_AI
	int     hatred;
	int     addhpskill;
	int     purgeflg;
	int		proskilluse;
#endif
}BATTLE_ENTRY;
#define BENT_FLG_ULTIMATE	(1<<0)

typedef struct
{
	int		type;
	int		flg;
	int		common_dp;
	BATTLE_ENTRY	Entry[BATTLE_ENTRY_MAX];
}BATTLE_SIDE;

#define BSIDE_FLG_SURPRISE ( 1 << 0 )
#define BSIDE_FLG_HELP_OK ( 1 << 1 )



#ifdef _ALLBLUES_LUA_1_4
typedef enum
{
	BATTLE_FINISH,
	BATTLE_ESCAPE,
	BATTLE_FUNCTABLENUM,
}BATTLE_FUNCTABLE;
#endif


typedef struct _Battle
{
	BOOL	use;	/* 银匀化中月井升丹井 */
	int		battleindex; /* 田玄伙  寞 */
	int		mode;	/* 蜇箕及爵  乒□玉 */
	int		type;	/* 爵  正奶皿 (0:骚橘)(1:DUEL)(2:示旦爵) */
	int		dpbattle;	/* DP田玄伙井＂ */
	int		norisk;	/* 韶氏匹手伉旦弁及  中田玄伙井＂ */
	int		turn;	/* 正□件醒 */
	int		timer;	/* 它巨奶玄羁卞银丹正奶穴 */
	int		leaderindex; /* 巨件市它件玄毛粟仇仄凶平乓仿及奶件犯永弁旦 */
#ifdef _AUTO_PK
	char  leadercdkey[CDKEYLEN];
	char  leadername[CHARNAMELEN];
	int		rivalindex;
	char  rivalcdkey[CDKEYLEN];
	char  rivalname[CHARNAMELEN];
#endif

#ifdef _TRADE_PK
	STradeList TradeList[2];
#endif
	int		BattleFloor; /*   厍仄凶扔奶玉 */
	int		winside; /*   厍仄凶扔奶玉 */
	int		field_att;	/* 白奴□伙玉及箪岭 */
	int		att_count;	/* 白奴□伙玉及箪岭  祭  及正奶穴 */
	int		att_pow;	/* 白奴□伙玉及箪岭  祭  及由伐□ */
	int		field_no;
	int		flg;		/* 备潘白仿弘 */
	BATTLE_SIDE		Side[2];
#ifdef _BATTLE_TIMESPEED
	unsigned int CreateTime;
	unsigned int EndTime;
	unsigned int PartTime;
	int flgTime;
#endif

#ifdef _PROFESSION_ADDSKILL
	//冰爆术存放
	int ice_count;//暂存数量
	int ice_bout[20];//回合计数
	BOOL ice_use[20];//是否使用
	int ice_toNo[20];//对象
	int ice_level[20];//攻击力
	int ice_array[20];
	int ice_charaindex[20];
	int ice_attackNo[20];
#endif

	int		iEntryBack[BATTLE_ENTRY_MAX*2];		// 蟆正□件瓒  今木化中凶丢件田□
	int		iEntryBack2[BATTLE_ENTRY_MAX*2];		// 蟆正□件瓒  今木化中凶丢件田□
	int		createindex;	/* 仇及爵  毛综曰请仄凶平乓仿奶件犯永弁旦(NPC卅升) */
	int    (*WinFunc)( int battleindex, int charaindex );
#ifdef _ALLBLUES_LUA_1_4
		lua_State *lua[BATTLE_FUNCTABLENUM];
		char *luafunctable[BATTLE_FUNCTABLENUM];
#endif
	struct _Battle *pNext;		// 戚及棋爵弘伙□皿
	struct _Battle *pBefore;	// 蟆及棋爵弘伙□皿
#ifdef _BATTLE_TIME
	unsigned int tv_sec;
	unsigned int tv_usec;
#endif
	int topbattleindex;
	
#ifdef NB_BATTLEDATA
	int		leaderindex1;
	int		leaderindex2;
	int		leaderindex3;
	int		leaderindex4;
	int		leaderindex5;
	int		rivalindex1;
	int		rivalindex2;
	int		rivalindex3;
	int		rivalindex4;
	int		rivalindex5;
#endif
	
}BATTLE;

#define BATTLE_FLG_FREEDP ( 1 << 0 )	//   仆化手    蛹日卅中
#define BATTLE_FLG_CHARALOST   ( 1 << 1 )	// 平乓仿互韶氏分曰  仃凶曰仄化中月

enum{	// 晓及field_att 卞  木月袄
	BATTLE_ATTR_NONE = 0,	//   箪岭
	BATTLE_ATTR_EARTH,		// 哗
	BATTLE_ATTR_WATER,		//   
	BATTLE_ATTR_FIRE,		// 绍
	BATTLE_ATTR_WIND,		// 氘
	BATTLE_ATTR_END
};


//krynn 2001/12/28
enum
{
	BATTLE_SIDE_RIGHT,		// 战斗中右侧	right side of battle
	BATTLE_SIDE_LEFT,		// 战斗中左侧	left side of battle
	BATTLE_SIDE_WATCH,		// 观战			watch battle player
};
//krynn end

#define TARGET_SIDE_0	20	// 惘础  扔奶玉ㄟ  隙烂
#define TARGET_SIDE_1	21	// 尔础  扔奶玉ㄠ  隙烂
#define TARGET_ALL	22	// 蝈  隙烂

#ifdef _ATTACK_MAGIC

#define TARGET_SIDE_0_B_ROW     26      // 右下後一列
#define TARGET_SIDE_0_F_ROW     25      // 右下前一列
#define TARGET_SIDE_1_F_ROW     24      // 左上前一列
#define TARGET_SIDE_1_B_ROW     23      // 左上後一列

// won add
#define	TARGER_THROUGH			27

#endif

extern int	gItemCrushRate;		//   莽  犯白巧伙玄
extern BATTLE *BattleArray; 	/* 爵  正旦弁     */
extern int BATTLE_battlenum;	/*     及醒 */
extern char szAllBattleString[BATTLE_STRING_MAX];	/* 爵  卞银丹戊穴件玉  侬   */
extern char *pszBattleTop, *pszBattleLast;	/* 爵  卞银丹  侬  及匏   */
extern char szBadStatusString[];	// 旦  □正旦唱橘迕  侬  
extern int gWeponType;	// 蜇箕及  湛及潘  
extern float gDamageDiv;	// 母丢□斥坌喃

BOOL BATTLE_CHECKINDEX( int battleindex );
#define BATTLE_CHECKSIDE( a ) ( ((a)>=2 || (a)<0)?(FALSE):( TRUE) )
#define BATTLE_CHECKNO( a ) ( ((a)>=20 || (a)<0 )?(FALSE):(TRUE) )
#define BATTLE_CHECKADDRESS( a )  ((&BattleArray[0])<=(a) && (a)<=(&BattleArray[BATTLE_battlenum-1] )?(TRUE):(FALSE) ) 

#define IsBATTLING( a ) (CHAR_getWorkInt((a),CHAR_WORKBATTLEMODE)?(TRUE):(FALSE))

#define STRCPY_TAIL( _pszTop, _pszLast, _szBuffer)	{ int _len = strlen( _szBuffer ); ( _pszTop + _len < (_pszLast)-1 )?( memcpy( _pszTop, _szBuffer, _len ),	_pszTop += _len, _pszTop[0] = 0):(0); }

#define BATTLESTR_ADD( _szBuffer ){ int _len = strlen( _szBuffer ); ( pszBattleTop + _len < ( pszBattleLast)-1 )?( memcpy( pszBattleTop, _szBuffer, _len ),	pszBattleTop += _len, pszBattleTop[0] = 0):(0); }

#define BATTLE_MAP_MAX 219

#define CH_FIX_PLAYERLEVELUP	(+2)	// 皿伊奶乩□及伊矛伙互失永皿
#define CH_FIX_PLAYERDEAD		(-2)	// 皿伊奶乩□互骚橘韶
#define CH_FIX_PLAYEULTIMATE	(-4)	// 皿伊奶乩□互失伙  奴丢永玄韶
#define CH_FIX_PETESCAPE		(-1)	// 矢永玄互  仆凶

#define AI_FIX_PETLEVELUP		(+5*100)	// 矢永玄互伊矛伙失永皿
#define AI_FIX_PETWIN			(+1)		// 矢永玄互衬毛逦仄凶
#define AI_FIX_PETGOLDWIN		(+2*10)	// 矢永玄互伊矛伙及嫖中衬毛逦仄凶
#define AI_FIX_PETRECOVERY		(+10)		// 爵    卞荚汊仄化手日匀凶
#define AI_FIX_PETRESSURECT		(+3*100)	// 爵    卞汊唾仄化手日匀凶
//#define AI_FIX_PETRECOVERY	(+50)		// 爵    卞荚汊仄化手日匀凶

#define AI_FIX_SEKKAN 			(-2*100)	// 愤坌及矢永玄毛  猾
#define AI_FIX_PLAYERULTIMATE	(-10*100)	// 愤坌及潜谛互失伙  奴丢永玄韶
#define AI_FIX_PETULTIMATE		(-10*100)	// 矢永玄互失伙  奴丢永玄韶
#define AI_FIX_PLAYERDEAD		(-1*100)	// 愤坌及潜谛互竣濮
#define AI_FIX_PETDEAD			(-5*100)	// 矢永玄互竣濮


#ifdef _Item_ReLifeAct
int BATTLE_getBattleDieIndex( int battleindex, int bid );
#endif
int BATTLE_AddProfit( int battleindex,	int *pBidList);
int BATTLE_No2Index( int battleindex, int No);

int BATTLE_Index2No( int battleindex, int charaindex);

int BATTLE_ToRandNo(int battleindex,int flg);

BOOL BATTLE_initBattleArray( int battlenum);

int BATTLE_CreateBattle( void );
int BATTLE_DeleteBattle( int battleindex);

int BATTLE_NewEntry( int charaindex, int battleindex, int side);

#define BATTLE_Exit( charaindex, battleindex) _BATTLE_Exit( __FILE__, __LINE__, charaindex, battleindex)
INLINE int _BATTLE_Exit( char *file, int line, int charaindex ,int battleindex);

#define BATTLE_ExitAll( battleindex) _BATTLE_ExitAll( __FILE__, __LINE__, battleindex)
INLINE void _BATTLE_ExitAll( char *file, int line, int battleindex);

int BATTLE_CreateVsPlayer( int charaindex0,	int charaindex1);

int BATTLE_CreateVsEnemy( int charaindex, int mode,	int	npcindex);

int BATTLE_CreateVsEnemyNew( int charaindex, int npcindex, int *enemytable );
int BATTLE_CreateVsEnemyLvNew( int charaindex, int npcindex, int *table, int *lvtable );

int BATTLE_CountEntry( int battleindex,	int side);

int BATTLE_Loop( void );

int BATTLE_FinishSet( int battleindex );
int BATTLE_StopSet( int battleindex );
int BATTLE_RescueEntry( int charaindex, int toindex);

int BATTLE_PetDefaultExit( int charaindex, int battleindex);

int	BATTLE_PetDefaultEntry(
	int charaindex,	// 矢永玄毛  匀化中月皿伊奶乩□及          
	int battleindex,// 田玄伙奶件犯永弁旦
	int side
);

BOOL BATTLE_RescueTry( int charaindex);

BOOL BATTLE_RescueParentTry(
		int charaindex,
		int pindex
	);

int BATTLE_DefaultAttacker(	int battleindex, int side);

BOOL BATTLE_IsThrowWepon( int itemindex);

void BATTLE_BadStatusString( int defNo, int status );
int BATTLE_MultiList( int battleindex, int toNo, int ToList[] );
BOOL BATTLE_IsCharge( int com );
BOOL BATTLE_CanMoveCheck( int charaindex );
int BATTLE_TargetCheck( int battleindex, int defNo);
char *BATTLE_CharTitle( int charaindex );
void BATTLE_EscapeDpSend( int battleindex, int charaindex );
int BATTLE_GetDuelPoint( int battleindex, int side, int num);
int BATTLE_TargetCheckDead(	int battleindex, int defNo);

void BATTLE_MultiListDead( int battleindex, int toNo, int ToList[] );
BOOL BATTLE_WatchTry( int charaindex);
int BATTLE_WatchEntry( int charaindex, int toindex);
void BATTLE_WatchStop( int charaindex );
int BATTLE_WatchUnLink( int battleindex );
void BATTLE_BpSendToWatch( BATTLE *pBattle,	char *pszBcString);

int BATTLE_GetWepon( int charaindex );

#ifdef _ITEM_EQUITSPACE
int BATTLE_GetEqShield( int charaindex );
#endif

int BATTLE_GetAttackCount( int charaindex );
int DoujyouRandomWeponSet( int charaindex );
void BATTLE_AttReverse( int charaindex );
void BATTLE_BadStatusAllClr( int charaindex );
#define CHAR_GETWORKINT_HIGH( index, pos )	( CHAR_getWorkInt( (index), (pos) ) >> 16 )
#define CHAR_SETWORKINT_HIGH( index, pos, set )	{ int iTmp = CHAR_getWorkInt( (index), (pos) ) & 0xFFFF, work = (set);	CHAR_setWorkInt( (index), (pos), (work << 16)|iTmp ); }
#define CHAR_GETWORKINT_LOW( index, pos )	( CHAR_getWorkInt( (index), (pos) ) & 0xFFFF )
#define CHAR_SETWORKINT_LOW( index, pos, set )	{ int iTmp = CHAR_getWorkInt( index, pos ) & 0xFFFF0000, work = (set);	CHAR_setWorkInt( (index), (pos), (work & 0x0000FFFF) | iTmp ); }

int Battle_getTotalBattleNum();

#ifdef _TYPE_TOXICATION
void CHAR_ComToxicationHp( int charaindex);
#endif

#ifdef _PROFESSION_SKILL			// WON ADD 人物职业技能
void BATTLE_ProfessionStatus_init( int battleindex, int charaindex );
void BATTLE_ProfessionStatusSeq( int battleindex, int charaindex);
#endif
#ifdef _TRADE_PK
int BATTLE_CreateVsPlayerForTrade( STradeList TradeList1, STradeList TradeList2 );
#endif

#ifdef _ALLBLUES_LUA_1_4
INLINE BOOL BATTLE_setLUAFunction( int battleindex, int functype, lua_State *L, const char *luafunctable);
INLINE lua_State *BATTLE_getLUAFunction( int battle, int functype);
#endif

#endif
