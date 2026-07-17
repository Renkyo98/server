#include "version.h"
#include <signal.h>
#include <errno.h>
#include <unistd.h>

#include <stdio.h>
#include <execinfo.h> 

#include "buf.h"
#include "net.h"
#include "char.h"
#include "item.h"
#include "object.h"
#include "configfile.h"
#include "lssproto_serv.h"
#include "saacproto_cli.h"
#include "log.h"
#include "petmail.h"
#include "vertime.h"
#ifdef _ALLBLUES_LUA
#include "mylua/mylua.h"
#endif
/*------------------------------------------------------------
 * 允屯化及忡绣仄卅仃木壬卅日卅中犯□正毛母件皿允月楮醒
 *  卅仄
 ------------------------------------------------------------*/
static void endlsprotocol( void )
{
    lssproto_CleanupServer();
    saacproto_CleanupClient();
}

void logerr(char *token)
{
	char tmp[256];
	struct tm now;
	time_t timep;
	time(&timep);
	memcpy(&now, localtime(&timep), sizeof(now));

	sprintf(tmp, "%04d-%02d-%02d.log", 	now.tm_year+1900,	now.tm_mon+1,	now.tm_mday);
																																								
	FILE *fp=fopen(tmp,"a+");
	fwrite(token, strlen(token), 1, fp);
  fclose(fp);
	printf( token );
}

void dump()
{
  void *array[10];
  size_t size;
  char **strings;
  size_t i;

  size = backtrace (array, 10);
  strings = backtrace_symbols (array, size);

  printf ("Obtained %zd stack frames.\n", size);

  for (i = 0; i < size; i++){
  	logerr(strings[i]);
	}

  free (strings);

}

void signalset( void );
 
static void allDataDump( void )
{

	int i;
	for( i = 0; i < CHAR_getPlayerMaxNum(); i ++ ){
		if(CHAR_CHECKINDEX(i) == TRUE){
			CHAR_charSaveFromConnect(i, FALSE);
		}
	}

	saveforsaac();

	storeCharaData();

  closeAllLogFile();
#ifdef _PET_ITEM
	storeObjects( getStoredir() );
	storePetmail();
#endif
#ifdef _ALLBLUES_LUA   
	closemyluaload();
#endif
}

/*------------------------------------------------------------
 *  卅仄
 ------------------------------------------------------------*/
void shutdownProgram( void )
{
#ifndef _NB_FIX_SHUTDOWN_SAVE
	printf("关闭SAAC连接:%d\n",close( acfd ));
	printf("关闭绑定端口:%d\n",close( bindedfd ));
#endif
	close( acfd );
	close( bindedfd );
	endlsprotocol();
	allDataDump();
  memEnd();
}

#ifdef _GMSV_DEBUG
char *DebugMainFunction = NULL;
extern time_t initTime;
#endif
extern int player_online;
extern int player_maxonline;
char saacretfunc[255]="";
char *saacsendfunc = NULL;
int cliretfunc=0;
int clisendfunc=0;


#ifdef _ABSOLUTE_DEBUG
char errordata[256]="";
char charId[32]="";
int lastfunctime=0;
int debugline=0;
int comnum=-1;
#endif


void sigshutdown( int number)
{
		char buff[256];

		if( number == 0 ){
			printf( "\n\n\nGMSV正常关闭\n" );
		}else if( number == 2 ){
			printf( "\n\n\nGMSV被CTRL+C手动中断\n" );
		}else{
			sprintf( buff, "\n=========以下是服务器出错原因=========\n");
			logerr(buff);
	    sprintf( buff, "标准信息: %d\n" , number  );
	    logerr(buff);
#ifdef _GMSV_DEBUG
			sprintf( buff, "主 函 数: %s\n", DebugMainFunction );
			logerr(buff);
#endif
			sprintf( buff, "在线人数: %d\n", player_online);
			logerr(buff);
			sprintf( buff, "最高在线: %d\n", player_maxonline);
			logerr(buff);
			sprintf( buff, "SAAC接收: %s\n", saacretfunc);
			logerr(buff);
			sprintf( buff, "SAAC发送: %s\n", saacsendfunc);
			logerr(buff);
			sprintf( buff, "cli 接收: %d\n", cliretfunc);
			logerr(buff);
			sprintf( buff, "cli 发送: %d\n", clisendfunc);
			logerr(buff);
#ifdef _ABSOLUTE_DEBUG
			sprintf( buff, "错误数据: %s\n", errordata);
			logerr(buff);
			sprintf( buff, "错误账号: %s\n", charId);
			logerr(buff);
			sprintf( buff, "最后执行: %d\n", lastfunctime);
			logerr(buff);
			sprintf( buff, "调试行数: %d\n", debugline);
			logerr(buff);
			sprintf( buff, "COM 接口: %d\n", comnum);
			logerr(buff);
			sprintf( buff, "编译时间：%s\n", SERVER_VERTIME);
			logerr(buff);
#endif
			sprintf( buff, "以下是主要错误，必须向我们提交的错误\n");
			logerr(buff);
			dump();

			sprintf( buff, "=========以上是服务器出错原因=========\n");
			logerr(buff);

		}
		if( number == 0 || number == 2 ){
			printf( "在线人数: %d\n", player_online);
			printf( "最高在线: %d\n", player_maxonline);
			printf( "%s\n", SERVER_VERSION);
			printf( "编译时间：%s\n", SERVER_VERTIME);
		}
		
#ifdef _GMSV_DEBUG
	  {
	    	time_t new_t;
	    	int dd,hh,mm,ss;
	    	char buf[128];
	    	time(&new_t);
	    	if(initTime==0){
	    		printf( "运行时间: 尚未初始化完\n" );
	    	}else{
		    	new_t-=initTime;
			
					dd=(int) new_t / 86400; new_t=new_t % 86400;
		   		hh=(int) new_t / 3600;  new_t=new_t % 3600;
		      mm=(int) new_t / 60;    new_t=new_t % 60;
		      ss=(int) new_t;
		      
					if (dd>0) {
		      	snprintf( buf, sizeof( buf ) , "服务器共运行了 %d 日 %d 小时 %d 分 %d 秒。",dd,hh,mm,ss);
		      } else if (hh>0) {
		      	snprintf( buf, sizeof( buf ) , "服务器共运行了 %d 小时 %d 分 %d 秒。",hh,mm,ss);
		      } else {
		       	snprintf( buf, sizeof( buf ) , "服务器共运行了 %d 分 %d 秒。",mm,ss);
		      }
		      if( number == 0 || number == 2 ){
		      	printf( "运行时间: %s\n", buf );
		      }else{
			      sprintf( buff, "运行时间: %s\n", buf );
			      logerr(buff);
			    }
	    	}
		}
#endif
		remove( "gmsvlog.err2");
		rename( "gmsvlog.err1", "gmsvlog.err2" );
		rename( "gmsvlog.err", "gmsvlog.err1" );
		rename( "gmsvlog", "gmsvlog.err" );

    allDataDump();

    signal(SIGINT , SIG_IGN );
    signal(SIGQUIT, SIG_IGN );
    signal(SIGILL,  SIG_IGN );
    signal(SIGTRAP, SIG_IGN );
    signal(SIGIOT,  SIG_IGN );
    signal(SIGBUS,  SIG_IGN );
    signal(SIGFPE,  SIG_IGN );
    signal(SIGKILL, SIG_IGN );
    signal(SIGSEGV, SIG_IGN );
    signal(SIGPIPE, SIG_IGN );
    signal(SIGTERM, SIG_IGN );

    shutdownProgram();
    exit(number);
}



void signalset( void )
{
    // CoolFish: Test Signal 2001/10/26
    print("\n开始获取信号..\n");

		print("SIGINT:%d\n",  SIGINT);
		print("SIGQUIT:%d\n", SIGQUIT);
		print("SIGFPE:%d\n",  SIGILL);
		print("SIGTRAP:%d\n", SIGTRAP);
		print("SIGIOT:%d\n",  SIGIOT);
		print("SIGBUS:%d\n",  SIGBUS);
		print("SIGFPE:%d\n",  SIGFPE);
		print("SIGKILL:%d\n", SIGKILL);
		print("SIGSEGV:%d\n", SIGSEGV);
		print("SIGPIPE:%d\n", SIGPIPE);
		print("SIGTERM:%d\n", SIGTERM);
    
    signal( SIGINT , sigshutdown );
    signal( SIGQUIT, sigshutdown );
    signal( SIGILL,  sigshutdown );
    signal( SIGTRAP, sigshutdown );
    signal( SIGIOT,  sigshutdown );
    signal( SIGBUS,  sigshutdown );
    signal( SIGFPE,  sigshutdown );
    signal( SIGKILL, sigshutdown );
    signal( SIGSEGV, sigshutdown );
    signal( SIGPIPE, SIG_IGN );
    signal( SIGTERM, sigshutdown );
}
