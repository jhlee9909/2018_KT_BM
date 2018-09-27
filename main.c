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


		slot[star] = '��';
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
	//dir(���̷��� : ����) 1�϶� ������ -1�϶� ����
	int a=0, b=0;
	//�÷��̾�� ���� ��ġ
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

	printf("\n\n\n\n			A�� ��");
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
	printf("\n\n\n\n		�ֻ����� �����ϴ� :   ");
	Sleep(500);
	system("cls");
	dice = rand() % 6 + 1;
	printf("\n\n\n\n		�ֻ����� �����ϴ� : %d ",dice);
	Sleep(500);
	system("cls");


	
	return;
}