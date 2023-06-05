#include <iostream>
#include <conio.h>
#include <stdlib.h> //random 사용하기위한 헤더파일
#include <time.h>
#include <windows.h>


void criticaldamge();
void ex();
void randomnumber();
void comdiceeasy();
void comdiceNomal();
void oddeven(int num);

int main()
{
	//char userInput = 0;
	//printf("User input : ");
	//userInput = _getch();

	//printf("\n\n");

	////scanf_s("%d", &userInput);

	//switch (userInput)
	//{
	//case 'a':
	//	printf("이것은 가위 \n");
	//	break;
	//case 'b':
	//	printf("이것은 바위 \n");
	//	break;
	//case 'c':
	//	printf("이것은 보 \n");
	//	break;
	//default:
	//	printf("처리되지 않은 예외 입력입니다. \n");
	//	break;
	//}
	//

	//printf("프로그램을 종료합니다. \n");


	comdiceNomal();
	
}	//main 함수 종료


//함수 시작

void criticaldamge()
{
	
	const int CRITICAL_PER = 60;
	const int CRITICALDAMAGE_RATE = 1.5;
	float ciriticaldamge = 1.5;
	int critical = 0;
	
	srand(time(NULL));

	printf("크리티컬 확률은 60%%로, 1-100까지 숫자를 뽑아 1-40이 나오면 일반데미지,41-100이나오면 크리티컬 데미지입니다.\n");
	printf("q키를 누르면 프로그램을 종료합니다.\n\n");
	printf("아무키나 눌러서 공격해보세요. 키를 입력할때마다 공격합니다!\n");
	_getch();

	while (1)
	{
		float damage = rand() % 10 + 10;
		int critical = rand() % 100 + 1;
		char touch = 0;

		printf("\n이번턴 당신의 공격력은 %0.f 입니다.\n", damage);

		if (critical <= 40)
		{	
			printf("\n나온숫자는 %d..\n 치명타 실패..\n", critical);
			printf("크리티컬이 뜨지않았습니다.. %f..\n", damage);
		}
		else
		{
			printf("\n나온 숫자는 %d!!\n 치명타 성공!!\n", critical);
			printf("크리티컬 데미지!! %f!!\n", damage*1.5);
		}
		touch = _getch();
		if (touch == 'q' || touch == 'Q')
		{
			printf("\n프로그램을 종료합니다.");
			break;
		}
	}

	
}


void ex()
{
	int randomNumber = 0;
	const int MAX_DICE_VALUE = 6;
	srand(time(NULL));

	_getch();
	printf("주사위 프로그램\n\n");
	printf("컴퓨터가 뽑은 3개의 주사위 값 ->  ");
	for (int i = 0; i < 3; i++)
	{
		Sleep(1000);
		randomNumber = rand() % 6 + 1;
		printf("%d  ", randomNumber);
	}
	Sleep(1000);
	printf("\n\n 프로그램 종료 \n\n");
}


void randomnumber()
{
	////여기서 키 값을 바꿔볼 예정
	//srand(time(NULL));
	////random 이해하기
	//int randomNumber1,randomNumber2, randomNumber3 = 0;
	//randomNumber1 = rand() % 11;
	//randomNumber2 = rand() % 11;
	//randomNumber3 = rand() % 11;
	//printf("랜덤 숫자?? %d \n", randomNumber1);
	//printf("랜덤 숫자?? %d \n", randomNumber2);
	//printf("랜덤 숫자?? %d \n", randomNumber3);

	
}

void comdiceeasy()// 주사위의 2개의 합의 홀짝을 출력하는 함수
{
	srand(time(NULL));

	int firstdice = rand() % 6 + 1;
	int seconddice = rand() % 6 + 1;
	int sumdice;

	printf("주사위의 숫자는 각각 %d, %d 입니다 \n", firstdice, seconddice);
	sumdice = firstdice + seconddice;
	printf("주사위의 합은 %d입니다.\n",sumdice);
	oddeven(sumdice);
	

}

void comdiceNomal() //주사위 2개를 굴리고 홀짝을 플레이어가 맞추는 함수
{
	srand(time(NULL));


	int sumdice;
	int answer;
	int oddevennum;
	char quit;



	while (true)
	{
		printf("\n주사위 2개를 굴렸습니다.(홀 = 1,짝 = 2,종료 = 0) \n 홀인지 짝인지 맞춰보세요 ->  ");
		int firstdice = rand() % 6 + 1;
		int seconddice = rand() % 6 + 1;

		sumdice = firstdice + seconddice;
		if (sumdice % 2)
		{
			oddevennum = 1;
		}
		else
		{
			oddevennum = 0;
		}

		scanf_s("%d", &answer);
		scanf_s("%c", &quit);


		if (answer == 0)
		{
			break;
		}
		else if (answer == 1)
		{
			printf("\n첫번째 주사위 : %d , 두번째 주사위 %d,\n 주사위의 합 : %d    ", firstdice, seconddice, sumdice);
			oddevennum == 1 ? printf("정답 : 홀수   \n축하합니다! 정답입니다.\n") : printf("정답 : 홀수   \n틀렸습니다.. 오답입니다.\n");
		}
		else if (answer == 2)
		{
			printf("\n첫번째 주사위 : %d , 두번째 주사위 %d,\n 주사위의 합 : %d    ", firstdice, seconddice, sumdice);
			oddevennum == 0 ? printf("정답 : 짝수   \n축하합니다! 정답입니다.\n") : printf("정답 : 짝수   \n틀렸습니다.. 오답입니다.\n");
		}
		else
		{
			printf("다시 입력해주세요.\n\n");
		}

	}
}

void oddeven(int num) // mod계산을 이용한 홀짝구별함수
{
	if (num % 2)
	{
		printf("주사위의 합의 값인 %d는 홀수입니다.\n\n", num);
	}
	else
	{
		printf("주사위의 합의 값인 %d는 짝수입니다.\n\n", num);
	}
}