#!/bin/bash

gcc -Wall -Werror -Wextra ft_foreach.c ft_putnbr.c ft_range.c main.c test.h
./a.out
rm a.out

