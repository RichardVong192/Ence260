# File:   Makefile
# Author: R. Lobb and J. Chen
# Date:   Aug 2014
# Descr:  Makefile for processstudent


# Definitions.
CFLAGS = -g -std=c99 -Wall -Werror


# Main target: create executable by linking the object files
coder: confab.o coder.o
	gcc coder.o confab.o -o coder -lm

# Intermediate targets: create object files from C source codes.
confab.o: confab.c confab.h
	gcc $(CFLAGS) -c confab.c

coder.o: coder.c
	gcc $(CFLAGS) -c coder.c


# Clean up target (used with the command "make clean")
clean:
	rm *.o coder
