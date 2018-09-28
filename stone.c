#include <stdio.h>
#include <windows.h>

#define Line 10		//오목판의 가로,세로의 숫자(정사각형)
#define stone 5		//승리하기 위해 놓아야하는 돌 수


void stone_game();

int main(void)
{
	stone_game();
	return 0;
}
////////////////////////////////////////////////////함수 시작
void stone_game(){
	int i,w,z,x,count=0;
	int input = 0;
	int score=0;
	
	char checked_pattern[Line*Line];

	for(i=0;i<Line*Line;i++){
		checked_pattern[i] = i+1;
	}

	for(i=0;i<Line*Line;i++){
		count++;
		printf(" %d	|  ",checked_pattern[i]);
		if(count%Line == 0){
			printf("\n");
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
			printf("\n");
		}
	}
	count=0;
//////////////////////////////////////////////////////오목판 생성
	for(i=0;i<Line*Line;i++){
	//총 둘수 있는 돌 만큼 반복
		printf("돌을 둘 자리를 선택해주세요. : ");
		scanf_s("%d",&input);

		if(i%2 == 0 && checked_pattern[input-1] != 'h' && checked_pattern[input-1] != 'k'){
			checked_pattern[input-1] = 'h';
			system("cls");
		}
		else if(i%2 == 1 && checked_pattern[input-1] != 'h' && checked_pattern[input-1] != 'k'){
			checked_pattern[input-1] = 'k';
			system("cls");
		}
		else{
			system("cls");
			printf("\n			***************잘못 입력하였습니다.***************\n\n");
			i--;
			
		}
		

		for(w=0;w<Line*Line;w++){
			count++;
			if(checked_pattern[w] == 'h'){
				printf(" %c	|  ",checked_pattern[w]);
			}
			else if(checked_pattern[w] == 'k'){
				printf(" %c	|  ",checked_pattern[w]);
			}
			else{
			printf(" %d	|  ",checked_pattern[w]);
			}

			if(count%Line == 0){
				printf("\n");
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
				printf("\n");
			}
		}
		printf("전 플레이어가 둔 자리 : %d\n\n",input);
/////////////////////////////////////////////////////////돌맹이 놓는것까지 구현
		for(x=0;x<Line;x++){
			for(w=0+(x*10);w<Line-(stone-1)+(x*10);w++){
				//한줄씩 따로 확인
				for(z=0;z<stone;z++){
					if(checked_pattern[w+z] == checked_pattern[w+z+1]){
						score++;
					}
					if(score == stone-1){
						if(i%2 == 1)
							printf("k돌을 놓은 플레이어가 승리하였습니다.");
						else if(i%2 == 0)
							printf("h돌을 놓은 플레이어가 승리하였습니다.");
						return;
					}
				}
			score=0;
			}
		}
		score=0;
/////////////////////////////////////////////////////////////가로 5개로 승리하는 경우
		for(w=0;w<(Line-stone+1)*Line;w++){
			for(z=0;z<stone;z++){
				if(checked_pattern[w+(z*10)] == checked_pattern[w+((z+1)*10)]){
						score++;
				}
				if(score == stone-1){
					if(i%2 == 1)
						printf("k돌을 놓은 플레이어가 승리하였습니다.");
					else if(i%2 == 0)
						printf("h돌을 놓은 플레이어가 승리하였습니다.");
					return;
				}
			}
			score=0;
		}
		score=0;
///////////////////////////////////////////////////////////////세로 5개로 승리하는 경우
		for(w=0;w<Line-stone+1;w++){
			for(z=0;z<Line-stone+1;z++){
				if(checked_pattern[w+(z*11)] == checked_pattern[(w+11)+(z*11)]){
						score++;
				}
				if(score == stone-1){
					if(i%2 == 1)
						printf("k돌을 놓은 플레이어가 승리하였습니다.");
					else if(i%2 == 0)
						printf("h돌을 놓은 플레이어가 승리하였습니다.");
					return;
				}
			}
			score=0;
		}
		score=0;
///////////////////////////////////////////////////////////////대각선(왼쪽위에서 오른쪽아래) 5개로 승리
		for(w=stone-1;w<Line;w++){
			for(z=0;z<Line-stone+1;z++){
				if(checked_pattern[w+(z*9)] == checked_pattern[(w+9)+(z*9)]){
						score++;
				}
				if(score == stone-1){
					if(i%2 == 1)
						printf("k돌을 놓은 플레이어가 승리하였습니다.");
					else if(i%2 == 0)
						printf("h돌을 놓은 플레이어가 승리하였습니다.");
					return;
				}
			}
			score=0;
		}
///////////////////////////////////////////////////////////////대각선(왼쪽아래에서 오른쪽위) 5개로 승리
	}
	return;
}