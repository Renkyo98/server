#include "version.h"
#include <string.h>
#include "char.h"
#include "object.h"
#include "char_base.h"
#include "npcutil.h"
#include "lssproto_serv.h"
#include "npc_charm.h"

//    Ò½Ã«  ÈÊ»ÍÒ£Ö¿·´

//ÒÁÃ¬»ï¡û        ¡û  òØ»þ¼°    /          

//¼ÔãâÐÚ·´£û¨äÆ¥ÔÊ£Û
/*
#define RATE  4		//ÒÁ¡õÐþ£¢
#define CHARMHEAL 5 //    ¼°¼ÔãâÐÚ
#define WARU	3	//    Ã«à«ÔÂ°À

*/

#define RATE  10	//ÒÁ¡õÐþ£¢
#define CHARMHEAL 5 //    ¼°¼ÔãâÐÚ
#define WARU	3	//    Ã«à«ÔÂ°À


static void NPC_Charm_selectWindow( int meindex, int toindex, int num);
int NPC_CharmCost(int meindex,int talker);
void NPC_CharmUp(int meindex,int talker);


/*********************************
* âÙÓåÖÊ  
*********************************/
BOOL NPC_CharmInit( int meindex )
{
	/*--Æ½ÅÒ·Â¼°ÕýÄÌÃóÃ«É¬ÀÃ--*/
    CHAR_setInt( meindex , CHAR_WHICHTYPE , CHAR_TYPECHARM );
	return TRUE;

}


/*********************************
*   ØÆ¾®ØêÈÕÄ¾Ð×ÁÝ¼°ÖÊ  
*********************************/
void NPC_CharmTalked( int meindex , int talkerindex , char *szMes ,int color )
{

    /* ÃóÒÁÄÌØÀ¡õ±å¸²ØÆ»¯·ÖØê  É±ÔÊÔÂ */
    if( CHAR_getInt( talkerindex , CHAR_WHICHTYPE ) != CHAR_TYPEPLAYER )
    {
    	return;
    }
	
	/*--  ¼°ó¡±åÖÐÔÂ¾®Éýµ¤¾®£¢--*/
	if(NPC_Util_isFaceToFace( meindex ,talkerindex , 2) == FALSE) {
		/* ¨àºëØøÓÀÓñ¶¯  ¼°ÐÄ */
		if(NPC_Util_isFaceToChara( talkerindex, meindex, 1) == FALSE) return;
	}

	NPC_Charm_selectWindow( meindex, talkerindex, 0);
}


/*
 * ±¸ÖÊ  ±åÛÐØêÔÂ
 */
static void NPC_Charm_selectWindow( int meindex, int toindex, int num)
{

	char token[1024];
	char escapedname[1024];
	int fd = getfdFromCharaIndex( toindex);
	int buttontype = 0;
	int windowtype = 0;
	int windowno = 0;
	int cost = 0;
	int chartype;
	
	/*--ËüÄÌ¼þÓñËüÕýÄÌÃó¶ªÓÀ±¾¡õ³â»¥ÔÆÔÆÖÐ¼°Æ¥ÛÆ±åÉ¬ÀÃ--*/
  	windowtype = WINDOW_MESSAGETYPE_MESSAGE;

	switch( num) {
	  case 0:
  		/*--¼»      --*/
		sprintf(token,"4\n ¡¡¡¡¡¡       ¹Ì¿ë°ü¸®»ç     "
				     "\n\n ¡¡¹«½¼ÀÏÀÌ¾ß£¬¸Å·ÂÀ» ¿Ã¸®·Á±¸£¿"
				  "\n "
				  "\n\n¡¡¡¡¡¡¡¡¡¶¡¡¸Å·ÂÈ¸º¹¡¡¡· "
				  "\n\n¡¡¡¡¡¡¡¡¡¶ ³ª°¡±â ¡· "
		);

	  	buttontype = WINDOW_BUTTONTYPE_NONE;
	  	windowtype = WINDOW_MESSAGETYPE_SELECT;
	  	windowno = CHAR_WINDOWTYPE_CHARM_START; 
	  	break;

	case 1:
		cost = NPC_CharmCost( meindex, toindex);
		if(cost == -1){
			sprintf(token,"¡¡¡¡¡¡¡¡         ¹Ì¿ë°ü¸®»ç      "
				      "\n\n¡¡¡¡¡¡¡¡¸Å·ÂÀ» ¿Ã¸± ÇÊ¿ä°¡ ¾ø¾î"
				      "\n\n¡¡¡¡¡¡¿ÏÀü ¸ÚÀÖ´Â´ë!!?"
			);
		  	buttontype = WINDOW_BUTTONTYPE_OK;
		}else{
			sprintf(token,"¡¡¡¡¡¡¡¡         ¹Ì¿ë°ü¸®»ç       "
				 	    "\n¡¡¸Å·ÂÀ» ¿Ã¸±²¨¾ß??"
					  "\n\n ¸Å·ÂÀ» ¿Ã¸®·Á¸é ½ºÅæÀÌ ÇÊ¿äÇØ"
					  "\n¡¡¡¡¡¡¡¡±Ý¾×:%6dstoneÀÌ¾ß£¡"
						"\n\n¡¡¡¡¡¡±×·¡µµ ¿Ã¸±²¨¾ß£¿",cost
			);
		  	buttontype = WINDOW_BUTTONTYPE_YESNO;

		}
	  	windowtype = WINDOW_MESSAGETYPE_MESSAGE;
	  	windowno = CHAR_WINDOWTYPE_CHARM_END; 

		break;

	case 2:
		cost = NPC_CharmCost( meindex, toindex);
		chartype = CHAR_getInt( toindex, CHAR_IMAGETYPE);
		
		if(cost > CHAR_getInt( toindex, CHAR_GOLD)) {
			sprintf(token,"¡¡¡¡¡¡¡¡         ¹Ì¿ë°ü¸®»ç      "
					  "\n\n¡¡¡¡ ½ÇÆÐ!¼ÒÁö±Ý ºÎÁ·£¡"
				        "\n¡¡¡¡    ¸Å·ÂÀ» ¿Ã¸®·Á¸é µ·ÀÌ ÇÊ¿äÇØ£¡"
			);

		}else{
			NPC_CharmUp( meindex, toindex);

			/*--Æ½ÅÒ·Â¼°ÕýÄÌÃó±å·½ÔÈ»¯¶ªÓÀ±¾¡õ³âÃ«  Òü»¯ÐÄÐ×--*/
			switch( chartype) {
			  case CHAR_IMAGETYPE_GIRL:
				sprintf(token,"¡¡¡¡¡¡¡¡         ¹Ì¿ë°ü¸®»ç       "
					  "\n\n ¡¡¸Å·Â 5°¡ Áõ°¡µÇ¾ú½À´Ï´Ù£¡"
					  "\n\n¡¡¡¡¡¡¿ÏÀü ÀÌ»Û´ë£¡"
				);

				break;
			  case CHAR_IMAGETYPE_BOY:
				sprintf(token,"¡¡¡¡¡¡¡¡         ¹Ì¿ë°ü¸®»ç     "
					  "\n\n ¡¡¸Å·Â 5°¡ Áõ°¡µÇ¾ú½À´Ï´Ù£¡"
					  "\n\n¡¡¡¡¿ÏÀü ¸ÚÁ®º¸¿© £¡"
				);
			  	break;
			  	
			  case CHAR_IMAGETYPE_CHILDBOY:
			  case CHAR_IMAGETYPE_CHILDGIRL:
				sprintf(token,"¡¡¡¡¡¡¡¡         ¹Ì¿ë°ü¸®»ç      "
					  "\n\n ¡¡¸Å·Â 5°¡ Áõ°¡µÇ¾ú½À´Ï´Ù£¡"
					  "\n\n¡¡¡¡  Å°°¡ ÀÚ¶ú±¸³ª£¡"
				);
			 	break;
			 	
			   case CHAR_IMAGETYPE_MAN:
				sprintf(token,"¡¡¡¡¡¡¡¡         ¹Ì¿ë°ü¸®»ç       "
					  "\n\n ¡¡¸Å·Â 5°¡ Áõ°¡µÇ¾ú½À´Ï´Ù£¡"
					  "\n\n ¡¡¡¡¡¡¸ÚÀÖ¾î¿ä£¡"
				);
			 	break;
			 	
			   case CHAR_IMAGETYPE_WOMAN:
				sprintf(token,"¡¡¡¡¡¡¡¡         ¹Ì¿ë°ü¸®»ç      "
				  "\n\n ¡¡¸Å·Â 5°¡ Áõ°¡µÇ¾ú½À´Ï´Ù£¡"
				  "\n\n    ÈÎ¾À Àþ¾îÁö¼Ì³×¿ä£¡"
				);
			 	break;
			 
			 }
		}

		buttontype = WINDOW_BUTTONTYPE_OK;
		windowtype = WINDOW_MESSAGETYPE_MESSAGE;
	  	windowno = CHAR_WINDOWTYPE_CHARM_END; 
		break;
	}
	
	makeEscapeString( token, escapedname, sizeof( escapedname));
	/*-³ð³ðÆ¥ËªññÔÊÔÂ--*/
	lssproto_WN_send( fd, windowtype, 
					buttontype, 
					windowno,
					CHAR_getWorkInt( meindex, CHAR_WORKOBJINDEX),
					escapedname);

}


/*-----------------------------------------
ÛÍ·ÂÄÌÊ§¼þÐþ¾®ÈÕß¯ÔÈ»¯ÎåÐ×ÁÝ±åôÄÌ«Çë½ñÄ¾ÔÂ£Û
-------------------------------------------*/
void NPC_CharmWindowTalked( int meindex, int talkerindex, 
								int seqno, int select, char *data)
{
	if( NPC_Util_CharDistance( talkerindex, meindex ) > 2) return;

	switch( seqno){
	  case CHAR_WINDOWTYPE_CHARM_START:
	  	if(atoi( data) == 2) {
			NPC_Charm_selectWindow( meindex, talkerindex, 1 );
		}
		break;

	  case CHAR_WINDOWTYPE_CHARM_END:
	  	if(select == WINDOW_BUTTONTYPE_YES) {
			NPC_Charm_selectWindow( meindex, talkerindex, 2 );
		}
		break;
	}
	
}



/*--        --*/
void NPC_CharmUp(int meindex,int talker)
{
	int cost;
	int i;
	int petindex;
	char petsend[64];	

	/*--ÔÆàÅÃ«Ó¼ÈÕØÆÒýØÆ½ïµ¤--*/
	cost = NPC_CharmCost( meindex, talker);
	CHAR_setInt( talker, CHAR_GOLD,
			CHAR_getInt( talker, CHAR_GOLD) - cost);
	CHAR_send_P_StatusString( talker, CHAR_P_STRING_GOLD);

	/*--    »¥¨à¨ß¨ß¶¯Ïþ±åØ¦ÔÂèëÄþ·´ÐÛÂ¦±å¨à¨ß¨ß±åÔÊÔÂ--*/
	if(CHAR_getInt( talker, CHAR_CHARM) + CHARMHEAL >= 100) {
		CHAR_setInt( talker, CHAR_CHARM, 100);
	}else{
		/*--    Ã«±¾ÓÀÐþ--*/
		CHAR_setInt(talker, CHAR_CHARM,
	 			(CHAR_getInt( talker, CHAR_CHARM) + CHARMHEAL));
	}
	
	/*--µ©  ¡õÕýµ©¼°µÊÞ¥--*/
	CHAR_complianceParameter( talker );
	CHAR_send_P_StatusString( talker, CHAR_P_STRING_CHARM);


	/*--Ê¸ÓÀÐþ¼°ÓÉ·Â¶ª¡õÕýÃ«µÊÞ¥--*/
	for( i = 0 ; i < CHAR_MAXPETHAVE ; i++){
    	petindex = CHAR_getCharPet( talker, i);

		if( petindex == -1  )  continue;

	   /*  Æ½ÅÒ·Â¼°    ÃñÄáÓÀÛÍ    */
		if( !CHAR_CHECKINDEX( talker ) )  continue;

		/*--ÓÉ·Â¶ª¡õÕýÆ©°ï--*/
		CHAR_complianceParameter( petindex );
		sprintf( petsend, "K%d", i );
		CHAR_sendStatusString( talker , petsend );
	}
}


/*--ÔÆàÅ¼°»ÍÒ£--*/
int NPC_CharmCost(int meindex,int talker)
{
	int cost;
	int level;
	int charm;
	int trans;

	level = CHAR_getInt( talker, CHAR_LV);
	charm = CHAR_getInt( talker, CHAR_CHARM);
	trans = CHAR_getInt( talker, CHAR_TRANSMIGRATION);

	if(charm >= 100) return -1;
	
	if(charm <= 1) charm = WARU;
	
	/*-- »ÍÒ£Ö¿ --*/
	cost = level * RATE * (charm / WARU) * (trans+1);

	return cost;

}
