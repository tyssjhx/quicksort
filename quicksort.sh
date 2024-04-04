#!/bin/bash
as -gstabs -o partition.o partition.s
as -gstabs -o quicksort.o quicksort.s
gcc -g -static -o quicksort partition.o quicksort.o quicksort-main.c
