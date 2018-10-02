#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void main_screen();
void StarCatch();
void SnakeLadder();
void SnakeLadder_PrintCurrentMap(int j, int map[], int OriginalMap[], int dir);

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
	int i, j = 0, dir = 1, move, tmp;
	//dir(다이렉션 : 방향) 1일때 오른쪽 -1일때 왼쪽
	int a = 0, b = 0;
	//플레이어들 현재 위치
	int s1 = 23, s2 = 18, s3 = 39, s4 = 30, l1 = 20, l2 = 21, l3 = 34, l4 = 28, l5 = 41;
	//snake,ladder
	int dice;
	int OriginalMap[49];
	int map[49];


	//initialize map
	for (i = 0; i < 49; i++)
	{
		OriginalMap[i] = i;
		map[i] = i;
	}

	map[23] = 83;
	map[18] = 83;
	map[39] = 83;
	map[30] = 83;
	map[20] = 76;
	map[21] = 76;
	map[28] = 76;
	map[34] = 76;
	map[41] = 76;

	map[0] = 65;
	
	//game
	system("cls");
	SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);
	printf("\n S는 뱀입니다 위에서 아래로 내려옵니다");
	printf("\n L은 사다리입니다 아래에서 위로 올라갑니다");
	printf("\n\n 아무 키나 눌러서 시작하세요");
	getch();
	

	while (1)
	{
		system("cls");

		printf("\n\n\n\n			A의 턴");
		Sleep(1000);
		system("cls");
		SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);
		Sleep(1000);

		system("cls");
		printf("\n\n\n\n		A의 주사위를 굴립니다 :   ");
		printf("\n\n\n		아무 키나 눌러주세요");
		getch();
		system("cls");
		dice = rand() % 12 + 1;
		printf("\n\n\n\n		A의 주사위를 굴립니다 : %d ", dice);
		Sleep(1000);
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
			//출발 걸음이 특수기호면?
			if (move == a + dice)//마지막 이동이
			{
				tmp = map[move];
				map[move] = 65;//쓰고
				SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);//출력
				map[move] = tmp;
				Sleep(500);
				system("cls");
				if (move == b)//B자리라면
				{
					printf("\n\n\n		KICK !");
					printf("\n\n		B는 원점으로 이동합니다");
					b = 0;//보내고
					Sleep(1000);
					system("cls");
					map[0] = 66;
					map[move] = 65;//쓰고 필요없나?
					SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);//출력
					Sleep(500);
					system("cls");

				}
				//snake1
				if (move == s1)
				{
					printf("\n\n\n		Snake !");
					printf("\n\n		18번으로 이동합니다");
					Sleep(1000);
					system("cls");
					map[move] = 83;//원래 수 써주고
					a = 18;
					map[s2] = 65;//쓰고
					SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);//출력
					Sleep(500);
					system("cls");

					if (b == 18)//B자리라면
					{
						printf("\n\n\n		KICK !");
						printf("\n\n		B는 원점으로 이동합니다");
						b = 0;//보내고
						Sleep(1000);
						system("cls");
						map[0] = 66;
						map[18] = 65;//쓰고 필요없나?
						SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);//출력
						Sleep(500);
						system("cls");

					}
					break;
				}
				//Snake2
				if (move == s3)
				{
					printf("\n\n\n		Snake !");
					printf("\n\n		30번으로 이동합니다");
					Sleep(1000);
					system("cls");
					map[move] = 83;//원래 수 써주고
					a = 30;
					map[s4] = 65;//쓰고
					SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);//출력
					Sleep(500);
					system("cls");

					if (b == 30)//B자리라면
					{
						printf("\n\n\n		KICK !");
						printf("\n\n		B는 원점으로 이동합니다");
						b = 0;//보내고
						Sleep(1000);
						system("cls");
						map[0] = 66;
						map[30] = 65;//쓰고 필요없나?
						SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);//출력
						Sleep(500);

					}
					break;
				}
				//ladder1
				if (move == l1)
				{
					system("cls");
					printf("\n\n\n		Ladder !");
					printf("\n\n		34번으로 이동합니다");
					Sleep(1000);
					system("cls");

					map[l1] = 76;//쓰고
					map[l2] = 65;
					SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);//출력
					Sleep(500);
					system("cls");
					if (b == l2)
						map[l2] = 66;
					else
					map[l2] = 76;//쓰고

					map[l3] = 65;
					SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);//출력
					Sleep(500);
					system("cls");
					a = 34;
					if (b == 34)//B자리라면
					{
						printf("\n\n\n		KICK !");
						printf("\n\n		B는 원점으로 이동합니다");
						b = 0;//보내고
						Sleep(1000);
						system("cls");
						map[0] = 66;
						map[34] = 65;//쓰고 필요없나?
						SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);//출력
						Sleep(500);

					}
					break;
				}
				//ladder2
				if (move == l4)
				{
					system("cls");
					printf("\n\n\n		Ladder !");
					printf("\n\n		41번으로 이동합니다");
					Sleep(1000);
					system("cls");

					map[l4] = 76;//쓰고
					map[l5] = 65;
					SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);//출력
					Sleep(500);
					system("cls");
					a = 41;
					if (b == 41)//B자리라면
					{
						printf("\n\n\n		KICK !");
						printf("\n\n		B는 원점으로 이동합니다");
						b = 0;//보내고
						Sleep(1000);
						system("cls");
						map[0] = 66;
						map[41] = 65;//쓰고 필요없나?
						SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);//출력
						Sleep(500);

					}
					break;
				}
			}

			tmp = map[move];
			map[move] = 65;//쓰고
			SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);//출력
			map[move] = tmp;
			Sleep(500);
			system("cls");

			if (map[move] == b || map[move] == 66)//지나가는 자리가 B 자리라면
				map[move] = 66;
			else if (move == a + dice)
				map[move] = 65;
			else if (move == s1 || move == s2 || move == s3 || move == s4)//지나가는 자리가 s 자리라면
				map[move] = 83;
			else if (move == l1 || move == l2 || move == l3 || move == l4 || move == l5)
				map[move] = 76;
			
			else 
				map[move] = OriginalMap[move];//숫자로 덮고

			if (move == a + dice)
			{
				a = a + dice;//a 재위치
				break;
			}
		}
		

		if (a == 48)
		{
			Sleep(1000);
			system("cls");
			printf("\n\n\n		A 승리!!!!!");
			Sleep(1000);
			system("cls");
			main_screen();
		}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&//

		system("cls");

		printf("\n\n\n\n			B의 턴");
		Sleep(1000);
		system("cls");
		SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);
		Sleep(1000);

		system("cls");
		printf("\n\n\n\n		B의 주사위를 굴립니다 :   ");
		printf("\n\n\n		아무 키나 눌러주세요");
		getch();
		system("cls");
		dice = rand() % 12 + 1;
		printf("\n\n\n\n		B의 주사위를 굴립니다 : %d ", dice);
		Sleep(1000);
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
			//출발 걸음이 특수기호면?
			if (move == b + dice)//마지막 이동이
			{
				tmp = map[move];
				map[move] = 66;//쓰고
				SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);//출력
				map[move] = tmp;
				Sleep(500);
				system("cls");
				if (move == a)//A자리라면
				{
					printf("\n\n\n		KICK !");
					printf("\n\n		A는 원점으로 이동합니다");
					a = 0;//보내고
					Sleep(1000);
					system("cls");
					map[0] = 65;
					map[move] = 66;//쓰고 필요없나?
					SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);//출력
					Sleep(500);
					system("cls");
				}
				//snake1
				if (move == s1)
				{
					printf("\n\n\n		Snake !");
					printf("\n\n		18번으로 이동합니다");
					Sleep(1000);
					system("cls");
					map[move] = 83;//원래 수 써주고
					b = 18;
					map[s2] = 66;//쓰고
					SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);//출력
					Sleep(500);
					system("cls");

					if (a == 18)//A자리라면
					{
						printf("\n\n\n		KICK !");
						printf("\n\n		A는 원점으로 이동합니다");
						a = 0;//보내고
						Sleep(1000);
						system("cls");
						map[0] = 65;
						map[18] = 66;//쓰고 필요없나?
						SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);//출력
						Sleep(500);
						system("cls");
					}
					break;
				}
				//Snake2
				if (move == s3)
				{
					printf("\n\n\n		Snake !");
					printf("\n\n		30번으로 이동합니다");
					Sleep(1000);
					system("cls");
					map[move] = 83;//원래 수 써주고
					b = 30;
					map[s4] = 66;//쓰고
					SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);//출력
					Sleep(500);
					system("cls");

					if (a == 30)//A자리라면
					{
						printf("\n\n\n		KICK !");
						printf("\n\n		A는 원점으로 이동합니다");
						a = 0;//보내고
						Sleep(1000);
						system("cls");
						map[0] = 65;
						map[30] = 66;//쓰고 필요없나?
						SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);//출력
						Sleep(500);
						system("cls");
					}
					break;
				}

				//ladder1
				if (move == l1)
				{
					system("cls");
					printf("\n\n\n		Ladder !");
					printf("\n\n		34번으로 이동합니다");
					Sleep(1000);
					system("cls");

					map[l1] = 76;//쓰고
					map[l2] = 66;
					SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);//출력
					Sleep(500);
					system("cls");
					if (a == l2)
						map[l2] = 66;
					else
						map[l2] = 76;//쓰고
					map[l3] = 66;
					SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);//출력
					Sleep(500);
					system("cls");
					b = 34;
					if (a == 34)//A자리라면
					{
						printf("\n\n\n		KICK !");
						printf("\n\n		A는 원점으로 이동합니다");
						a = 0;//보내고
						Sleep(1000);
						system("cls");
						map[0] = 65;
						map[34] = 66;//쓰고 필요없나?
						SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);//출력
						Sleep(500);
						system("cls");
					}
					break;
				}

				//ladder2
				if (move == l4)
				{
					system("cls");
					printf("\n\n\n		Ladder !");
					printf("\n\n		41번으로 이동합니다");
					Sleep(1000);
					system("cls");

					map[l4] = 76;//쓰고
					map[l5] = 66;
					SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);//출력
					Sleep(500);
					system("cls");
					b = 41;
					if (a == 41)//A자리라면
					{
						printf("\n\n\n		KICK !");
						printf("\n\n		A는 원점으로 이동합니다");
						a = 0;//보내고
						Sleep(1000);
						system("cls");
						map[0] = 65;
						map[41] = 66;//쓰고 필요없나?
						SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);//출력
						Sleep(500);
						system("cls");
					}
					break;
				}

			}

			tmp = map[move];
			map[move] = 66;//쓰고
			SnakeLadder_PrintCurrentMap(j, map, OriginalMap, dir);//출력
			map[move] = tmp;
			Sleep(500);
			system("cls");

			if (map[move] == a || map[move] == 65)//지나가는 자리가 A 자리라면
				map[move] = 65;
			else if (move == b + dice)
				map[move] = 66;
			else if (move == s1 || move == s2 || move == s3 || move == s4)//지나가는 자리가 s 자리라면
				map[move] = 83;
			else if (move == l1 || move == l2 || move == l3 || move == l4 || move == l5)
				map[move] = 76;

			else
				map[move] = OriginalMap[move];//숫자로 덮고

			if (move == b + dice)
			{
				b = b + dice;//b 재위치
				break;
			}
			
		}

		if (b == 48)
		{
			Sleep(1000);
			system("cls");
			printf("\n\n\n		B 승리!!!!!");
			Sleep(1000);
			system("cls");
			main_screen();
		}
	}
		

	main_screen();
}

void SnakeLadder_PrintCurrentMap(int j, int map[], int OriginalMap[], int dir)
{
	int i = 42;
	printf("\n\n");
	while (1)
	{
		for (j = 0; j < 7; j++)
		{
			if (map[i] != OriginalMap[i])//숫자가 아니라 알파벳
				printf("  %5c", map[i]);
			else
				printf("  %5d", map[i]);//숫자


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
		printf("\n");
		if (i == 6)
			break;
		i = i - 7;
		dir = dir * (-1);
		printf("\n");
	}
return;
}