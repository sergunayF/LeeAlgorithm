#include "func.h"

#include <stdlib.h>

void _init() {

	for (int x = 0; x < ROWS; x++) {
		for (int y = 0; y < COLS; y++) {

			field[x][y] = rand() % 2;

			if (field[x][y] == 1) field[x][y] = rand() % 2;
			if (field[x][y] == 0) field[x][y] = -1;
			if (field[x][y] == 1) field[x][y] = 99;

		}
	}
}

void _print() {

	for (int y = 0; y < COLS; y++) {
		for (int x = 0; x < ROWS; x++) {
			if (field[x][y] == 99) printf("[] ");
			else printf("%02d ", field[x][y]);
		}

		printf("\n");
	}
}

void _lee(int sx, int sy, int ex, int ey) {

	int wave = -1;
	field[sx][sy] = 0;

	for (int i = 0; i < ROWS * COLS; i++) {

		wave++;

		for (int x = 0; x < ROWS; x++) {
			for (int y = 0; y < COLS; y++) {

				if (field[x][y] == wave) {

					for (int k = 0; k < 4; k++) {

						int nx = x + cx[k];
						int ny = y + cy[k];

						if (nx >= 0 && nx < ROWS && ny >= 0 && ny < COLS && field[nx][ny] == -1) {
							field[nx][ny] = wave + 1;

							//printf("%d\n", wave);
							//_print();

						}
					}
				}
			}
		}
	}
}

void _path(sx, sy, ex, ey) {

	printf("\n");

	int wave = field[ex][ey];
	int d = 0;

	while (wave > 1) {

		for (int i = 0; i < 4; i++) {

			int nx = ex + cx[i];
			int ny = ey + cy[i];

			if (nx >= 0 && nx < ROWS && ny >= 0 && ny < COLS && field[nx][ny] == wave - 1) {

				printf("[%d][%d] -> ", nx, ny);

				ex = nx;
				ey = ny;
				wave--;

				d++;

				break;
			}
		}
	}
	printf("[%d][%d]\n\nLENGTH: %d\n", sx, sy, d + 1);
}