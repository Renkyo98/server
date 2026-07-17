#!/bin/sh
folders=(. battle char include item log magic map mylua newbilu npc)
for ((i=0;i<11;i++))
do 
	for f in ./${folders[i]}/*.c
	do
	  filename="$(cut -d'/' -f3 <<<"$f")"
	  if file -i $f | grep -wq "utf-8"
	  then
	    converted="./${folders[i]}/converted"
	    mkdir -p ${converted}
	    iconv -f UTF-8 -t EUC-KR//TRANSLIT $f -o "${converted}/${filename}"
	    cp -f "${converted}/${filename}" $f
	    printf "${filename}: CONVERTED TO EUC-KR.\n"
	  fi
	done
done
for ((i=0;i<11;i++))
do 
	for f in ./${folders[i]}/*.c
	do
	  convFolder="./${folders[i]}/converted"
	  rm -rf ${convFolder}
	done
done
make clean
make depend
make
read -p "Done!"
