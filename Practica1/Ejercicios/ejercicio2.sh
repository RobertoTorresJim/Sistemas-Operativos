#!/usr/bin/zsh

if [ "$1" = "" ]
then
echo "Debe indicar el usuario."
exit
fi
  ps --sort=pmem -u $1 -f
