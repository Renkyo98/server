#include "version.h"
#define __NPCCREATE__

#include <stdio.h>
#include <string.h>

#include "common.h"
#include "npccreate.h"
#include "npctemplate.h"
#include "util.h"
#include "buf.h"
#include "readmap.h"
#include "char_data.h"
#include "handletime.h"
#include "configfile.h"
#include "autil.h"

INLINE int NPC_CHECKCREATEINDEX(int index)
{
    if(  NPC_createnum <= index || index < 0 )return FALSE;
    return TRUE;
}

INLINE int NPC_CHECKCREATEINTINDEX( int index)
{
    if(  NPC_CREATEINTNUM <= index || index < 0 )return FALSE;
    return TRUE;
}

INLINE int NPC_setCreateInt( int index , NPC_CREATEINT element, int data )
{
    int buf;
    buf = NPC_create[index].intdata[element];
    NPC_create[index].intdata[element] = data;
    return buf;
}

INLINE int NPC_getCreateInt( int index , NPC_CREATEINT element )
{
    return NPC_create[index].intdata[element];
}


BOOL NPC_initCreateArray( int createnum )
{
    NPC_createnum = createnum;
    NPC_create  = (NPC_Create*)allocateMemory( sizeof( NPC_Create ) * NPC_createnum );

	print( "¿ÀÇÂ Å©±â:%d. »ý¼º °³¼ö:%d.\n", sizeof( NPC_Create ), createnum);
    if( NPC_create == NULL ){
		return FALSE;
	}
    NPC_create_readindex = 0;
    return TRUE;
}

void NPC_setDefaultNPCCreate( NPC_Create*  cr )
{
    if( cr == NULL )return;

    cr->intdata[NPC_CREATEFLOORID]=0;
    cr->intdata[NPC_CREATEBORNLEFTUPX]=0;
    cr->intdata[NPC_CREATEBORNLEFTUPY]=0;
    cr->intdata[NPC_CREATEBORNRIGHTDOWNX]=0;
    cr->intdata[NPC_CREATEBORNRIGHTDOWNY]=0;
    cr->intdata[NPC_CREATEMOVELEFTUPX]=0;
    cr->intdata[NPC_CREATEMOVELEFTUPY]=0;
    cr->intdata[NPC_CREATEMOVERIGHTDOWNX]=0;
    cr->intdata[NPC_CREATEMOVERIGHTDOWNY]=0;

    cr->intdata[NPC_CREATEDIR]=0;
	//jeffrey 1231
#ifdef _ADD_ACTION
	cr->intdata[NPC_CREATEACTION] = 0;
#endif
    cr->intdata[NPC_CREATEBASEIMAGENUMBER]=-1;
    cr->intdata[NPC_CREATETIME]=0;
    cr->intdata[NPC_CREATEBORNNUM]=0;
    cr->intdata[NPC_CREATEENEMYNUM]=0;
    cr->intdata[NPC_CREATEBOUNDARY]=1;
    cr->intdata[NPC_CREATEIGNOREINVINCIBLE]=0;

    cr->intdata[NPC_CREATEDATE]=0;
    
    cr->intdata[NPC_CREATEFAMILY]=0;

    cr->chardata[NPC_CREATENAME].string[0]= '\0';
    
#ifdef _NB_CHARSTRTITLE
    cr->chardata[NPC_CREATENEWNAME].string[0]= '\0';
    cr->intdata[NPC_CREATECOLOR]= 0;
#endif
#ifdef _NB_CHARHALO
    cr->intdata[NPC_CREATEHALO]= 0;
#endif
#ifdef _NB_CHARDISPTITLE
    cr->intdata[NPC_CREATENAMEMOTO]= 0;
#endif
    cr->workdata[NPC_CREATEWORKENEMYNUM]=0;
    cr->workdata[NPC_CREATEWORKMAKESTARTSEC]=0;
    cr->workdata[NPC_CREATEWORKMAKESTARTUSEC]=0;
    cr->workdata[NPC_CREATEWORKNEVERMAKE]=0;
    {
        int i;
        for( i=0 ; i<arraysizeof(cr->templateindex) ; i++ ){
            cr->templateindex[i] = -1;
            cr->arg[i].string[0] = '\0';
        }
    }
}

BOOL NPC_IsNPCCreateFile( char* filename )
{
    FILE*   f;
    char    line1[128];
    char*   ret;

    /*  ~Æ¥±ÎÔÂ°×ÑëÄÌ»ï·´Ø¦ØÆ±åÔÊÔÂ */
    if( filename == NULL
        || strlen( filename ) < 1
        || filename[strlen(filename)-1] == '~'
        || filename[0] == '#'
        || strcmptail( filename, ".bak" ) == 0 )return FALSE;

    f= fopen( filename , "r" );
    if( f == NULL ) goto RETURNFALSE;
    ret = fgets( line1, sizeof( line1 ), f );
    if( ret == NULL )goto FCLOSERETURNFALSE;
    if( strcasecmp( NPC_CREATEFILEMAGIC, line1 ) == 0 ){
        fclose(f);
        return TRUE;
    }

FCLOSERETURNFALSE:
    fclose(f);
RETURNFALSE:
    return FALSE;
}

int NPC_readCreateFile( char* filename )
{
    FILE*   f;
    char    line[512];
    int     linenum=0;
    int     start=OFF;
    NPC_Create  cr;
    int     enemyreadindex=0;

    typedef struct tagPOINT
    {
        int x,y;
    }POINT;
    typedef struct tagREC
    {
        int w,h;
    }REC;
    POINT   center[2]={{0,0},{0,0}};     /*  born »¥ 0 Æ¥ move »¥ 1 */
    REC     wh[2]    ={{0,0},{0,0}};      /*  born »¥ 0 Æ¥ move »¥ 1 */

    POINT   lu[2]    ={{0,0},{0,0}};     /*  born »¥ 0 Æ¥ move »¥ 1 */
    POINT   rd[2]    ={{0,0},{0,0}};     /*  born »¥ 0 Æ¥ move »¥ 1 */

    int     defborn=FALSE;              /*  born Ã«É¬ÀÃØÆÐ×¾®Éýµ¤¾® */
    int     defmove=FALSE;              /*  move Ã«É¬ÀÃØÆÐ×¾®Éýµ¤¾® */
    
    int     deflurd[2]={FALSE,FALSE};   /*  lu,rd Æ¥É¬ÀÃØÆÐ×¾®Éýµ¤¾® */
    char*   ret;


    if( NPC_create_readindex >= NPC_createnum ){
        print("»ý¼ºÀÌ ¼³Á¤ ¹öÆÛ¸¦ ÃÊ°úÇÔ\n" );
        print("¼³Á¤ ¹öÆÛ °³¼ö´Â %d\n",NPC_createnum);
        print("¹«È¿ ÆÄÀÏ %s\n",filename);
        return FALSE;
    }

    NPC_setDefaultNPCCreate( &cr );
    f= fopen( filename ,"r");
    if( f == NULL )return FALSE;

    ret = fgets( line, sizeof( line ), f );
    if( ret == NULL )goto FCLOSERETURNFALSE;
    if( strcmp( NPC_CREATEFILEMAGIC, line ) != 0 ){
        print( "ÀÌ°ÍÀº create ÆÄÀÏÀÌ ¾Æ´Õ´Ï´Ù.\n" );
        goto FCLOSERETURNFALSE;
    }
    linenum = 1;

    while( fgets( line , sizeof( line ) , f ) ){
        linenum++;

        if( line[0] == '#' )continue;        /* comment */
        if( line[0] == '\n' )continue;       /* none    */
        chomp( line );

        switch( line[0] ){
        case '{':
            if( start == ON ){
                fprint( "Find {. But already START state. %s:%d\n",
                        filename, linenum);
                fprint( "Á¾·á\n" );
                goto FCLOSERETURNFALSE;

            }else{
                NPC_setDefaultNPCCreate( &cr );
                start = ON;
            }
            break;
        case '}':
            if( start == ON ){
                int     err = FALSE;
                if( enemyreadindex == 0 ){
                    err = TRUE;
                    print( "Á¶¿ì µ¥ÀÌÅÍ°¡ ¾Æ´Õ´Ï´Ù  %s:%d\n",
                           filename,linenum);
                }else if( MAP_IsThereSpecificFloorid(
                    cr.intdata[NPC_CREATEFLOORID]) == FALSE ){
                    err = TRUE;
                    print( "¸ÊID ¹øÈ£¿¡ ¹®Á¦°¡ ÀÖÀ½ %s:%d-floor:%d\n",
                           filename,linenum, cr.intdata[NPC_CREATEFLOORID]);
                }else if( defborn == FALSE ){
                    err = TRUE;
                    print( "born ¼³Á¤ÀÌ ¾Æ´Õ´Ï´Ù %s:%d\n",
                           filename,linenum);
                }

                if( err == FALSE ){
                    cr.intdata[NPC_CREATEENEMYNUM] = enemyreadindex;

                    if( deflurd[0] ){
                        cr.intdata[NPC_CREATEBORNLEFTUPX] =
                            min(lu[0].x,rd[0].x);
                        cr.intdata[NPC_CREATEBORNRIGHTDOWNX] =
                            max(lu[0].x,rd[0].x);
                        cr.intdata[NPC_CREATEBORNLEFTUPY] =
                            min(lu[0].y,rd[0].y);
                        cr.intdata[NPC_CREATEBORNRIGHTDOWNY] =
                            max(lu[0].y,rd[0].y);
                    }else{
                        cr.intdata[NPC_CREATEBORNLEFTUPX] =
                            center[0].x-wh[0].w/2;
                        cr.intdata[NPC_CREATEBORNRIGHTDOWNX] =
                            center[0].x+wh[0].w/2;
                        cr.intdata[NPC_CREATEBORNLEFTUPY] =
                            center[0].y-wh[0].h/2;
                        cr.intdata[NPC_CREATEBORNRIGHTDOWNY] =
                            center[0].y+wh[0].h/2;
                    }
                    if( defmove ){
                        if( deflurd[0] ){
                            cr.intdata[NPC_CREATEMOVELEFTUPX] =
                                min(lu[1].x,rd[1].x);
                            cr.intdata[NPC_CREATEMOVERIGHTDOWNX] =
                                max(lu[1].x,rd[1].x);
                            cr.intdata[NPC_CREATEMOVELEFTUPY] =
                                min(lu[1].y,rd[1].y);
                            cr.intdata[NPC_CREATEMOVERIGHTDOWNY] =
                                max(lu[1].y,rd[1].y);
                        }else{
                            cr.intdata[NPC_CREATEMOVELEFTUPX] =
                                center[1].x-wh[1].w/2;
                            cr.intdata[NPC_CREATEMOVERIGHTDOWNX] =
                                center[1].x+wh[1].w/2;
                            cr.intdata[NPC_CREATEMOVELEFTUPY] =
                                center[1].y-wh[1].h/2;
                            cr.intdata[NPC_CREATEMOVERIGHTDOWNY] =
                                center[1].y+wh[1].h/2;
                        }

                    }else{
                        /*  born Ã«Îìñâ¡õÔÊÔÂ */
                        cr.intdata[NPC_CREATEMOVELEFTUPX] =
                            cr.intdata[NPC_CREATEBORNLEFTUPX];
                        cr.intdata[NPC_CREATEMOVERIGHTDOWNX] =
                            cr.intdata[NPC_CREATEBORNRIGHTDOWNX];
                        cr.intdata[NPC_CREATEMOVELEFTUPY] =
                            cr.intdata[NPC_CREATEBORNLEFTUPY];
                        cr.intdata[NPC_CREATEMOVERIGHTDOWNY] =
                            cr.intdata[NPC_CREATEBORNRIGHTDOWNY];
                    }

                    memcpy( &NPC_create[NPC_create_readindex], &cr,
                            sizeof( NPC_Create ) );


                    NPC_create_readindex++;

                    if( NPC_create_readindex >= NPC_createnum ){
                        print("»ý¼ºÀÌ ¼³Á¤ ¹öÆÛ¸¦ ÃÊ°úÇÔ\n" );
                        print("¼³Á¤ »ý¼º ÆÄÀÏ °³¼ö %d\n",
                              NPC_createnum);
                        print("¹«È¿ ÆÄÀÏ:%s\n",filename);
                        goto FCLOSERETURNFALSE;
                    }

                }

                NPC_setDefaultNPCCreate( &cr );
                enemyreadindex=0;
                defborn=FALSE;
                defmove=FALSE;
                deflurd[0]=FALSE;
                deflurd[1]=FALSE;
                start = OFF;
            }else{
                fprint( "ÇØ°áµÇÁö ¾ÊÀº '}' at %s:%d\n",filename,linenum);
                goto FCLOSERETURNFALSE;
            }
            break;
        default:
        {
 
            char    firstToken[256];
            char    secondToken[256];
            int     ret;
            ret = getStringFromIndexWithDelim( line, "=",  1, firstToken,sizeof( firstToken ) );
            if( ret == FALSE ){
                print( "Find error at %s in line %d. Ignore\n",filename , linenum);
                break;
            }
            ret = getStringFromIndexWithDelim( line, "=", 2, secondToken,sizeof( secondToken ) );
            if( ret == FALSE ){
                print( "Find error at %s in line %d. Ignore\n",filename , linenum);
                break;
            }
            if( strcasecmp("floorid",firstToken) == 0 ){
                cr.intdata[NPC_CREATEFLOORID] = atoi(secondToken);

            }else if( strcasecmp("borncenter", firstToken) == 0 ){
                getFourIntsFromString(secondToken,&center[0].x,&center[0].y,&wh[0].w,&wh[0].h );
                defborn = TRUE;
            }else if( strcasecmp("borncorner", firstToken) == 0 ){
                getFourIntsFromString(secondToken,&lu[0].x,&lu[0].y,&rd[0].x,&rd[0].y );
                defborn = TRUE;
                deflurd[0]=TRUE;
            }else if( strcasecmp("movecenter", firstToken) == 0 ){
                getFourIntsFromString(secondToken,&center[1].x,&center[1].y,&wh[1].w,&wh[1].h );
                defmove = TRUE;
            }else if( strcasecmp("movecorner", firstToken) == 0 ){
                getFourIntsFromString(secondToken,&lu[1].x,&lu[1].y,&rd[1].x,&rd[1].y );
                defmove = TRUE;
                deflurd[1]=TRUE;

            }
            
            else if( strcasecmp("dir",firstToken) == 0 ){
                cr.intdata[NPC_CREATEDIR] = atoi( secondToken );
            }else if( strcasecmp("graphicname",firstToken) == 0 ){
                cr.intdata[NPC_CREATEBASEIMAGENUMBER] = CHAR_seekGraphicNumberFromString(secondToken);

            }else if( strcasecmp("name",firstToken) == 0 ){
                strcpysafe( cr.chardata[NPC_CREATENAME].string,sizeof(cr.chardata[NPC_CREATENAME].string),secondToken );
#ifdef _NB_CHARSTRTITLE
						}else if( strcasecmp("charstrtitle",firstToken) == 0 ){
                strcpysafe( cr.chardata[NPC_CREATENEWNAME].string,sizeof(cr.chardata[NPC_CREATENEWNAME].string),secondToken );
            }else if( strcasecmp("charstrcolor",firstToken) == 0 ){
                cr.intdata[NPC_CREATECOLOR] = atoi( secondToken );
#endif
#ifdef _NB_CHARHALO
						}else if( strcasecmp("halo",firstToken) == 0 ){
							 cr.intdata[NPC_CREATEHALO] = atoi( secondToken );
#endif
#ifdef _NB_CHARDISPTITLE
						}else if( strcasecmp("namemoto",firstToken) == 0 ){
							 cr.intdata[NPC_CREATENAMEMOTO] = atoi( secondToken );
#endif
            }else if( strcasecmp("time",firstToken) == 0 ){
                cr.intdata[NPC_CREATETIME] = atoi( secondToken );

            }else if( strcasecmp("date",firstToken) == 0 ){
                cr.intdata[NPC_CREATEDATE] = atoi( secondToken );

            }else if( strcasecmp("createnum",firstToken) == 0 ){
                cr.intdata[NPC_CREATEBORNNUM] = atoi( secondToken );

            }else if( strcasecmp( "boundary", firstToken) == 0 ){
                cr.intdata[NPC_CREATEBOUNDARY] = atoi( secondToken );

            }else if( strcasecmp( "ignoreinvincible", firstToken) == 0 ){
                cr.intdata[NPC_CREATEIGNOREINVINCIBLE] = atoi( secondToken );

		//jeffrey 1231
#ifdef _ADD_ACTION
			}else if( strcasecmp( "action", firstToken) == 0 ){
				cr.intdata[NPC_CREATEACTION] = atoi( secondToken );
#endif		
	    // Robin 0731
            }else if( strcasecmp( "family", firstToken) == 0 ){
                cr.intdata[NPC_CREATEFAMILY] = atoi( secondToken );

            }else if( strcasecmp("enemy", firstToken) == 0 ){
                int     templateindex;
                char    enemyname[64];
                if( enemyreadindex <= arraysizeof(cr.templateindex) )
                    /* OK */
                    ;
                else
                    break;
                getStringFromIndexWithDelim(secondToken,"|",1,enemyname,sizeof(enemyname) );
                templateindex= NPC_templateGetTemplateIndex(enemyname);
                if( templateindex != -1 ){
                    cr.templateindex[enemyreadindex] = templateindex;
                    {
                        char    tmp[2];
                        int     ret;
                        ret = getStringFromIndexWithDelim( secondToken,"|",2,tmp,sizeof(tmp) );
                        if( ret == FALSE )
                            cr.arg[enemyreadindex].string[0] = '\0';
                        else
                            strcpysafe( cr.arg[enemyreadindex].string,sizeof( cr.arg[enemyreadindex].string ),secondToken+strlen(enemyname)+1 );
                    }
                    enemyreadindex++;
                }else
                    fprint( "ÇØ´ç ¸ðµâ ¾øÀ½:\n[%s(%d)%s] enemy:%s\n",filename ,linenum,secondToken, enemyname);
            }else{
                fprint( "ÇØ´ç ·Î±×ÀÎ ¾øÀ½ %s %s:%d\n",firstToken,filename,linenum );
            }
        }
        }
    }

    fclose(f);
    return TRUE;

FCLOSERETURNFALSE:
    fclose(f);
    return FALSE;
}

BOOL NPC_readNPCCreateFiles( char* topdirectory ,int createsize)
{
    STRING64    *filenames;
    int         filenum;
    int         i;
    filenames = (STRING64 *)allocateMemory( sizeof( STRING64 ) *
                                              (int)getFilesearchnum( ) );
	if( filenames == NULL ){
	    print( "NPC »ý¼º ÆÄÀÏ ÀÐ´Â Áß... ¸Þ¸ð¸® ¿À·ù\n" );
		return FALSE;
	}
    filenum = rgetFileName( topdirectory ,filenames ,getFilesearchnum( ) );
    if( filenum == -1 ){
	    freeMemory( filenames );
    	return FALSE;
    }
	if( filenum >= getFilesearchnum( ) ){
		print( "ÆÄÀÏ °Ë»ö °³¼ö ½ÇÆÐ %d\n", getFilesearchnum( ) );
		while( 1 );
	}
    if( !NPC_initCreateArray( createsize ) ){
        fprint( "»ý¼º ¹è¿­ ¿­±â ¿À·ù\n" );
	    freeMemory( filenames );
        return FALSE;
    }
    print( "NPC »ý¼º ÆÄÀÏ ÀÐ´Â Áß..." );
    for( i = 0 ; i < filenum ; i ++ ){
      if( NPC_IsNPCCreateFile( filenames[i].string )){
        if( NPC_readCreateFile( filenames[i].string ) == -1 ){
          break;
        }
      }
    }
    print( "NPC %d Á¤»ó »ý¼º ..." , NPC_create_readindex );
     //NPC_createnum=NPC_create_readindex;
#ifdef DEBUG
	/* 99/4/8 By Kawata csväßÖ¿±åØÆ»¯Ö§ÔÂ */
	print( "Npc_Create's\n");
    for( i = 0 ; i < NPC_createnum ; i ++ ){
        int     j;
        /*print( "NPC_create[%d]:\n", i);*/
        print( "%d,", i);
        for( j = 0 ; j < NPC_CREATECHARNUM ; j ++ )
            print("%s," , NPC_create[i].chardata[j].string );
        /*print( "\tIntdata\t" );*/
        for( j = 0 ; j < NPC_CREATEINTNUM ; j ++ )
            print("%d," , NPC_create[i].intdata[j] );
        /***print("\n" );
        print( "\tChardata\t" );***/
        for( j = 0 ; j < NPC_create[i].intdata[NPC_CREATEENEMYNUM]; j ++ )
            print("%d" , NPC_create[i].templateindex[j] );
        /*print("\n" );*/
        print("\n" );
    }
#endif /*DEBUG*/

    freeMemory( filenames );
    return TRUE;
}



/*------------------------------------------------------------
 * createindex ¾®ÈÕ boundary »¥É¬ÀÃ½ñÄ¾»¯ÖÐÔÂ¾®Éýµ¤¾®Ã«Î­ÔÂ
 * Â¦ÐÑ
 *  createindex         int         create¼°ÄÌ¼þ·¸ÓÀÛÍµ©
 * ß¯Ô»°À
 *  É¬ÀÃ½ñÄ¾»¯ÖÐÔÂ          TRUE(1)
 *  É¬ÀÃ½ñÄ¾»¯ÖÐØ¦ÖÐ        FALSE(0)
 ------------------------------------------------------------*/
BOOL NPC_isBoundarySet( int createindex )
{
    if( NPC_CHECKCREATEINDEX(createindex) == FALSE )return FALSE;
    return NPC_create[createindex].intdata[NPC_CREATEBOUNDARY];
}
/*------------------------------------------------------------
 * Â¦ÐÑ
 *  r                   RECT*       °ÀÃ«°¾ØêÎçÔÂRECT ¼°ºÌÄÌ¼þÕý
 * ß¯Ô»°À
 ------------------------------------------------------------*/
BOOL NPC_createGetRECT( int createindex,RECT*   r )
{
    if( NPC_CHECKCREATEINDEX(createindex) == FALSE )return FALSE;

    r->x = NPC_create[createindex].intdata[NPC_CREATEMOVELEFTUPX];
    r->y = NPC_create[createindex].intdata[NPC_CREATEMOVELEFTUPY];
    r->width
        = NPC_create[createindex].intdata[NPC_CREATEMOVERIGHTDOWNX]
        - NPC_create[createindex].intdata[NPC_CREATEMOVELEFTUPX];
    r->height
        = NPC_create[createindex].intdata[NPC_CREATEMOVERIGHTDOWNY]
        - NPC_create[createindex].intdata[NPC_CREATEMOVELEFTUPY];
    return TRUE;
}



/*------------------------------------------------------------
 * Â¦ÐÑ
 *  cindex      int     ÄÌ¼þ·¸ÓÀÛÍµ©
 * ß¯Ô»°À
 *  BOOL    ×ÛÔÈ»¯ÖÐÖÐèëÄþ  TRUE(1)
 *  BOOL    ×ÛÔÈ»¯ÖÐØêØ¦ÖÐèëÄþ  FALSE(0)
 ------------------------------------------------------------*/
BOOL NPC_createCheckGenerateFromTime( int cindex )
{
    struct timeval  old;
    if( !NPC_CHECKCREATEINDEX(cindex) )
        return FALSE;

    if( NPC_create[cindex].workdata[NPC_CREATEWORKNEVERMAKE] )
        return FALSE;

    if( NPC_create[cindex].intdata[NPC_CREATEBORNNUM]
        <=  NPC_create[cindex].workdata[NPC_CREATEWORKENEMYNUM] )
        return FALSE;

    if( NPC_create[cindex].intdata[NPC_CREATETIME] < 0 )return FALSE;
    old.tv_sec = NPC_create[cindex].workdata[NPC_CREATEWORKMAKESTARTSEC];
    old.tv_usec= NPC_create[cindex].workdata[NPC_CREATEWORKMAKESTARTUSEC];

    if( time_diff_us( NowTime , old ) <=
        NPC_create[cindex].intdata[NPC_CREATETIME]*1000 )
        return FALSE;

    return TRUE;
}




/*------------------------------------------------------------
 * Â¦ÐÑ
 *  tindex      int     ÄÌ¼þ·¸ÓÀÛÍµ©
 * ß¯Ô»°À
 *  Ø¦ØÆ
 ------------------------------------------------------------*/
void NPC_createInitTime( int index )
{
    /*  ×ÛÔÂÒÇ±åØ¦ÔÈÐ×¾®ÈÕ°ÀÃ«É¬ÀÃ  */
    NPC_create[index].workdata[NPC_CREATEWORKMAKESTARTSEC] =
        NowTime.tv_sec;
    NPC_create[index].workdata[NPC_CREATEWORKMAKESTARTUSEC] =
        NowTime.tv_usec;
}
/*------------------------------------------------------------
 * Â¦ÐÑ
 *  index       int         ÄÌ¼þ·¸ÓÀÛÍµ©
 * ß¯Ô»°À
 *  Ø¦ØÆ
 ------------------------------------------------------------*/
void NPC_createIncreaseEnemynum( int index )
{
    if( !NPC_CHECKCREATEINDEX(index) )return;
    NPC_create[index].workdata[NPC_CREATEWORKENEMYNUM] ++;
}
/*------------------------------------------------------------
 * ³Ä»¥ÉØÊÏÆ¥ÊÐËü¼þÐþÐÑÃ«Ó¼ÈÕÔÊèúÐÑ
 * Â¦ÐÑ
 *  index       int         ÄÌ¼þ·¸ÓÀÛÍµ©
 * ß¯Ô»°À
 *  Ø¦ØÆ
 ------------------------------------------------------------*/
void NPC_createDecreaseEnemynum( int index )
{
    if( !NPC_CHECKCREATEINDEX(index) )return;
    NPC_create[index].workdata[NPC_CREATEWORKENEMYNUM] --;
}
/*------------------------------------------------------------
 * Â¦ÐÑ
 *  index       int         ÄÌ¼þ·¸ÓÀÛÍµ©
 * ß¯Ô»°À
 *  TRUE:MAX  FALSE:à¨µ¤
 ------------------------------------------------------------*/
BOOL NPC_createCheckMaxEnemynum( int index )
{

    if( NPC_create[index].intdata[NPC_CREATEBORNNUM]
        <=  NPC_create[index].workdata[NPC_CREATEWORKENEMYNUM] )
        return TRUE;
	else
		return FALSE;
}
