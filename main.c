#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define SIZE 32
#define Line 10		//오목판의 가로,세로의 숫자(정사각형)
#define stone 5		//승리하기 위해 놓아야하는 돌 수


void stone_game();

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
	printf("1.숫자 야구			2.가위바위보			3.뱀사다리 게임			4.스타캐치\n5.돌게임\n\n\n");

	printf("-번호만 입력해주세요 : ");
	scanf("%d", &select);

	while (select < 1 || select > 5) {

		printf("-입력값이 올바르지 않음 다시 입력해주세요 :");
		scanf_s("%d", &select);

	}

	fflush(stdin);

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
	case 5:
		stone_game();
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
	char slot[SIZE] = { ' ' };
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

	fflush(stdin);
	printf("*아무키나 입력해주세요");

	getch();
	fflush(stdin);

	system("cls");
	main_screen();
	return;
}

void stone_game() {
	int i, w, z, x, count = 0;
	int input = 0;
	int score = 0;

	char checked_pattern[Line*Line];

	system("cls");
	fflush(stdin);
	for (i = 0; i < Line*Line; i++) {
		checked_pattern[i] = i + 1;
	}

	for (i = 0; i < Line*Line; i++) {
		count++;
		printf(" %d	|  ", checked_pattern[i]);
		if (count%Line == 0) {
			printf("\n");
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
			printf("\n");
		}
	}
	count = 0;
	//////////////////////////////////////////////////////오목판 생성
	for (i = 0; i < Line*Line; i++) {
		//총 둘수 있는 돌 만큼 반복
		printf("돌을 둘 자리를 선택해주세요. : ");
		scanf_s("%d", &input);

		if (i % 2 == 0 && checked_pattern[input - 1] != 'x' && checked_pattern[input - 1] != 'o') {
			checked_pattern[input - 1] = 'x';
			system("cls");
		}
		else if (i % 2 == 1 && checked_pattern[input - 1] != 'x' && checked_pattern[input - 1] != 'o') {
			checked_pattern[input - 1] = 'o';
			system("cls");
		}
		else if (input > 100 || input < 1) {
			system("cls");
			printf("\n			***************잘못 입력하였습니다.***************\n\n");
			i--;

		}
		else {
			system("cls");
			printf("\n			***************잘못 입력하였습니다.***************\n\n");
			i--;

		}


		for (w = 0; w < Line*Line; w++) {
			count++;
			if (checked_pattern[w] == 'x') {
				printf(" %c	|  ", checked_pattern[w]);
			}
			else if (checked_pattern[w] == 'o') {
				printf(" %c	|  ", checked_pattern[w]);
			}
			else {
				printf(" %d	|  ", checked_pattern[w]);
			}

			if (count%Line == 0) {
				printf("\n");
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
				printf("\n");
			}
		}
		printf("전 플레이어가 둔 자리 : %d\n\n", input);
		/////////////////////////////////////////////////////////돌맹이 놓는것까지 구현
		for (x = 0; x < Line; x++) {
			for (w = 0 + (x * 10); w < Line - (stone - 1) + (x * 10); w++) {
				//한줄씩 따로 확인
				for (z = 0; z < stone; z++) {
					if (checked_pattern[w + z] == checked_pattern[w + z + 1]) {
						score++;
					}
					if (score == stone - 1) {
						if (i % 2 == 1)
							printf("O돌을 놓은 플레이어가 승리하였습니다.");
						else if (i % 2 == 0)
							printf("X돌을 놓은 플레이어가 승리하였습니다.");

						fflush(stdin);
						printf("\n*아무키나 입력해주세요");
						fflush(stdin);
						getch();
						fflush(stdin);
						getch();
						fflush(stdin);
						system("cls");
						main_screen();
						return;
					}
				}
				score = 0;
			}
		}
		score = 0;
		/////////////////////////////////////////////////////////////가로 5개로 승리하는 경우
		for (w = 0; w < (Line - stone + 1)*Line; w++) {
			for (z = 0; z < stone; z++) {
				if (checked_pattern[w + (z * 10)] == checked_pattern[w + ((z + 1) * 10)]) {
					score++;
				}
				if (score == stone - 1) {
					if (i % 2 == 1)
						printf("O돌을 놓은 플레이어가 승리하였습니다.");
					else if (i % 2 == 0)
						printf("X돌을 놓은 플레이어가 승리하였습니다.");

					fflush(stdin);
					printf("\n*아무키나 입력해주세요");
					fflush(stdin);
					getch();
					fflush(stdin);
					getch();
					fflush(stdin);
					system("cls");
					main_screen();
					return;
				}
			}
			score = 0;
		}
		score = 0;
		///////////////////////////////////////////////////////////////세로 5개로 승리하는 경우
		for (w = 0; w < Line - stone + 1; w++) {
			for (z = 0; z < Line - stone + 1; z++) {
				if (checked_pattern[w + (z * 11)] == checked_pattern[(w + 11) + (z * 11)]) {
					score++;
				}
				if (score == stone - 1) {
					if (i % 2 == 1)
						printf("O돌을 놓은 플레이어가 승리하였습니다.");
					else if (i % 2 == 0)
						printf("X돌을 놓은 플레이어가 승리하였습니다.");

					fflush(stdin);
					printf("\n*아무키나 입력해주세요");
					fflush(stdin);
					getch();
					fflush(stdin);
					getch();
					fflush(stdin);
					system("cls");
					main_screen();
					return;
				}
			}
			score = 0;
		}
		score = 0;
		///////////////////////////////////////////////////////////////대각선(왼쪽위에서 오른쪽아래) 5개로 승리
		for (x = 0; x < Line - stone + 1; x++) {
			for (w = stone - 1; w < Line + 1; w++) {
				for (z = 0; z < stone; z++) {
					if (checked_pattern[w + (z * 9) + (x * 10)] == checked_pattern[(w + 9) + (z * 9) + (x * 10)]) {
						score++;
					}
					if (score == stone - 1) {
						if (i % 2 == 1)
							printf("O돌을 놓은 플레이어가 승리하였습니다.");
						else if (i % 2 == 0)
							printf("X돌을 놓은 플레이어가 승리하였습니다.");

						fflush(stdin);
						printf("\n*아무키나 입력해주세요");
						fflush(stdin);
						getch();
						fflush(stdin);
						getch();
						fflush(stdin);
						system("cls");
						main_screen();
						return;
					}

				}
				score = 0;
			}
		}
		///////////////////////////////////////////////////////////////대각선(왼쪽아래에서 오른쪽위) 5개로 승리
	}
	return;
}