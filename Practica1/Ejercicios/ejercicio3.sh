#!/bin/bash
echo Procesos S:
ps -o state,ppid -A | grep -e '^[S]' | wc -l
echo Procesos R:
ps -o state,ppid -A | grep -e '^[R]' | wc -l
echo Procesos D:
ps -o state,ppid -A | grep -e '^[D]' | wc -l
echo Procesos T:
ps -o state,ppid -A | grep -e '^[T]' | wc -l
echo Procesos Z:
ps -o state,ppid -A | grep -e '^[Z]' | wc -l
