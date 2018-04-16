# makefile for ConsoleTrigoC
appName = ConsoleTrigoC.exe
CC = gcc
ver = c11
objects = diag.o main.o solve.o
src = diag.c solve.c main.c

build:
	$(CC) -Wall -c $(src) -std=$(ver)
	$(CC) -s $(objects) -o $(appName)
clean:
	del $(objects)
