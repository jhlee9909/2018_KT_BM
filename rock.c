#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
 

int main(void){

 

     int input, a;
     int draw = 0, win = 0;
	 int W=0,D=0,L=0;
 
	 srand((int)time(NULL));
     //사용자가 질 때 까지 반복
     while (1){
          printf("바위는 1, 가위는 2, 보는 3: ");
          scanf_s("%d", &input);

  

//srand()와 time()을 이용해서 1~3까지 난수생성
a = rand() % ((3 - 1) + 1) + 1;

 

          //비겼을 때
          if (input == a){


               //난수가 바위이면
               if (input == 1){
                    printf("당신은 바위, 컴퓨터는 바위 선택, 비겼습니다.");
                    draw++;
					D++;
               }


               //난수가 가위이면
               else if (input == 2){
                    printf("당신은 가위, 컴퓨터는 가위 선택, 비겼습니다.");
                    draw++;
					D++;
               }


               //난수가 보자기이면
               else{
                    printf("당신은 보자기, 컴퓨터는 보자기 선택, 비겼습니다.");
                    draw++;
					D++;
               }
          }
		  
               if (input == 1 && a == 2){
                    printf("당신은 바위, 컴퓨터는 가위 선택, 이겼습니다.");
                    win++;
					W++;
               }


               else if (input == 2 && a == 3){
                    printf("당신은 가위, 컴퓨터는 보자기 선택, 이겼습니다.");
                    win++;
					W++;
               }


               else if (input == 3 && a == 1){
                    printf("당신은 보자기, 컴퓨터는 바위 선택, 이겼습니다.");
                    win++;
					W++;
               }
        
               if (input == 1 && a == 3){
                    printf("당신은 바위, 컴퓨터는 보자기 선택, 졌습니다.");
                    break;
               }


               else if (input == 2 && a == 1){
                    printf("당신은 가위, 컴퓨터는 바위 선택, 졌습니다.");
                    break;
               }


               else if (input == 3 && a == 2){
                    printf("당신은 보자기, 컴퓨터는 가위 선택, 졌습니다.");
                    break;
               }
			   printf("\n");
			   if(W == 1){
				printf("\n\n\n\n\n\n\n\n");
			   printf("         ********          *********          *********       ********         **********      *****\n");
			   printf("          ********        ***********        *********        ********         ***********     *****\n");
			   printf("           ********      *************      *********         ********         ************    *****\n");
			   printf("            *********  ******** ********  **********          ********         ****** ******   *****\n");
			   printf("             *****************   ******************           ********         ******  ******* *****\n");
			   printf("              **************       ***************            ********         ******   ************\n");
			   printf("               ***********           ***********              ********         ******    ***********\n");
			   printf("                 *******               *******                ********         ******     **********\n");
			  

			   }
			W=0,D=0,L=0;
			Sleep(2000);
			system("cls");
     }

 

     printf("\n\n");
     printf("게임의 결과 : %d승, %d무", win, draw);

     return 0;
}