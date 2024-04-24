#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "func.h"

int main() {
	
	system("color a");

	srand(15);

	//_init();

	_pos start = {3, 6,};
	_pos end = {3, 0,};

	printf("LEE:\n\n");

	_lee(start.x, start.y, end.x, end.y);

	_print();

	_path(start.x, start.y, end.x, end.y);

	return 0;
}