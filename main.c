#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void main_screen();
void StarCatch();
void SnakeLadder();
void SnakeLadder_PrintCurrentMap(int j, int map, int OriginalMap, int dir);

int main(void)
{
	main_screen();
}
void main_screen()
{
	srand((unsigned)time(NULL));
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
	int i, j = 0, dir = 1, move;
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

	map[0] = 65;
	
	while (1)
	{
		system("cls");

		printf("\n\n\n			A의 턴");
		Sleep(1500);
		system("cls");
		SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);
		Sleep(2000);
		system("cls");
		printf("\n\n\n		A의 주사위를 굴립니다 :   ");
		printf("\n\n		아무 키나 눌러주세요");
		getch();
		system("cls");
		dice = rand() % 30 + 10;
		printf("\n\n\n\n		A의 주사위를 굴립니다 : %d ", dice);
		Sleep(500);
		system("cls");

		while (1)
		{
			if (a + dice > 48)
				dice--;
			else
				break;
		}


		for (move = a; move <= a + dice; move++)
		{
			if (move == a + dice)//마지막 이동이
			{
				if (map[move] == 66)//B자리라면
				{
					system("cls");
					printf("\n\n		KICK !");
					printf("\n		B는 원점으로 이동합니다");
					b = 0;//보내고
					Sleep(1000);
					system("cls");
				}
			}
			
			map[move] = 65;//쓰고
			SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);//출력
			map[move] = OriginalMap[move];//지우고
			if (map[move] == b)//지나가는 자리가 B 자리라면
				map[move] = 66;
		
			Sleep(500);
			system("cls");
		}
		map[move-1] = 65;//다시쓰고
		a = a + dice;//a 재위치
		if (a == 48)
		{
			Sleep(1000);
			system("cls");
			printf("\n\n		A 승리!!!!!");
			Sleep(2000);
			return;
		}

		

		printf("\n\n\n			B의 턴");
		Sleep(1500);
		system("cls");
		i = 42;
		SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);
		Sleep(2000);
		system("cls");
		printf("\n\n\n		B의 주사위를 굴립니다 :   ");
		printf("\n\n		아무 키나 눌러주세요");
		getch();
		system("cls");
		dice = rand() % 30 + 10;
		printf("\n\n\n\n		B의 주사위를 굴립니다 : %d ", dice);
		Sleep(500);
		system("cls");

		while (1)
		{
			if (b + dice > 48)
				dice--;
			else
				break;
		}

		for (move = b; move <= b + dice; move++)
		{
			if (move == b + dice)//마지막 이동이
			{
				if (map[move] == 65)//A자리라면
				{
					system("cls");
					printf("\n\n		KICK !");
					printf("\n		A는 원점으로 이동합니다");
					a = 0;//보내고
					Sleep(1000);
					system("cls");
				}
			}
			map[move] = 66;//쓰고
			SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);//출력
			map[move] = OriginalMap[move];//지우고
			if (map[move] == a)//지나가는 자리가 A 자리라면
				map[move] = 65;
			
			Sleep(500);
			system("cls");
		}
		map[move-1] = 66;//다시쓰고
		b = b + dice;//b 재위치
		if (b == 48)
		{
			Sleep(1000);
			system("cls");
			printf("\n\n		B 승리!!!!!");
			Sleep(2000);
			return;
		}

	}
	return;
}
void SnakeLadder_PrintCurrentMap(int j, int map[], int OriginalMap[],int dir)
{
	int i = 42;
	while (1)
	{
		for (j = 0; j < 7; j++)
		{
			if (map[i] != OriginalMap[i])
				printf("%5c", map[i]);
			else
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
return;
}