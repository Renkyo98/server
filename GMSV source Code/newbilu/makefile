export CC=gcc
export RM=rm -f
export AR=ar cr
export MV=mv
export RANLIB=ranlib
export SED=sed


export SHELL=/bin/sh

INCFLAGS=-I. -I../include -I../include/lua

CFLAGS=-w  -O0 -g -rdynamic $(INCFLAGS)
#Pentium 4 (Intel)
#CFLAGS=-march=pentium4 -O3 -pipe -fomit-frame-pointer $(INCFLAGS)
#Athlon XP (AMD)
#CFLAGS="-march=athlon-xp -O3 -pipe -fomit-frame-pointer" $(INCFLAGS)
#Athlon64£º
#CFLAGS="-O2 -march=athlon64 -ftracer -fprefetch-loop-arrays -pipe" $(INCFLAGS)


ifeq ($(shell uname),CYGWIN_NT-5.1)
	SQLSRC=sasql_cygwin.c
	SQL=-lodbc32 -lz
endif
ifeq ($(shell uname),Linux)
	SQLSRC=sasql.c
	SQL=-L /usr/lib64/mysql/ -lmysqlclient -lz  -lpthread
endif


PROG=libnewbilu.a

SRC=crypto.c characters.c newshop.c $(SQLSRC)
OBJ=$(SRC:.c=.o)

ifeq (0,$(MAKELEVEL))
CC=gcc
RM=rm -f
AR=ar cr
MV=mv
RANLIB=ranlib
SED=sed
SHELL=/bin/sh
endif

all: $(PROG)

$(PROG): $(OBJ)
	$(RM) $(PROG)
	$(AR) $(PROG) $(OBJ)
	$(RANLIB) $(PROG)

dos2unix:
	dos2unix $(SRC) makefile
	
chmod:
	chmod 777 $(SRC) makefile
	
depend:
	$(MV) makefile makefile.bak
	$(SED) -ne '1,/^# DO NOT DELETE THIS LINE/p' makefile.bak>makefile
	$(CC) $(INCFLAGS) -M $(SRC) >> makefile 
	chmod 777 makefile
	
clean:
	$(RM) $(PROG)
	$(RM) $(OBJ)
	$(RM) *~

distclean:
	$(RM) $(PROG)
	$(RM) $(OBJ)
	$(RM) *~
	$(MV) makefile Makefile.bak
	$(SED) -ne '1,/^# DO NOT DELETE THIS LINE/p' makefile.bak>makefile
	$(RM) makefile.bak

# DO NOT DELETE THIS LINE
crypto.o: crypto.c /usr/include/stdio.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/dirent.h /usr/include/bits/dirent.h \
 /usr/include/bits/posix1_lim.h /usr/include/bits/local_lim.h \
 /usr/include/linux/limits.h /usr/include/string.h /usr/include/xlocale.h \
 /usr/include/sys/types.h /usr/include/time.h /usr/include/endian.h \
 /usr/include/bits/endian.h /usr/include/bits/byteswap.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/sys/stat.h /usr/include/bits/stat.h ../include/autil.h \
 ../include/version.h ../include/correct_bug.h ../include/common.h \
 /usr/include/errno.h /usr/include/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../include/NewBilu/version.h ../include/NewBilu/debug.h \
 ../include/util.h /usr/include/sys/time.h /usr/include/stdlib.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/alloca.h
characters.o: characters.c /usr/include/string.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stddef.h \
 /usr/include/xlocale.h ../include/version.h ../include/correct_bug.h \
 ../include/common.h /usr/include/stdio.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/errno.h /usr/include/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../include/NewBilu/version.h ../include/NewBilu/debug.h \
 ../include/common.h ../include/NewBilu/characters.h ../include/readmap.h \
 ../include/util.h /usr/include/sys/time.h /usr/include/time.h \
 /usr/include/bits/time.h /usr/include/sys/select.h \
 /usr/include/bits/select.h /usr/include/bits/sigset.h \
 /usr/include/stdlib.h /usr/include/bits/waitflags.h \
 /usr/include/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/bits/endian.h /usr/include/bits/byteswap.h \
 /usr/include/sys/types.h /usr/include/sys/sysmacros.h \
 /usr/include/bits/pthreadtypes.h /usr/include/alloca.h \
 ../include/saacproto_cli.h ../include/version.h \
 ../include/saacproto_util.h /usr/include/strings.h /usr/include/unistd.h \
 /usr/include/bits/posix_opt.h /usr/include/bits/environments.h \
 /usr/include/bits/confname.h /usr/include/getopt.h
newshop.o: newshop.c /usr/include/string.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stddef.h \
 /usr/include/xlocale.h ../include/version.h ../include/correct_bug.h \
 ../include/common.h /usr/include/stdio.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/errno.h /usr/include/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../include/NewBilu/version.h ../include/NewBilu/debug.h \
 ../include/NewBilu/newshop.h ../include/NewBilu/sasql.h \
 ../include/NewBilu/version.h ../include/char.h ../include/char_base.h \
 ../include/version.h ../include/skill.h ../include/util.h \
 /usr/include/sys/time.h /usr/include/time.h /usr/include/bits/time.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/stdlib.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/sys/types.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h ../include/title.h ../include/addressbook.h \
 ../include/net.h ../include/autil.h /usr/include/netinet/in.h \
 /usr/include/stdint.h /usr/include/bits/wchar.h \
 /usr/include/sys/socket.h /usr/include/sys/uio.h /usr/include/bits/uio.h \
 /usr/include/bits/socket.h /usr/include/bits/sockaddr.h \
 /usr/include/asm/socket.h /usr/include/asm-generic/socket.h \
 /usr/include/asm/sockios.h /usr/include/asm-generic/sockios.h \
 /usr/include/bits/in.h /usr/include/signal.h /usr/include/bits/signum.h \
 /usr/include/bits/siginfo.h /usr/include/bits/sigaction.h \
 /usr/include/bits/sigcontext.h /usr/include/bits/sigstack.h \
 /usr/include/sys/ucontext.h /usr/include/bits/sigthread.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
 /usr/include/bits/setjmp.h ../include/link.h ../include/lua/lua.h \
 ../include/lua/luaconf.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/limits.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/syslimits.h \
 /usr/include/limits.h /usr/include/bits/posix1_lim.h \
 /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
 /usr/include/bits/posix2_lim.h ../include/lua/lauxlib.h \
 ../include/lua/lua.h ../include/lua/lualib.h ../include/char_data.h \
 ../include/item.h ../include/char.h ../include/autil.h \
 ../include/enemy.h ../include/item.h ../include/lssproto_serv.h \
 ../include/lssproto_util.h /usr/include/strings.h /usr/include/unistd.h \
 /usr/include/bits/posix_opt.h /usr/include/bits/environments.h \
 /usr/include/bits/confname.h /usr/include/getopt.h
sasql.o: sasql.c ../include/NewBilu/version.h ../include/NewBilu/sasql.h \
 ../include/NewBilu/version.h ../include/char_base.h ../include/version.h \
 ../include/correct_bug.h ../include/common.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/errno.h /usr/include/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../include/NewBilu/version.h ../include/NewBilu/debug.h \
 ../include/skill.h ../include/util.h /usr/include/sys/time.h \
 /usr/include/time.h /usr/include/bits/time.h /usr/include/sys/select.h \
 /usr/include/bits/select.h /usr/include/bits/sigset.h \
 /usr/include/stdlib.h /usr/include/bits/waitflags.h \
 /usr/include/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/bits/endian.h /usr/include/bits/byteswap.h \
 /usr/include/sys/types.h /usr/include/sys/sysmacros.h \
 /usr/include/bits/pthreadtypes.h /usr/include/alloca.h \
 ../include/title.h ../include/addressbook.h ../include/net.h \
 ../include/autil.h /usr/include/netinet/in.h /usr/include/stdint.h \
 /usr/include/bits/wchar.h /usr/include/sys/socket.h \
 /usr/include/sys/uio.h /usr/include/bits/uio.h \
 /usr/include/bits/socket.h /usr/include/bits/sockaddr.h \
 /usr/include/asm/socket.h /usr/include/asm-generic/socket.h \
 /usr/include/asm/sockios.h /usr/include/asm-generic/sockios.h \
 /usr/include/bits/in.h /usr/include/signal.h /usr/include/bits/signum.h \
 /usr/include/bits/siginfo.h /usr/include/bits/sigaction.h \
 /usr/include/bits/sigcontext.h /usr/include/bits/sigstack.h \
 /usr/include/sys/ucontext.h /usr/include/bits/sigthread.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/bits/sched.h \
 /usr/include/xlocale.h /usr/include/bits/setjmp.h ../include/link.h \
 ../include/lua/lua.h ../include/lua/luaconf.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/limits.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/syslimits.h \
 /usr/include/limits.h /usr/include/bits/posix1_lim.h \
 /usr/include/bits/local_lim.h /usr/include/linux/limits.h \
 /usr/include/bits/posix2_lim.h ../include/lua/lauxlib.h \
 ../include/lua/lua.h ../include/lua/lualib.h ../include/configfile.h \
 /usr/include/mysql/mysql.h /usr/include/mysql/mysql_version.h \
 /usr/include/mysql/mysql_com.h /usr/include/mysql/mysql_time.h \
 /usr/include/mysql/my_list.h /usr/include/mysql/typelib.h \
 /usr/include/mysql/my_alloc.h /usr/include/string.h
