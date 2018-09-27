#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define SIZE 32

void main_screen();
void StarCatch();

void initGame();

int main(void)
{
	main_screen();
}
void initGame()
{
	srand((unsigned)time(NULL));
}
void main_screen()
{

	int select;

	printf("\n");
	printf("		********************************************************************************\n");
	printf("		********************************************************************************\n");
	printf("		****                                                                        ****\n");
	printf("		****                *               *                  *  *             *   ****\n");
	printf("		****    *******	    *   *           *   **********     *  *     ****    *   ****\n");
	printf("		****    *     *	    *   *           *           *      *  *    *    *   *   ****\n");
	printf("		****    *     *	    *   *           *          *  ******  *    *    *   *   ****\n");
	printf("		****    *     *	    *   *           *         *        *  *     ****    *   ****\n");
	printf("		****    *******	    *   ********    *        *         *  *                 ****\n");
	printf("		****                *               *       *             *      ********   ****\n");
	printf("		****                                                             *      *   ****\n");
	printf("		****                                                             ********   ****\n");
	printf("		****                                                                        ****\n");
	printf("		********************************************************************************\n");
	printf("		********************************************************************************\n\n\n");

	printf("������ ������ �������ּ���.\n\n");
	printf("1.���� �߱�			2.����������			3.���ٸ� ����			4.��Ÿĳġ\n\n\n");

	printf("-��ȣ�� �Է����ּ��� : ");
	scanf("%d", &select);

	while (select < 1 || select > 4) {

		printf("-�Է°��� �ùٸ��� ���� �ٽ� �Է����ּ��� :");
		scanf_s("%d", &select);

	}

	switch (select)
	{
	case 1:
		//1������
		break;
	case 2:
		//2�� ����
		break;
	case 3:

		break;
	case 4:
		StarCatch();
		break;

	default:
		break;
	}

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

