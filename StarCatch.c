#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


#define SIZE 32

void StarCatch();

int main(void) {


	StarCatch();

	return 0;
}

void StarCatch() {
	int counter = 0;
	int counterMax;
	int answer;
	int i;
	char slot[SIZE];
	int sw = 1;
	int star = 1;

	char input = 0;

	srand(time(NULL));
	counterMax = (rand() % 29) + 1;

	system("cls");
	printf("*��÷��ȣ �̱� ����\n");

	printf("*����� ��÷�ɱ��?(1~29) :");
	scanf_s("%d", &answer);

	while (1) {
		printf("*����� ���� : %d\n\n", answer);
		for (i = 0; i < SIZE; i++) {

			slot[i] = '=';

		}

		slot[0] = '[';
		slot[SIZE - 1] = ']';


		slot[star] = 'A';
		printf("\n\n\n\n\n");
		for (i = 0; i < SIZE; i++) {

			printf(" %c ", slot[i]);


		}

		printf("\n");
		printf(" [ ");
		for (i = 0; i < SIZE - 2; i++) {

			printf(" V ");


		}
		printf(" ]");




		if (star == 1 && sw == -1)
			sw = 1;
		else if (star == SIZE - 2 && sw == 1)
			sw *= -1;

		if (counter == counterMax) {

			printf("\n");
			printf(" [ ");
			for (i = 0; i < SIZE - 2; i++) {

				if (i != counterMax)
					printf("   ");
				else
					printf(" X ");


			}
			printf(" ]");
			printf("\n\n\n\n\n");
			break;

		}

		star += sw;
		counter++;


		Sleep(100);



		system("cls");
	}
	if (answer != counterMax) {
		printf("*��÷�� %d �� �̾����ϴ�!\n", counterMax + 1);
	}
	else
		printf("*�����մϴ� %d�� ��÷�Դϴ� \n", counterMax + 1);
	printf("\n\n\n\n\n");

	printf("*�ƹ�Ű�� �Է����ּ���");

	getch();
	fflush(stdin);

	system("cls");
	main_screen();
	return;
}

