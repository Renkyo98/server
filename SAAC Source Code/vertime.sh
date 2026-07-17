#!/bin/sh
OUT=./vertime.h
touch main.c
echo "#define SERVER_VERTIME \"$(date +%YÄê%mÔÂ%dÈÕ¡¡%H:%M:%S)\"" > $OUT
