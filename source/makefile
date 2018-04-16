# makefile for ConsoleTrigoC
appName = ConsoleTrigoC.exe
CC = gcc
ver = c11
heads = mainhead.h
objects = diag.o main.o solve.o
srcs = diag.c solve.c main.c

build:
	$(CC) -Wall -c $(srcs) -std=$(ver)
	$(CC) -s $(objects) -o $(appName)
clean:
	del $(objects) $(srcs) $(heads)
	del makefile
