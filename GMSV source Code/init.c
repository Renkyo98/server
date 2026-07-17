#include "version.h"
#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include  <dirent.h>   
#include  <sys/types.h>   
#include  <sys/stat.h> 

#include "configfile.h"
#include "util.h"
#include "net.h"
#include "msignal.h"
#include "buf.h"
#include "object.h"
#include "char.h"
#include "char_data.h"
#include "item.h"
#include "readmap.h"
#include "function.h"
#include "saacproto_cli.h"
#include "lssproto_serv.h"
#include "readnpc.h"
#include "log.h"
#include "handletime.h"
#include "title.h"
#include "encount.h"
#include "enemy.h"
#include "battle.h"
#include "magic_base.h"
#include "pet_skill.h"
#include "item_gen.h"
#include "petmail.h"
#include "npc_quiz.h"
#include "char_talk.h"
#include "autil.h"
#ifdef _PROFESSION_SKILL			// WON ADD ÈËÎïÖ°Òµ¼¼ÄÜ
#include "profession_skill.h"
#endif
#ifdef _ALLBLUES_LUA
#include "mylua/mylua.h"
#endif
#ifdef _ONLINE_SHOP
#include "NewBilu/newshop.h"
#endif

#ifdef _ITEM_QUITPARTY
#include "init.h"
//int itemquitparty_num = 0;
//static DisappearItem *Disappear_Item;
#endif


#include "NewBilu/sasql.h"

#define MESSAGEFILE "hoge.txt"

#define OPTIONSTRING "d:f:hcl"
#define usage() print( "Usage: %s ["OPTIONSTRING"]\n", getProgname() );

void printUsage( void )
{
    usage();
  /*print( "Usage: %s ["OPTIONSTRING"]\n", progname );*/
    print( "          [-d debuglevel]        default value is 0\n" );
    print( "          [-f configfilename]    default value is setup.cf\n"
        );
}

/*
 *
 * Â¦ĞÑ
 * ß¯Ô»°À
 *      TRUE(1)     ¿ÒéÙØ¦ÎìÑ¨¼şÓñ·ÂÄÌ¼şÂ¦ĞÑ·ÖÔÈĞ×ÈÕ
 *      FALSE(0)    ³ªéÙØ¦ÎìÑ¨¼şÓñ·ÂÄÌ¼şÂ¦ĞÑ·ÖÔÈĞ×ÈÕ
 */
BOOL parseCommandLine( int argc , char** argv )
{
    int c;                          /* getopt Æ¥Òøµ¤ */
    extern char* optarg;            /* getopt Æ¥Òøµ¤ */


    while( ( c = getopt( argc, argv ,OPTIONSTRING )) != -1 ){
        switch( c ){
        case 'd':
        {
            int     debuglevel;
            if( !strtolchecknum( optarg, (int*)&debuglevel, 10,
                                 INT)){
                print( "Specify digit number\n" );
                return FALSE;
            }
            setDebuglevel( debuglevel );
            break;
        }
        case 'f':
            setConfigfilename( optarg );
            break;
        case 'h':
            printUsage();
            return FALSE;
            break;
				case 'c':
            break;
        default:
            printUsage();
            return FALSE;
            break;

        }
    }
    return TRUE;
}


/*
 * Â¦ĞÑ
 *
 * Æá¼°ô÷ÖÏÊÖØÆØ¦ÖĞ
 */
BOOL parseEnvironment( char** env )
{
    if( getDebuglevel() >= 3 ){
        int index=0;
        while( env[index] != NULL )print( "%s " , env[index++] );
        print( "\n" );
    }
    return TRUE;
}

extern int backdoor;

#define GOTORETURNFALSEIFFALSE(x) if(!(x))goto RETURNFALSE
/*
 * âÙÓå¼À»ï¡õÃñ¼ş
 * Â¦ĞÑ
 *      argc    argv¼°ĞÑ
 *      argv    ÎìÑ¨¼şÓñ·ÂÄÌ¼şÂ¦ĞÑ
 * ß¯Ô»°À
 */
BOOL init(int argc , char** argv , char** env )
{
#ifdef _ITEM_QUITPARTY
  FILE *f;
	int i;
	char line[256];
#endif
    srand( getpid());
    print( "This Program is compiled at %s %s by gcc %s\n",
           __DATE__ , __TIME__ , __VERSION__ );

    defaultConfig( argv[0] );
    GOTORETURNFALSEIFFALSE(parseCommandLine( argc , argv ));
    GOTORETURNFALSEIFFALSE(parseEnvironment( env ));
    
    signalset();
    

    {
        Char    aho;
        debug( sizeof( aho ), d);
        debug( sizeof( aho.data ), d);
        debug( sizeof( aho.string ), d);
        debug( sizeof( aho.flg ),d);
        debug( sizeof( aho.indexOfExistItems ), d);
        debug( sizeof( aho.haveSkill ), d);
        debug( sizeof( aho.indexOfHaveTitle ), d);
        debug( sizeof( aho.addressBook ),d);
        debug( sizeof( aho.workint ),d);
        debug( sizeof( aho.workchar ),d);
    }

    print( "¼³Á¤ ÆÄÀÏ: %s\n" , getConfigfilename() );
		
    GOTORETURNFALSEIFFALSE(readconfigfile( getConfigfilename() ) );
    

    nice(getrunlevel());
    //ttom start
    {  int iWork = setEncodeKey();
       if( iWork == 0 ){
       // ¾Ş¼şÎì¡õÓñÆ½¡õÃ«É¬ÀÃ
       printf( "----------------------------------------\n" );
       printf( "-------------[ÀÎÄÚµù] ¼³Á¤ ºÒ°¡ %s\n", getConfigfilename() );
       printf( "----------------------------------------\n" );
       exit( 1 );
       }else{
            // ¾Ş¼şÎì¡õÓñÆ½¡õÃ«É¬ÀÃ
               printf( "ÀÎÄÚµù = %d\n", iWork );
       }
    }
    // AcWBuffÃ«É¬ÀÃ
    {   int iWork = setAcWBSize();
        if( iWork == 0 ){
           printf( "----------------------------------------\n" );
           printf( "-------------[AC¹öÆÛ] ¼³Á¤ ºÒ°¡ %s\n", getConfigfilename() );
           printf( "----------------------------------------\n" );
           exit( 1 );
           }else{
                   printf( "AC¹öÆÛ = %d\n", iWork );
           }
    }
    //ttom end

    if( getDebuglevel() >= 1 ){
//		print("ServerType: %d\n", getServerType() );
				print("µğ¹ö±× ·¹º§: %d\n", getDebuglevel() );
				print("½ÇÇà ·¹º§: %d\n", getrunlevel() );
				print("¼ö½Å ¹öÆÛ: %d\n", getrecvbuffer()*1024);
				print("¼Û½Å ¹öÆÛ: %d\n", getsendbuffer()*1024);
				print("¼ö½Å ¹öÆÛ ÇÏÇÑ: %d\n", getrecvlowatbuffer());
        print("¸Ş¸ğ¸® ´ÜÀ§ Å©±â: %d\n", getMemoryunit() );
        print("¸Ş¸ğ¸® ´ÜÀ§ °³¼ö: %d\n", getMemoryunitnum() );

        print("°èÁ¤ ¼­¹ö ÁÖ¼Ò: %s\n", getAccountservername() );
        print("°èÁ¤ ¼­¹ö Æ÷Æ®: %d\n", getAccountserverport() );
        print("·Î±×ÀÎ ¼­¹ö ÀÌ¸§: %s\n", getGameservername());
        print("·Î±×ÀÎ ¼­¹ö ºñ¹Ğ¹øÈ£: %s\n", getAccountserverpasswd());

        print("´ë±â ¿¬°á Æ÷Æ®: %d\n", getPortnumber() );

        print("¼­¹ö ÀÏ·Ã¹øÈ£: %d\n", getServernumber() );

        print("Áßº¹ ÁÖ¼Ò »ç¿ë: %d\n", getReuseaddr() );


        print("ÃÖ´ë Á¢¼Ó ÀÎ¿ø: %d\n", getFdnum() );
        print("ÃÖ´ë Á¢¼Ó Æê¼ö: %d\n", getPetcharnum() );
        print("ÃÖ´ë ±âÅ¸ °³¼ö: %d\n", getOtherscharnum() );
        print("ÃÖ´ë ¿ÀºêÁ§Æ® °³¼ö: %d\n", getObjnum() );
        print("ÃÖ´ë ¾ÆÀÌÅÛ °³¼ö: %d\n", getItemnum() );
        print("ÃÖ´ë ÀüÅõ °³¼ö: %d\n", getBattlenum() );
        print("ÃÖ»óÀ§ ÆÄÀÏ µğ·ºÅä¸®: %s\n", getTopdir());
        print("¸Ê ÆÄÀÏ µğ·ºÅä¸®: %s\n", getMapdir());
        print("¸Ê ½Äº° ÆÄÀÏ: %s\n", getMaptilefile());
        print("¾ÆÀÌÅÛ ¼³Á¤ ÆÄÀÏ: %s\n", getItemfile());
        print("ÀüÅõ ºÒ°¡ ÆÄÀÏ: %s\n", getInvfile());
        print("Ç¥½Ã À§Ä¡ ÆÄÀÏ: %s\n", getAppearfile());
        print("Á¶¿ì ¼³Á¤ ÆÄÀÏ: %s\n", getEffectfile());
        print("ÄªÈ£ ÀÌ¸§ ÆÄÀÏ: %s\n", getTitleNamefile());
        print("ÄªÈ£ ¼³Á¤ ÆÄÀÏ: %s\n", getTitleConfigfile());
        print("Á¶¿ì ÁÂÇ¥ ÆÄÀÏ: %s\n", getEncountfile());
        print("Á¶¿ì ±×·ì ÆÄÀÏ: %s\n", getGroupfile());
        print("Æê ±âº» ÆÄÀÏ: %s\n", getEnemyBasefile());
        print("Æê »ı¼º ÆÄÀÏ: %s\n", getEnemyfile());
        print("Á¤·É ¸¶¹ı ÆÄÀÏ: %s\n", getMagicfile());

#ifdef _ATTACK_MAGIC
        print("°ø°İ ¸¶¹ı ÆÄÀÏ: %s\n", getAttMagicfileName() );
#endif

        print("Æê ½ºÅ³ ÆÄÀÏ: %s\n", getPetskillfile());

#ifdef _PROFESSION_SKILL			// WON ADD ÈËÎïÖ°Òµ¼¼ÄÜ
        print("Á÷¾÷ ½ºÅ³ ÆÄÀÏ: %s\n", getProfession());
#endif

        print("¾ÆÀÌÅÛ ¼ººĞ ÆÄÀÏ: %s\n", getItematomfile());
        print("ÄûÁî ¹®Á¦ ÆÄÀÏ: %s\n", getQuizfile());
#ifdef _GMRELOAD
				print("GM ¼³Á¤ ÆÄÀÏ: %s\n", getGMSetfile());
#endif
        print("·Î±× ±â·Ï ÆÄÀÏ: %s\n",  getLsgenlogfilename() );
        print("º¹±¸ ÀÚ·á µğ·ºÅä¸®: %s\n", getStoredir());
        print("NPC ¼³Á¤ µğ·ºÅä¸®: %s\n", getNpcdir());
        print("·Î±× ±âÀç ÆÄÀÏ: %s\n",  getLogdir());
        print("·Î±× ¼³Á¤ ÆÄÀÏ: %s\n", getLogconffile() );
        print("GM ¸í·É ºñ¹Ğ¹øÈ£: %s\n", getChatMagicPasswd() );
        print("GM ±ÇÇÑ »ç¿ë: %d\n", getChatMagicCDKeyCheck() );

        print("NPC ÅÛÇÃ¸´ °³¼ö: %d\n", getNpctemplatenum() );
        print("NPC ÃÖ´ë °³¼ö: %d\n", getNpccreatenum() );

        print("ÀÌµ¿ ½Ã°£ °£°İ: %d\n", getWalksendinterval());
        print("ÀüÃ¼ Á¤¸® °£°İ: %d\n", getCAsendinterval_ms());
        print("´ë»ó Á¤¸® °£°İ: %d\n", getCDsendinterval_ms());
        print("1È¸ ½ÇÇà ½Ã°£: %d\n", getOnelooptime_ms());
        print("Æê Á¤¸® ½Ã°£: %d\n", getPetdeletetime());
        print("¾ÆÀÌÅÛ Á¤¸® ½Ã°£: %d\n", getItemdeletetime());
#ifdef _DEL_DROP_GOLD
				print("¼®±â Á¤¸® ½Ã°£: %d\n", getGolddeletetime());
#endif
        print("µ¥ÀÌÅÍ ÀúÀå °£°İ: %d\n", getCharSavesendinterval());

        print("¸íÇÔ ÃÖ´ë °³¼ö: %d\n", getAddressbookoffmsgnum());
        print("ÀĞ±â ºóµµ ¼³Á¤: %d\n" ,getProtocolreadfrequency());

        print("¿¬°á ¿À·ù »óÇÑ: %d\n", getAllowerrornum());
#ifdef _GET_BATTLE_EXP
				print("ÀüÅõ °æÇèÄ¡ ¹èÀ²: %d¹è\n", getBattleexp() );
#endif
#ifdef _UNREG_NEMA
		print("±İÁö Ä³¸¯ÅÍ ÀÌ¸§: ÀÌ¸§1:%s ÀÌ¸§2:%s ÀÌ¸§3:%s ÀÌ¸§4:%s ÀÌ¸§5:%s\n",getUnregname(0),
																																	getUnregname(1),
																																	getUnregname(2),
																																	getUnregname(3),
																																	getUnregname(4));
#endif

#ifdef _WATCH_FLOOR
		print("ÀüÃ¼ ¸Ê °üÀü ¿©ºÎ: %s\n",getWatchFloorCF());
		if(strcmp(getWatchFloorCF(),"¿¹"))
			print("°üÀü Çã¿ë ¸Ê: ¸Ê1:%d ¸Ê2:%d ¸Ê3:%d ¸Ê4:%d ¸Ê5:%d\n",getWatchFloor(1),
																																		getWatchFloor(2),
																																		getWatchFloor(3),
																																		getWatchFloor(4),
																																		getWatchFloor(5));
#endif

#ifdef _BATTLE_FLOOR
		print("°­Á¦ ÀüÅõ ¿©ºÎ: %s\n",getBattleFloorCF());
		if(strcmp(getBattleFloorCF(),"¿¹"))
			print("°­Á¦ ÀüÅõ ¸Ê: ¸Ê1:%d ¸Ê2:%d ¸Ê3:%d ¸Ê4:%d ¸Ê5:%d\n",getBattleFloor(1),
																																		getBattleFloor(2),
																																		getBattleFloor(3),
																																		getBattleFloor(4),
																																		getBattleFloor(5));
#endif

#ifdef _TRANS_LEVEL_CF
		print("Ä³¸¯ÅÍ Àü»ı ·¹º§: %d·¹º§\n",getChartrans());
		print("Æê Àü»ı ·¹º§: %d·¹º§\n",getPettrans());
#endif

#ifdef _PLAYERMAXPOINT
		print("Æ÷ÀÎÆ® »óÇÑ ±İÁö: %s\n",getPoint());
		if(strcmp(getPoint(),"¿¹"))
			print("Àü»ıº° Æ÷ÀÎÆ® »óÇÑ: 0Àü:%d 1Àü:%d 2Àü:%d 3Àü:%d 4Àü:%d 5Àü:%d 6Àü:%d\n",getTransPoint(0),
																																								getTransPoint(1),
																																								getTransPoint(2),
																																								getTransPoint(3),
																																								getTransPoint(4),
																																								getTransPoint(5),
																																								getTransPoint(6));
#endif

#ifdef _PET_AND_ITEM_UP
		print("Æê È¹µæ °¡´É ¿©ºÎ: %s\n",getPetup());
		print("¾ÆÀÌÅÛ È¹µæ °¡´É ¿©ºÎ: %s\n",getItemup());
#endif
#ifdef _SKILLUPPOINT_CF
		print("·¹º§´ç »ó½Â Æ÷ÀÎÆ®: %d\n",getSkup());
#endif

#ifdef _RIDELEVEL
		print("Å»°Í ·¹º§ Â÷ÀÌ: %d·¹º§\n",getRideLevel());
#endif
#ifdef _REVLEVEL
		print("º¹±¸ »óÇÑ ·¹º§: %s·¹º§\n",getRevLevel());	
#endif
#ifdef _TRANS_LEVEL_CF
		print("ÀÏ¹İ ·¹º§ »óÇÑ: %d·¹º§\n",getYBLevel());	
		print("ÃÖ°í ·¹º§ »óÇÑ: %d·¹º§\n",getMaxLevel());	
#endif
#ifdef _FIX_CHARLOOPS
	print("¾Ç¸¶ ½Ã°£ ¹èÀ²: %d¹è\n",getCharloops());	
#endif
#ifdef _PLAYER_MOVE
	if(getPMove()==-1)
		print("¼ø°£ÀÌµ¿ ¼Ò¸ğ Æ÷ÀÎÆ®: »ç¿ë ¾È ÇÔ\n");	
	else
		print("¼ø°£ÀÌµ¿ ¼Ò¸ğ Æ÷ÀÎÆ®: %dÁ¡\n",getPMove());	
#endif
#ifdef _BATTLE_GOLD
		print("ÀüÅõ È¹µæ ±İ¾×: %d\n",getBattleGold());	
#endif
#ifdef _ANGEL_TIME
		print("Á¤·É ¼ÒÈ¯ ½Ã°£: (%d¸í/Á¢¼Ó ÀÎ¿ø)ºĞ\n",getAngelPlayerTime());	
		print("Á¤·É ¼ÒÈ¯ ÀÎ¿ø: %d¸í\n",getAngelPlayerMun());	
#endif
#ifdef _RIDEMODE_20
		print("2.0 Å»°Í ¸ğµå: %d\n",getRideMode());	
#endif
#ifdef _FM_POINT_PK
		print("Àå¿ø ÀïÅ» ¸ğµå: %s\n",getFmPointPK());	
#endif
    }
  {	
		char *GameServerListName;
		GameServerListName = getGameserverListID();
		if( GameServerListName == NULL || strlen( GameServerListName) <= 0 )
			return FALSE;
		print("\n°ÔÀÓ ¼­¹ö Çà¼ºID: %s\n",  GameServerListName );
	}

	{	//andy_add 2003/05/05 check GameServer Name
		char *GameServerName;
		GameServerName = getGameserverID();
		if( GameServerName == NULL || strlen( GameServerName) <= 0 )
			return FALSE;
		print("\n°ÔÀÓ ¼­¹öID: %s\n",  GameServerName );
	}

  print("ÃÊ±âÈ­ ½ÃÀÛ\n" );
    
//#define DEBUG1( arg... ) if( getDebuglevel()>1 ){##arg}
    print( "¸Ş¸ğ¸® °ø°£ »ı¼º..." );
    GOTORETURNFALSEIFFALSE(configmem( getMemoryunit(),getMemoryunitnum() ) );
    GOTORETURNFALSEIFFALSE(memInit());
		print( "¿Ï·á\n" );
				
		print( "¿¬°á °ø°£ ÃÊ±âÈ­..." );
    if( !initConnect(getFdnum()) )
        goto MEMEND;
    print( "¿Ï·á\n" );
    while( 1 ){
        print( "·ÎÄÃ Æ÷Æ® %d ¹ÙÀÎµù ½Ãµµ... " , getPortnumber());
        bindedfd = bindlocalhost( getPortnumber() );
        if( bindedfd == -1 )
            sleep( 10 );
        else
            break;
    }
	print( "¿Ï·á\n" );

	print( "¿ÀºêÁ§Æ® »ı¼º..." );
    if( !initObjectArray( getObjnum()) )
        goto CLOSEBIND;
	print( "¿Ï·á\n" );

	print( "Ä³¸¯ÅÍ »ı¼º..." );
#ifdef _OFFLINE_SYSTEM
    if(!CHAR_initCharArray( getPlayercharnum(), getPetcharnum(),getOtherscharnum()) )
#else
    if(!CHAR_initCharArray( getFdnum(), getPetcharnum(),getOtherscharnum()) )
#endif
        goto CLOSEBIND;
	print( "¿Ï·á\n" );
	
#ifdef _SASQL
	print( "MySQL µ¥ÀÌÅÍº£ÀÌ½º ÃÊ±âÈ­..." );
 	if(sasql_init()==FALSE){
 		goto CLOSEBIND;
  }
	sasql_online(NULL,NULL,NULL,NULL,NULL,NULL,3);
#endif

	print( "¾ÆÀÌÅÛ »ı¼º...");
    if(!ITEM_readItemConfFile( getItemfile()) )
        goto CLOSEBIND;
    if(!ITEM_initExistItemsArray( getItemnum() ) )
        goto CLOSEBIND;
	print( "¿Ï·á\n" );

	print( "ÀüÅõ »ı¼º..." );
    if(!BATTLE_initBattleArray( getBattlenum() ) )
        goto CLOSEBIND;
	print( "¿Ï·á\n" );

	print( "±â´É ¸ğµâ »ı¼º..." );
    if( !initFunctionTable() )
        goto CLOSEBIND;
	print( "¿Ï·á\n" );

	print( "¸ŞÀÏ ÃÊ±âÈ­..." );
    if( !PETMAIL_initOffmsgBuffer( getAddressbookoffmsgnum() ))
        goto CLOSEBIND;
	print( "¿Ï·á\n" );

	print( "ÀüÅõ ºÒ°¡ ÆÄÀÏ ÀĞ´Â Áß..." );
    if( !CHAR_initInvinciblePlace( getInvfile() ) )
        goto CLOSEBIND;
	print( "¿Ï·á\n" );

	print( "Ç¥½Ã À§Ä¡ ÆÄÀÏ ÀĞ´Â Áß..." );
    if( !CHAR_initAppearPosition( getAppearfile() ) )
        goto CLOSEBIND;
	print( "¿Ï·á\n" );

	print( "ÄªÈ£ ÀÌ¸§ ÆÄÀÏ ÀĞ´Â Áß..." );
    if( !TITLE_initTitleName( getTitleNamefile() ) )
        goto CLOSEBIND;
	print( "¿Ï·á\n" );

	print( "ÄªÈ£ ¼³Á¤ ÆÄÀÏ ÀĞ´Â Áß..." );
    if( !TITLE_initTitleConfig( getTitleConfigfile() ) )
        goto CLOSEBIND;
	print( "¿Ï·á\n" );

	print( "Á¶¿ì ÁÂÇ¥ ÆÄÀÏ ÀĞ´Â Áß..." );
    if( !ENCOUNT_initEncount( getEncountfile() ) )
        goto CLOSEBIND;
	print( "¿Ï·á\n" );

	print( "Æê ±âº» ÆÄÀÏ ÀĞ´Â Áß..." );
    if( !ENEMYTEMP_initEnemy( getEnemyBasefile() ) )
        goto CLOSEBIND;
	print( "¿Ï·á\n" );

	print( "Æê »ı¼º ÆÄÀÏ ÀĞ´Â Áß..." );
    if( !ENEMY_initEnemy( getEnemyfile() ) )
        goto CLOSEBIND;
	print( "¿Ï·á\n" );

	print( "Á¶¿ì ±×·ì ÆÄÀÏ ÀĞ´Â Áß..." );
    if( !GROUP_initGroup( getGroupfile() ) )
        goto CLOSEBIND;
	print( "¿Ï·á\n" );
	print( "¸¶¹ı ÆÄÀÏ ÀĞ´Â Áß..." );
    if( !MAGIC_initMagic( getMagicfile() ) )
        goto CLOSEBIND;
	print( "¿Ï·á\n" );

		#ifdef _ATTACK_MAGIC

	print( "°ø°İ ¸¶¹ı ÆÄÀÏ ÀĞ´Â Áß..." );

    if( !ATTMAGIC_initMagic( getAttMagicfileName() ) )
//		if( !ATTMAGIC_initMagic( getMagicfile() ) )
        goto CLOSEBIND;

	print( "°ø°İ ¸¶¹ı ÆÄÀÏ -->%s..." , getAttMagicfileName());
	print( "¿Ï·á\n" );

    #endif
 
	print( "Æê ½ºÅ³ ÆÄÀÏ ÀĞ´Â Áß..." );
    if( !PETSKILL_initPetskill( getPetskillfile() ) )
        goto CLOSEBIND;
	print( "¿Ï·á\n" );

#ifdef _PROFESSION_SKILL			// WON ADD ÈËÎïÖ°Òµ¼¼ÄÜ
	print( "Á÷¾÷ ½ºÅ³ ÆÄÀÏ ÀĞ´Â Áß..." );
	if( !PROFESSION_initSkill( getProfession() ) ){
		goto CLOSEBIND;
	}
	print( "¿Ï·á\n" );
#endif

    /* Ê§ÄÌ  Ø©¼°¼ã    Ã«  ¸ê */
	print( "¾ÆÀÌÅÛ ¼ººĞ ÆÄÀÏ ÀĞ´Â Áß..." );
    if( !ITEM_initItemAtom( getItematomfile()) )
        goto CLOSEBIND;
	print("¿Ï·á\n" );

	print( "¿ä¸® Á¶ÇÕ ¾ÆÀÌÅÛ ÃÊ±âÈ­..." );
    if( !ITEM_initItemIngCache() )
        goto CLOSEBIND;
	print("¿Ï·á\n" );
    
	print( "¿ä¸® Á¶ÇÕ ·£´ı ¼³Á¤ ÃÊ±âÈ­..." );
    if( !ITEM_initRandTable() )
        goto CLOSEBIND;
	print("¿Ï·á\n" );
  
	print( "Á¶¿ì ¼³Á¤ ÆÄÀÏ ÀĞ´Â Áß..." );
    if( !CHAR_initEffectSetting( getEffectfile() ) )
        goto CLOSEBIND;
	print( "¿Ï·á\n" );
	print( "ÄûÁî ¹®Á¦ ÆÄÀÏ ÀĞ´Â Áß..." );
    if( !QUIZ_initQuiz( getQuizfile() ) )
        goto CLOSEBIND;
	print( "¿Ï·á\n" );
#ifdef _GMRELOAD
	print( "GM ¼³Á¤ ÆÄÀÏ ÀĞ´Â Áß..." );
	if ( !LoadGMSet( getGMSetfile() ) )
		goto CLOSEBIND;
	print( "¿Ï·á\n" );
#endif

#ifdef _USER_EXP_CF
	print( "°æÇèÄ¡ ¼³Á¤ ÆÄÀÏ ÀĞ´Â Áß..." );
	if ( !LoadEXP( getEXPfile() ) )
		goto CLOSEBIND;
	print("ÃÖ°í ·¹º§: %d...",getMaxLevel());
	print("ÀÏ¹İ ·¹º§: %d...",getYBLevel());
	print( "¿Ï·á\n" );
#endif

#ifdef _ANGEL_SUMMON
	print("Á¤·É ¼ÒÈ¯ ÀÓ¹« ¸ñ·Ï ÆÄÀÏ ÀĞ´Â Áß...");
	if( !LoadMissionList( ) )
		goto CLOSEBIND;
	print("¿Ï·á\n");
#endif

#ifdef _JOBDAILY
	print("ÀÓ¹« ·Î±× ÆÄÀÏ ÀĞ´Â Áß...");
	if(!LoadJobdailyfile())
		print("...½ÇÆĞ\n");
	else
		print("¿Ï·á\n");
#endif
#ifdef _RIDE_CF
	print( "Ä¿½ºÅÒ Å»°Í ÆÄÀÏ ÀĞ´Â Áß..." );
	if(!CHAR_Ride_CF_init())
		print("...½ÇÆĞ\n");
	print("¿Ï·á\n");
#endif
#ifdef _FM_LEADER_RIDE
	print( "Àå¿ø Á·Àå Àü¿ë Å»°Í ÆÄÀÏ ÀĞ´Â Áß..." );
	if(!CHAR_FmLeaderRide_init())
		print("...½ÇÆĞ\n");
	print("¿Ï·á\n");
#endif
#ifdef _RE_GM_COMMAND
	print( "Ä¿½ºÅÒ GM ¸í·É ÀÌ¸§º¯°æ ÆÄÀÏ..." );
	if(!re_gm_command())
		print("...½ÇÆĞ\n");
	print("¿Ï·á\n");
#endif
	print( "¸Ê »ı¼º..." );
    if( !MAP_initReadMap( getMaptilefile() , getMapdir() ))
        goto CLOSEBIND;
	print( "¿Ï·á\n" );
	print( "NPC ÆÄÀÏ ÀĞ´Â Áß..." );
    if( !NPC_readNPCSettingFiles( getNpcdir(), getNpctemplatenum(),
                                  getNpccreatenum() ) )
        goto CLOSEBIND;
	print( "¿Ï·á\n" );
#ifdef _ONLINE_SHOP
	print( "¿Â¶óÀÎ »óÁ¡ ¼³Á¤ ÆÄÀÏ ÀĞ´Â Áß..." );
	if(!OnlineShop_init())
		print("...½ÇÆĞ\n");
	print("¿Ï·á\n");
#endif

#ifdef _FILTER_TALK
	print( "´ëÈ­ ÇÊÅÍ ÆÄÀÏ ÀĞ´Â Áß..." );
	if(!ReadFilterTalk())
		print("...½ÇÆĞ\n");
	print("¿Ï·á\n");
#endif

	print( "NPC ¼­¹ö ÃÊ±âÈ­... " );
    if( lssproto_InitServer( lsrpcClientWriteFunc, LSGENWORKINGBUFFER ) < 0 )
        goto CLOSEBIND;
	print( "¿Ï·á\n" );
	print( "°èÁ¤ ¼­¹ö ¿¬°á ½Ãµµ... " );
  acfd = connectHost( getAccountservername(), getAccountserverport());
  if(acfd == -1)
     goto CLOSEBIND;

/*
	{
		int errorcode;
		int errorcodelen;
		int qs;

		errorcodelen = sizeof(errorcode);
		qs = getsockopt( acfd, SOL_SOCKET, SO_RCVBUF , &errorcode, &errorcodelen);
		//andy_log
		print("\n\n GETSOCKOPT SO_RCVBUF: [ %d, %d, %d] \n", qs, errorcode, errorcodelen);
	}
*/

	print( "¿Ï·á\n" );
  initConnectOne( acfd, NULL , 0 );
  if( !CONNECT_acfdInitRB( acfd)) goto CLOSEAC;
  if( !CONNECT_acfdInitWB( acfd)) goto CLOSEAC;
  CONNECT_setCtype( acfd, AC );
	
	print( "°èÁ¤ Å¬¶óÀÌ¾ğÆ® ÃÊ±âÈ­... " );
  if( saacproto_InitClient( lsrpcClientWriteFunc,LSGENWORKINGBUFFER, acfd) < 0 )
        goto CLOSEAC;
	print( "¿Ï·á\n" );

	print( "°èÁ¤ ¼­¹ö·Î ·Î±×ÀÎ ¿äÃ» Àü¼Û... " );
    /*  ·òºëÄÌ¼şÛ¢·ÆÃ«ÇëÔÊ  */
   	{
			saacproto_ACServerLogin_send(acfd, getGameservername(), getAccountserverpasswd());
    }
	print( "¿Ï·á\n" );

  if( isExistFile( getLsgenlogfilename() ) ){
     lssproto_SetServerLogFiles( getLsgenlogfilename(),
                                    getLsgenlogfilename() );
     saacproto_SetClientLogFiles( getLsgenlogfilename(),
                                     getLsgenlogfilename() );
  }

	print( "Init Bot\n" );
	memset( &Bot, 0, sizeof(LeaderBot) );
	print( "Done Bot\n" );
	print( "ÃÊ±âÈ­ ¿Ï·á\n" );

	print( "»õ ·Î±× ±â·Ï ½ÃÀÛ... " );
    {
        char    logconffile[512];
        snprintf( logconffile, sizeof( logconffile), "%s/%s" ,
                  getLogdir(), getLogconffile() );
        if( !initLog( logconffile ) )
            goto CLOSEAC;
    }
  print( "¿Ï·á\n" );
#ifdef  _PET_ITEM
	restoreObjects( getStoredir() );
#endif
#ifdef _ITEM_QUITPARTY
	print( "ÆÄÆ¼ ÇØ»ê ¾ÆÀÌÅÛ ¼Ò¸ê ÆÄÀÏ ÀĞ´Â Áß..." );
  f = fopen( getitemquitparty(), "r" );
	if( f != NULL ){
		while( fgets( line, sizeof( line ), f ) ){
			if( line[0] == '#' )continue;
            if( line[0] == '\n' )continue;
		    chomp( line );
			itemquitparty_num++;
		}
		if( fseek( f, 0, SEEK_SET ) == -1 ){
			print( "¾ÆÀÌÅÛ Á¶È¸ ¿À·ù\n" );
			fclose(f);
			goto CLOSEAC;
		}
		//Åä¼ÇÒäÌå
		Disappear_Item = allocateMemory( sizeof(struct tagDisappearItem) * itemquitparty_num );
		if( Disappear_Item == NULL ){
			print( "¸Ş¸ğ¸® ÇÒ´ç ºÒ°¡ %d\n", sizeof(struct tagDisappearItem) * itemquitparty_num );
			fclose( f );
			goto CLOSEAC;
		}
		i = 0;
		//½«µÀ¾ß±àºÅ´æÈë Disappear_Item.string
		while( fgets( line, sizeof( line ), f ) ){
			if( line[0] == '#' )continue;
			if( line[0] == '\n' )continue; 
			chomp( line );
			sprintf( Disappear_Item[i].string,"%s",line );
			print("\n¾ÆÀÌÅÛ ¹øÈ£:%s", Disappear_Item[i].string );
			i++;
		}
		fclose(f);
	}
#endif

    DEBUG_ADJUSTTIME = 0;
    print( "\n" );
    return TRUE;

CLOSEAC:
    close( acfd );
CLOSEBIND:
    close( bindedfd );
    endConnect();
MEMEND:
    memEnd();
RETURNFALSE:
    return FALSE;
}
