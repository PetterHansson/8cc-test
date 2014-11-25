// Copyright 2012 Rui Ueyama <rui314@gmail.com>
// This program is free software licensed under the MIT license.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void testmain(void);

// For test/extern.c
int externvar1 = 98;
int externvar2 = 99;

// For test/function.c
int booltest1(bool x) {
    return x;
}

int oldstyle1(int x, int y) {
    return x + y;
}

void print(char *s) {
    printf("Testing %s ... ", s);
    fflush(stdout);
}

void printfail(void) {
    printf("Failed\n");
}

static void doexit(int code)
{
	//TODO: main isn't being handled correctly, hence requirement for exit and flush. need to check what crt should do
	fflush(stdout);
	fflush(stderr);
	exit(code);
}

void ffail(char *file, int line, char *msg) {
    printfail();
    printf("%s:%d: %s\n", file, line, msg);
    doexit(1);
}

void fexpect(char *file, int line, int a, int b) {
    if (!(a == b)) {
        printfail();
        printf("%s:%d: %d expected, but got %d\n", file, line, a, b);
        doexit(1);
    }
}

void fexpect_string(char *file, int line, char *a, char *b) {
    if (strcmp(a, b)) {
        printfail();
        printf("%s:%d: \"%s\" expected, but got \"%s\"\n", file, line, a, b);
        doexit(1);
    }
}

void fexpectf(char *file, int line, float a, float b) {
    if (!(a == b)) {
        printfail();
        printf("%s:%d: %f expected, but got %f\n", file, line, a, b);
        doexit(1);
    }
}

void fexpectd(char *file, int line, double a, double b) {
    if (!(a == b)) {
        printfail();
        printf("%s:%d: %lf expected, but got %lf\n", file, line, a, b);
        doexit(1);
    }
}

void fexpectl(char *file, int line, long a, long b) {
    if (!(a == b)) {
        printfail();
        printf("%s:%d: %ld expected, but got %ld\n", file, line, a, b);
        doexit(1);
    }
}

int main() {
    testmain();
    printf("OK\n");
	doexit(0);
    return 0;
}
