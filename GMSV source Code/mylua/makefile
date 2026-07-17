export CC=gcc
export RM=rm -f
export AR=ar cr
export MV=mv
export RANLIB=ranlib
export SED=sed


export SHELL=/bin/sh

INCFLAGS=-I. -I../include -I../include/lua

CFLAGS=-w -O3 -rdynamic $(INCFLAGS) -std=gnu89 -fcommon
#Pentium 4 (Intel)
#CFLAGS=-march=pentium4 -O3 -pipe -fomit-frame-pointer $(INCFLAGS)
#Athlon XP (AMD)
#CFLAGS="-march=athlon-xp -O3 -pipe -fomit-frame-pointer" $(INCFLAGS)
#Athlon64£º
#CFLAGS="-O2 -march=athlon64 -ftracer -fprefetch-loop-arrays -pipe" $(INCFLAGS)

PROG=libmylua.a

SRC=mylua.c ablua.c init.c charbase.c npcbase.c function.c lssprotobase.c battlebase.c objectbase.c mapbase.c otherbase.c configbase.c itembase.c magicbase.c offlinebase.c netbase.c enemytempbase.c sasqlbase.c saacproto.c family.c petskill.c

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
mylua.o: mylua.c /usr/include/stdc-predef.h /usr/include/signal.h \
 /usr/include/features.h /usr/include/features-time64.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/bits/timesize.h \
 /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/long-double.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h \
 /usr/include/x86_64-linux-gnu/bits/time64.h \
 /usr/include/x86_64-linux-gnu/bits/signum-generic.h \
 /usr/include/x86_64-linux-gnu/bits/signum-arch.h \
 /usr/include/x86_64-linux-gnu/bits/types/sig_atomic_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endianness.h \
 /usr/include/x86_64-linux-gnu/bits/types/time_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-arch.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-consts.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigevent_t.h \
 /usr/include/x86_64-linux-gnu/bits/sigevent-consts.h \
 /usr/include/x86_64-linux-gnu/bits/sigaction.h \
 /usr/include/x86_64-linux-gnu/bits/sigcontext.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h \
 /usr/include/x86_64-linux-gnu/bits/types/stack_t.h \
 /usr/include/x86_64-linux-gnu/sys/ucontext.h \
 /usr/include/x86_64-linux-gnu/bits/sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigstksz.h \
 /usr/include/x86_64-linux-gnu/bits/ss_flags.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/thread-shared-types.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h \
 /usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h \
 /usr/include/x86_64-linux-gnu/bits/struct_mutex.h \
 /usr/include/x86_64-linux-gnu/bits/struct_rwlock.h \
 /usr/include/x86_64-linux-gnu/bits/sigthread.h \
 /usr/include/x86_64-linux-gnu/bits/signal_ext.h /usr/include/stdio.h \
 /usr/include/x86_64-linux-gnu/bits/libc-header-start.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/cookie_io_functions_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/floatn.h \
 /usr/include/x86_64-linux-gnu/bits/floatn-common.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/bits/types/clock_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/clockid_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/timer_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-intn.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/uintn-identity.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timeval.h \
 /usr/include/alloca.h /usr/include/x86_64-linux-gnu/bits/stdlib-float.h \
 /usr/include/string.h \
 /usr/include/x86_64-linux-gnu/bits/types/locale_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h \
 /usr/include/strings.h /usr/include/dirent.h \
 /usr/include/x86_64-linux-gnu/bits/dirent.h \
 /usr/include/x86_64-linux-gnu/bits/posix1_lim.h \
 /usr/include/x86_64-linux-gnu/bits/local_lim.h \
 /usr/include/linux/limits.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min-dynamic.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min.h \
 /usr/include/x86_64-linux-gnu/bits/dirent_ext.h ../include/autil.h \
 ../include/version.h ../include/correct_bug.h ../include/common.h \
 /usr/include/errno.h /usr/include/x86_64-linux-gnu/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/x86_64-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../include/NewBilu/version.h ../include/NewBilu/debug.h ../include/buf.h \
 ../include/util.h /usr/include/x86_64-linux-gnu/sys/time.h \
 ../include/lua/lua.h ../include/lua/luaconf.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/limits.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/syslimits.h \
 /usr/include/limits.h /usr/include/x86_64-linux-gnu/bits/posix2_lim.h \
 ../include/lua/lauxlib.h ../include/lua/lua.h ../include/lua/lualib.h \
 ../include/NewBilu/version.h ../include/mylua/mylua.h
ablua.o: ablua.c /usr/include/stdc-predef.h /usr/include/pthread.h \
 /usr/include/features.h /usr/include/features-time64.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/bits/timesize.h \
 /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/long-double.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h /usr/include/sched.h \
 /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h \
 /usr/include/x86_64-linux-gnu/bits/time64.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h \
 /usr/include/x86_64-linux-gnu/bits/types/time_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endianness.h \
 /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sched_param.h \
 /usr/include/x86_64-linux-gnu/bits/cpu-set.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/clock_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_tm.h \
 /usr/include/x86_64-linux-gnu/bits/types/clockid_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/timer_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_itimerspec.h \
 /usr/include/x86_64-linux-gnu/bits/types/locale_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/thread-shared-types.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h \
 /usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h \
 /usr/include/x86_64-linux-gnu/bits/struct_mutex.h \
 /usr/include/x86_64-linux-gnu/bits/struct_rwlock.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct___jmp_buf_tag.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min-dynamic.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min.h \
 /usr/include/stdio.h \
 /usr/include/x86_64-linux-gnu/bits/libc-header-start.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/cookie_io_functions_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/floatn.h \
 /usr/include/x86_64-linux-gnu/bits/floatn-common.h /usr/include/dirent.h \
 /usr/include/x86_64-linux-gnu/bits/dirent.h \
 /usr/include/x86_64-linux-gnu/bits/posix1_lim.h \
 /usr/include/x86_64-linux-gnu/bits/local_lim.h \
 /usr/include/linux/limits.h \
 /usr/include/x86_64-linux-gnu/bits/dirent_ext.h /usr/include/string.h \
 /usr/include/strings.h /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-intn.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/uintn-identity.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timeval.h \
 /usr/include/x86_64-linux-gnu/sys/stat.h \
 /usr/include/x86_64-linux-gnu/bits/stat.h \
 /usr/include/x86_64-linux-gnu/bits/struct_stat.h ../include/autil.h \
 ../include/version.h ../include/correct_bug.h ../include/common.h \
 /usr/include/errno.h /usr/include/x86_64-linux-gnu/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/x86_64-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../include/NewBilu/version.h ../include/NewBilu/debug.h \
 ../include/util.h /usr/include/x86_64-linux-gnu/sys/time.h \
 /usr/include/stdlib.h /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h \
 ../include/mylua/mylua.h ../include/lua/lua.h ../include/lua/luaconf.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/limits.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/syslimits.h \
 /usr/include/limits.h /usr/include/x86_64-linux-gnu/bits/posix2_lim.h \
 ../include/lua/lauxlib.h ../include/lua/lua.h ../include/lua/lualib.h \
 ../include/mylua/base.h ../include/char_base.h ../include/skill.h \
 ../include/util.h ../include/title.h ../include/addressbook.h \
 ../include/net.h ../include/autil.h /usr/include/netinet/in.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-uintn.h \
 /usr/include/x86_64-linux-gnu/sys/socket.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_iovec.h \
 /usr/include/x86_64-linux-gnu/bits/socket.h \
 /usr/include/x86_64-linux-gnu/bits/socket_type.h \
 /usr/include/x86_64-linux-gnu/bits/sockaddr.h \
 /usr/include/x86_64-linux-gnu/asm/socket.h \
 /usr/include/asm-generic/socket.h /usr/include/linux/posix_types.h \
 /usr/include/linux/stddef.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types_64.h \
 /usr/include/asm-generic/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/bitsperlong.h \
 /usr/include/asm-generic/bitsperlong.h \
 /usr/include/x86_64-linux-gnu/asm/sockios.h \
 /usr/include/asm-generic/sockios.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_osockaddr.h \
 /usr/include/x86_64-linux-gnu/bits/in.h /usr/include/signal.h \
 /usr/include/x86_64-linux-gnu/bits/signum-generic.h \
 /usr/include/x86_64-linux-gnu/bits/signum-arch.h \
 /usr/include/x86_64-linux-gnu/bits/types/sig_atomic_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-arch.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-consts.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigevent_t.h \
 /usr/include/x86_64-linux-gnu/bits/sigevent-consts.h \
 /usr/include/x86_64-linux-gnu/bits/sigaction.h \
 /usr/include/x86_64-linux-gnu/bits/sigcontext.h \
 /usr/include/x86_64-linux-gnu/bits/types/stack_t.h \
 /usr/include/x86_64-linux-gnu/sys/ucontext.h \
 /usr/include/x86_64-linux-gnu/bits/sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigstksz.h \
 /usr/include/x86_64-linux-gnu/bits/ss_flags.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigthread.h \
 /usr/include/x86_64-linux-gnu/bits/signal_ext.h ../include/link.h \
 ../include/NewBilu/version.h
init.o: init.c /usr/include/stdc-predef.h ../include/lua/lua.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stdarg.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h \
 ../include/lua/luaconf.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/limits.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/syslimits.h \
 /usr/include/limits.h \
 /usr/include/x86_64-linux-gnu/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/features-time64.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/bits/timesize.h \
 /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/long-double.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/include/x86_64-linux-gnu/bits/posix1_lim.h \
 /usr/include/x86_64-linux-gnu/bits/local_lim.h \
 /usr/include/linux/limits.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min-dynamic.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min.h \
 /usr/include/x86_64-linux-gnu/bits/posix2_lim.h ../include/lua/lualib.h \
 ../include/lua/lua.h ../include/lua/lauxlib.h /usr/include/stdio.h \
 /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h \
 /usr/include/x86_64-linux-gnu/bits/time64.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/cookie_io_functions_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/floatn.h \
 /usr/include/x86_64-linux-gnu/bits/floatn-common.h \
 ../include/mylua/base.h ../include/char_base.h ../include/version.h \
 ../include/correct_bug.h ../include/common.h /usr/include/errno.h \
 /usr/include/x86_64-linux-gnu/bits/errno.h /usr/include/linux/errno.h \
 /usr/include/x86_64-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../include/NewBilu/version.h ../include/NewBilu/debug.h \
 ../include/skill.h ../include/util.h \
 /usr/include/x86_64-linux-gnu/sys/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/time_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timeval.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endianness.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/bits/types/clock_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/clockid_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/timer_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-intn.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/uintn-identity.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/thread-shared-types.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h \
 /usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h \
 /usr/include/x86_64-linux-gnu/bits/struct_mutex.h \
 /usr/include/x86_64-linux-gnu/bits/struct_rwlock.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h ../include/title.h \
 ../include/addressbook.h ../include/net.h ../include/autil.h \
 /usr/include/netinet/in.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-uintn.h \
 /usr/include/x86_64-linux-gnu/sys/socket.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_iovec.h \
 /usr/include/x86_64-linux-gnu/bits/socket.h \
 /usr/include/x86_64-linux-gnu/bits/socket_type.h \
 /usr/include/x86_64-linux-gnu/bits/sockaddr.h \
 /usr/include/x86_64-linux-gnu/asm/socket.h \
 /usr/include/asm-generic/socket.h /usr/include/linux/posix_types.h \
 /usr/include/linux/stddef.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types_64.h \
 /usr/include/asm-generic/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/bitsperlong.h \
 /usr/include/asm-generic/bitsperlong.h \
 /usr/include/x86_64-linux-gnu/asm/sockios.h \
 /usr/include/asm-generic/sockios.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_osockaddr.h \
 /usr/include/x86_64-linux-gnu/bits/in.h /usr/include/signal.h \
 /usr/include/x86_64-linux-gnu/bits/signum-generic.h \
 /usr/include/x86_64-linux-gnu/bits/signum-arch.h \
 /usr/include/x86_64-linux-gnu/bits/types/sig_atomic_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-arch.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-consts.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigevent_t.h \
 /usr/include/x86_64-linux-gnu/bits/sigevent-consts.h \
 /usr/include/x86_64-linux-gnu/bits/sigaction.h \
 /usr/include/x86_64-linux-gnu/bits/sigcontext.h \
 /usr/include/x86_64-linux-gnu/bits/types/stack_t.h \
 /usr/include/x86_64-linux-gnu/sys/ucontext.h \
 /usr/include/x86_64-linux-gnu/bits/sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigstksz.h \
 /usr/include/x86_64-linux-gnu/bits/ss_flags.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigthread.h \
 /usr/include/x86_64-linux-gnu/bits/signal_ext.h /usr/include/pthread.h \
 /usr/include/sched.h /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sched_param.h \
 /usr/include/x86_64-linux-gnu/bits/cpu-set.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_tm.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_itimerspec.h \
 /usr/include/x86_64-linux-gnu/bits/types/locale_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct___jmp_buf_tag.h \
 ../include/link.h
charbase.o: charbase.c /usr/include/stdc-predef.h /usr/include/string.h \
 /usr/include/x86_64-linux-gnu/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/features-time64.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/bits/timesize.h \
 /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/long-double.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h \
 /usr/include/x86_64-linux-gnu/bits/types/locale_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h \
 /usr/include/strings.h ../include/char.h ../include/common.h \
 /usr/include/stdio.h /usr/lib/gcc/x86_64-linux-gnu/13/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h \
 /usr/include/x86_64-linux-gnu/bits/time64.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/cookie_io_functions_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/floatn.h \
 /usr/include/x86_64-linux-gnu/bits/floatn-common.h /usr/include/errno.h \
 /usr/include/x86_64-linux-gnu/bits/errno.h /usr/include/linux/errno.h \
 /usr/include/x86_64-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../include/char_base.h ../include/version.h ../include/correct_bug.h \
 ../include/NewBilu/version.h ../include/NewBilu/debug.h \
 ../include/skill.h ../include/util.h \
 /usr/include/x86_64-linux-gnu/sys/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/time_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timeval.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endianness.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/bits/types/clock_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/clockid_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/timer_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-intn.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/uintn-identity.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/thread-shared-types.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h \
 /usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h \
 /usr/include/x86_64-linux-gnu/bits/struct_mutex.h \
 /usr/include/x86_64-linux-gnu/bits/struct_rwlock.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h ../include/title.h \
 ../include/addressbook.h ../include/net.h ../include/autil.h \
 /usr/include/netinet/in.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-uintn.h \
 /usr/include/x86_64-linux-gnu/sys/socket.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_iovec.h \
 /usr/include/x86_64-linux-gnu/bits/socket.h \
 /usr/include/x86_64-linux-gnu/bits/socket_type.h \
 /usr/include/x86_64-linux-gnu/bits/sockaddr.h \
 /usr/include/x86_64-linux-gnu/asm/socket.h \
 /usr/include/asm-generic/socket.h /usr/include/linux/posix_types.h \
 /usr/include/linux/stddef.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types_64.h \
 /usr/include/asm-generic/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/bitsperlong.h \
 /usr/include/asm-generic/bitsperlong.h \
 /usr/include/x86_64-linux-gnu/asm/sockios.h \
 /usr/include/asm-generic/sockios.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_osockaddr.h \
 /usr/include/x86_64-linux-gnu/bits/in.h /usr/include/signal.h \
 /usr/include/x86_64-linux-gnu/bits/signum-generic.h \
 /usr/include/x86_64-linux-gnu/bits/signum-arch.h \
 /usr/include/x86_64-linux-gnu/bits/types/sig_atomic_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-arch.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-consts.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigevent_t.h \
 /usr/include/x86_64-linux-gnu/bits/sigevent-consts.h \
 /usr/include/x86_64-linux-gnu/bits/sigaction.h \
 /usr/include/x86_64-linux-gnu/bits/sigcontext.h \
 /usr/include/x86_64-linux-gnu/bits/types/stack_t.h \
 /usr/include/x86_64-linux-gnu/sys/ucontext.h \
 /usr/include/x86_64-linux-gnu/bits/sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigstksz.h \
 /usr/include/x86_64-linux-gnu/bits/ss_flags.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigthread.h \
 /usr/include/x86_64-linux-gnu/bits/signal_ext.h /usr/include/pthread.h \
 /usr/include/sched.h /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sched_param.h \
 /usr/include/x86_64-linux-gnu/bits/cpu-set.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_tm.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_itimerspec.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct___jmp_buf_tag.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min-dynamic.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min.h ../include/link.h \
 ../include/lua/lua.h ../include/lua/luaconf.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/limits.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/syslimits.h \
 /usr/include/limits.h /usr/include/x86_64-linux-gnu/bits/posix1_lim.h \
 /usr/include/x86_64-linux-gnu/bits/local_lim.h \
 /usr/include/linux/limits.h \
 /usr/include/x86_64-linux-gnu/bits/posix2_lim.h ../include/lua/lauxlib.h \
 ../include/lua/lua.h ../include/lua/lualib.h ../include/char_data.h \
 ../include/item.h ../include/char.h ../include/battle.h \
 ../include/trade.h ../include/object.h ../include/char_base.h \
 ../include/enemy.h ../include/mylua/base.h ../include/npcutil.h \
 ../include/readmap.h ../include/log.h ../include/pet.h \
 ../include/NewBilu/version.h ../include/configfile.h \
 ../include/handletime.h ../include/item_event.h \
 ../include/lssproto_serv.h ../include/lssproto_util.h \
 /usr/include/unistd.h /usr/include/x86_64-linux-gnu/bits/posix_opt.h \
 /usr/include/x86_64-linux-gnu/bits/environments.h \
 /usr/include/x86_64-linux-gnu/bits/confname.h \
 /usr/include/x86_64-linux-gnu/bits/getopt_posix.h \
 /usr/include/x86_64-linux-gnu/bits/getopt_core.h \
 /usr/include/x86_64-linux-gnu/bits/unistd_ext.h ../include/npc_healer.h \
 ../include/pet_skill.h ../include/char_talk.h ../include/mylua/mylua.h
npcbase.o: npcbase.c /usr/include/stdc-predef.h /usr/include/string.h \
 /usr/include/x86_64-linux-gnu/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/features-time64.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/bits/timesize.h \
 /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/long-double.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h \
 /usr/include/x86_64-linux-gnu/bits/types/locale_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h \
 /usr/include/strings.h ../include/battle.h ../include/net.h \
 ../include/common.h /usr/include/stdio.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h \
 /usr/include/x86_64-linux-gnu/bits/time64.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/cookie_io_functions_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/floatn.h \
 /usr/include/x86_64-linux-gnu/bits/floatn-common.h /usr/include/errno.h \
 /usr/include/x86_64-linux-gnu/bits/errno.h /usr/include/linux/errno.h \
 /usr/include/x86_64-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../include/autil.h ../include/version.h ../include/correct_bug.h \
 ../include/NewBilu/version.h ../include/NewBilu/debug.h \
 /usr/include/x86_64-linux-gnu/sys/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/time_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timeval.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endianness.h \
 /usr/include/netinet/in.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-uintn.h \
 /usr/include/x86_64-linux-gnu/sys/socket.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_iovec.h \
 /usr/include/x86_64-linux-gnu/bits/socket.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/bits/types/clock_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/clockid_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/timer_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-intn.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/uintn-identity.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/thread-shared-types.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h \
 /usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h \
 /usr/include/x86_64-linux-gnu/bits/struct_mutex.h \
 /usr/include/x86_64-linux-gnu/bits/struct_rwlock.h \
 /usr/include/x86_64-linux-gnu/bits/socket_type.h \
 /usr/include/x86_64-linux-gnu/bits/sockaddr.h \
 /usr/include/x86_64-linux-gnu/asm/socket.h \
 /usr/include/asm-generic/socket.h /usr/include/linux/posix_types.h \
 /usr/include/linux/stddef.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types_64.h \
 /usr/include/asm-generic/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/bitsperlong.h \
 /usr/include/asm-generic/bitsperlong.h \
 /usr/include/x86_64-linux-gnu/asm/sockios.h \
 /usr/include/asm-generic/sockios.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_osockaddr.h \
 /usr/include/x86_64-linux-gnu/bits/in.h /usr/include/signal.h \
 /usr/include/x86_64-linux-gnu/bits/signum-generic.h \
 /usr/include/x86_64-linux-gnu/bits/signum-arch.h \
 /usr/include/x86_64-linux-gnu/bits/types/sig_atomic_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-arch.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-consts.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigevent_t.h \
 /usr/include/x86_64-linux-gnu/bits/sigevent-consts.h \
 /usr/include/x86_64-linux-gnu/bits/sigaction.h \
 /usr/include/x86_64-linux-gnu/bits/sigcontext.h \
 /usr/include/x86_64-linux-gnu/bits/types/stack_t.h \
 /usr/include/x86_64-linux-gnu/sys/ucontext.h \
 /usr/include/x86_64-linux-gnu/bits/sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigstksz.h \
 /usr/include/x86_64-linux-gnu/bits/ss_flags.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigthread.h \
 /usr/include/x86_64-linux-gnu/bits/signal_ext.h /usr/include/pthread.h \
 /usr/include/sched.h /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sched_param.h \
 /usr/include/x86_64-linux-gnu/bits/cpu-set.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_tm.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_itimerspec.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct___jmp_buf_tag.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min-dynamic.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min.h ../include/link.h \
 ../include/trade.h ../include/util.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h ../include/lua/lua.h \
 ../include/lua/luaconf.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/limits.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/syslimits.h \
 /usr/include/limits.h /usr/include/x86_64-linux-gnu/bits/posix1_lim.h \
 /usr/include/x86_64-linux-gnu/bits/local_lim.h \
 /usr/include/linux/limits.h \
 /usr/include/x86_64-linux-gnu/bits/posix2_lim.h ../include/lua/lauxlib.h \
 ../include/lua/lua.h ../include/lua/lualib.h ../include/char_base.h \
 ../include/skill.h ../include/title.h ../include/addressbook.h \
 ../include/npccreate.h ../include/object.h ../include/char.h \
 ../include/char_base.h ../include/char_data.h ../include/item.h \
 ../include/char.h ../include/enemy.h ../include/npc_eventaction.h \
 ../include/NewBilu/version.h ../include/npcutil.h ../include/log.h
function.o: function.c /usr/include/stdc-predef.h /usr/include/string.h \
 /usr/include/x86_64-linux-gnu/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/features-time64.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/bits/timesize.h \
 /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/long-double.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h \
 /usr/include/x86_64-linux-gnu/bits/types/locale_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h \
 /usr/include/strings.h ../include/common.h /usr/include/stdio.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h \
 /usr/include/x86_64-linux-gnu/bits/time64.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/cookie_io_functions_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/floatn.h \
 /usr/include/x86_64-linux-gnu/bits/floatn-common.h /usr/include/errno.h \
 /usr/include/x86_64-linux-gnu/bits/errno.h /usr/include/linux/errno.h \
 /usr/include/x86_64-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../include/char_base.h ../include/version.h ../include/correct_bug.h \
 ../include/common.h ../include/NewBilu/version.h \
 ../include/NewBilu/debug.h ../include/skill.h ../include/util.h \
 /usr/include/x86_64-linux-gnu/sys/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/time_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timeval.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endianness.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/bits/types/clock_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/clockid_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/timer_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-intn.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/uintn-identity.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/thread-shared-types.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h \
 /usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h \
 /usr/include/x86_64-linux-gnu/bits/struct_mutex.h \
 /usr/include/x86_64-linux-gnu/bits/struct_rwlock.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h ../include/title.h \
 ../include/addressbook.h ../include/net.h ../include/autil.h \
 /usr/include/netinet/in.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-uintn.h \
 /usr/include/x86_64-linux-gnu/sys/socket.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_iovec.h \
 /usr/include/x86_64-linux-gnu/bits/socket.h \
 /usr/include/x86_64-linux-gnu/bits/socket_type.h \
 /usr/include/x86_64-linux-gnu/bits/sockaddr.h \
 /usr/include/x86_64-linux-gnu/asm/socket.h \
 /usr/include/asm-generic/socket.h /usr/include/linux/posix_types.h \
 /usr/include/linux/stddef.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types_64.h \
 /usr/include/asm-generic/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/bitsperlong.h \
 /usr/include/asm-generic/bitsperlong.h \
 /usr/include/x86_64-linux-gnu/asm/sockios.h \
 /usr/include/asm-generic/sockios.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_osockaddr.h \
 /usr/include/x86_64-linux-gnu/bits/in.h /usr/include/signal.h \
 /usr/include/x86_64-linux-gnu/bits/signum-generic.h \
 /usr/include/x86_64-linux-gnu/bits/signum-arch.h \
 /usr/include/x86_64-linux-gnu/bits/types/sig_atomic_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-arch.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-consts.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigevent_t.h \
 /usr/include/x86_64-linux-gnu/bits/sigevent-consts.h \
 /usr/include/x86_64-linux-gnu/bits/sigaction.h \
 /usr/include/x86_64-linux-gnu/bits/sigcontext.h \
 /usr/include/x86_64-linux-gnu/bits/types/stack_t.h \
 /usr/include/x86_64-linux-gnu/sys/ucontext.h \
 /usr/include/x86_64-linux-gnu/bits/sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigstksz.h \
 /usr/include/x86_64-linux-gnu/bits/ss_flags.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigthread.h \
 /usr/include/x86_64-linux-gnu/bits/signal_ext.h /usr/include/pthread.h \
 /usr/include/sched.h /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sched_param.h \
 /usr/include/x86_64-linux-gnu/bits/cpu-set.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_tm.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_itimerspec.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct___jmp_buf_tag.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min-dynamic.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min.h ../include/link.h \
 ../include/lua/lua.h ../include/lua/luaconf.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/limits.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/syslimits.h \
 /usr/include/limits.h /usr/include/x86_64-linux-gnu/bits/posix1_lim.h \
 /usr/include/x86_64-linux-gnu/bits/local_lim.h \
 /usr/include/linux/limits.h \
 /usr/include/x86_64-linux-gnu/bits/posix2_lim.h ../include/lua/lauxlib.h \
 ../include/lua/lua.h ../include/lua/lualib.h ../include/item.h \
 ../include/configfile.h ../include/battle.h ../include/trade.h \
 ../include/mylua/base.h ../include/NewBilu/version.h \
 ../include/mylua/mylua.h
lssprotobase.o: lssprotobase.c /usr/include/stdc-predef.h \
 /usr/include/string.h \
 /usr/include/x86_64-linux-gnu/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/features-time64.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/bits/timesize.h \
 /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/long-double.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h \
 /usr/include/x86_64-linux-gnu/bits/types/locale_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h \
 /usr/include/strings.h /usr/include/stdio.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h \
 /usr/include/x86_64-linux-gnu/bits/time64.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/cookie_io_functions_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/floatn.h \
 /usr/include/x86_64-linux-gnu/bits/floatn-common.h /usr/include/math.h \
 /usr/include/x86_64-linux-gnu/bits/math-vector.h \
 /usr/include/x86_64-linux-gnu/bits/libm-simd-decl-stubs.h \
 /usr/include/x86_64-linux-gnu/bits/flt-eval-method.h \
 /usr/include/x86_64-linux-gnu/bits/fp-logb.h \
 /usr/include/x86_64-linux-gnu/bits/fp-fast.h \
 /usr/include/x86_64-linux-gnu/bits/mathcalls-helper-functions.h \
 /usr/include/x86_64-linux-gnu/bits/mathcalls.h ../include/char.h \
 ../include/common.h /usr/include/errno.h \
 /usr/include/x86_64-linux-gnu/bits/errno.h /usr/include/linux/errno.h \
 /usr/include/x86_64-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../include/char_base.h ../include/version.h ../include/correct_bug.h \
 ../include/NewBilu/version.h ../include/NewBilu/debug.h \
 ../include/skill.h ../include/util.h \
 /usr/include/x86_64-linux-gnu/sys/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/time_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timeval.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endianness.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/bits/types/clock_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/clockid_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/timer_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-intn.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/uintn-identity.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/thread-shared-types.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h \
 /usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h \
 /usr/include/x86_64-linux-gnu/bits/struct_mutex.h \
 /usr/include/x86_64-linux-gnu/bits/struct_rwlock.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h ../include/title.h \
 ../include/addressbook.h ../include/net.h ../include/autil.h \
 /usr/include/netinet/in.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-uintn.h \
 /usr/include/x86_64-linux-gnu/sys/socket.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_iovec.h \
 /usr/include/x86_64-linux-gnu/bits/socket.h \
 /usr/include/x86_64-linux-gnu/bits/socket_type.h \
 /usr/include/x86_64-linux-gnu/bits/sockaddr.h \
 /usr/include/x86_64-linux-gnu/asm/socket.h \
 /usr/include/asm-generic/socket.h /usr/include/linux/posix_types.h \
 /usr/include/linux/stddef.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types_64.h \
 /usr/include/asm-generic/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/bitsperlong.h \
 /usr/include/asm-generic/bitsperlong.h \
 /usr/include/x86_64-linux-gnu/asm/sockios.h \
 /usr/include/asm-generic/sockios.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_osockaddr.h \
 /usr/include/x86_64-linux-gnu/bits/in.h /usr/include/signal.h \
 /usr/include/x86_64-linux-gnu/bits/signum-generic.h \
 /usr/include/x86_64-linux-gnu/bits/signum-arch.h \
 /usr/include/x86_64-linux-gnu/bits/types/sig_atomic_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-arch.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-consts.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigevent_t.h \
 /usr/include/x86_64-linux-gnu/bits/sigevent-consts.h \
 /usr/include/x86_64-linux-gnu/bits/sigaction.h \
 /usr/include/x86_64-linux-gnu/bits/sigcontext.h \
 /usr/include/x86_64-linux-gnu/bits/types/stack_t.h \
 /usr/include/x86_64-linux-gnu/sys/ucontext.h \
 /usr/include/x86_64-linux-gnu/bits/sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigstksz.h \
 /usr/include/x86_64-linux-gnu/bits/ss_flags.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigthread.h \
 /usr/include/x86_64-linux-gnu/bits/signal_ext.h /usr/include/pthread.h \
 /usr/include/sched.h /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sched_param.h \
 /usr/include/x86_64-linux-gnu/bits/cpu-set.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_tm.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_itimerspec.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct___jmp_buf_tag.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min-dynamic.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min.h ../include/link.h \
 ../include/lua/lua.h ../include/lua/luaconf.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/limits.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/syslimits.h \
 /usr/include/limits.h /usr/include/x86_64-linux-gnu/bits/posix1_lim.h \
 /usr/include/x86_64-linux-gnu/bits/local_lim.h \
 /usr/include/linux/limits.h \
 /usr/include/x86_64-linux-gnu/bits/posix2_lim.h ../include/lua/lauxlib.h \
 ../include/lua/lua.h ../include/lua/lualib.h ../include/char_data.h \
 ../include/item.h ../include/char.h ../include/char_base.h \
 ../include/mylua/base.h ../include/lssproto_serv.h \
 ../include/lssproto_util.h /usr/include/unistd.h \
 /usr/include/x86_64-linux-gnu/bits/posix_opt.h \
 /usr/include/x86_64-linux-gnu/bits/environments.h \
 /usr/include/x86_64-linux-gnu/bits/confname.h \
 /usr/include/x86_64-linux-gnu/bits/getopt_posix.h \
 /usr/include/x86_64-linux-gnu/bits/getopt_core.h \
 /usr/include/x86_64-linux-gnu/bits/unistd_ext.h
battlebase.o: battlebase.c /usr/include/stdc-predef.h \
 /usr/include/string.h \
 /usr/include/x86_64-linux-gnu/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/features-time64.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/bits/timesize.h \
 /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/long-double.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h \
 /usr/include/x86_64-linux-gnu/bits/types/locale_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h \
 /usr/include/strings.h ../include/NewBilu/version.h \
 ../include/char_base.h ../include/version.h ../include/correct_bug.h \
 ../include/common.h /usr/include/stdio.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h \
 /usr/include/x86_64-linux-gnu/bits/time64.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/cookie_io_functions_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/floatn.h \
 /usr/include/x86_64-linux-gnu/bits/floatn-common.h /usr/include/errno.h \
 /usr/include/x86_64-linux-gnu/bits/errno.h /usr/include/linux/errno.h \
 /usr/include/x86_64-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../include/NewBilu/version.h ../include/NewBilu/debug.h \
 ../include/skill.h ../include/util.h \
 /usr/include/x86_64-linux-gnu/sys/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/time_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timeval.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endianness.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/bits/types/clock_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/clockid_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/timer_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-intn.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/uintn-identity.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/thread-shared-types.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h \
 /usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h \
 /usr/include/x86_64-linux-gnu/bits/struct_mutex.h \
 /usr/include/x86_64-linux-gnu/bits/struct_rwlock.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h ../include/title.h \
 ../include/addressbook.h ../include/net.h ../include/autil.h \
 /usr/include/netinet/in.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-uintn.h \
 /usr/include/x86_64-linux-gnu/sys/socket.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_iovec.h \
 /usr/include/x86_64-linux-gnu/bits/socket.h \
 /usr/include/x86_64-linux-gnu/bits/socket_type.h \
 /usr/include/x86_64-linux-gnu/bits/sockaddr.h \
 /usr/include/x86_64-linux-gnu/asm/socket.h \
 /usr/include/asm-generic/socket.h /usr/include/linux/posix_types.h \
 /usr/include/linux/stddef.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types_64.h \
 /usr/include/asm-generic/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/bitsperlong.h \
 /usr/include/asm-generic/bitsperlong.h \
 /usr/include/x86_64-linux-gnu/asm/sockios.h \
 /usr/include/asm-generic/sockios.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_osockaddr.h \
 /usr/include/x86_64-linux-gnu/bits/in.h /usr/include/signal.h \
 /usr/include/x86_64-linux-gnu/bits/signum-generic.h \
 /usr/include/x86_64-linux-gnu/bits/signum-arch.h \
 /usr/include/x86_64-linux-gnu/bits/types/sig_atomic_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-arch.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-consts.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigevent_t.h \
 /usr/include/x86_64-linux-gnu/bits/sigevent-consts.h \
 /usr/include/x86_64-linux-gnu/bits/sigaction.h \
 /usr/include/x86_64-linux-gnu/bits/sigcontext.h \
 /usr/include/x86_64-linux-gnu/bits/types/stack_t.h \
 /usr/include/x86_64-linux-gnu/sys/ucontext.h \
 /usr/include/x86_64-linux-gnu/bits/sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigstksz.h \
 /usr/include/x86_64-linux-gnu/bits/ss_flags.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigthread.h \
 /usr/include/x86_64-linux-gnu/bits/signal_ext.h /usr/include/pthread.h \
 /usr/include/sched.h /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sched_param.h \
 /usr/include/x86_64-linux-gnu/bits/cpu-set.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_tm.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_itimerspec.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct___jmp_buf_tag.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min-dynamic.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min.h ../include/link.h \
 ../include/lua/lua.h ../include/lua/luaconf.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/limits.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/syslimits.h \
 /usr/include/limits.h /usr/include/x86_64-linux-gnu/bits/posix1_lim.h \
 /usr/include/x86_64-linux-gnu/bits/local_lim.h \
 /usr/include/linux/limits.h \
 /usr/include/x86_64-linux-gnu/bits/posix2_lim.h ../include/lua/lauxlib.h \
 ../include/lua/lua.h ../include/lua/lualib.h ../include/enemy.h \
 ../include/object.h ../include/char.h ../include/char_base.h \
 ../include/char_data.h ../include/item.h ../include/char.h \
 ../include/lssproto_serv.h ../include/lssproto_util.h \
 /usr/include/unistd.h /usr/include/x86_64-linux-gnu/bits/posix_opt.h \
 /usr/include/x86_64-linux-gnu/bits/environments.h \
 /usr/include/x86_64-linux-gnu/bits/confname.h \
 /usr/include/x86_64-linux-gnu/bits/getopt_posix.h \
 /usr/include/x86_64-linux-gnu/bits/getopt_core.h \
 /usr/include/x86_64-linux-gnu/bits/unistd_ext.h ../include/battle.h \
 ../include/trade.h ../include/battle_command.h ../include/mylua/mylua.h \
 ../include/mylua/base.h
objectbase.o: objectbase.c /usr/include/stdc-predef.h \
 /usr/include/string.h \
 /usr/include/x86_64-linux-gnu/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/features-time64.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/bits/timesize.h \
 /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/long-double.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h \
 /usr/include/x86_64-linux-gnu/bits/types/locale_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h \
 /usr/include/strings.h ../include/char_base.h ../include/version.h \
 ../include/correct_bug.h ../include/common.h /usr/include/stdio.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h \
 /usr/include/x86_64-linux-gnu/bits/time64.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/cookie_io_functions_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/floatn.h \
 /usr/include/x86_64-linux-gnu/bits/floatn-common.h /usr/include/errno.h \
 /usr/include/x86_64-linux-gnu/bits/errno.h /usr/include/linux/errno.h \
 /usr/include/x86_64-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../include/NewBilu/version.h ../include/NewBilu/debug.h \
 ../include/skill.h ../include/util.h \
 /usr/include/x86_64-linux-gnu/sys/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/time_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timeval.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endianness.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/bits/types/clock_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/clockid_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/timer_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-intn.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/uintn-identity.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/thread-shared-types.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h \
 /usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h \
 /usr/include/x86_64-linux-gnu/bits/struct_mutex.h \
 /usr/include/x86_64-linux-gnu/bits/struct_rwlock.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h ../include/title.h \
 ../include/addressbook.h ../include/net.h ../include/autil.h \
 /usr/include/netinet/in.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-uintn.h \
 /usr/include/x86_64-linux-gnu/sys/socket.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_iovec.h \
 /usr/include/x86_64-linux-gnu/bits/socket.h \
 /usr/include/x86_64-linux-gnu/bits/socket_type.h \
 /usr/include/x86_64-linux-gnu/bits/sockaddr.h \
 /usr/include/x86_64-linux-gnu/asm/socket.h \
 /usr/include/asm-generic/socket.h /usr/include/linux/posix_types.h \
 /usr/include/linux/stddef.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types_64.h \
 /usr/include/asm-generic/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/bitsperlong.h \
 /usr/include/asm-generic/bitsperlong.h \
 /usr/include/x86_64-linux-gnu/asm/sockios.h \
 /usr/include/asm-generic/sockios.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_osockaddr.h \
 /usr/include/x86_64-linux-gnu/bits/in.h /usr/include/signal.h \
 /usr/include/x86_64-linux-gnu/bits/signum-generic.h \
 /usr/include/x86_64-linux-gnu/bits/signum-arch.h \
 /usr/include/x86_64-linux-gnu/bits/types/sig_atomic_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-arch.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-consts.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigevent_t.h \
 /usr/include/x86_64-linux-gnu/bits/sigevent-consts.h \
 /usr/include/x86_64-linux-gnu/bits/sigaction.h \
 /usr/include/x86_64-linux-gnu/bits/sigcontext.h \
 /usr/include/x86_64-linux-gnu/bits/types/stack_t.h \
 /usr/include/x86_64-linux-gnu/sys/ucontext.h \
 /usr/include/x86_64-linux-gnu/bits/sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigstksz.h \
 /usr/include/x86_64-linux-gnu/bits/ss_flags.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigthread.h \
 /usr/include/x86_64-linux-gnu/bits/signal_ext.h /usr/include/pthread.h \
 /usr/include/sched.h /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sched_param.h \
 /usr/include/x86_64-linux-gnu/bits/cpu-set.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_tm.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_itimerspec.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct___jmp_buf_tag.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min-dynamic.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min.h ../include/link.h \
 ../include/lua/lua.h ../include/lua/luaconf.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/limits.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/syslimits.h \
 /usr/include/limits.h /usr/include/x86_64-linux-gnu/bits/posix1_lim.h \
 /usr/include/x86_64-linux-gnu/bits/local_lim.h \
 /usr/include/linux/limits.h \
 /usr/include/x86_64-linux-gnu/bits/posix2_lim.h ../include/lua/lauxlib.h \
 ../include/lua/lua.h ../include/lua/lualib.h ../include/object.h \
 ../include/NewBilu/version.h ../include/mylua/base.h
mapbase.o: mapbase.c /usr/include/stdc-predef.h /usr/include/string.h \
 /usr/include/x86_64-linux-gnu/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/features-time64.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/bits/timesize.h \
 /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/long-double.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h \
 /usr/include/x86_64-linux-gnu/bits/types/locale_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h \
 /usr/include/strings.h /usr/include/stdio.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h \
 /usr/include/x86_64-linux-gnu/bits/time64.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/cookie_io_functions_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/floatn.h \
 /usr/include/x86_64-linux-gnu/bits/floatn-common.h ../include/char.h \
 ../include/common.h /usr/include/errno.h \
 /usr/include/x86_64-linux-gnu/bits/errno.h /usr/include/linux/errno.h \
 /usr/include/x86_64-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../include/char_base.h ../include/version.h ../include/correct_bug.h \
 ../include/NewBilu/version.h ../include/NewBilu/debug.h \
 ../include/skill.h ../include/util.h \
 /usr/include/x86_64-linux-gnu/sys/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/time_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timeval.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endianness.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/bits/types/clock_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/clockid_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/timer_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-intn.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/uintn-identity.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/thread-shared-types.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h \
 /usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h \
 /usr/include/x86_64-linux-gnu/bits/struct_mutex.h \
 /usr/include/x86_64-linux-gnu/bits/struct_rwlock.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h ../include/title.h \
 ../include/addressbook.h ../include/net.h ../include/autil.h \
 /usr/include/netinet/in.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-uintn.h \
 /usr/include/x86_64-linux-gnu/sys/socket.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_iovec.h \
 /usr/include/x86_64-linux-gnu/bits/socket.h \
 /usr/include/x86_64-linux-gnu/bits/socket_type.h \
 /usr/include/x86_64-linux-gnu/bits/sockaddr.h \
 /usr/include/x86_64-linux-gnu/asm/socket.h \
 /usr/include/asm-generic/socket.h /usr/include/linux/posix_types.h \
 /usr/include/linux/stddef.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types_64.h \
 /usr/include/asm-generic/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/bitsperlong.h \
 /usr/include/asm-generic/bitsperlong.h \
 /usr/include/x86_64-linux-gnu/asm/sockios.h \
 /usr/include/asm-generic/sockios.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_osockaddr.h \
 /usr/include/x86_64-linux-gnu/bits/in.h /usr/include/signal.h \
 /usr/include/x86_64-linux-gnu/bits/signum-generic.h \
 /usr/include/x86_64-linux-gnu/bits/signum-arch.h \
 /usr/include/x86_64-linux-gnu/bits/types/sig_atomic_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-arch.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-consts.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigevent_t.h \
 /usr/include/x86_64-linux-gnu/bits/sigevent-consts.h \
 /usr/include/x86_64-linux-gnu/bits/sigaction.h \
 /usr/include/x86_64-linux-gnu/bits/sigcontext.h \
 /usr/include/x86_64-linux-gnu/bits/types/stack_t.h \
 /usr/include/x86_64-linux-gnu/sys/ucontext.h \
 /usr/include/x86_64-linux-gnu/bits/sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigstksz.h \
 /usr/include/x86_64-linux-gnu/bits/ss_flags.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigthread.h \
 /usr/include/x86_64-linux-gnu/bits/signal_ext.h /usr/include/pthread.h \
 /usr/include/sched.h /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sched_param.h \
 /usr/include/x86_64-linux-gnu/bits/cpu-set.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_tm.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_itimerspec.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct___jmp_buf_tag.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min-dynamic.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min.h ../include/link.h \
 ../include/lua/lua.h ../include/lua/luaconf.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/limits.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/syslimits.h \
 /usr/include/limits.h /usr/include/x86_64-linux-gnu/bits/posix1_lim.h \
 /usr/include/x86_64-linux-gnu/bits/local_lim.h \
 /usr/include/linux/limits.h \
 /usr/include/x86_64-linux-gnu/bits/posix2_lim.h ../include/lua/lauxlib.h \
 ../include/lua/lua.h ../include/lua/lualib.h ../include/char_data.h \
 ../include/item.h ../include/char.h ../include/object.h \
 ../include/readmap.h ../include/map_deal.h ../include/char_base.h \
 ../include/battle.h ../include/trade.h ../include/mylua/base.h \
 ../include/lssproto_serv.h ../include/lssproto_util.h \
 /usr/include/unistd.h /usr/include/x86_64-linux-gnu/bits/posix_opt.h \
 /usr/include/x86_64-linux-gnu/bits/environments.h \
 /usr/include/x86_64-linux-gnu/bits/confname.h \
 /usr/include/x86_64-linux-gnu/bits/getopt_posix.h \
 /usr/include/x86_64-linux-gnu/bits/getopt_core.h \
 /usr/include/x86_64-linux-gnu/bits/unistd_ext.h
otherbase.o: otherbase.c /usr/include/stdc-predef.h /usr/include/string.h \
 /usr/include/x86_64-linux-gnu/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/features-time64.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/bits/timesize.h \
 /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/long-double.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h \
 /usr/include/x86_64-linux-gnu/bits/types/locale_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h \
 /usr/include/strings.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h \
 /usr/include/x86_64-linux-gnu/bits/time64.h \
 /usr/include/x86_64-linux-gnu/bits/types/clock_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/time_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_tm.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endianness.h \
 /usr/include/x86_64-linux-gnu/bits/types/clockid_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/timer_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_itimerspec.h \
 /usr/include/x86_64-linux-gnu/sys/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timeval.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h ../include/char.h \
 ../include/common.h /usr/include/stdio.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/cookie_io_functions_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/floatn.h \
 /usr/include/x86_64-linux-gnu/bits/floatn-common.h /usr/include/errno.h \
 /usr/include/x86_64-linux-gnu/bits/errno.h /usr/include/linux/errno.h \
 /usr/include/x86_64-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../include/char_base.h ../include/version.h ../include/correct_bug.h \
 ../include/NewBilu/version.h ../include/NewBilu/debug.h \
 ../include/skill.h ../include/util.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-intn.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/uintn-identity.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/thread-shared-types.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h \
 /usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h \
 /usr/include/x86_64-linux-gnu/bits/struct_mutex.h \
 /usr/include/x86_64-linux-gnu/bits/struct_rwlock.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h ../include/title.h \
 ../include/addressbook.h ../include/net.h ../include/autil.h \
 /usr/include/netinet/in.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-uintn.h \
 /usr/include/x86_64-linux-gnu/sys/socket.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_iovec.h \
 /usr/include/x86_64-linux-gnu/bits/socket.h \
 /usr/include/x86_64-linux-gnu/bits/socket_type.h \
 /usr/include/x86_64-linux-gnu/bits/sockaddr.h \
 /usr/include/x86_64-linux-gnu/asm/socket.h \
 /usr/include/asm-generic/socket.h /usr/include/linux/posix_types.h \
 /usr/include/linux/stddef.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types_64.h \
 /usr/include/asm-generic/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/bitsperlong.h \
 /usr/include/asm-generic/bitsperlong.h \
 /usr/include/x86_64-linux-gnu/asm/sockios.h \
 /usr/include/asm-generic/sockios.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_osockaddr.h \
 /usr/include/x86_64-linux-gnu/bits/in.h /usr/include/signal.h \
 /usr/include/x86_64-linux-gnu/bits/signum-generic.h \
 /usr/include/x86_64-linux-gnu/bits/signum-arch.h \
 /usr/include/x86_64-linux-gnu/bits/types/sig_atomic_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-arch.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-consts.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigevent_t.h \
 /usr/include/x86_64-linux-gnu/bits/sigevent-consts.h \
 /usr/include/x86_64-linux-gnu/bits/sigaction.h \
 /usr/include/x86_64-linux-gnu/bits/sigcontext.h \
 /usr/include/x86_64-linux-gnu/bits/types/stack_t.h \
 /usr/include/x86_64-linux-gnu/sys/ucontext.h \
 /usr/include/x86_64-linux-gnu/bits/sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigstksz.h \
 /usr/include/x86_64-linux-gnu/bits/ss_flags.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigthread.h \
 /usr/include/x86_64-linux-gnu/bits/signal_ext.h /usr/include/pthread.h \
 /usr/include/sched.h /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sched_param.h \
 /usr/include/x86_64-linux-gnu/bits/cpu-set.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct___jmp_buf_tag.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min-dynamic.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min.h ../include/link.h \
 ../include/lua/lua.h ../include/lua/luaconf.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/limits.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/syslimits.h \
 /usr/include/limits.h /usr/include/x86_64-linux-gnu/bits/posix1_lim.h \
 /usr/include/x86_64-linux-gnu/bits/local_lim.h \
 /usr/include/linux/limits.h \
 /usr/include/x86_64-linux-gnu/bits/posix2_lim.h ../include/lua/lauxlib.h \
 ../include/lua/lua.h ../include/lua/lualib.h ../include/char_data.h \
 ../include/item.h ../include/char.h ../include/char_base.h \
 ../include/mylua/base.h ../include/util.h ../include/lssproto_serv.h \
 ../include/lssproto_util.h /usr/include/unistd.h \
 /usr/include/x86_64-linux-gnu/bits/posix_opt.h \
 /usr/include/x86_64-linux-gnu/bits/environments.h \
 /usr/include/x86_64-linux-gnu/bits/confname.h \
 /usr/include/x86_64-linux-gnu/bits/getopt_posix.h \
 /usr/include/x86_64-linux-gnu/bits/getopt_core.h \
 /usr/include/x86_64-linux-gnu/bits/unistd_ext.h ../include/mylua/mylua.h
configbase.o: configbase.c /usr/include/stdc-predef.h \
 /usr/include/string.h \
 /usr/include/x86_64-linux-gnu/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/features-time64.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/bits/timesize.h \
 /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/long-double.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h \
 /usr/include/x86_64-linux-gnu/bits/types/locale_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h \
 /usr/include/strings.h ../include/char.h ../include/common.h \
 /usr/include/stdio.h /usr/lib/gcc/x86_64-linux-gnu/13/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h \
 /usr/include/x86_64-linux-gnu/bits/time64.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/cookie_io_functions_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/floatn.h \
 /usr/include/x86_64-linux-gnu/bits/floatn-common.h /usr/include/errno.h \
 /usr/include/x86_64-linux-gnu/bits/errno.h /usr/include/linux/errno.h \
 /usr/include/x86_64-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../include/char_base.h ../include/version.h ../include/correct_bug.h \
 ../include/NewBilu/version.h ../include/NewBilu/debug.h \
 ../include/skill.h ../include/util.h \
 /usr/include/x86_64-linux-gnu/sys/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/time_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timeval.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endianness.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/bits/types/clock_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/clockid_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/timer_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-intn.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/uintn-identity.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/thread-shared-types.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h \
 /usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h \
 /usr/include/x86_64-linux-gnu/bits/struct_mutex.h \
 /usr/include/x86_64-linux-gnu/bits/struct_rwlock.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h ../include/title.h \
 ../include/addressbook.h ../include/net.h ../include/autil.h \
 /usr/include/netinet/in.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-uintn.h \
 /usr/include/x86_64-linux-gnu/sys/socket.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_iovec.h \
 /usr/include/x86_64-linux-gnu/bits/socket.h \
 /usr/include/x86_64-linux-gnu/bits/socket_type.h \
 /usr/include/x86_64-linux-gnu/bits/sockaddr.h \
 /usr/include/x86_64-linux-gnu/asm/socket.h \
 /usr/include/asm-generic/socket.h /usr/include/linux/posix_types.h \
 /usr/include/linux/stddef.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types_64.h \
 /usr/include/asm-generic/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/bitsperlong.h \
 /usr/include/asm-generic/bitsperlong.h \
 /usr/include/x86_64-linux-gnu/asm/sockios.h \
 /usr/include/asm-generic/sockios.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_osockaddr.h \
 /usr/include/x86_64-linux-gnu/bits/in.h /usr/include/signal.h \
 /usr/include/x86_64-linux-gnu/bits/signum-generic.h \
 /usr/include/x86_64-linux-gnu/bits/signum-arch.h \
 /usr/include/x86_64-linux-gnu/bits/types/sig_atomic_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-arch.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-consts.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigevent_t.h \
 /usr/include/x86_64-linux-gnu/bits/sigevent-consts.h \
 /usr/include/x86_64-linux-gnu/bits/sigaction.h \
 /usr/include/x86_64-linux-gnu/bits/sigcontext.h \
 /usr/include/x86_64-linux-gnu/bits/types/stack_t.h \
 /usr/include/x86_64-linux-gnu/sys/ucontext.h \
 /usr/include/x86_64-linux-gnu/bits/sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigstksz.h \
 /usr/include/x86_64-linux-gnu/bits/ss_flags.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigthread.h \
 /usr/include/x86_64-linux-gnu/bits/signal_ext.h /usr/include/pthread.h \
 /usr/include/sched.h /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sched_param.h \
 /usr/include/x86_64-linux-gnu/bits/cpu-set.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_tm.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_itimerspec.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct___jmp_buf_tag.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min-dynamic.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min.h ../include/link.h \
 ../include/lua/lua.h ../include/lua/luaconf.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/limits.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/syslimits.h \
 /usr/include/limits.h /usr/include/x86_64-linux-gnu/bits/posix1_lim.h \
 /usr/include/x86_64-linux-gnu/bits/local_lim.h \
 /usr/include/linux/limits.h \
 /usr/include/x86_64-linux-gnu/bits/posix2_lim.h ../include/lua/lauxlib.h \
 ../include/lua/lua.h ../include/lua/lualib.h ../include/char_data.h \
 ../include/item.h ../include/char.h ../include/char_base.h \
 ../include/mylua/base.h ../include/configfile.h
itembase.o: itembase.c /usr/include/stdc-predef.h /usr/include/string.h \
 /usr/include/x86_64-linux-gnu/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/features-time64.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/bits/timesize.h \
 /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/long-double.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h \
 /usr/include/x86_64-linux-gnu/bits/types/locale_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h \
 /usr/include/strings.h ../include/common.h /usr/include/stdio.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h \
 /usr/include/x86_64-linux-gnu/bits/time64.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/cookie_io_functions_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/floatn.h \
 /usr/include/x86_64-linux-gnu/bits/floatn-common.h /usr/include/errno.h \
 /usr/include/x86_64-linux-gnu/bits/errno.h /usr/include/linux/errno.h \
 /usr/include/x86_64-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../include/char_base.h ../include/version.h ../include/correct_bug.h \
 ../include/common.h ../include/NewBilu/version.h \
 ../include/NewBilu/debug.h ../include/skill.h ../include/util.h \
 /usr/include/x86_64-linux-gnu/sys/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/time_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timeval.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endianness.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/bits/types/clock_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/clockid_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/timer_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-intn.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/uintn-identity.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/thread-shared-types.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h \
 /usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h \
 /usr/include/x86_64-linux-gnu/bits/struct_mutex.h \
 /usr/include/x86_64-linux-gnu/bits/struct_rwlock.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h ../include/title.h \
 ../include/addressbook.h ../include/net.h ../include/autil.h \
 /usr/include/netinet/in.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-uintn.h \
 /usr/include/x86_64-linux-gnu/sys/socket.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_iovec.h \
 /usr/include/x86_64-linux-gnu/bits/socket.h \
 /usr/include/x86_64-linux-gnu/bits/socket_type.h \
 /usr/include/x86_64-linux-gnu/bits/sockaddr.h \
 /usr/include/x86_64-linux-gnu/asm/socket.h \
 /usr/include/asm-generic/socket.h /usr/include/linux/posix_types.h \
 /usr/include/linux/stddef.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types_64.h \
 /usr/include/asm-generic/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/bitsperlong.h \
 /usr/include/asm-generic/bitsperlong.h \
 /usr/include/x86_64-linux-gnu/asm/sockios.h \
 /usr/include/asm-generic/sockios.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_osockaddr.h \
 /usr/include/x86_64-linux-gnu/bits/in.h /usr/include/signal.h \
 /usr/include/x86_64-linux-gnu/bits/signum-generic.h \
 /usr/include/x86_64-linux-gnu/bits/signum-arch.h \
 /usr/include/x86_64-linux-gnu/bits/types/sig_atomic_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-arch.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-consts.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigevent_t.h \
 /usr/include/x86_64-linux-gnu/bits/sigevent-consts.h \
 /usr/include/x86_64-linux-gnu/bits/sigaction.h \
 /usr/include/x86_64-linux-gnu/bits/sigcontext.h \
 /usr/include/x86_64-linux-gnu/bits/types/stack_t.h \
 /usr/include/x86_64-linux-gnu/sys/ucontext.h \
 /usr/include/x86_64-linux-gnu/bits/sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigstksz.h \
 /usr/include/x86_64-linux-gnu/bits/ss_flags.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigthread.h \
 /usr/include/x86_64-linux-gnu/bits/signal_ext.h /usr/include/pthread.h \
 /usr/include/sched.h /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sched_param.h \
 /usr/include/x86_64-linux-gnu/bits/cpu-set.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_tm.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_itimerspec.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct___jmp_buf_tag.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min-dynamic.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min.h ../include/link.h \
 ../include/lua/lua.h ../include/lua/luaconf.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/limits.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/syslimits.h \
 /usr/include/limits.h /usr/include/x86_64-linux-gnu/bits/posix1_lim.h \
 /usr/include/x86_64-linux-gnu/bits/local_lim.h \
 /usr/include/linux/limits.h \
 /usr/include/x86_64-linux-gnu/bits/posix2_lim.h ../include/lua/lauxlib.h \
 ../include/lua/lua.h ../include/lua/lualib.h ../include/mylua/base.h \
 ../include/char.h ../include/char_base.h ../include/char_data.h \
 ../include/item.h ../include/char.h ../include/item.h \
 ../include/lssproto_serv.h ../include/lssproto_util.h \
 /usr/include/unistd.h /usr/include/x86_64-linux-gnu/bits/posix_opt.h \
 /usr/include/x86_64-linux-gnu/bits/environments.h \
 /usr/include/x86_64-linux-gnu/bits/confname.h \
 /usr/include/x86_64-linux-gnu/bits/getopt_posix.h \
 /usr/include/x86_64-linux-gnu/bits/getopt_core.h \
 /usr/include/x86_64-linux-gnu/bits/unistd_ext.h ../include/mylua/mylua.h
magicbase.o: magicbase.c /usr/include/stdc-predef.h /usr/include/string.h \
 /usr/include/x86_64-linux-gnu/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/features-time64.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/bits/timesize.h \
 /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/long-double.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h \
 /usr/include/x86_64-linux-gnu/bits/types/locale_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h \
 /usr/include/strings.h ../include/common.h /usr/include/stdio.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h \
 /usr/include/x86_64-linux-gnu/bits/time64.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/cookie_io_functions_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/floatn.h \
 /usr/include/x86_64-linux-gnu/bits/floatn-common.h /usr/include/errno.h \
 /usr/include/x86_64-linux-gnu/bits/errno.h /usr/include/linux/errno.h \
 /usr/include/x86_64-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../include/char_talk.h ../include/common.h ../include/util.h \
 /usr/include/x86_64-linux-gnu/sys/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/time_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timeval.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endianness.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/bits/types/clock_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/clockid_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/timer_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-intn.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/uintn-identity.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/thread-shared-types.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h \
 /usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h \
 /usr/include/x86_64-linux-gnu/bits/struct_mutex.h \
 /usr/include/x86_64-linux-gnu/bits/struct_rwlock.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h ../include/net.h \
 ../include/autil.h ../include/version.h ../include/correct_bug.h \
 ../include/NewBilu/version.h ../include/NewBilu/debug.h \
 /usr/include/netinet/in.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-uintn.h \
 /usr/include/x86_64-linux-gnu/sys/socket.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_iovec.h \
 /usr/include/x86_64-linux-gnu/bits/socket.h \
 /usr/include/x86_64-linux-gnu/bits/socket_type.h \
 /usr/include/x86_64-linux-gnu/bits/sockaddr.h \
 /usr/include/x86_64-linux-gnu/asm/socket.h \
 /usr/include/asm-generic/socket.h /usr/include/linux/posix_types.h \
 /usr/include/linux/stddef.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types_64.h \
 /usr/include/asm-generic/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/bitsperlong.h \
 /usr/include/asm-generic/bitsperlong.h \
 /usr/include/x86_64-linux-gnu/asm/sockios.h \
 /usr/include/asm-generic/sockios.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_osockaddr.h \
 /usr/include/x86_64-linux-gnu/bits/in.h /usr/include/signal.h \
 /usr/include/x86_64-linux-gnu/bits/signum-generic.h \
 /usr/include/x86_64-linux-gnu/bits/signum-arch.h \
 /usr/include/x86_64-linux-gnu/bits/types/sig_atomic_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-arch.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-consts.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigevent_t.h \
 /usr/include/x86_64-linux-gnu/bits/sigevent-consts.h \
 /usr/include/x86_64-linux-gnu/bits/sigaction.h \
 /usr/include/x86_64-linux-gnu/bits/sigcontext.h \
 /usr/include/x86_64-linux-gnu/bits/types/stack_t.h \
 /usr/include/x86_64-linux-gnu/sys/ucontext.h \
 /usr/include/x86_64-linux-gnu/bits/sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigstksz.h \
 /usr/include/x86_64-linux-gnu/bits/ss_flags.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigthread.h \
 /usr/include/x86_64-linux-gnu/bits/signal_ext.h /usr/include/pthread.h \
 /usr/include/sched.h /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sched_param.h \
 /usr/include/x86_64-linux-gnu/bits/cpu-set.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_tm.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_itimerspec.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct___jmp_buf_tag.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min-dynamic.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min.h ../include/link.h \
 ../include/lua/lua.h ../include/lua/luaconf.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/limits.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/syslimits.h \
 /usr/include/limits.h /usr/include/x86_64-linux-gnu/bits/posix1_lim.h \
 /usr/include/x86_64-linux-gnu/bits/local_lim.h \
 /usr/include/linux/limits.h \
 /usr/include/x86_64-linux-gnu/bits/posix2_lim.h ../include/lua/lauxlib.h \
 ../include/lua/lua.h ../include/lua/lualib.h ../include/mylua/base.h \
 ../include/char_base.h ../include/skill.h ../include/title.h \
 ../include/addressbook.h ../include/mylua/ablua.h \
 ../include/magic_base.h ../include/lssproto_serv.h \
 ../include/lssproto_util.h /usr/include/unistd.h \
 /usr/include/x86_64-linux-gnu/bits/posix_opt.h \
 /usr/include/x86_64-linux-gnu/bits/environments.h \
 /usr/include/x86_64-linux-gnu/bits/confname.h \
 /usr/include/x86_64-linux-gnu/bits/getopt_posix.h \
 /usr/include/x86_64-linux-gnu/bits/getopt_core.h \
 /usr/include/x86_64-linux-gnu/bits/unistd_ext.h ../include/mylua/mylua.h
offlinebase.o: offlinebase.c /usr/include/stdc-predef.h \
 /usr/include/string.h \
 /usr/include/x86_64-linux-gnu/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/features-time64.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/bits/timesize.h \
 /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/long-double.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h \
 /usr/include/x86_64-linux-gnu/bits/types/locale_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h \
 /usr/include/strings.h ../include/NewBilu/version.h \
 ../include/char_base.h ../include/version.h ../include/correct_bug.h \
 ../include/common.h /usr/include/stdio.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h \
 /usr/include/x86_64-linux-gnu/bits/time64.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/cookie_io_functions_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/floatn.h \
 /usr/include/x86_64-linux-gnu/bits/floatn-common.h /usr/include/errno.h \
 /usr/include/x86_64-linux-gnu/bits/errno.h /usr/include/linux/errno.h \
 /usr/include/x86_64-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../include/NewBilu/version.h ../include/NewBilu/debug.h \
 ../include/skill.h ../include/util.h \
 /usr/include/x86_64-linux-gnu/sys/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/time_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timeval.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endianness.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/bits/types/clock_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/clockid_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/timer_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-intn.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/uintn-identity.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/thread-shared-types.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h \
 /usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h \
 /usr/include/x86_64-linux-gnu/bits/struct_mutex.h \
 /usr/include/x86_64-linux-gnu/bits/struct_rwlock.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h ../include/title.h \
 ../include/addressbook.h ../include/net.h ../include/autil.h \
 /usr/include/netinet/in.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-uintn.h \
 /usr/include/x86_64-linux-gnu/sys/socket.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_iovec.h \
 /usr/include/x86_64-linux-gnu/bits/socket.h \
 /usr/include/x86_64-linux-gnu/bits/socket_type.h \
 /usr/include/x86_64-linux-gnu/bits/sockaddr.h \
 /usr/include/x86_64-linux-gnu/asm/socket.h \
 /usr/include/asm-generic/socket.h /usr/include/linux/posix_types.h \
 /usr/include/linux/stddef.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types_64.h \
 /usr/include/asm-generic/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/bitsperlong.h \
 /usr/include/asm-generic/bitsperlong.h \
 /usr/include/x86_64-linux-gnu/asm/sockios.h \
 /usr/include/asm-generic/sockios.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_osockaddr.h \
 /usr/include/x86_64-linux-gnu/bits/in.h /usr/include/signal.h \
 /usr/include/x86_64-linux-gnu/bits/signum-generic.h \
 /usr/include/x86_64-linux-gnu/bits/signum-arch.h \
 /usr/include/x86_64-linux-gnu/bits/types/sig_atomic_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-arch.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-consts.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigevent_t.h \
 /usr/include/x86_64-linux-gnu/bits/sigevent-consts.h \
 /usr/include/x86_64-linux-gnu/bits/sigaction.h \
 /usr/include/x86_64-linux-gnu/bits/sigcontext.h \
 /usr/include/x86_64-linux-gnu/bits/types/stack_t.h \
 /usr/include/x86_64-linux-gnu/sys/ucontext.h \
 /usr/include/x86_64-linux-gnu/bits/sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigstksz.h \
 /usr/include/x86_64-linux-gnu/bits/ss_flags.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigthread.h \
 /usr/include/x86_64-linux-gnu/bits/signal_ext.h /usr/include/pthread.h \
 /usr/include/sched.h /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sched_param.h \
 /usr/include/x86_64-linux-gnu/bits/cpu-set.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_tm.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_itimerspec.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct___jmp_buf_tag.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min-dynamic.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min.h ../include/link.h \
 ../include/lua/lua.h ../include/lua/luaconf.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/limits.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/syslimits.h \
 /usr/include/limits.h /usr/include/x86_64-linux-gnu/bits/posix1_lim.h \
 /usr/include/x86_64-linux-gnu/bits/local_lim.h \
 /usr/include/linux/limits.h \
 /usr/include/x86_64-linux-gnu/bits/posix2_lim.h ../include/lua/lauxlib.h \
 ../include/lua/lua.h ../include/lua/lualib.h ../include/enemy.h \
 ../include/object.h ../include/char.h ../include/char_base.h \
 ../include/char_data.h ../include/item.h ../include/char.h \
 ../include/battle.h ../include/trade.h ../include/mylua/mylua.h
netbase.o: netbase.c /usr/include/stdc-predef.h /usr/include/string.h \
 /usr/include/x86_64-linux-gnu/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/features-time64.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/bits/timesize.h \
 /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/long-double.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h \
 /usr/include/x86_64-linux-gnu/bits/types/locale_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h \
 /usr/include/strings.h ../include/lua/lua.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stdarg.h \
 ../include/lua/luaconf.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/limits.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/syslimits.h \
 /usr/include/limits.h /usr/include/x86_64-linux-gnu/bits/posix1_lim.h \
 /usr/include/x86_64-linux-gnu/bits/local_lim.h \
 /usr/include/linux/limits.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min-dynamic.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min.h \
 /usr/include/x86_64-linux-gnu/bits/posix2_lim.h \
 ../include/NewBilu/version.h ../include/lua/lauxlib.h \
 /usr/include/stdio.h /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h \
 /usr/include/x86_64-linux-gnu/bits/time64.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/cookie_io_functions_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/floatn.h \
 /usr/include/x86_64-linux-gnu/bits/floatn-common.h ../include/lua/lua.h \
 ../include/lua/lualib.h ../include/lssproto_serv.h \
 ../include/lssproto_util.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/bits/types/clock_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/clockid_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/time_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/timer_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-intn.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endianness.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/uintn-identity.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timeval.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/thread-shared-types.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h \
 /usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h \
 /usr/include/x86_64-linux-gnu/bits/struct_mutex.h \
 /usr/include/x86_64-linux-gnu/bits/struct_rwlock.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/unistd.h \
 /usr/include/x86_64-linux-gnu/bits/posix_opt.h \
 /usr/include/x86_64-linux-gnu/bits/environments.h \
 /usr/include/x86_64-linux-gnu/bits/confname.h \
 /usr/include/x86_64-linux-gnu/bits/getopt_posix.h \
 /usr/include/x86_64-linux-gnu/bits/getopt_core.h \
 /usr/include/x86_64-linux-gnu/bits/unistd_ext.h ../include/net.h \
 ../include/common.h /usr/include/errno.h \
 /usr/include/x86_64-linux-gnu/bits/errno.h /usr/include/linux/errno.h \
 /usr/include/x86_64-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../include/autil.h ../include/version.h ../include/correct_bug.h \
 ../include/NewBilu/version.h ../include/NewBilu/debug.h \
 /usr/include/x86_64-linux-gnu/sys/time.h /usr/include/netinet/in.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-uintn.h \
 /usr/include/x86_64-linux-gnu/sys/socket.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_iovec.h \
 /usr/include/x86_64-linux-gnu/bits/socket.h \
 /usr/include/x86_64-linux-gnu/bits/socket_type.h \
 /usr/include/x86_64-linux-gnu/bits/sockaddr.h \
 /usr/include/x86_64-linux-gnu/asm/socket.h \
 /usr/include/asm-generic/socket.h /usr/include/linux/posix_types.h \
 /usr/include/linux/stddef.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types_64.h \
 /usr/include/asm-generic/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/bitsperlong.h \
 /usr/include/asm-generic/bitsperlong.h \
 /usr/include/x86_64-linux-gnu/asm/sockios.h \
 /usr/include/asm-generic/sockios.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_osockaddr.h \
 /usr/include/x86_64-linux-gnu/bits/in.h /usr/include/signal.h \
 /usr/include/x86_64-linux-gnu/bits/signum-generic.h \
 /usr/include/x86_64-linux-gnu/bits/signum-arch.h \
 /usr/include/x86_64-linux-gnu/bits/types/sig_atomic_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-arch.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-consts.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigevent_t.h \
 /usr/include/x86_64-linux-gnu/bits/sigevent-consts.h \
 /usr/include/x86_64-linux-gnu/bits/sigaction.h \
 /usr/include/x86_64-linux-gnu/bits/sigcontext.h \
 /usr/include/x86_64-linux-gnu/bits/types/stack_t.h \
 /usr/include/x86_64-linux-gnu/sys/ucontext.h \
 /usr/include/x86_64-linux-gnu/bits/sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigstksz.h \
 /usr/include/x86_64-linux-gnu/bits/ss_flags.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigthread.h \
 /usr/include/x86_64-linux-gnu/bits/signal_ext.h /usr/include/pthread.h \
 /usr/include/sched.h /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sched_param.h \
 /usr/include/x86_64-linux-gnu/bits/cpu-set.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_tm.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_itimerspec.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct___jmp_buf_tag.h \
 ../include/link.h ../include/log.h
enemytempbase.o: enemytempbase.c /usr/include/stdc-predef.h \
 /usr/include/string.h \
 /usr/include/x86_64-linux-gnu/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/features-time64.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/bits/timesize.h \
 /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/long-double.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h \
 /usr/include/x86_64-linux-gnu/bits/types/locale_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h \
 /usr/include/strings.h /usr/include/stdio.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h \
 /usr/include/x86_64-linux-gnu/bits/time64.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/cookie_io_functions_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/floatn.h \
 /usr/include/x86_64-linux-gnu/bits/floatn-common.h ../include/char.h \
 ../include/common.h /usr/include/errno.h \
 /usr/include/x86_64-linux-gnu/bits/errno.h /usr/include/linux/errno.h \
 /usr/include/x86_64-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../include/char_base.h ../include/version.h ../include/correct_bug.h \
 ../include/NewBilu/version.h ../include/NewBilu/debug.h \
 ../include/skill.h ../include/util.h \
 /usr/include/x86_64-linux-gnu/sys/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/time_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timeval.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endianness.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/bits/types/clock_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/clockid_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/timer_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-intn.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/uintn-identity.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/thread-shared-types.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h \
 /usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h \
 /usr/include/x86_64-linux-gnu/bits/struct_mutex.h \
 /usr/include/x86_64-linux-gnu/bits/struct_rwlock.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h ../include/title.h \
 ../include/addressbook.h ../include/net.h ../include/autil.h \
 /usr/include/netinet/in.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-uintn.h \
 /usr/include/x86_64-linux-gnu/sys/socket.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_iovec.h \
 /usr/include/x86_64-linux-gnu/bits/socket.h \
 /usr/include/x86_64-linux-gnu/bits/socket_type.h \
 /usr/include/x86_64-linux-gnu/bits/sockaddr.h \
 /usr/include/x86_64-linux-gnu/asm/socket.h \
 /usr/include/asm-generic/socket.h /usr/include/linux/posix_types.h \
 /usr/include/linux/stddef.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types_64.h \
 /usr/include/asm-generic/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/bitsperlong.h \
 /usr/include/asm-generic/bitsperlong.h \
 /usr/include/x86_64-linux-gnu/asm/sockios.h \
 /usr/include/asm-generic/sockios.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_osockaddr.h \
 /usr/include/x86_64-linux-gnu/bits/in.h /usr/include/signal.h \
 /usr/include/x86_64-linux-gnu/bits/signum-generic.h \
 /usr/include/x86_64-linux-gnu/bits/signum-arch.h \
 /usr/include/x86_64-linux-gnu/bits/types/sig_atomic_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-arch.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-consts.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigevent_t.h \
 /usr/include/x86_64-linux-gnu/bits/sigevent-consts.h \
 /usr/include/x86_64-linux-gnu/bits/sigaction.h \
 /usr/include/x86_64-linux-gnu/bits/sigcontext.h \
 /usr/include/x86_64-linux-gnu/bits/types/stack_t.h \
 /usr/include/x86_64-linux-gnu/sys/ucontext.h \
 /usr/include/x86_64-linux-gnu/bits/sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigstksz.h \
 /usr/include/x86_64-linux-gnu/bits/ss_flags.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigthread.h \
 /usr/include/x86_64-linux-gnu/bits/signal_ext.h /usr/include/pthread.h \
 /usr/include/sched.h /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sched_param.h \
 /usr/include/x86_64-linux-gnu/bits/cpu-set.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_tm.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_itimerspec.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct___jmp_buf_tag.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min-dynamic.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min.h ../include/link.h \
 ../include/lua/lua.h ../include/lua/luaconf.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/limits.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/syslimits.h \
 /usr/include/limits.h /usr/include/x86_64-linux-gnu/bits/posix1_lim.h \
 /usr/include/x86_64-linux-gnu/bits/local_lim.h \
 /usr/include/linux/limits.h \
 /usr/include/x86_64-linux-gnu/bits/posix2_lim.h ../include/lua/lauxlib.h \
 ../include/lua/lua.h ../include/lua/lualib.h ../include/char_data.h \
 ../include/item.h ../include/char.h ../include/readmap.h \
 ../include/map_deal.h ../include/char_base.h ../include/enemy.h \
 ../include/mylua/base.h ../include/lssproto_serv.h \
 ../include/lssproto_util.h /usr/include/unistd.h \
 /usr/include/x86_64-linux-gnu/bits/posix_opt.h \
 /usr/include/x86_64-linux-gnu/bits/environments.h \
 /usr/include/x86_64-linux-gnu/bits/confname.h \
 /usr/include/x86_64-linux-gnu/bits/getopt_posix.h \
 /usr/include/x86_64-linux-gnu/bits/getopt_core.h \
 /usr/include/x86_64-linux-gnu/bits/unistd_ext.h \
 ../include/npc_transmigration.h
sasqlbase.o: sasqlbase.c /usr/include/stdc-predef.h /usr/include/string.h \
 /usr/include/x86_64-linux-gnu/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/features-time64.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/bits/timesize.h \
 /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/long-double.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h \
 /usr/include/x86_64-linux-gnu/bits/types/locale_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h \
 /usr/include/strings.h ../include/lua/lua.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stdarg.h \
 ../include/lua/luaconf.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/limits.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/syslimits.h \
 /usr/include/limits.h /usr/include/x86_64-linux-gnu/bits/posix1_lim.h \
 /usr/include/x86_64-linux-gnu/bits/local_lim.h \
 /usr/include/linux/limits.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min-dynamic.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min.h \
 /usr/include/x86_64-linux-gnu/bits/posix2_lim.h \
 ../include/NewBilu/version.h ../include/lua/lauxlib.h \
 /usr/include/stdio.h /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h \
 /usr/include/x86_64-linux-gnu/bits/time64.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/cookie_io_functions_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/floatn.h \
 /usr/include/x86_64-linux-gnu/bits/floatn-common.h ../include/lua/lua.h \
 ../include/lua/lualib.h ../include/net.h ../include/common.h \
 /usr/include/errno.h /usr/include/x86_64-linux-gnu/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/x86_64-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../include/autil.h ../include/version.h ../include/correct_bug.h \
 ../include/NewBilu/version.h ../include/NewBilu/debug.h \
 /usr/include/x86_64-linux-gnu/sys/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/time_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timeval.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endianness.h \
 /usr/include/netinet/in.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-uintn.h \
 /usr/include/x86_64-linux-gnu/sys/socket.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_iovec.h \
 /usr/include/x86_64-linux-gnu/bits/socket.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/bits/types/clock_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/clockid_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/timer_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-intn.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/uintn-identity.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/thread-shared-types.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h \
 /usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h \
 /usr/include/x86_64-linux-gnu/bits/struct_mutex.h \
 /usr/include/x86_64-linux-gnu/bits/struct_rwlock.h \
 /usr/include/x86_64-linux-gnu/bits/socket_type.h \
 /usr/include/x86_64-linux-gnu/bits/sockaddr.h \
 /usr/include/x86_64-linux-gnu/asm/socket.h \
 /usr/include/asm-generic/socket.h /usr/include/linux/posix_types.h \
 /usr/include/linux/stddef.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types_64.h \
 /usr/include/asm-generic/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/bitsperlong.h \
 /usr/include/asm-generic/bitsperlong.h \
 /usr/include/x86_64-linux-gnu/asm/sockios.h \
 /usr/include/asm-generic/sockios.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_osockaddr.h \
 /usr/include/x86_64-linux-gnu/bits/in.h /usr/include/signal.h \
 /usr/include/x86_64-linux-gnu/bits/signum-generic.h \
 /usr/include/x86_64-linux-gnu/bits/signum-arch.h \
 /usr/include/x86_64-linux-gnu/bits/types/sig_atomic_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-arch.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-consts.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigevent_t.h \
 /usr/include/x86_64-linux-gnu/bits/sigevent-consts.h \
 /usr/include/x86_64-linux-gnu/bits/sigaction.h \
 /usr/include/x86_64-linux-gnu/bits/sigcontext.h \
 /usr/include/x86_64-linux-gnu/bits/types/stack_t.h \
 /usr/include/x86_64-linux-gnu/sys/ucontext.h \
 /usr/include/x86_64-linux-gnu/bits/sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigstksz.h \
 /usr/include/x86_64-linux-gnu/bits/ss_flags.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigthread.h \
 /usr/include/x86_64-linux-gnu/bits/signal_ext.h /usr/include/pthread.h \
 /usr/include/sched.h /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sched_param.h \
 /usr/include/x86_64-linux-gnu/bits/cpu-set.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_tm.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_itimerspec.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct___jmp_buf_tag.h \
 ../include/link.h ../include/log.h ../include/char_base.h \
 ../include/skill.h ../include/util.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h ../include/title.h \
 ../include/addressbook.h ../include/net.h ../include/NewBilu/sasql.h \
 ../include/NewBilu/version.h /usr/include/mysql/mysql.h \
 /usr/include/mysql/mariadb_com.h /usr/include/mysql/mariadb_version.h \
 /usr/include/mysql/ma_list.h /usr/include/mysql/mariadb_ctype.h \
 /usr/include/ctype.h /usr/include/mysql/mariadb_stmt.h
saacproto.o: saacproto.c /usr/include/stdc-predef.h /usr/include/string.h \
 /usr/include/x86_64-linux-gnu/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/features-time64.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/bits/timesize.h \
 /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/long-double.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h \
 /usr/include/x86_64-linux-gnu/bits/types/locale_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h \
 /usr/include/strings.h ../include/char.h ../include/common.h \
 /usr/include/stdio.h /usr/lib/gcc/x86_64-linux-gnu/13/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h \
 /usr/include/x86_64-linux-gnu/bits/time64.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/cookie_io_functions_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/floatn.h \
 /usr/include/x86_64-linux-gnu/bits/floatn-common.h /usr/include/errno.h \
 /usr/include/x86_64-linux-gnu/bits/errno.h /usr/include/linux/errno.h \
 /usr/include/x86_64-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../include/char_base.h ../include/version.h ../include/correct_bug.h \
 ../include/NewBilu/version.h ../include/NewBilu/debug.h \
 ../include/skill.h ../include/util.h \
 /usr/include/x86_64-linux-gnu/sys/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/time_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timeval.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endianness.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/bits/types/clock_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/clockid_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/timer_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-intn.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/uintn-identity.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/thread-shared-types.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h \
 /usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h \
 /usr/include/x86_64-linux-gnu/bits/struct_mutex.h \
 /usr/include/x86_64-linux-gnu/bits/struct_rwlock.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h ../include/title.h \
 ../include/addressbook.h ../include/net.h ../include/autil.h \
 /usr/include/netinet/in.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-uintn.h \
 /usr/include/x86_64-linux-gnu/sys/socket.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_iovec.h \
 /usr/include/x86_64-linux-gnu/bits/socket.h \
 /usr/include/x86_64-linux-gnu/bits/socket_type.h \
 /usr/include/x86_64-linux-gnu/bits/sockaddr.h \
 /usr/include/x86_64-linux-gnu/asm/socket.h \
 /usr/include/asm-generic/socket.h /usr/include/linux/posix_types.h \
 /usr/include/linux/stddef.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types_64.h \
 /usr/include/asm-generic/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/bitsperlong.h \
 /usr/include/asm-generic/bitsperlong.h \
 /usr/include/x86_64-linux-gnu/asm/sockios.h \
 /usr/include/asm-generic/sockios.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_osockaddr.h \
 /usr/include/x86_64-linux-gnu/bits/in.h /usr/include/signal.h \
 /usr/include/x86_64-linux-gnu/bits/signum-generic.h \
 /usr/include/x86_64-linux-gnu/bits/signum-arch.h \
 /usr/include/x86_64-linux-gnu/bits/types/sig_atomic_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-arch.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-consts.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigevent_t.h \
 /usr/include/x86_64-linux-gnu/bits/sigevent-consts.h \
 /usr/include/x86_64-linux-gnu/bits/sigaction.h \
 /usr/include/x86_64-linux-gnu/bits/sigcontext.h \
 /usr/include/x86_64-linux-gnu/bits/types/stack_t.h \
 /usr/include/x86_64-linux-gnu/sys/ucontext.h \
 /usr/include/x86_64-linux-gnu/bits/sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigstksz.h \
 /usr/include/x86_64-linux-gnu/bits/ss_flags.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigthread.h \
 /usr/include/x86_64-linux-gnu/bits/signal_ext.h /usr/include/pthread.h \
 /usr/include/sched.h /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sched_param.h \
 /usr/include/x86_64-linux-gnu/bits/cpu-set.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_tm.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_itimerspec.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct___jmp_buf_tag.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min-dynamic.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min.h ../include/link.h \
 ../include/lua/lua.h ../include/lua/luaconf.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/limits.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/syslimits.h \
 /usr/include/limits.h /usr/include/x86_64-linux-gnu/bits/posix1_lim.h \
 /usr/include/x86_64-linux-gnu/bits/local_lim.h \
 /usr/include/linux/limits.h \
 /usr/include/x86_64-linux-gnu/bits/posix2_lim.h ../include/lua/lauxlib.h \
 ../include/lua/lua.h ../include/lua/lualib.h ../include/char_data.h \
 ../include/item.h ../include/char.h ../include/char_base.h \
 ../include/mylua/base.h ../include/saacproto_cli.h \
 ../include/saacproto_util.h /usr/include/unistd.h \
 /usr/include/x86_64-linux-gnu/bits/posix_opt.h \
 /usr/include/x86_64-linux-gnu/bits/environments.h \
 /usr/include/x86_64-linux-gnu/bits/confname.h \
 /usr/include/x86_64-linux-gnu/bits/getopt_posix.h \
 /usr/include/x86_64-linux-gnu/bits/getopt_core.h \
 /usr/include/x86_64-linux-gnu/bits/unistd_ext.h
family.o: family.c /usr/include/stdc-predef.h /usr/include/string.h \
 /usr/include/x86_64-linux-gnu/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/features-time64.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/bits/timesize.h \
 /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/long-double.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h \
 /usr/include/x86_64-linux-gnu/bits/types/locale_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h \
 /usr/include/strings.h ../include/char.h ../include/common.h \
 /usr/include/stdio.h /usr/lib/gcc/x86_64-linux-gnu/13/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h \
 /usr/include/x86_64-linux-gnu/bits/time64.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/cookie_io_functions_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/floatn.h \
 /usr/include/x86_64-linux-gnu/bits/floatn-common.h /usr/include/errno.h \
 /usr/include/x86_64-linux-gnu/bits/errno.h /usr/include/linux/errno.h \
 /usr/include/x86_64-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../include/char_base.h ../include/version.h ../include/correct_bug.h \
 ../include/NewBilu/version.h ../include/NewBilu/debug.h \
 ../include/skill.h ../include/util.h \
 /usr/include/x86_64-linux-gnu/sys/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/time_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timeval.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endianness.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/bits/types/clock_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/clockid_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/timer_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-intn.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/uintn-identity.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/thread-shared-types.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h \
 /usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h \
 /usr/include/x86_64-linux-gnu/bits/struct_mutex.h \
 /usr/include/x86_64-linux-gnu/bits/struct_rwlock.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h ../include/title.h \
 ../include/addressbook.h ../include/net.h ../include/autil.h \
 /usr/include/netinet/in.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-uintn.h \
 /usr/include/x86_64-linux-gnu/sys/socket.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_iovec.h \
 /usr/include/x86_64-linux-gnu/bits/socket.h \
 /usr/include/x86_64-linux-gnu/bits/socket_type.h \
 /usr/include/x86_64-linux-gnu/bits/sockaddr.h \
 /usr/include/x86_64-linux-gnu/asm/socket.h \
 /usr/include/asm-generic/socket.h /usr/include/linux/posix_types.h \
 /usr/include/linux/stddef.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types_64.h \
 /usr/include/asm-generic/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/bitsperlong.h \
 /usr/include/asm-generic/bitsperlong.h \
 /usr/include/x86_64-linux-gnu/asm/sockios.h \
 /usr/include/asm-generic/sockios.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_osockaddr.h \
 /usr/include/x86_64-linux-gnu/bits/in.h /usr/include/signal.h \
 /usr/include/x86_64-linux-gnu/bits/signum-generic.h \
 /usr/include/x86_64-linux-gnu/bits/signum-arch.h \
 /usr/include/x86_64-linux-gnu/bits/types/sig_atomic_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-arch.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-consts.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigevent_t.h \
 /usr/include/x86_64-linux-gnu/bits/sigevent-consts.h \
 /usr/include/x86_64-linux-gnu/bits/sigaction.h \
 /usr/include/x86_64-linux-gnu/bits/sigcontext.h \
 /usr/include/x86_64-linux-gnu/bits/types/stack_t.h \
 /usr/include/x86_64-linux-gnu/sys/ucontext.h \
 /usr/include/x86_64-linux-gnu/bits/sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigstksz.h \
 /usr/include/x86_64-linux-gnu/bits/ss_flags.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigthread.h \
 /usr/include/x86_64-linux-gnu/bits/signal_ext.h /usr/include/pthread.h \
 /usr/include/sched.h /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sched_param.h \
 /usr/include/x86_64-linux-gnu/bits/cpu-set.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_tm.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_itimerspec.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct___jmp_buf_tag.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min-dynamic.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min.h ../include/link.h \
 ../include/lua/lua.h ../include/lua/luaconf.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/limits.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/syslimits.h \
 /usr/include/limits.h /usr/include/x86_64-linux-gnu/bits/posix1_lim.h \
 /usr/include/x86_64-linux-gnu/bits/local_lim.h \
 /usr/include/linux/limits.h \
 /usr/include/x86_64-linux-gnu/bits/posix2_lim.h ../include/lua/lauxlib.h \
 ../include/lua/lua.h ../include/lua/lualib.h ../include/char_data.h \
 ../include/item.h ../include/char.h ../include/char_base.h \
 ../include/family.h ../include/mylua/base.h ../include/saacproto_cli.h \
 ../include/saacproto_util.h /usr/include/unistd.h \
 /usr/include/x86_64-linux-gnu/bits/posix_opt.h \
 /usr/include/x86_64-linux-gnu/bits/environments.h \
 /usr/include/x86_64-linux-gnu/bits/confname.h \
 /usr/include/x86_64-linux-gnu/bits/getopt_posix.h \
 /usr/include/x86_64-linux-gnu/bits/getopt_core.h \
 /usr/include/x86_64-linux-gnu/bits/unistd_ext.h \
 ../include/npc_scheduleman.h ../include/npc_fmwarpman.h \
 ../include/handletime.h
petskill.o: petskill.c /usr/include/stdc-predef.h /usr/include/string.h \
 /usr/include/x86_64-linux-gnu/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/features-time64.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/bits/timesize.h \
 /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/long-double.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h \
 /usr/include/x86_64-linux-gnu/bits/types/locale_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h \
 /usr/include/strings.h ../include/common.h /usr/include/stdio.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h \
 /usr/include/x86_64-linux-gnu/bits/time64.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h \
 /usr/include/x86_64-linux-gnu/bits/types/cookie_io_functions_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/floatn.h \
 /usr/include/x86_64-linux-gnu/bits/floatn-common.h /usr/include/errno.h \
 /usr/include/x86_64-linux-gnu/bits/errno.h /usr/include/linux/errno.h \
 /usr/include/x86_64-linux-gnu/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../include/version.h ../include/correct_bug.h ../include/common.h \
 ../include/NewBilu/version.h ../include/NewBilu/debug.h \
 ../include/pet_skill.h ../include/util.h \
 /usr/include/x86_64-linux-gnu/sys/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/time_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timeval.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endianness.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/bits/types/clock_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/clockid_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/timer_t.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-intn.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/uintn-identity.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/thread-shared-types.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h \
 /usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h \
 /usr/include/x86_64-linux-gnu/bits/struct_mutex.h \
 /usr/include/x86_64-linux-gnu/bits/struct_rwlock.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h \
 ../include/mylua/base.h ../include/char_base.h ../include/version.h \
 ../include/skill.h ../include/title.h ../include/addressbook.h \
 ../include/net.h ../include/autil.h /usr/include/netinet/in.h \
 /usr/include/x86_64-linux-gnu/bits/stdint-uintn.h \
 /usr/include/x86_64-linux-gnu/sys/socket.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_iovec.h \
 /usr/include/x86_64-linux-gnu/bits/socket.h \
 /usr/include/x86_64-linux-gnu/bits/socket_type.h \
 /usr/include/x86_64-linux-gnu/bits/sockaddr.h \
 /usr/include/x86_64-linux-gnu/asm/socket.h \
 /usr/include/asm-generic/socket.h /usr/include/linux/posix_types.h \
 /usr/include/linux/stddef.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/posix_types_64.h \
 /usr/include/asm-generic/posix_types.h \
 /usr/include/x86_64-linux-gnu/asm/bitsperlong.h \
 /usr/include/asm-generic/bitsperlong.h \
 /usr/include/x86_64-linux-gnu/asm/sockios.h \
 /usr/include/asm-generic/sockios.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_osockaddr.h \
 /usr/include/x86_64-linux-gnu/bits/in.h /usr/include/signal.h \
 /usr/include/x86_64-linux-gnu/bits/signum-generic.h \
 /usr/include/x86_64-linux-gnu/bits/signum-arch.h \
 /usr/include/x86_64-linux-gnu/bits/types/sig_atomic_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/siginfo_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/__sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-arch.h \
 /usr/include/x86_64-linux-gnu/bits/siginfo-consts.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigval_t.h \
 /usr/include/x86_64-linux-gnu/bits/types/sigevent_t.h \
 /usr/include/x86_64-linux-gnu/bits/sigevent-consts.h \
 /usr/include/x86_64-linux-gnu/bits/sigaction.h \
 /usr/include/x86_64-linux-gnu/bits/sigcontext.h \
 /usr/include/x86_64-linux-gnu/bits/types/stack_t.h \
 /usr/include/x86_64-linux-gnu/sys/ucontext.h \
 /usr/include/x86_64-linux-gnu/bits/sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigstksz.h \
 /usr/include/x86_64-linux-gnu/bits/ss_flags.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sigstack.h \
 /usr/include/x86_64-linux-gnu/bits/sigthread.h \
 /usr/include/x86_64-linux-gnu/bits/signal_ext.h /usr/include/pthread.h \
 /usr/include/sched.h /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_sched_param.h \
 /usr/include/x86_64-linux-gnu/bits/cpu-set.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_tm.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct_itimerspec.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/bits/types/struct___jmp_buf_tag.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min-dynamic.h \
 /usr/include/x86_64-linux-gnu/bits/pthread_stack_min.h ../include/link.h \
 ../include/lua/lua.h ../include/lua/luaconf.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/limits.h \
 /usr/lib/gcc/x86_64-linux-gnu/13/include/syslimits.h \
 /usr/include/limits.h /usr/include/x86_64-linux-gnu/bits/posix1_lim.h \
 /usr/include/x86_64-linux-gnu/bits/local_lim.h \
 /usr/include/linux/limits.h \
 /usr/include/x86_64-linux-gnu/bits/posix2_lim.h ../include/lua/lauxlib.h \
 ../include/lua/lua.h ../include/lua/lualib.h ../include/char.h \
 ../include/char_base.h ../include/char_data.h ../include/item.h \
 ../include/char.h ../include/item.h ../include/lssproto_serv.h \
 ../include/lssproto_util.h /usr/include/unistd.h \
 /usr/include/x86_64-linux-gnu/bits/posix_opt.h \
 /usr/include/x86_64-linux-gnu/bits/environments.h \
 /usr/include/x86_64-linux-gnu/bits/confname.h \
 /usr/include/x86_64-linux-gnu/bits/getopt_posix.h \
 /usr/include/x86_64-linux-gnu/bits/getopt_core.h \
 /usr/include/x86_64-linux-gnu/bits/unistd_ext.h ../include/mylua/mylua.h
