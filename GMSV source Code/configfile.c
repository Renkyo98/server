#define __CONFIGFILE_C__
#include "version.h"
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

#include "util.h"
//#include "configfile.h"
//ttom
#include "lssproto_util.h"
#include "configfile.h"
#include "net.h"
//ttom end
#include "npcutil.h"
// Arminius 7.12 login announce
#include "char.h"
#include "char_data.h"
// CoolFish: add 
#include "lssproto_serv.h"
#include "autil.h"

#ifdef _ANGEL_SUMMON
extern struct MissionInfo missionlist[MAXMISSION];
extern struct MissionTable missiontable[MAXMISSIONTABLE];
#endif

extern char* CHAR_setintdata[CHAR_DATAINTNUM];
extern char* CHAR_setchardata[CHAR_DATACHARNUM];

char firstdesToken[100000][12];
char seconddesToken[100000][20];

char firstrandToken[900000][12];
char secondrandToken[900000][20];

/* É¬ÀÃÃ«âç  ÔÊÔÂÑáÕ°   */
typedef struct tagConfig
{
    /*Ãó·òºë·ÂØ©  (·ß  ¶Á±å·Æ»§Ð×ÖÐØêÉýÒý·ÖòÍ  */
  char    progname[8];
  char    configfilename[32]; /* config°×ÑëÄÌ»ï   */
    unsigned char debuglevel;   /* ·¸ÌïÓÀºëÒÁÃ¬»ï */
  unsigned int  usememoryunit;    /*¶ªÆ¹Øø¼°½»ÍßÓÀÐþÈÓÄÌÊõ */
  unsigned int  usememoryunitnum; /*¶ªÆ¹Øø¼°½»ÍßÓÀÐþÐÑ */
  char    asname[32];         /*Ê§ÊÐËü¼þÐþÈÓ¡õÌï¼°  ó¡*/
  unsigned short  acservport; /*Ê§ÊÐËü¼þÐþÈÓ¡õÌï¼°ºÌ¡õÐþ  */
  char    acpasswd[32];       /*Ê§ÊÐËü¼þÐþÈÓ¡õÌï³ß¼°ÓÉµ©·¥¡õÓñ*/
  char    gsnamefromas[32];   /*
                                 * Ê§ÊÐËü¼þÐþÈÓ¡õÌï¾®ÈÕÎ­ÒüÔÂ
                                 * ±Ø¡õØ©ÈÓ¡õÌïÎçØÆ»¯¼°  ó¡
                                 */
                                 
    // Arminius 7.24 manor pk
  char gsid[32];	// game server chinese id
  char gslsid[32];	// game server chinese id
  unsigned short allowmanorpk;	// is this server allow manor pk
  unsigned short port;        /* ÈÓ¡õÌï¼°½÷ÇÐ°¾ØêºÌ¡õÐþ */
	int				servernumber;	/* ±Ø¡õØ©ÈÓ¡õÌï¼°  Ä¯ */
	int				reuseaddr;	/* Address already used... »¥÷±ÒýÈÕØ¦ÖÐÁÝ¼°Ð×»§±å */
  int             do_nodelay;     /* TCP_NODELAY ±åÔÊÔÂ¾®Éýµ¤¾® */
  int             log_write_time; /* Ì¤Îå³ðÐÄ·òºëÃ«ÔÊÔÂ¾®Éýµ¤¾®£Û */
  int             log_io_time;    /* I/Oòå  ¼°ÁÝÃÞ·´¾®ÔÂ¾®Éýµ¤¾®£Û */
  int             log_game_time;  /* ±Ø¡õØ©¼°ÖÊ  òå  ¼°ÁÝÃÞÃ«·´¾®ÔÂ */
  int             log_netloop_faster; /* netloop_faster ¼°·òºë */
	int				saacwritenum;	/* Ê§ÊÐËü¼þÐþÈÓ¡õÌï³ß¼°ÖÏÚÐ  ±åwriteÔÊÔÂ¾® */
	int				saacreadnum;	/* Ê§ÊÐËü¼þÐþÈÓ¡õÌï¾®ÈÕ¼°dispatch Ã«ÖÏ¼ÔÔÊÔÂ¾® */
  unsigned short fdnum;           /*ÉýÄ¾·ÖØêÎìÉúÛÍÆËÒà¼þÃ«âç  ÔÊÔÂ¾® */
  unsigned short charnum;           /*ÉýÄ¾·ÖØêÎìÉúÛÍÆËÒà¼þÃ«âç  ÔÊÔÂ¾® */
  unsigned int   othercharnum;    /*  ¹«¼°Ö°¼°Æ½ÅÒ·Â¼°ÐÑ  */
  unsigned int objnum;            /* ×óÆ¤³âÄáÛÍÐþ¼°    ÐÑ*/
  unsigned int   petcharnum;   	/* Ê¸ÓÀÐþ¼°ÐÑ    */
  unsigned int itemnum;           /* Ê§ÄÌ  Ø©¼°    ÐÑ*/
  unsigned int battlenum;         /* ÌïÐþ»ï¼°    */
#ifdef _GET_BATTLE_EXP
  unsigned int battleexp;         /* ÌïÐþ»ï¼°    */
#endif
    char    topdir[64];         	/* ÐþÓÀÃó·¸Å«ÒÁÛÍÐþØø  */

    char    mapdir[64];         	/* Ñ¨ÓÀÃó·¸Å«ÒÁÛÍÐþØø  */
    char    maptilefile[64];    	/* Ñ¨ÓÀÃóÉ¬ÀÃ°×ÑëÄÌ»ï  */
    char    battlemapfile[64];    	/* ÌïÐþ»ïÑ¨ÓÀÃóÉ¬ÀÃ°×ÑëÄÌ»ï  */
    char    itemfile[64];       	/* Ê§ÄÌ  Ø©É¬ÀÃ°×ÑëÄÌ»ï  */
    char    invfile[64];        	/*   ³ÄÉ¬ÀÃ°×ÑëÄÌ»ï  */
    char    appearfile[64];     	/* ÇëòØÞË  É¬ÀÃ°×ÑëÄÌ»ï  */
	char	titlenamefile[64];		/* ±¹Ä¯°×ÑëÄÌ»ï   */
	char	titleconfigfile[64];	/* ±¹Ä¯É¬ÀÃ°×ÑëÄÌ»ï   */
	char	encountfile[64];		/* ¾Þ¼þÊÐËü¼þÐþÉ¬ÀÃ°×ÑëÄÌ»ï   */
	char	enemybasefile[64];		/* ³ÄÏæ  É¬ÀÃ°×ÑëÄÌ»ï   */
	char	enemyfile[64];			/* ³ÄÉ¬ÀÃ°×ÑëÄÌ»ï   */
	char	groupfile[64];			/* ºë»ï¡õÃóÉ¬ÀÃ°×ÑëÄÌ»ï   */
	char	magicfile[64];			/* ÈÈÖîÉ¬ÀÃ°×ÑëÄÌ»ï   */
#ifdef _ATTACK_MAGIC
	char  attmagicfile[64];       // ¹¥»÷ÐÔÖäÊõ
#endif

	char	petskillfile[64];		/* Ê¸ÓÀÐþ  ÈÈÖîÉ¬ÀÃ°×ÑëÄÌ»ï   */
    char    itematomfile[64];       /* Ê§ÄÌ  Ø©¼°¼ã    °×ÑëÄÌ»ï */
    char    effectfile[64];     	/* ÉÒÇëÉ¬ÀÃ°×ÑëÄÌ»ï  */
    char    quizfile[64];     		/* ÛÍÄÌÊõÉ¬ÀÃ°×ÑëÄÌ»ï  */


    char    lsgenlog[64];       /*ÈÓ¡õÌï¼°lsgen Ê§ËüÐþÃóÓÀÐþ°×ÑëÄÌ»ï  */

    char    storedir[64];       /*µ©ÐþÊ§·¸Å«ÒÁÛÍÐþØø    */
    char    npcdir[64];         /*NPC¼°É¬ÀÃ°×ÑëÄÌ»ïÃ«  ÈÊ·¸Å«ÒÁÛÍÐþØø   */

    char    logdir[64];         /*
                                 * ·òºë·¸Å«ÒÁÛÍÐþØø
                                 */
    char    logconfname[64];    /*
                                 * ·òºëÉ¬ÀÃ°×ÑëÄÌ»ï  
                                 */
    char	chatmagicpasswd[64];	/* ÃñÅÒÓÀÐþ  Ü·ÓÉµ©·¥¡õÓñ */

#ifdef _STORECHAR
    char	storechar[64];
#endif
	unsigned int 	chatmagiccdkeycheck;	/* ÃñÅÒÓÀÐþ  Ü·Æ¥CDKEYÃ«ÃñÄáÓÀÛÍÔÊÔÂ¾® */
  unsigned int    filesearchnum;     /*°×ÑëÄÌ»ïÃ«¸¹³ñÆ¥ÎåÔÂ°×ÑëÄÌ»ï¼°ÐÑ*/
  unsigned int    npctemplatenum;     /*NPC¼°  ¼þÃóÒÁ¡õÐþ°×ÑëÄÌ»ï¼°ÐÑ*/
  unsigned int    npccreatenum;       /*NPC¼°Ï·Ç²°×ÑëÄÌ»ï¼°ÐÑ*/
  unsigned int    walksendinterval;   /* ÐÚÈÊ¼°Ã«ËªÔÂÃÞØÊ */
  unsigned int    CAsendinterval_ms;     /* CAÃ«ËªÔÂÃÞØÊ (ms)*/
  unsigned int    CDsendinterval_ms;     /* CDÃ«ËªÔÂÃÞØÊ (ms)*/
  unsigned int    Onelooptime_ms;     	/* 1»ï¡õÃó±å¾®ØêÔÂÁÝÃÞ */
	unsigned int	Petdeletetime;		/* Ê¸ÓÀÐþ»¥ÛÕ  ÔÊÔÂÁÝÃÞ */
	unsigned int	Itemdeletetime;		/* Ê§ÄÌ  Ø©»¥ÛÕ  ÔÊÔÂÁÝÃÞ */
	unsigned int	Functionfile;//º¯ÊýÎÄ¼þÃû

    /* ·òºëÄÌ¼þ  ¼°Æ½ÅÒ·Â¼°±¾¡õÆ¤Ã«ÔÊÔÂÃÞØÊ */
  unsigned int    CharSavesendinterval;
  unsigned int    addressbookoffmsgnum;  /*
                                          * Ê§ÓñÒÁµ©Æ¤ÓÀÛÍ±å×ó°×·ÂÄÌ¼þ
                                          * ¶ªÓÀ±¾¡õ³âÃ«
                                          * ÖÏ¶ªÓÀ±¾¡õ³âËáÁùÔÂ¾®
                                          */
  unsigned int    protocolreadfrequency;  /*
                                           * Ãó·òÐþÎì»ïÃ«ÖÏÁ¢Øø    
                                           * ±å  ¸ê¾®
                                           */
  unsigned int    allowerrornum;          /*
                                           * ¾Þ·Â¡õÃ«ÖÏòÛÒýÆ¥¸¤ÔÊ¾®
                                           */
  unsigned int    loghour;          		/*
                                           * ·òºëÃ«âçÐåÔÊÔÂÁÝ¶Ô  £¢ÁÝ  
                                           */
  unsigned int    battledebugmsg;    		/*
                                           * ÌïÐþ»ï  ¼°·¸ÌïÓÀºë¶ªÓÀ±¾¡õ³âÃ«ÇëÔÊ¾®£Û¨ßØ¦ÈÕÇë½ñØ¦ÖÐ
                                           */
  //ttom add this because the second had this                                         
  unsigned int    encodekey;              
  unsigned int    acwbsize;             
  unsigned int    acwritesize;
  unsigned int    ErrUserDownFlg;
  //ttom end
#ifdef _GMRELOAD
	char	gmsetfile[64];				/* GMÕÊºÅ¡¢È¨ÏÞÉè¶¨µµ */
#endif

#ifdef _PROFESSION_SKILL			// WON ADD ÈËÎïÖ°Òµ¼¼ÄÜ
	char profession[32];
#endif
#ifdef _ITEM_QUITPARTY
  char itemquitparty[32];
#endif

#ifdef _DEL_DROP_GOLD	
	unsigned int	Golddeletetime;
#endif
#ifdef _USER_EXP_CF
	char	expfile[64];
#endif
#ifdef _UNLAW_WARP_FLOOR
	char	unlawwarpfloor[512];
#endif
#ifdef _NO_JOIN_FLOOR
	char	nojoinfloor[512];
#endif
#ifdef _WATCH_FLOOR
	int	watchfloor[6];
#endif
#ifdef _BATTLE_FLOOR
	int	battlefloor;
	char battlefloorcf[512];
#endif
#ifdef _UNREG_NEMA
	char	unregname[5][16];
#endif
#ifdef _TRANS_LEVEL_CF
	int chartrans;
	int pettrans;
	int yblevel;
	int maxlevel;
#endif
#ifdef _PLAYERMAXPOINT
	int point;
	int transpoint[8];
#endif
#ifdef _PET_AND_ITEM_UP
	int petup;
	int itemup;
#endif
#ifdef _SKILLUPPOINT_CF
	int skup;
#endif
#ifdef _RIDELEVEL
	int ridelevel;
	int ridetrans;
#endif
#ifdef _REVLEVEL
	int revlevel;
#endif
#ifdef _FIX_CHARLOOPS
	int charloops;
#endif

#ifdef _PLAYER_MOVE
	int pmove;
#endif
	int recvbuffer;
	int sendbuffer;
	int recvlowatbuffer;
	int runlevel;

#ifdef _PLAYER_NUM
	int playernum;
#endif
#ifdef _BATTLE_GOLD
	int battlegold;
#endif
#ifdef _ANGEL_TIME
	int angelplayertime;
	int angelplayermun;
#endif
#ifdef _RIDEMODE_20
	int ridemode;
#endif
#ifdef _FM_POINT_PK
	int fmpointpk;
#endif
#ifdef _ENEMY_ACTION
	int	enemyact;
#endif
#ifdef _FUSIONBEIT_TRANS
	char	fusionbeittrans;
#endif
#ifdef _CHECK_PEPEAT
	int	CheckRepeat;
#endif
	int	cpuuse;
#ifdef _FM_JOINLIMIT
	int	joinfamilytime;
#endif
#ifdef _THE_WORLD_SEND
	int	thewordtrans;
	int	thewordlevel;
	int	thewordsend;
#endif
#ifdef _LOGIN_DISPLAY
	int	logindisplay;
#endif
#ifdef _VIP_POINT_PK
	char	vippointpk[256];
	int vippointpkcost;
#endif
#ifdef _AUTO_DEL_PET
	char autodelpet[256];
#endif
#ifdef _AUTO_DEL_ITEM
	char autodelitem[256];
#endif
#ifdef _UNLAW_THIS_LOGOUT
	char unlawthislogout[256];
#endif

#ifdef _TRANS_POINT_UP
	char transpointup[256];
#endif
#ifdef _NO_STW_ENEMY
	int nostwenemy;
	int nostwenemypoint;
#endif
#ifdef _ITEM_PET_LOCKED
	int itampetlocked;
#endif
#ifdef _PET_TRANS_ABILITY
	int	pettransability;
	int	pettransability1;
	int	pettransability2;
#endif
#ifdef _NEED_ITEM_ENEMY
	int delneeditem;
#endif
#ifdef _PLAYER_OVERLAP_PK
	char playeroverlappk[256];
#endif
#ifdef _FIMALY_PK_TIME
	int fimalypktime;
#endif
#ifdef _CANCEL_ANGLE_TRANS
	int cancelanlgetrans;
#endif
#ifdef _NO_HELP_MAP
	char nohelpmap[256];
#endif
#ifdef _BATTLE_TIME
	int battletime;
#endif
#ifdef _STREET_VENDOR_TRANS
	int streetvendortrans;
#endif
#ifdef _CHECK_SEVER_IP
	char serverip[256];
#endif
#ifdef	_PETUP_GET_EXP
	int petupgetexp;
#endif
	int Connectnum;
	int battlespeed;
#ifdef	_NO_ENEMYID_GROUP
	char noenemyidgroup[256];
#endif
#ifdef	_NEW_MAP_NO_FAME
	int nofamemap;
#endif
#ifdef	_TALK_AREA_CF
	int talkmin;
	int talkmax;
#endif
	char nosellpetid[512];
#ifdef	_BATTLE_RAND_DEX
	int battleranddex;
#endif
#ifdef _STREET_VENDOR_FAX
	char StreetFaxBuf[256];
	int StreetFax[10];
	char StreetEnableBuf[256];
	int StreetEnable[10];
	int StreetEnableTable[10];
#endif

#ifdef FAMLYNUM_CF
	int famlynum;
#endif

#ifdef _NB_ALLOW_FMPK
	char AllowFMPKMSG[256];
	int AllowFMPK[10];
	char FMPKNoMsg[128];
#endif

#ifdef _NB_CF_SHARE_EXP
	int expshare;
#endif
#ifdef _DAMMAGE_CALC
	int playdammagecalc;
	int petdammagecalc;
#endif
#ifdef _NB_SILENT_SWITCH
	int silentswitch;
#endif
#ifdef _NB_MAGICNOEXP
	int MagicNoExp1;
	int MagicNoExp2;
#endif
#ifdef _NB_DragonFunsionId
	int DragonFunsionRand;
	int DragonTrans;
	char DragonFunsionMsg[128];
	int DragonFunsionId[5];
#endif
}Config;

Config config;

#ifdef _USER_EXP_CF
int NeedLevelUpTbls[200];
#endif

typedef struct tagReadConf
{
    char    name[32];
    char  *charvalue;
    size_t  charsize;
    void*    value;
    CTYPE    valuetype;
}ReadConf;

ReadConf readconf[]=
{
	{ "debuglevel"      , NULL ,0 , (void*)&config.debuglevel      ,CHAR},

	{ "usememoryunit"   , NULL ,0 , (void*)&config.usememoryunit   ,INT},
	{ "usememoryunitnum", NULL ,0 , (void*)&config.usememoryunitnum,INT},

	{ "acserv",			config.asname,sizeof(config.asname) ,NULL , 0},
	{ "acservport",		NULL ,0 , (void*)&config.acservport     ,SHORT},
	{ "acpasswd",		config.acpasswd,sizeof( config.acpasswd),NULL,0},
	{ "gameservname",	config.gsnamefromas,sizeof(config.gsnamefromas),NULL,0},

    // Arminius 7.24 manor pk
	{ "gameservid", config.gsid, sizeof(config.gsid), NULL, 0}, 
	{ "gameservlistid", config.gslsid, sizeof(config.gslsid), NULL, 0}, 
	{ "allowmanorpk", NULL, 0, (void*)&config.allowmanorpk, SHORT},

	{ "port",			NULL ,0 , (void*)&config.port           ,SHORT},
	{ "servernumber",	NULL ,0 , (void*)&config.servernumber           ,INT},

	{ "reuseaddr",			NULL ,0 , (void*)&config.reuseaddr  ,		INT},
	{ "nodelay",			NULL , 0 , (void*)&config.do_nodelay ,		INT},
	{ "log_write_time", 	NULL, 0 , (void*)&config.log_write_time,	INT},
	{ "log_io_time", 		NULL, 0 , (void*)&config.log_io_time, 		INT},
	{ "log_game_time",		NULL, 0 , (void*)&config.log_game_time,		INT},
	{ "log_netloop_faster", NULL,0,(void*)&config.log_netloop_faster,	INT},
	{ "saacwritenum",		NULL,0,(void*)&config.saacwritenum, 		INT},
	{ "saacreadnum",		NULL,0,(void*)&config.saacreadnum, 			INT},
	{ "fdnum",				NULL ,0 , (void*)&config.fdnum,				SHORT},
	{ "charnum",				NULL ,0 , (void*)&config.charnum,				SHORT},
	{ "petnum",				NULL ,0 , (void*)&config.petcharnum,		INT},
	{ "othercharnum",		NULL ,0 , (void*)&config.othercharnum,		INT},

	{ "objnum",			NULL ,0 , (void*)&config.objnum,				INT},
	{ "itemnum",		NULL ,0 , (void*)&config.itemnum,				INT},
	{ "battlenum",		NULL ,0 , (void*)&config.battlenum,				INT},
#ifdef _GET_BATTLE_EXP
	{ "battleexp",		NULL ,0 , (void*)&config.battleexp,				INT},
#endif
	{ "topdir"          , config.topdir,sizeof(config.topdir),NULL,0},
	{ "mapdir"          , config.mapdir,sizeof(config.mapdir),NULL,0},
	{ "maptilefile"     , config.maptilefile,sizeof(config.maptilefile),NULL,0},
	{ "battlemapfile"   , config.battlemapfile,sizeof(config.battlemapfile),NULL,0},

#ifdef _ITEMSET6_TXT
	{ "itemset6file",	config.itemfile,	sizeof(config.invfile),	NULL,	0},
#else
#ifdef _ITEMSET5_TXT
	{ "itemset5file",	config.itemfile,	sizeof(config.invfile),	NULL,	0},
#else
#ifdef _ITEMSET4_TXT
	{ "itemset4file"  , config.itemfile,sizeof(config.invfile),NULL,0},
#else
#ifdef _ITEMSET3_ITEM
	{ "itemset3file"  , config.itemfile,sizeof(config.invfile),NULL,0},
#endif
#endif
#endif
#endif
  { "invinciblefile"  , config.invfile,sizeof(config.invfile),NULL,0},
  { "appearpositionfile"  , config.appearfile,sizeof(config.appearfile),NULL,0},
	{ "titlenamefile", config.titlenamefile, sizeof( config.titlenamefile),NULL,0},
	{ "titleconfigfile", config.titleconfigfile, sizeof( config.titleconfigfile),NULL,0},
	{ "encountfile", config.encountfile, sizeof( config.encountfile),NULL,0},
	{ "enemyfile", config.enemyfile, sizeof( config.enemyfile),NULL,0},
	{ "enemybasefile", config.enemybasefile, sizeof( config.enemybasefile),NULL,0},
	{ "groupfile", config.groupfile, sizeof( config.groupfile),NULL,0},
	{ "magicfile", config.magicfile, sizeof( config.magicfile),NULL,0},
#ifdef _ATTACK_MAGIC
	{ "attmagicfile" , config.attmagicfile , sizeof( config.attmagicfile )  , NULL , 0 },
#endif

#ifdef _PETSKILL2_TXT
	{ "petskillfile2", config.petskillfile, sizeof( config.petskillfile),NULL,0},
#else
	{ "petskillfile1", config.petskillfile, sizeof( config.petskillfile),NULL,0},
#endif

	{ "itematomfile" , config.itematomfile, sizeof( config.itematomfile),NULL,0},
	{ "effectfile"  , config.effectfile,sizeof(config.effectfile),NULL,0},
	{ "quizfile"  , config.quizfile,sizeof(config.quizfile),NULL,0},

	{ "lsgenlogfilename", config.lsgenlog,sizeof(config.lsgenlog),NULL,0},
#ifdef _GMRELOAD
	{ "gmsetfile", config.gmsetfile, sizeof( config.gmsetfile),NULL,0},
#endif

	{ "storedir"        ,config.storedir,sizeof(config.storedir),NULL,0},
	{ "npcdir"          ,config.npcdir,sizeof(config.npcdir),NULL,0},
	{ "logdir"          ,config.logdir,sizeof(config.logdir),NULL,0},
	{ "logconfname"     ,config.logconfname,sizeof(config.logconfname),NULL,0},
	{ "chatmagicpasswd", config.chatmagicpasswd, sizeof( config.chatmagicpasswd),NULL,0},
#ifdef _STORECHAR
	{ "storechar", config.storechar, sizeof( config.storechar),NULL,0},
#endif
	{ "chatmagiccdkeycheck",  NULL,0, &config.chatmagiccdkeycheck,INT},
	{ "filesearchnum",  NULL,0, &config.filesearchnum,INT},
	{ "npctemplatenum",  NULL,0, &config.npctemplatenum,INT},
	{ "npccreatenum",    NULL,0, &config.npccreatenum,INT},
	{ "walkinterval" ,NULL,0,(void*)&config.walksendinterval,INT},
	{ "CAinterval" ,NULL,0,(void*)&config.CAsendinterval_ms,INT},
	{ "CDinterval" ,NULL,0,(void*)&config.CDsendinterval_ms,INT},
	{ "CharSaveinterval" ,NULL,0,(void*)&config.CharSavesendinterval,INT},
	{ "Onelooptime" ,NULL,0,(void*)&config.Onelooptime_ms,INT},
	{ "Petdeletetime" ,NULL,0,(void*)&config.Petdeletetime,INT},
	{ "Itemdeletetime" ,NULL,0,(void*)&config.Itemdeletetime,INT},
	{ "Functionfile" ,NULL,0,(void*)&config.Functionfile,INT},
	{ "addressbookoffmesgnum" ,NULL,0,(void*)&config.addressbookoffmsgnum,INT},
	{ "protocolreadfrequency" ,NULL,0,(void*)&config.protocolreadfrequency,INT},

	{ "allowerrornum" ,NULL,0,(void*)&config.allowerrornum,INT},
	{ "loghour" ,NULL,0,(void*)&config.loghour,INT},
	{ "battledebugmsg" ,NULL,0,(void*)&config.battledebugmsg,INT},
   //ttom add because the second had
	{ "encodekey" ,NULL,0,(void*)&config.encodekey,INT},
	{ "acwritesize" ,NULL,0,(void*)&config.acwritesize,INT},
	{ "acwbsize" ,NULL,0,(void*)&config.acwbsize,INT},
	{ "erruser_down" ,NULL,0,(void*)&config.ErrUserDownFlg,INT},    

#ifdef _PROFESSION_SKILL			// WON ADD ÈËÎïÖ°Òµ¼¼ÄÜ
	{ "profession",		config.profession, sizeof(config.profession) ,NULL , 0},
#endif

#ifdef _ITEM_QUITPARTY
	{ "itemquitparty",	config.itemquitparty, sizeof(config.itemquitparty) ,NULL , 0},
#endif

#ifdef _DEL_DROP_GOLD
	{ "Golddeletetime" ,NULL,0,(void*)&config.Golddeletetime,	INT},
#endif

#ifdef _USER_EXP_CF
	{ "USEREXP", config.expfile, sizeof( config.expfile),NULL,0},
#endif

#ifdef _UNLAW_WARP_FLOOR
	{ "UNLAWWARPFLOOR" ,config.unlawwarpfloor, sizeof( config.unlawwarpfloor),NULL,0},
#endif

#ifdef _NO_JOIN_FLOOR
	{ "NOJOINFLOOR" ,config.nojoinfloor, sizeof( config.nojoinfloor),NULL,0},
#endif

#ifdef _WATCH_FLOOR
	{ "WATCHFLOOR" ,NULL,0,(void*)&config.watchfloor[0],	INT},
	{ "WATCHFLOOR1" ,NULL,0,(void*)&config.watchfloor[1],	INT},
	{ "WATCHFLOOR2" ,NULL,0,(void*)&config.watchfloor[2],	INT},	
	{ "WATCHFLOOR3" ,NULL,0,(void*)&config.watchfloor[3],	INT},	
	{ "WATCHFLOOR4" ,NULL,0,(void*)&config.watchfloor[4],	INT},	
	{ "WATCHFLOOR5" ,NULL,0,(void*)&config.watchfloor[5],	INT},
#endif

#ifdef _BATTLE_FLOOR
	{ "BATTLEFLOOR" ,NULL,0,(void*)&config.battlefloor,	INT},
	{ "BATTLEFLOORCF" ,config.battlefloorcf, sizeof( config.battlefloorcf),NULL,0},
#endif

#ifdef _UNREG_NEMA
	{ "NAME1" ,config.unregname[0], sizeof( config.unregname[0]),NULL,0},
	{ "NAME2" ,config.unregname[1], sizeof( config.unregname[1]),NULL,0},
	{ "NAME3" ,config.unregname[2], sizeof( config.unregname[2]),NULL,0},
	{ "NAME4" ,config.unregname[3], sizeof( config.unregname[3]),NULL,0},
	{ "NAME5" ,config.unregname[4], sizeof( config.unregname[4]),NULL,0},
#endif
#ifdef _TRANS_LEVEL_CF
	{ "CHARTRANS" ,NULL,0,(void*)&config.chartrans,	INT},
	{ "PETTRANS" ,NULL,0,(void*)&config.pettrans,	INT},	
	{ "LEVEL" ,NULL,0,(void*)&config.yblevel,	INT},	
	{ "MAXLEVEL" ,NULL,0,(void*)&config.maxlevel,	INT},	
#endif
#ifdef _PLAYERMAXPOINT
	{ "POINT" ,NULL,0,(void*)&config.point,	INT},
	{ "TRANS0" ,NULL,0,(void*)&config.transpoint[0],	INT},	
	{ "TRANS1" ,NULL,0,(void*)&config.transpoint[1],	INT},	
	{ "TRANS2" ,NULL,0,(void*)&config.transpoint[2],	INT},	
	{ "TRANS3" ,NULL,0,(void*)&config.transpoint[3],	INT},	
	{ "TRANS4" ,NULL,0,(void*)&config.transpoint[4],	INT},	
	{ "TRANS5" ,NULL,0,(void*)&config.transpoint[5],	INT},	
	{ "TRANS6" ,NULL,0,(void*)&config.transpoint[6],	INT},	
	{ "TRANS7" ,NULL,0,(void*)&config.transpoint[7],	INT},	
#endif

#ifdef _PET_AND_ITEM_UP
	{ "PETUP" ,NULL,0,(void*)&config.petup,	INT},
	{ "ITEMUP" ,NULL,0,(void*)&config.itemup,	INT},
#endif
#ifdef _SKILLUPPOINT_CF
	{ "SKILLUPPOINT" ,NULL,0,(void*)&config.skup,	INT},	
#endif
#ifdef _RIDELEVEL
	{ "RIDELEVEL" ,NULL,0,(void*)&config.ridelevel,	INT},	
	{ "RIDETRANS" ,NULL,0,(void*)&config.ridetrans,	INT},	
#endif

#ifdef _REVLEVEL
	{ "REVLEVEL" ,NULL,0,(void*)&config.revlevel,	INT},	
#endif

#ifdef _FIX_CHARLOOPS
	{ "CHARLOOPS" ,NULL,0,(void*)&config.charloops,	INT},	
#endif

#ifdef _PLAYER_MOVE
	{ "PMOVE" ,NULL,0,(void*)&config.pmove,	INT},
#endif

	{ "recvbuffer" ,NULL,0,(void*)&config.recvbuffer,	INT},
	{ "sendbuffer" ,NULL,0,(void*)&config.sendbuffer,	INT},
	{ "recvlowatbuffer" ,NULL,0,(void*)&config.recvlowatbuffer,	INT},
	{ "runlevel" ,NULL,0,(void*)&config.runlevel,	INT},
	
#ifdef _PLAYER_NUM
	{ "PLAYERNUM" ,NULL,0,(void*)&config.playernum,	INT},
#endif

#ifdef _BATTLE_GOLD
	{ "BATTLEGOLD" ,NULL,0,(void*)&config.battlegold,	INT},
#endif
#ifdef _ANGEL_TIME
	{ "ANGELPLAYERTIME" ,NULL,0,(void*)&config.angelplayertime,	INT},
	{ "ANGELPLAYERMUN" ,NULL,0,(void*)&config.angelplayermun,	INT},
#endif
#ifdef _RIDEMODE_20
	{ "RIDEMODE" ,NULL,0,(void*)&config.ridemode,	INT},
#endif
#ifdef _FM_POINT_PK
	{ "FMPOINTPK" ,NULL,0,(void*)&config.fmpointpk,	INT},
#endif
#ifdef _ENEMY_ACTION
	{ "ENEMYACTION" ,NULL,0,(void*)&config.enemyact,	INT},
#endif
#ifdef _FUSIONBEIT_TRANS
	{ "FUSIONBEIT" ,NULL,0,(void*)&config.fusionbeittrans,	INT},
#endif
#ifdef _CHECK_PEPEAT
	{ "CHECKPEPEAT" ,NULL,0,(void*)&config.CheckRepeat,	INT},
#endif
	{ "CPUUSE" ,NULL,0,(void*)&config.cpuuse,	INT},
#ifdef _FM_JOINLIMIT
	{ "JOINFAMILYTIME" ,NULL,0,(void*)&config.joinfamilytime,	INT},
#endif
#ifdef _MAP_HEALERALLHEAL
	{ "MAPHEAL" ,config.mapheal, sizeof( config.mapheal),NULL,0},
#endif

#ifdef _THE_WORLD_SEND
	{ "THEWORLDTRANS" ,NULL,0,(void*)&config.thewordtrans,	INT},
	{ "THEWORLDLEVEL" ,NULL,0,(void*)&config.thewordlevel,	INT},
	{ "THEWORLDSNED" ,NULL,0,(void*)&config.thewordsend,	INT},
#endif
#ifdef _LOGIN_DISPLAY
	{ "LOGINDISPLAY" ,NULL,0,(void*)&config.logindisplay,	INT},
#endif
#ifdef _VIP_POINT_PK
	{ "PKMAP" ,config.vippointpk, sizeof( config.vippointpk),NULL,0},
	{ "PKMAPCOST" ,NULL,0,(void*)&config.vippointpkcost,	INT},
#endif
#ifdef _AUTO_DEL_PET
	{ "AUTODELPET" ,config.autodelpet, sizeof( config.autodelpet),NULL,0},
#endif
#ifdef _AUTO_DEL_ITEM
	{ "AUTODELITEM" ,config.autodelitem, sizeof( config.autodelitem),NULL,0},
#endif
#ifdef _UNLAW_THIS_LOGOUT
	{ "UNLAWTHISLOGOUT" ,config.unlawthislogout, sizeof( config.unlawthislogout),NULL,0},
#endif
#ifdef _TRANS_POINT_UP
	{ "TRANSPOINTUP" ,config.transpointup, sizeof( config.transpointup),NULL,0},
#endif
#ifdef _NO_STW_ENEMY
	{ "NOSTWENEMY" ,NULL,0,(void*)&config.nostwenemy,	INT},
	{ "NOSTWENEMYGOLD" ,NULL,0,(void*)&config.nostwenemypoint,	INT},
#endif
#ifdef _ITEM_PET_LOCKED
	{ "ITEMPETLOCKED" ,NULL,0,(void*)&config.itampetlocked,	INT},
#endif
#ifdef _PET_TRANS_ABILITY
	{ "PETTRANSABILITY" ,NULL,0,(void*)&config.pettransability,	INT},
	{ "PETTRANSABILITY1" ,NULL,0,(void*)&config.pettransability1,	INT},
	{ "PETTRANSABILITY2" ,NULL,0,(void*)&config.pettransability2,	INT},
#endif
#ifdef _NEED_ITEM_ENEMY
	{ "DELNEEDITEM" ,NULL,0,(void*)&config.delneeditem,	INT},
#endif
#ifdef _PLAYER_OVERLAP_PK
	{ "PLAYEROVERLAPPK" ,config.playeroverlappk, sizeof( config.playeroverlappk),NULL,0},
#endif
#ifdef _FIMALY_PK_TIME
	{ "FIMALYPKTIME" ,NULL,0,(void*)&config.fimalypktime,	INT},
#endif

#ifdef _CANCEL_ANGLE_TRANS
	{ "CANCELANGLETRANS" ,NULL,0,(void*)&config.cancelanlgetrans,	INT},
#endif
#ifdef _NO_HELP_MAP
	{ "nohelpmap" ,config.nohelpmap, sizeof( config.nohelpmap),NULL,0},
#endif
#ifdef _BATTLE_TIME
	{ "battletime" ,NULL,0,(void*)&config.battletime,	INT},
#endif
#ifdef _STREET_VENDOR_TRANS
	{ "streetvendortrans" ,NULL,0,(void*)&config.streetvendortrans,	INT},
#endif
#ifdef _CHECK_SEVER_IP
	{ "serverip" ,config.serverip, sizeof( config.serverip),NULL,0},
#endif

#ifdef	_PETUP_GET_EXP
	{ "PETUPGETEXP" ,NULL,0,(void*)&config.petupgetexp,	INT},
#endif
	{ "Connectnum" ,NULL,0,(void*)&config.Connectnum,	INT},
	{ "BATTLESPEED" ,NULL,0,(void*)&config.battlespeed,	INT},
#ifdef	_NO_ENEMYID_GROUP
	{ "NOENEMYIDGROUP" ,config.noenemyidgroup, sizeof( config.noenemyidgroup),NULL,0},
#endif
#ifdef	_NEW_MAP_NO_FAME
	{ "NOFAMEMAP" ,NULL,0,(void*)&config.nofamemap,	INT},
#endif
#ifdef	_TALK_AREA_CF
	{ "TALKMIN" ,NULL,0,(void*)&config.talkmin,	INT},
	{ "TALKMAX" ,NULL,0,(void*)&config.talkmax,	INT},
#endif

	{ "NOSELLPETID" ,config.nosellpetid, sizeof( config.nosellpetid),NULL,0},
#ifdef	_BATTLE_RAND_DEX
	{ "BATTLERANDDEX" ,NULL,0,(void*)&config.battleranddex,	INT},
#endif
#ifdef _STREET_VENDOR_FAX
	{ "STREETFAX"  , config.StreetFaxBuf,sizeof(config.StreetFaxBuf),NULL,0},	
	{ "STREETENABLE"  , config.StreetEnableBuf,sizeof(config.StreetEnableBuf),NULL,0},	
#endif
#ifdef FAMLYNUM_CF
	{ "FAMLYNUM" ,NULL,0,(void*)&config.famlynum,INT},
#endif
#ifdef _NB_ALLOW_FMPK
	{ "AllowFMPK"  , config.AllowFMPKMSG,sizeof(config.AllowFMPKMSG),NULL,0},
	{ "FMPKNoMsg"  , config.FMPKNoMsg,sizeof(config.FMPKNoMsg),NULL,0},
#endif
#ifdef _NB_CF_SHARE_EXP
		{ "EXPSHARE",NULL,0,(void*)&config.expshare,INT},
#endif
#ifdef _DAMMAGE_CALC
	{ "playdammagecalc" ,NULL,0,(void*)&config.playdammagecalc,	INT},
	{ "petdammagecalc" ,NULL,0,(void*)&config.petdammagecalc,	INT},
#endif
#ifdef _NB_SILENT_SWITCH
	{ "SILENTSWITCH" ,NULL,0,(void*)&config.silentswitch,INT},
#endif
#ifdef _NB_MAGICNOEXP
	{ "MAGICNOEXP1" ,NULL,0,(void*)&config.MagicNoExp1,INT},
	{ "MAGICNOEXP2" ,NULL,0,(void*)&config.MagicNoExp2,INT},
#endif
#ifdef _NB_DragonFunsionId
	{ "DragonFunsionRand" ,NULL,0,(void*)&config.DragonFunsionRand,INT},
	{ "DragonTrans" ,NULL,0,(void*)&config.DragonTrans,INT},
	{ "DragonFunsionId"  , config.DragonFunsionMsg,sizeof(config.DragonFunsionMsg),NULL,0},
#endif
};

// Arminius 7.12 login announce
char announcetext[8192];
void AnnounceToPlayer(int charaindex)
{
  char *ptr,*qtr;
  
  ptr=announcetext;
  while ((qtr=strstr(ptr,"\n"))!=NULL) {
    qtr[0]='\0';
//    printf("ptr=%s\n",ptr);
    CHAR_talkToCli(charaindex, -1, ptr, CHAR_COLORYELLOW);
    qtr[0]='\n';
    ptr=qtr+1;
  }
  CHAR_talkToCli(charaindex, -1, ptr, CHAR_COLORYELLOW);
  
}

// Robin 0720
void AnnounceToPlayerWN(int fd)
{
	char buf[8192];
#ifdef _LOGOUTTIME
	char token[8192];
	int charaindex = CONNECT_getCharaindex( fd );
	long lastleavetime = CHAR_getInt( charaindex , CHAR_LASTLEAVETIME);
	struct tm *p;
	p=localtime(&lastleavetime);
	sprintf( token , "·¹º§¾÷! %d³â%d¿ù%dÀÏ %d:%d:%d\n\n%s",p->tm_year + 1900,
																																		p->tm_mon + 1,
																																		p->tm_mday,
																																		p->tm_hour,
																																		p->tm_min,
																																		p->tm_sec,
																																		announcetext);
	lssproto_WN_send( fd , WINDOW_MESSAGETYPE_LOGINMESSAGE,WINDOW_BUTTONTYPE_OK,-1,-1,makeEscapeString( token, buf, sizeof(buf)));
#else	
	lssproto_WN_send( fd , WINDOW_MESSAGETYPE_LOGINMESSAGE,WINDOW_BUTTONTYPE_OK,-1,-1,makeEscapeString( announcetext, buf, sizeof(buf)));
#endif
}


void LoadAnnounce(void)
{
    FILE *f;
    memset(announcetext, 0, sizeof(announcetext));
    if ((f=fopen("./announce.txt","r"))!=NULL) {
      fread(announcetext, sizeof(announcetext), 1, f);
      announcetext[sizeof(announcetext)-1]='\0';
      fclose(f);
    }
}
#ifdef _PET_TALKPRO
PTALK pettalktext[PETTALK_MAXID];

void LoadPetTalk(void)
{
	FILE *fp;
	char fn[256];
	char line[ 4096];
	char talkmem[4096];
	int maxid=0;
	char buf1[256], buf2[256], buf3[256];
	int talkNO=-1, mark=-1, i;
	int len = sizeof( talkmem);
	
	memset(talkmem, 0, sizeof(talkmem));
	sprintf(fn, "%s/pettalk/pettalk.menu", getNpcdir());

	for( i=0;i<PETTALK_MAXID;i++)	{
		pettalktext[i].ID = -1;
		strcpy( pettalktext[i].DATA, "\0");
	}

	print("\nÆê ´ëÈ­ ÆÄÀÏ ·Îµå:%s...", fn);
{
	fp = fopen( fn, "r");
}
    if( fp != NULL ) {
		while( fgets( line, sizeof( line), fp)) {
			if( strlen( talkmem) != 0 ) {
				if( talkmem[strlen( talkmem) -1] != '|' ) {
					strcatsafe( talkmem, len, "|");		
				}
			}
			chompex( line);
			strcatsafe( talkmem,len,  line);
		}
		fclose( fp);
    }else	{
		print("¿À·ù: ÆÄÀÏÀ» Ã£À» ¼ö ¾ø½À´Ï´Ù!");
	}

	talkNO=1;
	while( getStringFromIndexWithDelim( talkmem,"END",talkNO, buf1, sizeof( buf1)) != FALSE	){
		talkNO++;
		if( NPC_Util_GetStrFromStrWithDelim( buf1, "PETTEMPNO", buf2, sizeof( buf2)) == NULL  )
			continue;
		mark=1;
		strcpy( fn,"\0");

		if( getStringFromIndexWithDelim( buf2,",", mark+1,buf3,sizeof( buf3)) != FALSE )	{
			pettalktext[maxid].ID = atoi( buf3);
			if( getStringFromIndexWithDelim( buf2,",", mark,buf3,sizeof( buf3)) != FALSE )	{
				sprintf(fn, "%s/pettalk/%s", getNpcdir(), buf3);
				//print("\n ...file:%s", fn);
{
				fp = fopen( fn, "r");
}
				if( fp != NULL )	{
					char line[4096];
					while( fgets( line, sizeof( line), fp ) ) {
						if( strlen( pettalktext[maxid].DATA) != 0 ) {
							if( pettalktext[maxid].DATA[strlen( pettalktext[maxid].DATA) -1] != '|' ) {
								strcatsafe( pettalktext[maxid].DATA, sizeof( pettalktext[maxid].DATA), "|");
							}
						}
						chompex( line);
						strcatsafe( pettalktext[maxid].DATA, sizeof( pettalktext[maxid].DATA), line);
					}
					maxid++;
					fclose( fp);
				}else	{
					print("¿À·ù: [%s] À»(¸¦) Ã£À» ¼ö ¾ø½À´Ï´Ù!", fn);
					pettalktext[maxid].ID=-1;
				}
			}else	{
				pettalktext[maxid].ID=-1;
			}
		}
		print(".");
		if( maxid >= PETTALK_MAXID )
			break;
	}
	print("ÃÖ´ëID=%d...", maxid);
	{
		int haveid=0;
		for( i=0;i<PETTALK_MAXID;i++)	{
			if( pettalktext[i].ID >= 0 )	{
				haveid++;
			}
		}
		print("·Îµå ÃÑ¼ö=%d", haveid);
	}

}

#else
char pettalktext[4096];
void LoadPetTalk(void)
{
  FILE *fp;
  char fn[256];
  char	line[ 4096];
  int len = sizeof( pettalktext);
  
  memset(pettalktext, 0, sizeof(pettalktext));
  sprintf(fn, "%s/pettalk/pettalk.mem", getNpcdir());
{
  fp = fopen( fn, "r");
}
    if( fp != NULL ) {
		print("\n\n pettalk.mem ÀÐ´Â Áß");
		while( fgets( line, sizeof( line), fp)) {
			if( strlen( pettalktext) != 0 ) {
				if( pettalktext[strlen( pettalktext) -1] != '|' ) {
					strcatsafe( pettalktext, len, "|");		
				}
			}
			chompex( line);
			strcatsafe( pettalktext,len,  line);
		}
		fclose( fp);
		print("\n %s", pettalktext);
    }else	{
		print("\n pettalk.mem Ã£À» ¼ö ¾øÀ½");
	}
}
#endif

#ifdef _GAMBLE_BANK
GAMBLEBANK_ITEMS GB_ITEMS[GAMBLEBANK_ITEMSMAX];

void Load_GambleBankItems( void)
{

	FILE *fp;
	char filename[256];
	char buf1[256];
	char name[128];
	int num,ID,type;
	int i=0;
	sprintf(filename, "./data/gambleitems.txt" );
	print("\nµµ¹Ú ¾ÆÀÌÅÛ ÆÄÀÏ %s ·Îµå Áß...", filename);
{
	fp = fopen( filename, "r");
}
    if( fp != NULL ) {
		while( fgets( buf1, sizeof( buf1), fp) != NULL )	{
			if( strstr( buf1, "#") != 0 ) continue;
			sscanf( buf1,"%s %d %d %d", name, &ID, &num , &type);
			strcpy( GB_ITEMS[i].name, name);
			GB_ITEMS[i].Gnum = num;
			GB_ITEMS[i].ItemId = ID;
			GB_ITEMS[i].type = type;
			i++;
		}
		print("ÃÖ´ëID: %d ", i);
		fclose( fp);
    }else	{
		print("¿À·ù: ÆÄÀÏ %s À»(¸¦) Ã£À» ¼ö ¾øÀ½", filename);
	}

}
#endif


#ifdef _CFREE_petskill
PETSKILL_CODES Code_skill[PETSKILL_CODE];
void Load_PetSkillCodes( void)
{
	FILE *fp;
	char filename[256];
	char buf1[256];
	char name[128];
	char type[256];
	int num,ID;
	int i=0;
	sprintf(filename, "./data/skillcode.txt" );
	print("\nÆê ½ºÅ³ ÄÚµå ÆÄÀÏ ·Îµå:%s...", filename);
{
	fp = fopen( filename, "r");
}
    if( fp != NULL ) {
		while( fgets( buf1, sizeof( buf1), fp) != NULL )	{
			sscanf( buf1,"%s %d %d %s", name, &num, &ID, type);
			strcpy( Code_skill[i].name, name);
			Code_skill[i].TempNo = num;
			Code_skill[i].PetId = ID;
			strcpy( Code_skill[i].Code, type);
			//print("\n %s|%d|%d|%s|", Code_skill[i].name, Code_skill[i].TempNo, 
			//	Code_skill[i].PetId, Code_skill[i].Code);
			i++;
			if( i >= PETSKILL_CODE ) break;
		}
		fclose( fp);
    }else	{
		print("ÆÄÀÏ %s À»(¸¦) Ã£À» ¼ö ¾øÀ½", filename);
	}
	print("¿Ï·á\n");
}
#endif

#ifdef _GMRELOAD
BOOL LoadGMSet( char* filename )
{
	FILE* fp;
	int i = 0, gm_num = 0;
  fp = fopen(filename,"r");
	if (fp == NULL){
		print("ÆÄÀÏÀ» ¿­ ¼ö ¾ø½À´Ï´Ù\n");
		return FALSE;
	}
	for (i = 0; i < GMMAXNUM; i++){
		strcpy(gminfo[i].cdkey, "");
		gminfo[i].level = 0;
	}
	while(1){
		char	line[1024], cdkey[64], level[64];
		if (fgets(line, sizeof(line), fp) == NULL)	break;
		chop(line);
		if( line[0] == '#' )
			continue;
		for( i=0; i<strlen(line); i++ ){
			if( line[i] == '#' ){
				line[i] = '\0';
				break;
			}
		}
		//*************************************
		gm_num = gm_num + 1;
		if (gm_num > GMMAXNUM)	break;
		easyGetTokenFromString(line, 1, cdkey, sizeof(cdkey));
		if (strcmp(cdkey, "") == 0)	break;
		strncpy(gminfo[gm_num].cdkey, cdkey, sizeof(gminfo[gm_num].cdkey));
		easyGetTokenFromString(line, 2, level, sizeof(level));
		if (strcmp(level, "") == 0)	break;
		gminfo[gm_num].level = atoi(level);
	}
	fclose(fp);
	return TRUE;
}
#endif

/*------------------------------------------------------------
 * Ãó·òºë·ÂØ©  Ã«  ÔÂ
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  cahr*
 ------------------------------------------------------------*/
char* getProgname( void )
{
    return config.progname;
}
/*------------------------------------------------------------
 * configfilename Ã«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  char*
 ------------------------------------------------------------*/
char* getConfigfilename( void )
{
    return config.configfilename;
}
/*------------------------------------------------------------
 * configfilename Ã«É¬ÀÃÔÊÔÂ£Û
 * Â¦ÐÑ
 *  newv    char*   Þ¥ØÆÖÐ°À
 * ß¯Ô»°À
 *  Ø¦ØÆ
 ------------------------------------------------------------*/
void setConfigfilename( char* newv )
{
    strcpysafe( config.configfilename, sizeof( config.configfilename ),
                newv );
}

/*------------------------------------------------------------
 * ·¸ÌïÓÀºëÒÁÃ¬»ïÃ«  ÔÂ
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned int
 ------------------------------------------------------------*/
unsigned int getDebuglevel( void )
{
    return config.debuglevel;
}
/*------------------------------------------------------------
 * ·¸ÌïÓÀºëÒÁÃ¬»ïÃ«É¬ÀÃÔÊÔÂ
 * Â¦ÐÑ
 *  newv    int     Þ¥ØÆÖÐ°À
 * ß¯Ô»°À
 *  unsigned int    éÉ¼°°À
 ------------------------------------------------------------*/
unsigned int setDebuglevel( unsigned int newv )
{
    int old;
    old = config.debuglevel;
    config.debuglevel = newv;
    return old;
}
/*------------------------------------------------------------
 * memoryunit Ã«  ÔÂ
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned int
 ------------------------------------------------------------*/
unsigned int getMemoryunit( void )
{
    return config.usememoryunit;
}
/*------------------------------------------------------------
 * memoryunitnum Ã«  ÔÂ
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned int
 ------------------------------------------------------------*/
unsigned int getMemoryunitnum( void )
{
    return config.usememoryunitnum;
}

/*------------------------------------------------------------
 * Ê§ÊÐËü¼þÐþÈÓ¡õÌï¼°Ê§ÓñÒÁµ©Ã«  ÔÂ
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  char*
 ------------------------------------------------------------*/
char*   getAccountservername( void )
{
    return config.asname;
}
/*------------------------------------------------------------
 * Ê§ÊÐËü¼þÐþÈÓ¡õÌï¼°ºÌ¡õÐþÃ«  ÔÂ
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned short
 ------------------------------------------------------------*/
unsigned short   getAccountserverport( void )
{
    return config.acservport;
}
/*------------------------------------------------------------
 * Ê§ÊÐËü¼þÐþÈÓ¡õÌï³ß¼°ÓÉµ©·¥¡õÓñÃ«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned short
 ------------------------------------------------------------*/
char*   getAccountserverpasswd( void )
{
  return config.acpasswd;
}
/*------------------------------------------------------------
 * Ê§ÊÐËü¼þÐþÈÓ¡õÌï¾®ÈÕÎ­ÒüÔÂ±Ø¡õØ©ÈÓ¡õÌïÎçØÆ»¯¼°  ó¡Ã«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned short
 ------------------------------------------------------------*/
char*   getGameservername( void )
{
    return config.gsnamefromas;
}

// Arminius 7.24 manor pk
char* getGameserverID( void )
{
    if (config.gsid[strlen(config.gsid)-1]=='\n')
      config.gsid[strlen(config.gsid)-1]='\0';
      
    return config.gsid;
}

char* getGameserverListID( void )
{
    if (config.gslsid[strlen(config.gslsid)-1]=='\n')
      config.gslsid[strlen(config.gslsid)-1]='\0';
      
    return config.gslsid;
}

unsigned short getAllowManorPK( void )
{
    return config.allowmanorpk;
}

unsigned short getPortnumber( void )
{
    return config.port;
}
/*------------------------------------------------------------
 * ±Ø¡õØ©ÈÓ¡õÌï¼°  Ä¯   Ä¯Ã«  ÔÂ
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned short
 ------------------------------------------------------------*/
int getServernumber( void )
{
    return config.servernumber;
}
/*------------------------------------------------------------
 * reuseaddr ¼°°ÀÃ«  ÔÂ
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned short
 ------------------------------------------------------------*/
int getReuseaddr( void )
{
    return config.reuseaddr;
}

int getNodelay( void )
{
    return config.do_nodelay;
}
int getLogWriteTime(void)
{
    return config.log_write_time;
}
int getLogIOTime( void)
{
    return config.log_io_time;
}
int getLogGameTime(void)
{
    return config.log_game_time;
}
int getLogNetloopFaster(void)
{
    return config.log_netloop_faster;
}

/*------------------------------------------------------------
 * saacwritenum Ã«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *   int
 ------------------------------------------------------------*/
int getSaacwritenum( void )
{
    return config.saacwritenum;
}
/*------------------------------------------------------------
 * saacwritenum Ã«É¬ÀÃÔÊÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *   int
 ------------------------------------------------------------*/
void setSaacwritenum( int num )
{
    config.saacwritenum = num;
}
/*------------------------------------------------------------
 * saacreadnum Ã«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *   int
 ------------------------------------------------------------*/
int getSaacreadnum( void )
{
    return config.saacreadnum;
}
/*------------------------------------------------------------
 * saacreadnum Ã«É¬ÀÃÔÊÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *   int
 ------------------------------------------------------------*/
void setSaacreadnum( int num )
{
    config.saacreadnum = num;
}
/*------------------------------------------------------------
 * fdnum Ã«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned int
 ------------------------------------------------------------*/

unsigned int getFdnum( void )
{
	return config.fdnum;
}

unsigned int getPlayercharnum( void )
{
    return config.charnum;
}

/*------------------------------------------------------------
 * petcharanum Ã«  ÔÂ
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned int
 ------------------------------------------------------------*/
unsigned int getPetcharnum( void )
{
    return config.petcharnum;
}


/*------------------------------------------------------------
 * othercharnum Ã«  ÔÂ
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned int
 ------------------------------------------------------------*/
unsigned int getOtherscharnum( void )
{
    return config.othercharnum;
}

/*------------------------------------------------------------
 * objnum Ã«  ÔÂ
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned int
 ------------------------------------------------------------*/
unsigned int getObjnum( void )
{
    return config.objnum;
}

/*------------------------------------------------------------
 * itemnum Ã«  ÔÂ
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned int
 ------------------------------------------------------------*/
unsigned int getItemnum( void )
{
    return config.itemnum;
}


/*------------------------------------------------------------
 * battlenum Ã«  ÔÂ
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned int
 ------------------------------------------------------------*/
unsigned int getBattlenum( void )
{
    return config.battlenum;
}

#ifdef _GET_BATTLE_EXP
unsigned int getBattleexp( void )
{
    return config.battleexp;
}
#endif
/*------------------------------------------------------------
 * topdir Ã«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  char*
 ------------------------------------------------------------*/
char* getTopdir( void )
{
    return config.topdir;
}
/*------------------------------------------------------------
 * mapdir Ã«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  char*
 ------------------------------------------------------------*/
char* getMapdir( void )
{
    return config.mapdir;
}
/*------------------------------------------------------------
 * maptilefile Ã«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  char*
 ------------------------------------------------------------*/
char* getMaptilefile( void )
{
    return config.maptilefile;
}
/*------------------------------------------------------------
 * battlemapfile Ã«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  char*
 ------------------------------------------------------------*/
char* getBattleMapfile( void )
{
    return config.battlemapfile;
}
/*------------------------------------------------------------
 * itemfile Ã«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  char*
 ------------------------------------------------------------*/
char* getItemfile( void )
{
    return config.itemfile;
}
/*------------------------------------------------------------
 * invfile Ã«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  char*
 ------------------------------------------------------------*/
char* getInvfile( void )
{
    return config.invfile;
}
/*------------------------------------------------------------
 * appearfile Ã«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  char*
 ------------------------------------------------------------*/
char* getAppearfile( void )
{
    return config.appearfile;
}
/*------------------------------------------------------------
 * effectfile Ã«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  char*
 ------------------------------------------------------------*/
char* getEffectfile( void )
{
    return config.effectfile;
}
/*------------------------------------------------------------
 * titlenamefile Ã«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  char*
 ------------------------------------------------------------*/
char* getTitleNamefile( void )
{
    return config.titlenamefile;
}
/*------------------------------------------------------------
 * titleconfigfile Ã«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  char*
 ------------------------------------------------------------*/
char* getTitleConfigfile( void )
{
    return config.titleconfigfile;
}
/*------------------------------------------------------------
 * encountfile Ã«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  char*
 ------------------------------------------------------------*/
char* getEncountfile( void )
{
    return config.encountfile;
}
/*------------------------------------------------------------
 * enemyfile Ã«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  char*
 ------------------------------------------------------------*/
char* getEnemyfile( void )
{
    return config.enemyfile;
}
/*------------------------------------------------------------
 * enemybasefile Ã«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  char*
 ------------------------------------------------------------*/
char* getEnemyBasefile( void )
{
    return config.enemybasefile;
}
/*------------------------------------------------------------
 * groupfile Ã«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  char*
 ------------------------------------------------------------*/
char* getGroupfile( void )
{
    return config.groupfile;
}
/*------------------------------------------------------------
 * magicfile Ã«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  char*
 ------------------------------------------------------------*/
char* getMagicfile( void )
{
    return config.magicfile;
}

#ifdef _ATTACK_MAGIC

/*------------------------------------------------------------
 * È¡µÃ¹¥»÷ÐÔµÄÖäÊõ
 * ²ÎÊý
 * None
 * ·µ»ØÖµ
 * char*
 ------------------------------------------------------------*/
char* getAttMagicfileName( void )
{
    return config.attmagicfile;
}

#endif


char* getPetskillfile( void )
{
    return config.petskillfile;
}

#ifdef _PROFESSION_SKILL			// WON ADD ÈËÎïÖ°Òµ¼¼ÄÜ
char* getProfession( void )
{
    return config.profession;
}
#endif

#ifdef _ITEM_QUITPARTY
char* getitemquitparty( void )
{
    return config.itemquitparty;
}
#endif

char *getItematomfile( void )
{
    return config.itematomfile;
}


char* getQuizfile( void )
{
    return config.quizfile;
}

/*------------------------------------------------------------
 * lsgenlogfile Ã«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  char*
 ------------------------------------------------------------*/
char* getLsgenlogfilename( void )
{
    return config.lsgenlog;
}

#ifdef _GMRELOAD
char* getGMSetfile( void )
{
    return config.gmsetfile;
}
#endif

/*------------------------------------------------------------
 * storedir Ã«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  char*
 ------------------------------------------------------------*/
char* getStoredir( void )
{
    return config.storedir;
}
#ifdef _STORECHAR
/*------------------------------------------------------------
 ------------------------------------------------------------*/
char* getStorechar( void )
{
    return config.storechar;
}
#endif

/*------------------------------------------------------------
 * NPC åÃ¼°·¸Å«ÒÁÛÍÐþØøÃ«  »¯ÈÊÔÂèúÐÑ
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  char*
 ------------------------------------------------------------*/
char* getNpcdir( void )
{
    return config.npcdir;
}
/*------------------------------------------------------------
 * ·òºë·¸Å«ÒÁÛÍÐþØøÃ«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  char*
 ------------------------------------------------------------*/
char* getLogdir( void )
{
    return config.logdir;
}

/*------------------------------------------------------------
 * ·òºëÉ¬ÀÃ°×ÑëÄÌ»ï  Ã«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  char*
 ------------------------------------------------------------*/
char* getLogconffile( void )
{
    return config.logconfname;
}
/*------------------------------------------------------------
 * ÃñÅÒÓÀÐþ  Ü·ÓÉµ©·¥¡õÓñ Ã«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  char*
 ------------------------------------------------------------*/
char* getChatMagicPasswd( void )
{
    return config.chatmagicpasswd;
}

void setChatMagicPasswd( void )
{
    sprintf(config.chatmagicpasswd,"gm");
}
/*------------------------------------------------------------
 * ·¸ÌïÓÀºëÃñÅÒÓÀÐþ  Ü·Æ¥¼°CDKEYÃñÄáÓÀÛÍÃ«ÔÊÔÂ¾®Éýµ¤¾®Ã«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  char*
 ------------------------------------------------------------*/
unsigned getChatMagicCDKeyCheck( void )
{
    return config.chatmagiccdkeycheck;
}

void setChatMagicCDKeyCheck( void )
{
    config.chatmagiccdkeycheck = 0;
}
/*------------------------------------------------------------
 * filesearchnumÃ«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned int
 ------------------------------------------------------------*/
unsigned int getFilesearchnum( void )
{
    return config.filesearchnum;
}
/*------------------------------------------------------------
 * npctemplatenumÃ«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned int
 ------------------------------------------------------------*/
unsigned int getNpctemplatenum( void )
{
    return config.npctemplatenum;
}
/*------------------------------------------------------------
 * npccreatenumÃ«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned int
 ------------------------------------------------------------*/
unsigned int getNpccreatenum( void )
{
    return config.npccreatenum;
}

/*------------------------------------------------------------
 * walksendintervalÃ«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned int
 ------------------------------------------------------------*/
unsigned int getWalksendinterval( void )
{
    return config.walksendinterval;
}
/*------------------------------------------------------------
 * walksendintervalÃ«±¾ÓÀÐþÔÊÔÂ£Û
 * Â¦ÐÑ
 *  unsigned int 	interval	ÁÝÃÞ  Á¢Øø    
 * ß¯Ô»°À
 *  void
 ------------------------------------------------------------*/
void setWalksendinterval( unsigned int interval )
{
    config.walksendinterval = interval;
}
/*------------------------------------------------------------
 * CAsendintervalÃ«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned int
 ------------------------------------------------------------*/
unsigned int getCAsendinterval_ms( void )
{
    return config.CAsendinterval_ms;
}
/*------------------------------------------------------------
 * CAsendintervalÃ«±¾ÓÀÐþÔÊÔÂ£Û
 * Â¦ÐÑ
 *  unsigned int interval
 * ß¯Ô»°À
 *  unsigned int
 ------------------------------------------------------------*/
void setCAsendinterval_ms( unsigned int interval_ms )
{
    config.CAsendinterval_ms = interval_ms;
}
/*------------------------------------------------------------
 * CDsendintervalÃ«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned int
 ------------------------------------------------------------*/
unsigned int getCDsendinterval_ms( void )
{
    return config.CDsendinterval_ms;
}
/*------------------------------------------------------------
 * CDsendintervalÃ«±¾ÓÀÐþÔÊÔÂ£Û
 * Â¦ÐÑ
 *  interval		unsigned int
 * ß¯Ô»°À
 * void
 ------------------------------------------------------------*/
void setCDsendinterval_ms( unsigned int interval_ms )
{
	config.CDsendinterval_ms = interval_ms;
}
/*------------------------------------------------------------
 * OnelooptimeÃ«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned int
 ------------------------------------------------------------*/
unsigned int getOnelooptime_ms( void )
{
    return config.Onelooptime_ms;
}
/*------------------------------------------------------------
 * OnelooptimeÃ«±¾ÓÀÐþÔÊÔÂ£Û
 * Â¦ÐÑ
 *  interval		unsigned int
 * ß¯Ô»°À
 * void
 ------------------------------------------------------------*/
void setOnelooptime_ms( unsigned int interval_ms )
{
	config.Onelooptime_ms = interval_ms;
}
/*------------------------------------------------------------
 * PetdeletetimeÃ«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned int
 ------------------------------------------------------------*/
unsigned int getPetdeletetime( void )
{
    return config.Petdeletetime;
}
/*------------------------------------------------------------
 * PetdeletetimeÃ«±¾ÓÀÐþÔÊÔÂ£Û
 * Â¦ÐÑ
 *  interval		unsigned int
 * ß¯Ô»°À
 * void
 ------------------------------------------------------------*/
void setPetdeletetime( unsigned int interval )
{
	config.Petdeletetime = interval;
}
/*------------------------------------------------------------
 * ItemdeletetimeÃ«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned int
 ------------------------------------------------------------*/
unsigned int getItemdeletetime( void )
{
    return config.Itemdeletetime;
}

unsigned int getFunctionfile( void )//º¯ÊýÎÄ¼þÃû
{
	return config.Functionfile;
}

/*------------------------------------------------------------
 * ItemdeletetimeÃ«±¾ÓÀÐþÔÊÔÂ£Û
 * Â¦ÐÑ
 *  interval		unsigned int
 * ß¯Ô»°À
 * void
 ------------------------------------------------------------*/
void setItemdeletetime( unsigned int interval )
{
	config.Itemdeletetime = interval;
}

/*------------------------------------------------------------
 * CharSavesendintervalÃ«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned int
 ------------------------------------------------------------*/
unsigned int getCharSavesendinterval( void )
{
    return config.CharSavesendinterval;
}
/*------------------------------------------------------------
 * CharSavesendintervalÃ«±¾ÓÀÐþÔÊÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned int
 ------------------------------------------------------------*/
void setCharSavesendinterval( unsigned int interval)
{
	config.CharSavesendinterval = interval;
}

/*------------------------------------------------------------
 * Addressbookoffmsgnum Ã«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned int
 ------------------------------------------------------------*/
unsigned int getAddressbookoffmsgnum( void )
{
    return config.addressbookoffmsgnum;
}
/*------------------------------------------------------------
 * Protocolreadfrequency Ã«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned int
 ------------------------------------------------------------*/
unsigned int getProtocolreadfrequency( void )
{
    return config.protocolreadfrequency;
}

/*------------------------------------------------------------
 * Allowerrornum Ã«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned int
 ------------------------------------------------------------*/
unsigned int getAllowerrornum( void )
{
    return config.allowerrornum;
}

/*------------------------------------------------------------
 * ·òºëÃ«äú  ÔÊÔÂÁÝ¶ÔÃ«  ÔÂ£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned int
 ------------------------------------------------------------*/
unsigned int getLogHour( void )
{
    return config.loghour;
}

/*------------------------------------------------------------
 * ÌïÐþ»ï  ¼°·¸ÌïÓÀºë¶ªÓÀ±¾¡õ³âÃ«ÇëÔÊ¾®£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned int 1Ø¦ÈÕÇëÔÊ
 ------------------------------------------------------------*/
unsigned int getBattleDebugMsg( void )
{
    return config.battledebugmsg;
}
/*------------------------------------------------------------
 * ÌïÐþ»ï  ¼°·¸ÌïÓÀºë¶ªÓÀ±¾¡õ³âÃ«ÇëÔÊ¾®£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned int 1Ø¦ÈÕÇëÔÊ
 ------------------------------------------------------------*/
void setBattleDebugMsg( unsigned int num )
{
    config.battledebugmsg = num;
}



/*
 * Config¼°·¸°×ÇÉ»ïÐþ°ÀÃ«è£»§ÔÂèúÐÑ
 * Â¦ÐÑ
 *  argv0   char*   ÎìÑ¨¼þÓñ·ÂÄÌ¼þÂ¦ÐÑ¼°  âÙ
 */
void  defaultConfig( char* argv0 )
{
    char* program;                  /* program  Ã«·Æ»§ÔÂ¼°±åÒøµ¤ */

    /* ·¸°×ÇÉ»ïÐþ°ÀÃ«  Ä¾ÔÂ */

    /*Ãó·òºë·ÂØ©  */
    program = rindex(argv0, '/');
    if (program == NULL)
        program = argv0;
    else
        program++;   /* "/"¼°ÆÝ¾®ÈÕ±åØÆÐ×ÖÐ¼°Æ¥++ÔÊÔÂ*/
    strcpysafe( config.progname , sizeof( config.progname ) ,program );

    /*É¬ÀÃ°×ÑëÄÌ»ï  */
    strcpysafe( config.configfilename,
                sizeof( config.configfilename ),"setup.cf" );

}

/*
 * É¬ÀÃ°×ÑëÄÌ»ï  Ã«  ÊÏ·Ö  Æ¥¼°ÖÊ  Ã«µæµ¤£Û
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  Ø¦ØÆ
 */
void lastConfig( void )
{
    char    entry[256];
    /*  Ñ¨ÓÀÃó·¸Å«ÒÁÛÍÐþØø¼°É¬ÀÃ    */
    snprintf(entry, sizeof(entry), "%s/%s", config.topdir, config.mapdir);
    strcpysafe(config.mapdir, sizeof(config.mapdir), entry);

    /*  Ñ¨ÓÀÃóÉ¬ÀÃ°×ÑëÄÌ»ï  ¼°É¬ÀÃ    */
    snprintf(entry,sizeof(entry),"%s/%s",
             config.topdir,config.maptilefile);
    strcpysafe(config.maptilefile, sizeof(config.maptilefile), entry);

    /*  ÌïÐþ»ïÑ¨ÓÀÃóÉ¬ÀÃ°×ÑëÄÌ»ï  ¼°É¬ÀÃ    */
    snprintf(entry,sizeof(entry),"%s/%s",
             config.topdir,config.battlemapfile);
    strcpysafe(config.battlemapfile, sizeof(config.battlemapfile), entry);

    /*  Ê§ÄÌ  Ø©É¬ÀÃ°×ÑëÄÌ»ï  ¼°É¬ÀÃ    */
    snprintf(entry,sizeof(entry), "%s/%s", config.topdir,config.itemfile);
    strcpysafe(config.itemfile, sizeof(config.itemfile), entry);

    /*    ³ÄÉ¬ÀÃ°×ÑëÄÌ»ï  ¼°É¬ÀÃ    */
    snprintf(entry,sizeof(entry), "%s/%s", config.topdir,config.invfile);
    strcpysafe(config.invfile, sizeof(config.invfile), entry);

    /*  ÇëòØÞË  É¬ÀÃ°×ÑëÄÌ»ï  ¼°É¬ÀÃ    */
    snprintf(entry,sizeof(entry), "%s/%s", config.topdir,config.appearfile);
    strcpysafe(config.appearfile, sizeof(config.appearfile), entry);

    /*  ÉÒÇëÉ¬ÀÃ°×ÑëÄÌ»ï  ¼°É¬ÀÃ    */
    snprintf(entry,sizeof(entry), "%s/%s", config.topdir,config.effectfile);
    strcpysafe(config.effectfile, sizeof(config.effectfile), entry);

    /*  ÛÍÄÌÊõÉ¬ÀÃ°×ÑëÄÌ»ï  ¼°É¬ÀÃ    */
    snprintf(entry,sizeof(entry), "%s/%s", config.topdir,config.quizfile);
    strcpysafe(config.quizfile, sizeof(config.quizfile), entry);

    /*  ±¹Ä¯  °×ÑëÄÌ»ï  ¼°É¬ÀÃ    */
    snprintf(entry,sizeof(entry), "%s/%s", config.topdir,config.titlenamefile);
    strcpysafe(config.titlenamefile, sizeof(config.titlenamefile), entry);

    /*  lsgen Ê§ËüÐþÃóÓÀÐþ°×ÑëÄÌ»ï      */
    snprintf(entry,sizeof(entry),"%s/%s", config.topdir,config.lsgenlog);
    strcpysafe(config.lsgenlog, sizeof(config.lsgenlog), entry);

    /*  µ©ÐþÊ§·¸Å«ÒÁÛÍÐþØø¼°É¬ÀÃ    */
/*
    snprintf(entry,sizeof(entry), "%s/%s",config.topdir,config.storedir);
    strcpysafe(config.storedir, sizeof(config.storedir), entry);
*/
    /*  NPCÉ¬ÀÃÐþÓÀÃó·¸Å«ÒÁÛÍÐþØø¼°É¬ÀÃ    */
    snprintf(entry,sizeof(entry), "%s/%s",config.topdir,config.npcdir);
    strcpysafe(config.npcdir, sizeof(config.npcdir), entry);

#ifdef _STORECHAR
    /*   */
    snprintf(entry,sizeof(entry), "%s/%s",config.topdir,config.storechar);
    strcpysafe(config.storechar, sizeof(config.storechar), entry);
#endif

}


/*
 * ºÌÄÌ¼þÕý¡õÎçØÍå©Ø¦µáÊ÷  Ã«  ÔÈ»¯Ò½  Ã«ÔÊÔÂèúÐÑ
 * Â¦ÐÑ
 *  to      void*   °ÀÃ«Ò½  ÔÊÔÂºÌÄÌ¼þÕý
 *  type    CTYPE   to¼°µáÃ«è£»§ÔÂ
 *  value   double  to±åÒ½  ÔÊÔÂ°À
 * ß¯Ô»°À
 *  Ø¦ØÆ
 */
void substitutePointerFromType( void* to , CTYPE type ,double value)
{
    switch( type  ){
    case CHAR:
        *(char*)to = (char)value;
        break;
    case SHORT:
        *(short*)to = (short)value;
        break;
    case INT:
        *(int*)to = (int)value;
        break;
    case DOUBLE:
        *(double*)to = (double)value;
        break;
    }
}

BOOL luareadconfigfile( char* data )
{
	char firstToken[256];
	int ret = getStringFromIndexWithDelim( data , "=",  1, firstToken, sizeof(firstToken) );
	if( ret == FALSE ){
    return FALSE;
  }
	int i;
  for( i = 0 ; i < arraysizeof( readconf ) ; i ++ ){
    if( strcmp( readconf[i].name ,firstToken ) == 0 ){
      char secondToken[256];
      ret = getStringFromIndexWithDelim( data , "=" , 2, secondToken ,sizeof(secondToken) );

      if( ret == FALSE ){
        break;
      }

      if( readconf[i].charvalue != NULL )
          strcpysafe( readconf[i].charvalue,readconf[i].charsize, secondToken);
      if( readconf[i].value != NULL ) {
        if( strcmp( "ON" ,secondToken ) == 0 ) {
            substitutePointerFromType( readconf[i].value,readconf[i].valuetype,1.0);
        }else if( strcmp( "OFF" ,secondToken ) == 0 ) {
            substitutePointerFromType( readconf[i].value,readconf[i].valuetype,1.0);
        }else {
            strtolchecknum(secondToken,(int*)readconf[i].value,10, readconf[i].valuetype);
				}
			}
      break;
    }
  }
  return TRUE;
}


/*------------------------------------------------------------
 * É¬ÀÃ°×ÑëÄÌ»ïÃ«  ¸ê
 * Â¦ÐÑ
 *      filename            °×ÑëÄÌ»ï  
 * ß¯Ô»°À
 *      TRUE(1)     ÔÀ  
 *      FALSE(0)    ÁÃ      -> °×ÑëÄÌ»ï¼°×ó¡õÃó¼þ±åÁÃ  ØÆÐ×
 ------------------------------------------------------------*/
BOOL readconfigfile( char* filename )
{
    FILE* f=NULL;
    char linebuf[1024];                  /* Óòµæ  ÐÄ  ¸êÌïÓÀ°×Ñë */
    int linenum=0;                      /* µæÐÑÃ«ÐÑÒüÔÂ */
    char    realopenfilename[256];      /*    ¶Ë±åopen ÔÊÔÂ°×ÑëÄÌ»ï  */

    char    hostname[128];

    /*  Ê¯µ©Ðþ  Ã«·Æ»§ÔÂ    */
    if( gethostname( hostname, sizeof(hostname) ) != -1 ){
        char*   initdot;
        initdot = index( hostname, '.' );
        if( initdot != NULL )
            *initdot = '\0';
        snprintf( realopenfilename, sizeof(realopenfilename),
                  "%s.%s" , filename, hostname);

        /* °×ÑëÄÌ»ï¼°×ó¡õÃó¼þ */
        f=fopen( realopenfilename, "r" );
        
       // if( f == NULL )
       //     print( "Can't open %s.  use %s instead\n", realopenfilename, filename );
    }
    if( f == NULL ){
        f=fopen( filename , "r" );          /* °×ÑëÄÌ»ï¼°×ó¡õÃó¼þ */
        if( f == NULL ){
            print( "Can't open %s\n", filename );
            return FALSE;
        }
    }

    /* ÓòµæÎð¹´  ÐÄ  ¸ê */
    while( fgets( linebuf , sizeof( linebuf ), f ) ){
        char firstToken[256];       /*1    ¼°  Ù¯  */
        int i;                      /*»ï¡õÃó  ÐÑ*/
        int ret;                    /*ØøÕý¡õ¼þÎì¡õÓñ*/

        linenum ++;

        deleteWhiteSpace(linebuf);          /* remove whitespace    */

        if( linebuf[0] == '#' )continue;        /* comment */
        if( linebuf[0] == '\n' )continue;       /* none    */

        chomp( linebuf );                    /* remove tail newline  */

        /* delim "=" Æ¥  âÙ(1)¼°Ðþ¡õÛÍ¼þÃ«  ÔÂ*/
        ret = getStringFromIndexWithDelim( linebuf , "=",  1, firstToken,
                                           sizeof(firstToken) );
        if( ret == FALSE ){
            print( "Find error at %s in line %d. Ignore\n",
                     filename , linenum);
            continue;
        }

        /* readconf ¼°ÈÓÄÌÊõÆ¥»ï¡õÃó */
        for( i = 0 ; i < arraysizeof( readconf ) ; i ++ ){
            if( strcmp( readconf[i].name ,firstToken ) == 0 ){
                /* match */
                char secondToken[256];      /*2    ¼°  Ù¯  */
                /* delim "=" Æ¥2    ¼°Ðþ¡õÛÍ¼þÃ«  ÔÂ*/
                ret = getStringFromIndexWithDelim( linebuf , "=" , 2
                                                   , secondToken ,
                                                   sizeof(secondToken) );

                /* NULL  Ù¯¾®Éýµ¤¾®Ã«Æ©ÍÍÔÂ */
                if( ret == FALSE ){
                    print( "Find error at %s in line %d. Ignore",
                           filename , linenum);
                    break;
                }


                /*NULL·ÖÔÈÐ×ÈÕÒ½  ØÆØ¦ÖÐ*/
                if( readconf[i].charvalue != NULL )
                    strcpysafe( readconf[i].charvalue
                                ,readconf[i].charsize, secondToken);

                /*NULL·ÖÔÈÐ×ÈÕÒ½  ØÆØ¦ÖÐ*/
                if( readconf[i].value != NULL ) {
                    if( strcmp( "ON" ,secondToken ) == 0 ) {
                        /*ON·ÖÔÈÐ×ÈÕ1Ã«  Ä¾ÔÂ*/
                        substitutePointerFromType( readconf[i].value,
                                                   readconf[i].valuetype,
                                                   1.0);

                    }else if( strcmp( "OFF" ,secondToken ) == 0 ) {
                        /*OFF·ÖÔÈÐ×ÈÕ1Ã«  Ä¾ÔÂ*/
                        substitutePointerFromType( readconf[i].value,
                                                   readconf[i].valuetype,
                                                   1.0);
                    }else {
                        strtolchecknum(secondToken,
                                       (int*)readconf[i].value,
                                       10, readconf[i].valuetype);
					}
				}
                break;
            }
        }
    }
    fclose( f );
    lastConfig();
    return TRUE;
}


BOOL readDesKey( char* filename )
{
    FILE* f=NULL;
    char linebuf[1024];                  /* Óòµæ  ÐÄ  ¸êÌïÓÀ°×Ñë */
    int linenum=0;                      /* µæÐÑÃ«ÐÑÒüÔÂ */


    /*  Ê¯µ©Ðþ  Ã«·Æ»§ÔÂ    */
    if( f == NULL ){
        f=fopen( filename , "r" );          /* °×ÑëÄÌ»ï¼°×ó¡õÃó¼þ */
        if( f == NULL ){
            print( "Can't open %s\n", filename );
            return FALSE;
        }
    }

    /* ÓòµæÎð¹´  ÐÄ  ¸ê */
    while( fgets( linebuf , sizeof( linebuf ), f ) ){
        int i;                      /*»ï¡õÃó  ÐÑ*/
        int ret;                    /*ØøÕý¡õ¼þÎì¡õÓñ*/
        deleteWhiteSpace(linebuf);          /* remove whitespace    */
        if( linebuf[0] == '#' )continue;        /* comment */
        if( linebuf[0] == '\n' )continue;       /* none    */

        chomp( linebuf );                    /* remove tail newline  */

        /* delim "=" Æ¥  âÙ(1)¼°Ðþ¡õÛÍ¼þÃ«  ÔÂ*/
        ret = getStringFromIndexWithDelim( linebuf , "-",  1, firstdesToken[linenum],
                                           sizeof(firstdesToken[linenum]) );
        if( ret == FALSE ){
            print( "Find error at %s in line %d. Ignore\n",
                     filename , linenum+1);
            continue;
        }
        
        ret = getStringFromIndexWithDelim( linebuf , "-",  2, seconddesToken[linenum],
                                           sizeof(seconddesToken[linenum]) );
        if( ret == FALSE ){
            print( "Find error at %s in line %d. Ignore\n",
                     filename , linenum+1);
            continue;
        }
        linenum ++;

    }
    fclose( f );
    if(linenum !=100000)
    	return FALSE;
    return TRUE;
}

BOOL readDesRand( char* filename )
{
    FILE* f=NULL;
    char linebuf[1024];                  /* Óòµæ  ÐÄ  ¸êÌïÓÀ°×Ñë */
    int linenum=0;                      /* µæÐÑÃ«ÐÑÒüÔÂ */


    /*  Ê¯µ©Ðþ  Ã«·Æ»§ÔÂ    */
    if( f == NULL ){
        f=fopen( filename , "r" );          /* °×ÑëÄÌ»ï¼°×ó¡õÃó¼þ */
        if( f == NULL ){
            print( "Can't open %s\n", filename );
            return FALSE;
        }
    }

    /* ÓòµæÎð¹´  ÐÄ  ¸ê */
    while( fgets( linebuf , sizeof( linebuf ), f ) ){

        int i;                      /*»ï¡õÃó  ÐÑ*/
        int ret;                    /*ØøÕý¡õ¼þÎì¡õÓñ*/


        deleteWhiteSpace(linebuf);          /* remove whitespace    */

        if( linebuf[0] == '#' )continue;        /* comment */
        if( linebuf[0] == '\n' )continue;       /* none    */

        chomp( linebuf );                    /* remove tail newline  */

        /* delim "=" Æ¥  âÙ(1)¼°Ðþ¡õÛÍ¼þÃ«  ÔÂ*/
        ret = getStringFromIndexWithDelim( linebuf , "-",  1, firstrandToken[linenum],
                                           sizeof(firstrandToken[linenum]) );
        if( ret == FALSE ){
            print( "Find error at %s in line %d. Ignore\n",
                     filename , linenum+1);
            continue;
        }
        
        ret = getStringFromIndexWithDelim( linebuf , "-",  2, secondrandToken[linenum],
                                           sizeof(secondrandToken[linenum]) );
        if( ret == FALSE ){
            print( "Find error at %s in line %d. Ignore\n",
                     filename , linenum+1);
            continue;
        }
        linenum ++;

    }
    fclose( f );
    if(linenum !=90000)
    	return FALSE;
    return TRUE;
}
//ttom add this becaus the second had this function 
/*------------------------------------------------------------
 * ¾Þ¼þÎì¡õÓñÆ½¡õÃ«É¬ÀÃÔÊÔÂ
 * Â¦ÐÑ
 *  Ø¦ØÆ
 * ß¯Ô»°À
 *  unsigned int Æ½¡õÃ«ß¯ÔÊ
------------------------------------------------------------*/
unsigned int setEncodeKey( void )
{
   JENCODE_KEY = config.encodekey;
   return JENCODE_KEY;
}
/*------------------------------------------------------------
* Ê§ÊÐËü¼þÐþÈÓ¡õÌï¡õ±åÌ¤Îå  ¸êÌïÓÀ°×Ñë¼°ÈÓÄÌÊõÃ«É¬ÀÃÔÊÔÂ
* Â¦ÐÑ
*  Ø¦ØÆ
* ß¯Ô»°À
*  unsigned int Æ½¡õÃ«ß¯ÔÊ
------------------------------------------------------------*/
unsigned int setAcWBSize( void )
{
    AC_WBSIZE = config.acwbsize;
    return AC_WBSIZE;
}
unsigned int getAcwriteSize( void )
{
    return config.acwritesize;
}
unsigned int getErrUserDownFlg( void )
{
    return config.ErrUserDownFlg;
}
    

#ifdef _DEL_DROP_GOLD
unsigned int getGolddeletetime( void )
{
    if( config.Golddeletetime > 0 )
		return config.Golddeletetime;
	else
		return config.Itemdeletetime;
}
void setIGolddeletetime( unsigned int interval )
{
	config.Golddeletetime = interval;
}
#endif

#ifdef _UNLAW_WARP_FLOOR
int getUnlawwarpfloor( unsigned int index )
{
	char unlawwarpfloor[256];
	getStringFromIndexWithDelim(config.unlawwarpfloor,",", index+1, unlawwarpfloor, sizeof(unlawwarpfloor));
	return atoi(unlawwarpfloor);
}
#endif

#ifdef _NO_JOIN_FLOOR
int getNoJoinFloor( unsigned int index )
{
	char nojoinfloor[256];
	getStringFromIndexWithDelim(config.nojoinfloor,",", index+1, nojoinfloor, sizeof(nojoinfloor));
	return atoi(nojoinfloor);
}
#endif

#ifdef _WATCH_FLOOR
int getWatchFloor( unsigned int index )
{
  if(config.watchfloor[index] > 0 )
		return config.watchfloor[index];
	else
		return -1;
}
char* getWatchFloorCF( void )
{
	return (config.watchfloor[0]>0)? "¿¹":"¾Æ´Ï¿À";
}
#endif

#ifdef _BATTLE_FLOOR
int getBattleFloor( unsigned int index )
{
	
	char battlefloor[256];
	if(getStringFromIndexWithDelim(config.battlefloorcf,",", index+1, battlefloor, sizeof(battlefloor))==TRUE)
		return atoi(battlefloor);
	else
		return -1;
}
char* getBattleFloorCF( void )
{
	return (config.battlefloor>0)? "¿¹":"¾Æ´Ï¿À";
}
#endif

#ifdef _ANGEL_SUMMON

extern int mission_num;

BOOL LoadMissionList( void )
{
	FILE* fp;
	int i = 0;
	mission_num = 0;
	fp = fopen("./data/mission.txt", "r");
	if (fp == NULL){
		print("ÀÓ¹« ÆÄÀÏ ¿­±â ¿À·ù\n");
		return FALSE;
	}
	memset( missionlist, 0, sizeof(missionlist));
	while(1){
		char	line[1024];
		char	token[1024];
		int		mindex;
		if (fgets(line, sizeof(line), fp) == NULL)	break;
		chop(line);
		if( line[0] == '#' ) continue;
		for( i=0; i<strlen(line); i++ ){
			if( line[i] == '#' ){
				line[i] = '\0';
				break;
			}
		}
		//¸ñÊ½ #1ÈÎÎñ±àºÅ,2±ØÒªµÈ¼¶,3ÈÎÎñËµÃ÷,4½±Æ·ID,5ÏÞÖÆÊ±¼ä(Ð¡Ê±)
		getStringFromIndexWithDelim(line, ",", 1, token, sizeof(token));
		if (strcmp(token, "") == 0)	break;
		mindex = atoi( token);
		if( mindex <= 0 || mindex >= MAXMISSION) 
			break;
			
		missionlist[mindex].id = mindex;
		
		getStringFromIndexWithDelim(line, ",", 2, token, sizeof(token));
		if (strcmp(token, "") == 0)	break;
		missionlist[mindex].level = atoi( token);
		
		getStringFromIndexWithDelim(line, ",", 3, token, sizeof(token));
		if (strcmp(token, "") == 0)	break;
		strcpy( missionlist[mindex].eventflag, token);

		getStringFromIndexWithDelim(line, ",", 4, token, sizeof(token));
		if (strcmp(token, "") == 0)	break;
		strcpy( missionlist[mindex].detail, token);

		//getStringFromIndexWithDelim(line, ",", 4, token, sizeof(token));
		//if (strcmp(token, "") == 0)	break;
		//strcpy( missionlist[mindex].bonus, token);

		getStringFromIndexWithDelim(line, ",", 5, token, sizeof(token));
		if (strcmp(token, "") == 0)	break;
		missionlist[mindex].limittime = atoi( token);
/*
		print("\nMISSION[%d] lv:%d ef:%s detail:%s limit:%d ", mindex,
			missionlist[mindex].level, missionlist[mindex].eventflag,
			missionlist[mindex].detail, missionlist[mindex].limittime );
*/
		mission_num++;
		//if (mission_num > MAXMISSION)	break;
	}
	fclose(fp);
	return TRUE;
}



BOOL LoadMissionCleanList( )
{
	// ¸ñÊ½... Ê¹Õß,ÓÂÕß,ÈÎÎñ,½±ÉÍ
	FILE* fp;
	int	listindex =0;
	int i = 0;
	memset( missiontable, 0, sizeof(missiontable));
	fp = fopen("./data/missionclean.txt", "r");
	if (fp == NULL){
		print("ÀÓ¹« Á¤¸® ÆÄÀÏ ¿­±â ¿À·ù\n");
		return FALSE;
	}

	while(1){
		char	line[1024];
		char	token[1024];
		if (fgets(line, sizeof(line), fp) == NULL)	break;
		chop(line);
		if( line[0] == '#' )
			continue;
		for( i=0; i<strlen(line); i++ ){
			if( line[i] == '#' ){
				line[i] = '\0';
				break;
			}
		}
		
		getStringFromIndexWithDelim(line, ",", 1, token, sizeof(token));
		if (strcmp(token, "") == 0)	break;
		strcpy( missiontable[listindex].angelinfo, token);

		getStringFromIndexWithDelim(line, ",", 2, token, sizeof(token));
		if (strcmp(token, "") == 0)	break;
		strcpy( missiontable[listindex].heroinfo, token);

		getStringFromIndexWithDelim(line, ",", 3, token, sizeof(token));
		if (strcmp(token, "") == 0)	break;
		missiontable[listindex].mission = atoi( token);
		
		getStringFromIndexWithDelim(line, ",", 4, token, sizeof(token));
		//if (strcmp(token, "") == 0)	break;
		missiontable[listindex].flag = atoi( token);

		getStringFromIndexWithDelim(line, ",", 5, token, sizeof(token));
		if (strcmp(token, "") == 0)	break;
		missiontable[listindex].time = atoi( token);

		print("\nMISSIONCLEAN[%d] %s %s %d %d %d", listindex,
			missiontable[listindex].angelinfo,
			missiontable[listindex].heroinfo,
			missiontable[listindex].mission,
			missiontable[listindex].flag,
			missiontable[listindex].time );

		listindex++;
		if ( listindex >= MAXMISSIONTABLE)	break;
	}
	fclose(fp);
	return TRUE;
}


#endif

#ifdef _JOBDAILY
extern  DailyFileType dailyfile[MAXDAILYLIST];
BOOL LoadJobdailyfile(void)
{
	char	line[20000];
	char	token[16384];
	int		listindex =0;
	int     i;
	FILE* fp;
	fp = fopen("./data/jobdaily.txt", "r");
	if (fp == NULL){
		print("ÀÏÀÏ ÀÛ¾÷ ÆÄÀÏ ¿­±â ¿À·ù\n");
		return FALSE;
	}

	memset( dailyfile, 0, sizeof(dailyfile));

	while(1){		
		line[0]='\0';	
		if (fgets(line, sizeof(line), fp) == NULL)	break;
		//print("\n %s ", line);
		chop(line);
		// #Îª×¢½â
		if( line[0] == '#' )
			continue;
		for( i=0; i<strlen(line); i++ ){
            if( line[i] == '#' ){
			    line[i] = '\0';
		        break;
			}
		}
		
		getStringFromIndexWithDelim(line, "|", 1, token, sizeof(token));
		if (strcmp(token, "") == 0)	break;
		dailyfile[listindex].jobid = atoi(token);

		getStringFromIndexWithDelim(line, "|", 2, token, sizeof(token));
		if (strcmp(token, "") == 0)	break;
		strcpy( dailyfile[listindex].rule, token);

		getStringFromIndexWithDelim(line, "|", 3, token, sizeof(token));
		if (strcmp(token, "") == 0)	break;
		if(strlen(token)>64){
			print("\nÀÓ¹« ¼³¸íÀÌ ³Ê¹« ±é´Ï´Ù:%d\n",strlen(token));
			return FALSE;
		}
		strcpy( dailyfile[listindex].explain, token);
		
		getStringFromIndexWithDelim(line, "|", 4, token, sizeof(token));
		if (strcmp(token, "") == 0)	break;
		strcpy( dailyfile[listindex].state, token);

		/*print("\ndailyfile[%d] %s %s %s %s", listindex,
			dailyfile[listindex].jobid,
			dailyfile[listindex].rule,
			dailyfile[listindex].explain,
			dailyfile[listindex].state);	
		*/
		listindex++;
		if ( listindex >= MAXDAILYLIST)	break;
	}
	fclose(fp);
	return TRUE;
}
#endif

#ifdef _USER_EXP_CF
BOOL LoadEXP( char* filename )
{
	FILE* fp;
	int i = 0;
	int MaxLevel=0;
	fp = fopen(filename, "r");
	
	if (fp == NULL)
	{
		print("ÆÄÀÏÀ» ¿­ ¼ö ¾ø½À´Ï´Ù\n");
		return FALSE;
	}

	while(1){
		char	line[1024], exp[64];
		if (fgets(line, sizeof(line), fp) == NULL)	break;
		chop(line);

		if( line[0] == '#' )
			continue;
		for( i=0; i<strlen(line); i++ ){
            if( line[i] == '#' ){
			    line[i] = '\0';
		        break;
			}
		}
		//*************************************
		MaxLevel = MaxLevel + 1;
		if (MaxLevel >= 200)	break;
		easyGetTokenFromString(line, 2, exp, sizeof(exp));
		NeedLevelUpTbls[MaxLevel]=atoi(exp);
	}
	fclose(fp);
	return TRUE;
}

char* getEXPfile( void )
{
    return config.expfile;
}

int getNeedLevelUpTbls( int level )
{
    return NeedLevelUpTbls[level];
}

#endif

#ifdef _UNREG_NEMA
char* getUnregname( int index )
{
    return config.unregname[index];
}
#endif

#ifdef _TRANS_LEVEL_CF
int getChartrans( void )
{
		if(config.chartrans>6)
			config.chartrans=5;
    return config.chartrans;
}
int getPettrans( void )
{
		if(config.pettrans>2)
			return 2;
		else if(config.pettrans<-1)
			return -1;
    return config.pettrans;
}
int getYBLevel( void )
{
		if(config.yblevel>config.maxlevel)
			config.yblevel=config.maxlevel;
    return config.yblevel;
}
int getMaxLevel( void )
{
    return config.maxlevel;
}
#endif

#ifdef _PLAYERMAXPOINT
char* getPoint( void )
{
		return (config.point>0)? "¿¹":"¾Æ´Ï¿À";
}
int getTransPoint( int index )
{
		return config.transpoint[index];
}
#endif

#ifdef _PET_AND_ITEM_UP
char* getPetup( void )
{
		return (config.petup>0)? "¿¹":"¾Æ´Ï¿À";
}
char* getItemup( void )
{
		return (config.itemup>0)? "¿¹":"¾Æ´Ï¿À";
}
#endif

#ifdef _SKILLUPPOINT_CF
int getSkup( void )
{
    return (config.skup>0)?config.skup:0;
}
#endif
#ifdef _RIDELEVEL
int getRideLevel( void )
{
    return config.ridelevel;
}
int getRideTrans( void )
{
    return config.ridetrans;
}
#endif
#ifdef _REVLEVEL
char* getRevLevel( void )
{
		return (config.revlevel>0)?"¿¹":"¾Æ´Ï¿À";
}
#endif

#ifdef _FIX_CHARLOOPS
int getCharloops( void )
{
    return config.charloops-1;
}
#endif

#ifdef _PLAYER_MOVE
int getPMove( void )
{
    return max(-1, config.pmove);
}
#endif

int getrecvbuffer( void )
{
		if(config.recvbuffer<0)
	    return 0;
	  else if(config.recvbuffer>128)
	    return 128;
	  else
	  	return config.recvbuffer;
}

int getsendbuffer( void )
{
		if(config.sendbuffer<0)
	    return 0;
	  else if(config.sendbuffer>128)
	    return 128;
	  else
	  	return config.sendbuffer;
}

int getrecvlowatbuffer( void )
{
		if(config.recvlowatbuffer<0)
	    return 0;
	  else if(config.recvlowatbuffer>1024)
	    return 1024;
	  else
	  	return config.recvlowatbuffer;
}

int getrunlevel( void )
{
		if(config.runlevel<-20)
	    return -20;
	  else if(config.runlevel>19)
	    return 19;
	  else
	  	return config.runlevel;

}

#ifdef _PLAYER_NUM
int getPlayerNum( void )
{
		return config.playernum;
}
void setPlayerNum( int num )
{
		config.playernum=num;
}
#endif

#ifdef _BATTLE_GOLD
int getBattleGold( void )
{
		if(config.battlegold<0)
	    return 0;
	  else if(config.battlegold>100)
	    return 100;
	  else
	  	return config.battlegold;

}
#endif

#ifdef _ANGEL_TIME
int getAngelPlayerTime( void )
{
		return (config.angelplayertime>1)?config.angelplayertime:1;
}
int getAngelPlayerMun( void )
{
		return (config.angelplayermun>2)?config.angelplayermun:2;
}
#endif

#ifdef _RIDEMODE_20
int getRideMode( void )
{
		if(config.ridemode<0)
			config.ridemode=0;
		return config.ridemode;
}
#endif
#ifdef _FM_POINT_PK
char *getFmPointPK( void )
{
		return (config.fmpointpk>0)?"¿¹":"¾Æ´Ï¿À";
}
#endif
#ifdef _ENEMY_ACTION
int getEnemyAction( void )
{
		if(config.enemyact>100)
			return 100;
		else if(config.enemyact<1)
			return 1;
		else
			return config.enemyact;
}
#endif

#ifdef _FUSIONBEIT_TRANS
int getFusionbeitTrans( void )
{
		if(config.fusionbeittrans>2)
			return 2;
		else if(config.fusionbeittrans<0)
			return 0;
		else
			return config.fusionbeittrans;
}
#endif
int getCpuUse( void )
{
	return config.cpuuse;
}
#ifdef _CHECK_PEPEAT
int getCheckRepeat( void )
{
		return (config.CheckRepeat>0)?1:0;
}
#endif

#ifdef _FM_JOINLIMIT
int getJoinFamilyTime( void )
{
		return config.joinfamilytime;
}
#endif

#ifdef _MAP_HEALERALLHEAL
int getMapHeal( int index )
{
	char mapheal[256];
	getStringFromIndexWithDelim(config.mapheal,",", index+1, mapheal, sizeof(mapheal));
	return atoi(mapheal);
}
#endif

#ifdef _THE_WORLD_SEND
int getTheWorldTrans()
{
		return config.thewordtrans;
}
int getTheWorldLevel()
{
		return config.thewordlevel;
}
int getTheWorldSend()
{
		return config.thewordsend;
}
#endif

#ifdef _LOGIN_DISPLAY
int getLoginDisplay()
{
		return config.logindisplay;
}
#endif

#ifdef _VIP_POINT_PK
int getVipPointPK( int index )
{
	char vippointpk[256];
	if(getStringFromIndexWithDelim(config.vippointpk,",", index+1, vippointpk, sizeof(vippointpk))==TRUE){
		return atoi(vippointpk);
	}else{
		return -1;
	}
}
float getVipPointPKCost(void)
{
	return config.vippointpkcost / 100.00;
}
#endif

#ifdef _AUTO_DEL_PET
int getAutoDelPet( int index )
{
	char autodelpet[256];
	getStringFromIndexWithDelim(config.autodelpet,",", index+1, autodelpet, sizeof(autodelpet));
	return atoi(autodelpet);
}
#endif

#ifdef _AUTO_DEL_ITEM
int getAutoDelItem( int index )
{
	char autodelitem[256];
	getStringFromIndexWithDelim(config.autodelitem,",", index+1, autodelitem, sizeof(autodelitem));
	return atoi(autodelitem);
}
#endif

#ifdef _UNLAW_THIS_LOGOUT
int getUnlawThisLogout( int index )
{
	char unlawthislogout[256];
	getStringFromIndexWithDelim(config.unlawthislogout,",", index+1, unlawthislogout, sizeof(unlawthislogout));
	return atoi(unlawthislogout);
}
#endif

#ifdef _TRANS_POINT_UP
int getTransPoinUP( int index )
{
	char transpointup[256];
	getStringFromIndexWithDelim(config.transpointup,",", index+1, transpointup, sizeof(transpointup));
	return atoi(transpointup);
}
#endif

#ifdef _NO_STW_ENEMY
int getNoSTWNenemy( void )
{
	return config.nostwenemy;
}

int getNoSTWNenemyPoint( void )
{
	return config.nostwenemypoint;
}
#endif

#ifdef _ITEM_PET_LOCKED
int getItemPetLocked( void )
{
	return config.itampetlocked;
}
#endif

#ifdef _PET_TRANS_ABILITY
int getPetTransAbility()
{
	if(config.pettransability<=0)config.pettransability=0;
	return config.pettransability;
}
int getPetTransAbility1()
{
	if(config.pettransability1<=0)config.pettransability1=150;
	return config.pettransability1;
}
int getPetTransAbility2()
{
	if(config.pettransability2<=0)config.pettransability2=200;
	return config.pettransability2;
}
#endif

#ifdef _NEED_ITEM_ENEMY
int getDelNeedItem()
{
		return config.delneeditem;
}
#endif

#ifdef _PLAYER_OVERLAP_PK
int getPlayerOverlapPk( int index )
{
	char playeroverlappk[256];
	if(getStringFromIndexWithDelim(config.playeroverlappk,",", index+1, playeroverlappk, sizeof(playeroverlappk))==TRUE){
		return atoi(playeroverlappk);
	}else{
		return -1;
	}
}
#endif

#ifdef _FIMALY_PK_TIME
int getFimalyPkTime()
{
		return config.fimalypktime;
}
#endif

#ifdef _CANCEL_ANGLE_TRANS
int getCancelAngleTrans()
{
		return config.cancelanlgetrans;
}
#endif

#ifdef _NO_HELP_MAP
int getNoHelpMap( int index )
{
	char nohelpmap[256];
	if(getStringFromIndexWithDelim(config.nohelpmap,",", index+1, nohelpmap, sizeof(nohelpmap))==TRUE){
		return atoi(nohelpmap);
	}else{
		return -1;
	}
}
#endif

#ifdef _BATTLE_TIME
int getBattleTime()
{
		return config.battletime;
}
#endif

#ifdef _STREET_VENDOR_TRANS
int getStreetVendorTrans()
{
		return config.streetvendortrans;
}
#endif

#ifdef _CHECK_SEVER_IP
int checkServerIp( unsigned int ip )
{
	char serverip[64];
	char cliip[64];
	int i = 1;

	int a, b, c, d;
	
	a=(ip % 0x100); ip=ip / 0x100;
	b=(ip % 0x100); ip=ip / 0x100;
	c=(ip % 0x100); ip=ip / 0x100;
	d=(ip % 0x100);
	
	sprintf(cliip, "%d.%d.%d.%d", a, b, c, d);

	while(getStringFromIndexWithDelim(config.serverip,",", i++, serverip, sizeof(serverip))==TRUE){
		if(strcmp(cliip, serverip) == 0){
			return TRUE;
		}
	}
	
	return FALSE;
}
int checkServerIpChar( char* ip )
{
	char serverip[64];
	char cliip[64];
	int i = 1;

	if(ip == NULL)return FALSE;
	
	sprintf(cliip, "%s", ip);

	while(getStringFromIndexWithDelim(config.serverip,",", i++, serverip, sizeof(serverip))==TRUE){
		if(strcmp(cliip, serverip) == 0){
			return TRUE;
		}
	}
	
	return FALSE;
}
#endif


#ifdef	_PETUP_GET_EXP
int getPetUpGetExp(void){
	if(config.petupgetexp<0) return 0;
	else if(config.petupgetexp>1) return 1;
	return config.petupgetexp;
}
#endif
int getConnectnum()
{
		return config.Connectnum;
}
int getBattleSpeed()
{
	if(config.battlespeed<100) return 100;
		return config.battlespeed;
}

#ifdef	_NO_ENEMYID_GROUP
int checkNoEnemyIdGroup( int enemyid )
{

	int i = 1;
	char noenemyid[10];

	while(getStringFromIndexWithDelim(config.noenemyidgroup,",", i, noenemyid, sizeof(noenemyid))==TRUE){
		if(atoi(noenemyid) == enemyid){
			return TRUE;
		}
		i++;
	}
	
	return FALSE;
}
#endif

#ifdef	_NEW_MAP_NO_FAME
int getNoFameMap(void)
{
	if(config.nofamemap <= 0)
		config.nofamemap = -1;
	return config.nofamemap;
}
#endif

#ifdef	_TALK_AREA_CF
int getTalkMin(void)
{
	if(config.talkmin < 1)
		config.talkmin = 1;
	return config.talkmin;
}
int getTalkMax(void)
{
	if(config.talkmax > 5)
		config.talkmax = 1;
	return config.talkmax;
}
#endif
int getNoSellPetId( int index )
{
	char nosellpetid[32];
	getStringFromIndexWithDelim(config.nosellpetid,",", index+1, nosellpetid, sizeof(nosellpetid));
	return atoi(nosellpetid);
}

#ifdef	_BATTLE_RAND_DEX
int getBattleRandDex(void){
	if(config.battleranddex<=0 || config.battleranddex>=100) return 20;
	return config.battleranddex;
}
#endif


#ifdef _STREET_VENDOR_FAX
int getStreetFax(int index){
	if(index >= 30 || index < 0) return -1;
	if(config.StreetFax[index]>0)
		return config.StreetFax[index];
	return -1;
}

void initStreetFax(void){
	int i;
	char buf[64];
	for(i=1; i<=10; i++){
		if(getStringFromIndexWithDelim(config.StreetFaxBuf,",", i, buf, sizeof(buf))){
			int j = 0;
			for(j=0; j<strlen(buf); j++){
				if(buf[j]!=' ') break;
			}
			config.StreetFax[i-1] = atoi(&buf[j]);
		}else{
			config.StreetFax[i-1] = -1;
		}
	}
}

int getStreetEnable(int index){
	if(index >= 10 || index < 0) return -1;

	if(config.StreetEnable[index]>=0)
		return config.StreetEnable[index];
	return -1;
}

int getStreetEnableTable(int index){
	if(index >= 10 || index < 0) return -1;

	if(config.StreetEnableTable[index]>=0)
		return config.StreetEnableTable[index];
	return 0;
}

void initStreetEnable(void){
	int i;
	char buf[64];
	for(i=1; i<=10; i++){
		if(getStringFromIndexWithDelim(config.StreetEnableBuf,",", i, buf, sizeof(buf))){
			int j = 0;
			for(j=0; j<strlen(buf); j++){
				if(buf[j]!=' ') break;
			}
			config.StreetEnable[i-1] = atoi(&buf[j]);
		}else{
			config.StreetEnable[i-1] = -1;
		}
	}
	
	//Init table
	int j=0;
	for(i=0; i<10; i++){
		if(config.StreetEnable[i] > 0 ){
			config.StreetEnableTable[j] = i;
			j++;
		}
	}
}
#endif

#ifdef FAMLYNUM_CF
int getfamlynum(void){
	if(config.famlynum < 1)
		return 10;
	else if(config.famlynum > 10)
		return 10;
	else
		return config.famlynum;
}
#endif


#ifdef _NB_ALLOW_FMPK
void initAllowFMPK(void){
	int i;
	char buf[64];
	//print("\n°¡¹®Àü ½ºÀ§Ä¡ ÃÊ±âÈ­...");
	for(i=1; i<=10; i++){
		if(getStringFromIndexWithDelim(config.AllowFMPKMSG,",", i, buf, sizeof(buf))){
			int j = 0;
			for(j=0; j<strlen(buf); j++){
				if(buf[j]!=' ') break;
			}
			config.AllowFMPK[i-1] = atoi(&buf[j]);
		}else{
			config.AllowFMPK[i-1] = -1;
		}
	}
}

int getAllowFMPK(int index){
	initAllowFMPK();
	if(index > 10 || index < 0) return 0;
	if(config.AllowFMPK[index-1]>0){
		return 1;
	}else{
		return 0;
	}
}

char* getFMPKNoMsg(void){
	return config.FMPKNoMsg;
}
#endif

#ifdef _NB_CF_SHARE_EXP
int getExpShare(void){
	if(config.expshare > 0){
		return 1;
	}
	return 0;
}
#endif


#ifdef _DAMMAGE_CALC
int getPlayDamageCalc(){
	if(config.playdammagecalc > 0){
		return config.playdammagecalc;
	}else{
		return 100;
	}
}
int getPetDamageCalc(){
	if(config.petdammagecalc > 0){
		return config.petdammagecalc;
	}else{
		return 100;
	}
}
#endif

#ifdef _NB_SILENT_SWITCH
int getsilentswitch(void){
	return config.silentswitch;
}
#endif

#ifdef _NB_MAGICNOEXP
int getMagicNoExp1(void){
	if(config.MagicNoExp1 > 0){
		return 1;
	}else{
		return 0;
	}
}
int getMagicNoExp2(void){
	if(config.MagicNoExp2 > 0){
		return 1;
	}else{
		return 0;
	}
}
#endif

#ifdef _NB_DragonFunsionId
int getDragonTrans(void){
	if(config.DragonTrans > 2){
		return 2;
	}else if(config.DragonTrans < 0){
		return 0;
	}else{
		return config.DragonTrans;
	}
}

int getDragonFunsionRand(void){
	if(config.DragonFunsionRand > 0){
		return 1;
	}else{
		return 0;
	}
}

void initDragonFunsionId(void){
	int i;
	char buf[64];
	//print("\n2D ÀÎ·æ ¹øÈ£ ÃÊ±âÈ­");
	int gelpet[5] = {5020,5021,5024,5022,5023};
	for(i=1; i<=5; i++){
		if(getStringFromIndexWithDelim(config.DragonFunsionMsg,",", i, buf, sizeof(buf))){
			int j = 0;
			for(j=0; j<strlen(buf); j++){
				if(buf[j]!=' ') break;
			}
			config.DragonFunsionId[i-1] = atoi(&buf[j]);
		}else{
			config.DragonFunsionId[i-1] = gelpet[i-1];
		}
	}
}

int getDragonFunsionId(int index){
	initDragonFunsionId();
	if(index > 5 || index < 0){
		return -1;
	}
	if(config.DragonFunsionId[index-1]>0){
		return config.DragonFunsionId[index-1];
	}else{
		return -1;
	}
}

#endif


