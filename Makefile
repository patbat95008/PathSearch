# By Patrick Russell
#    pcrussel@ucsc.edu
#
# Modified by Nico Williams  and  Patrick Russell
#             nigowill@ucsc.edu || pcrussel@ucsc.edu 
#
# Makefile for programing assignment 5
# compiles graphDriver and pathSearch executables

GCC = gcc -ansi -Wall -Wextra

all: graphDriver pathSearch listdr

pathSearch : pathSearch.o graph.o list.o
	${GCC} -o pathSearch pathSearch.o graph.o list.o

graphDriver : graphDriver.o graph.o list.o 
	${GCC} -o graphDriver graphDriver.o graph.o list.o 
	
listdr : listdr.o list.o
	${GCC} -o listdr listdr.o list.o	

graphDriver.o : graphDriver.c graph.h list.h
	${GCC} -c graphDriver.c
	
pathSearch.o : pathSearch.c graph.h list.h
	${GCC} -c pathSearch.c

graph.o : graph.c graph.h list.h 
	${GCC} -c graph.c graph.h

list.o : list.c list.h
	${GCC} -c list.c list.h	
	
listdr.o : list.h listdr.c
	${GCC} -c  listdr.c	


clean :
	rm pathSearch.o graph.o list.o graphDriver.o listdr.o
