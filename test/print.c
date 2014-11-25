#include <stdio.h>
#include "test.h"

//first test to ensure we can actually print error messages and stuff

void testmain(void)
{
	print("basic printing");
	char buf[256];
	int a, b, c, d;
	FILE * f = fopen("testfile.txt", "w");
	if (f == 0) fail("couldn't open file for writing");
	fprintf(f, "Hello %s %d %d %d %d", "World", 1337, 1, 2, 3);
	fclose(f);
	f = fopen("testfile.txt", "r");
	if (f == 0) fail("couldn't open file for reading");
	fscanf(f, "Hello %s %d %d %d %d", buf, &a, &b, &c, &d);
	fclose(f);
	if (strcmp("World", buf)) fail("arg 1");
	if (a != 1337) fail("arg 2");
	if (b != 1) fail("arg 3");
	if (c != 2) fail("arg 4");
	if (d != 3) fail("arg 5");
}
