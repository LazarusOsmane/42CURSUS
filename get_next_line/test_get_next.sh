#!/usr/bin/env zsh

i = 0
for ((i = 0; i < 1000000), i++) do
       gcc -Wall -Werror -Wextra -g3 -D BUFFER_SIZE=i get_next_line.c main.c
done 	

