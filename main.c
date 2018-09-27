#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void main_screen();
void StarCatch();
void SnakeLadder();

int main(void)
{
	main_screen();
}
void main_screen()
{
	srand(time(NULL));
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
	int i, j, dir = 1;
	//dir(다이렉션 : 방향) 1일때 오른쪽 -1일때 왼쪽
	int a=0, b=0;
	//플레이어들 현재 위치
	int dice;
	int OriginalMap[49];
	int map[49];
	
	//initialize map
	for (i = 0; i < 49; i++)
	{
		OriginalMap[i] = i;
		map[i] = i;
	}
	
	system("cls");

	printf("\n\n\n\n			A의 턴");
	Sleep(1000);
	system("cls");
	i = 42;
	while(1)
	{
		for (j = 0; j < 7; j++)
		{
			printf("%5d", map[i]);
			if (dir == 1)
			{
				i++;
				if (j == 6)
					i--;
			}
			else if (dir == -1)
			{
				i--;
				if (j == 6)
					i++;
			}
		}
		if (i == 6)
			break;
		i = i - 7;
		dir = dir * (-1);
		printf("\n");
	}
	Sleep(3000);
	system("cls");
	printf("\n\n\n\n		주사위를 굴립니다 :   ");
	Sleep(500);
	system("cls");
	dice = rand() % 6 + 1;
	printf("\n\n\n\n		주사위를 굴립니다 : %d ",dice);
	Sleep(500);
	system("cls");


	
	return;
}