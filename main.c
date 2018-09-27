#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void main_screen();
void StarCatch();
void SnakeLadder();
void initGame();

int main(void)
{
	main_screen();
}
void initGame()
{
	srand(time(NULL));
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
		SnakeLadder();
		break;
	case 4:
		StarCatch();
		break;

	default:
		break;
	}

}



void StarCatch() {
	int i;
	char slot[10];
	int sw = 1;
	int star = 1;

	while (1) {
		for (i = 0; i < 10; i++) {

			slot[i] = '_';

		}

		slot[0] = '[';
		slot[9] = ']';


		slot[star] = '★';
		printf("\n\n\n\n\n");
		for (i = 0; i < 10; i++) {

			printf(" %c ", slot[i]);


		}
		printf("\n\n\n\n\n");



		if (star == 1 && sw == -1)
			sw = 1;
		else if (star == 8 && sw == 1)
			sw *= -1;

		star += sw;


		Sleep(5);
		system("cls");
	}

}

void SnakeLadder()
{
	int a,b;
	int dice;
	int map[7][7];
	printf("");
	


	return;
}