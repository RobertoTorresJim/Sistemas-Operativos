#!/usr/bin/zsh

if [ "$1" = "" ]
then
echo "Debe indicar el nombre del directorio a utilizar."
exit
fi
if [ -e $1 ]
then
	echo "Ok: existe el directoio"
else
	mkdir $1
	echo "Creando el directorio: "$1
fi
echo "Accediendo al directorio...."
cd $1
wget -q psdsuite.com/wp-content/uploads/2015/07/operating-system-icon-5746821.jpg
if [ $? -ne 0 ]
then
	echo "Archivo no descargado...Error"
else
	echo "Archivo descargado..."
fi
