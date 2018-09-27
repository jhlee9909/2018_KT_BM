#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

void StarCatch();

int main(void) {

	StarCatch();


	return 0;
}
void StarCatch() {
	int i;
	char slot[10];
	int sw=1;
	int star=1;

	while (1) {
		for (i = 0; i < 10; i++) {

			slot[i] = '_';

		}

		slot[0] = '[';
		slot[9] = ']';


		slot[star] = '¡Ú';
		printf("\n\n\n\n\n");
		for (i = 0; i < 10; i++) {

			printf(" %c ", slot[i]);


		}
		printf("\n\n\n\n\n");

		

		if (star==1 && sw==-1)
			sw = 1;
		else if (star == 8 && sw==1)
			sw*= -1;

		star += sw;


		Sleep(5);
		system("cls");
	}

}