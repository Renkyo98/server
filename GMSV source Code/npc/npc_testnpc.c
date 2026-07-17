#include "version.h"
#include "object.h"
#include "char_base.h"
#include "char.h"
#include "npc_testnpc.h"
#include "util.h"
#include "handletime.h"
#include "anim_tbl.h"
#include "npc_door.h"
#include "lssproto_serv.h"
#include "npcutil.h"

#ifdef _CHAR_TESTNPC
void NPC_TestNpcTalked( int index, int talker, char *msg, int color )
{
	char arg[NPC_UTIL_GETARGSTR_BUFSIZE], token[NPC_UTIL_GETARGSTR_LINEMAX];
    int i, tokennum;


	if( CHAR_getInt(talker,CHAR_WHICHTYPE) == CHAR_TYPEPLAYER 
        && NPC_Util_charIsInFrontOfChar( talker, index, 3 ) ){

        NPC_Util_GetArgStr( index, arg, sizeof( arg));

        tokennum = 1;
        for( i=0;arg[i]!='\0';i++ ){
            if( arg[i] == ',' ) tokennum++;
        }

        getStringFromIndexWithDelim( arg,",",
                                     rand()%tokennum+1,token, sizeof(token));

        CHAR_talkToCli( talker, index, token, CHAR_COLORWHITE );
    }
}

BOOL NPC_TestNpcInit( int meindex )
{
    CHAR_setInt( meindex , CHAR_WHICHTYPE , CHAR_TYPEPLAYER );
    return TRUE;
}

#endif