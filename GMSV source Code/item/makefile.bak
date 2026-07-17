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

PROG=libitem.a

SRC=item.c item_event.c item_gen.c
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
item.o: item.c ../include/version.h ../include/correct_bug.h \
 ../include/common.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/errno.h /usr/include/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../include/NewBilu/version.h ../include/NewBilu/debug.h \
 /usr/include/stdlib.h /usr/include/bits/waitflags.h \
 /usr/include/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/bits/endian.h /usr/include/bits/byteswap.h \
 /usr/include/sys/types.h /usr/include/time.h /usr/include/sys/select.h \
 /usr/include/bits/select.h /usr/include/bits/sigset.h \
 /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
 /usr/include/bits/pthreadtypes.h /usr/include/alloca.h \
 /usr/include/string.h /usr/include/xlocale.h /usr/include/strings.h \
 ../include/common.h ../include/char.h ../include/char_base.h \
 ../include/version.h ../include/skill.h ../include/util.h \
 /usr/include/sys/time.h ../include/title.h ../include/addressbook.h \
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
 ../include/item.h ../include/char.h ../include/char_data.h \
 ../include/battle.h ../include/trade.h ../include/item.h \
 ../include/buf.h ../include/function.h ../include/configfile.h \
 ../include/magic_base.h ../include/autil.h ../include/profession_skill.h
item_event.o: item_event.c ../include/version.h ../include/correct_bug.h \
 ../include/common.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/errno.h /usr/include/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../include/NewBilu/version.h ../include/NewBilu/debug.h \
 /usr/include/string.h /usr/include/xlocale.h /usr/include/ctype.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h ../include/common.h ../include/configfile.h \
 ../include/char.h ../include/char_base.h ../include/version.h \
 ../include/skill.h ../include/util.h /usr/include/sys/time.h \
 /usr/include/time.h /usr/include/bits/time.h /usr/include/sys/select.h \
 /usr/include/bits/select.h /usr/include/bits/sigset.h \
 /usr/include/stdlib.h /usr/include/bits/waitflags.h \
 /usr/include/bits/waitstatus.h /usr/include/sys/types.h \
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
 ../include/item.h ../include/char.h ../include/char_base.h \
 ../include/char_data.h ../include/battle_event.h ../include/item.h \
 ../include/item_event.h ../include/object.h ../include/anim_tbl.h \
 ../include/magic.h ../include/chatmagic.h ../include/handletime.h \
 ../include/log.h ../include/family.h ../include/util.h \
 ../include/encount.h ../include/battle.h ../include/trade.h \
 ../include/battle_item.h ../include/lssproto_serv.h \
 ../include/lssproto_util.h /usr/include/strings.h /usr/include/unistd.h \
 /usr/include/bits/posix_opt.h /usr/include/bits/environments.h \
 /usr/include/bits/confname.h /usr/include/getopt.h ../include/net.h \
 ../include/pet.h ../include/readmap.h ../include/npcutil.h \
 ../include/enemy.h ../include/saacproto_cli.h \
 ../include/saacproto_util.h ../include/char_talk.h \
 ../include/battle_magic.h ../include/pet_skill.h \
 ../include/npc_poolitemshop.h ../include/npc_freepetskillshop.h \
 ../include/mylua/function.h ../include/profession_skill.h \
 ../include/magic_base.h ../include/npc_petshop.h
item_gen.o: item_gen.c ../include/version.h ../include/correct_bug.h \
 ../include/common.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.4.7/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/errno.h /usr/include/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../include/NewBilu/version.h ../include/NewBilu/debug.h \
 /usr/include/stdlib.h /usr/include/bits/waitflags.h \
 /usr/include/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/bits/endian.h /usr/include/bits/byteswap.h \
 /usr/include/sys/types.h /usr/include/time.h /usr/include/sys/select.h \
 /usr/include/bits/select.h /usr/include/bits/sigset.h \
 /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
 /usr/include/bits/pthreadtypes.h /usr/include/alloca.h \
 /usr/include/string.h /usr/include/xlocale.h /usr/include/strings.h \
 /usr/include/ctype.h /usr/include/math.h /usr/include/bits/huge_val.h \
 /usr/include/bits/huge_valf.h /usr/include/bits/huge_vall.h \
 /usr/include/bits/inf.h /usr/include/bits/nan.h \
 /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h \
 ../include/autil.h ../include/version.h ../include/configfile.h \
 ../include/util.h /usr/include/sys/time.h ../include/buf.h \
 ../include/char.h ../include/char_base.h ../include/skill.h \
 ../include/util.h ../include/title.h ../include/addressbook.h \
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
 ../include/item.h ../include/char.h ../include/item.h \
 ../include/item_gen.h ../include/enemy.h ../include/log.h \
 ../include/saacproto_cli.h ../include/saacproto_util.h \
 /usr/include/unistd.h /usr/include/bits/posix_opt.h \
 /usr/include/bits/environments.h /usr/include/bits/confname.h \
 /usr/include/getopt.h ../include/family.h ../include/magic_base.h
