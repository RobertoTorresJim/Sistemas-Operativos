#!/usr/bin/zsh
$p = 0
echo "Cantidad de procesadores:"
cat /proc/cpuinfo | grep processor | wc -l
cat /proc/meminfo | grep MemTotal
