export CC=gcc
export RM=rm -f
export AR=ar cr
export MV=mv
export RANLIB=ranlib
export SED=sed

export SHELL=/bin/sh

#
# Edit by ringo 19980606
# 19990723
#
#
#

INCFLAGS=-I. -I./include

CFLAGS=-O3 -w -std=gnu89 -fcommon $(INCFLAGS)

LBITS := $(shell getconf LONG_BIT)
ifeq ($(LBITS),64)
   SQL=-lmysqlclient -lz -lpthread
   PROG = ./saac64
else
	 SQL=-lmysqlclient -lz -lpthread
   PROG = ./saac32
endif

	
TOP=../..
SHELL = /bin/sh
PERL=/usr/bin/perl

RPCGEN=${TOP}/bin/lsgen.perl

RPCHTML = ${TOP}/doc/saacproto.html
#RPCSRC = saacproto_serv.c saacproto_util.csaacproto_sup.c 
RPCSRC = saacproto_serv.c saacproto_util.c 
RPCINCLUDE = saacproto_serv.h saacproto_util.h mac.h
RPCNOUSE = saacproto_cli.c saacproto_cli.h

#加入mysql资料库功能
SRC = main.c recv.c util.c char.c db.c mail.c acfamily.c lock.c md5.c sasql.c $(RPCSRC)
#SRC = main.c recv.c util.c char.c db.c mail.c acfamily.c lock.c $(RPCSRC)

OBJ=$(SRC:.c=.o)

${PROG}: vertime $(RPCSRC) $(OBJ)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJ) $(SQL)

vertime:
	$(SHELL) ./vertime.sh

dos2unix:
	dos2unix $(SRC) ./include/*.h makefile

chmod:
	chmod 777 $(SRC) ./include/*.h makefile

depend: $(RPCSRC) $(ANIMDATAFILE)
	$(MV) makefile makefile.bak
	$(SED) -ne '1,/^# DO NOT DELETE THIS LINE/p' makefile.bak>makefile
	$(CC) $(INCFLAGS) -M $(SRC) >> makefile 
	chmod 777 makefile
clean:
	$(RM) $(PROG)
	$(RM) $(OBJ)
	$(RM) *~

distclean:
	$(RM) $(CLIRPCSRC)
	$(RM) $(CLIRPCINCLUDE)
	$(RM) $(SERVRPCSRC)
	$(RM) $(SERVRPCINCLUDE)
	$(RM) $(ANIMDATAFILE)
	$(RM) include/*~

	$(RM) $(PROG)
	$(RM) $(OBJ)
	$(RM) *~

	$(MV) Makefile Makefile.bak
	$(SED) -ne '1,/^# DO NOT DELETE THIS LINE/p' Makefile.bak>Makefile
	$(RM) Makefile.bak

rpc : ${RPCHTML} ${RPCGEN}
	$(PERL) ${RPCGEN} ${RPCHTML} -h . -o .
	rm -f ${RPCNOUSE}

# DO NOT DELETE THIS LINE
