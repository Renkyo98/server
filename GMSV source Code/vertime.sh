#!/bin/sh
OUT=./vertime.h
touch callfromac.c
echo "#define SERVER_VERTIME \"$(date +%YÄê%mÔÂ%dÈÕ¡¡%H:%M:%S)\"" > $OUT
