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

	printf("시작할 게임을 선택해주세요.\n\n");
	printf("1.숫자 야구			2.가위바위보			3.뱀사다리 게임			4.스타캐치\n\n\n");

	printf("-번호만 입력해주세요 : ");
	scanf("%d", &select);

	while (select < 1 || select > 4) {

		printf("-입력값이 올바르지 않음 다시 입력해주세요 :");
		scanf_s("%d", &select);

	}

	switch (select)
	{
	case 1:
		//1번게임
		break;
	case 2:
		//2번 게임
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
	printf("*당첨번호 뽑기 게임\n");

	printf("*몇번이 당첨될까요?(1~29) :");
	scanf_s("%d", &answer);

	while (1) {
		printf("*당신의 예상 : %d\n\n", answer);
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
		printf("*당첨은 %d 번 이었습니다!\n", counterMax + 1);
	}
	else
		printf("*축하합니다 %d번 당첨입니다 \n", counterMax + 1);
	printf("\n\n\n\n\n");

	printf("*아무키나 입력해주세요");

	getch();
	fflush(stdin);

	system("cls");
	main_screen();
	return;
}

