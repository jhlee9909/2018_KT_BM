#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

void main_screen();
void StarCatch();

//asdfghjk
int main(void)
{
	main_screen();
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
	printf("		****    *     *	    *   *           *         *   ******  *    *    *   *   ****\n");
	printf("		****    *     *	    *   *           *       *          *  *     ****    *   ****\n");
	printf("		****    *******	    *   ********    *     *            *  *                 ****\n");
	printf("		****                *               *                     *      ********   ****\n");
	printf("		****                                                             *      *   ****\n");
	printf("		****                                                             ********   ****\n");
	printf("		****                                                                        ****\n");
	printf("		********************************************************************************\n");
	printf("		********************************************************************************\n\n\n");

	printf("������ ������ �������ּ���.\n\n");
	printf("1.���� �߱�			2.����������			3.���ٸ� ����			4.��Ÿĳġ\n\n\n");

	printf("-��ȣ�� �Է����ּ��� : ");
	scanf_s("%d", &select);

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
		//3�� ����
		break;
	case 4 :
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