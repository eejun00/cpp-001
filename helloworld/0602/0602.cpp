#include <iostream>
#include <conio.h>
#include <stdlib.h> //random ����ϱ����� �������
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
	//	printf("�̰��� ���� \n");
	//	break;
	//case 'b':
	//	printf("�̰��� ���� \n");
	//	break;
	//case 'c':
	//	printf("�̰��� �� \n");
	//	break;
	//default:
	//	printf("ó������ ���� ���� �Է��Դϴ�. \n");
	//	break;
	//}
	//

	//printf("���α׷��� �����մϴ�. \n");


	comdiceNomal();
	
}	//main �Լ� ����


//�Լ� ����

void criticaldamge()
{
	
	const int CRITICAL_PER = 60;
	const int CRITICALDAMAGE_RATE = 1.5;
	float ciriticaldamge = 1.5;
	int critical = 0;
	
	srand(time(NULL));

	printf("ũ��Ƽ�� Ȯ���� 60%%��, 1-100���� ���ڸ� �̾� 1-40�� ������ �Ϲݵ�����,41-100�̳����� ũ��Ƽ�� �������Դϴ�.\n");
	printf("qŰ�� ������ ���α׷��� �����մϴ�.\n\n");
	printf("�ƹ�Ű�� ������ �����غ�����. Ű�� �Է��Ҷ����� �����մϴ�!\n");
	_getch();

	while (1)
	{
		float damage = rand() % 10 + 10;
		int critical = rand() % 100 + 1;
		char touch = 0;

		printf("\n�̹��� ����� ���ݷ��� %0.f �Դϴ�.\n", damage);

		if (critical <= 40)
		{	
			printf("\n���¼��ڴ� %d..\n ġ��Ÿ ����..\n", critical);
			printf("ũ��Ƽ���� �����ʾҽ��ϴ�.. %f..\n", damage);
		}
		else
		{
			printf("\n���� ���ڴ� %d!!\n ġ��Ÿ ����!!\n", critical);
			printf("ũ��Ƽ�� ������!! %f!!\n", damage*1.5);
		}
		touch = _getch();
		if (touch == 'q' || touch == 'Q')
		{
			printf("\n���α׷��� �����մϴ�.");
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
	printf("�ֻ��� ���α׷�\n\n");
	printf("��ǻ�Ͱ� ���� 3���� �ֻ��� �� ->  ");
	for (int i = 0; i < 3; i++)
	{
		Sleep(1000);
		randomNumber = rand() % 6 + 1;
		printf("%d  ", randomNumber);
	}
	Sleep(1000);
	printf("\n\n ���α׷� ���� \n\n");
}


void randomnumber()
{
	////���⼭ Ű ���� �ٲ㺼 ����
	//srand(time(NULL));
	////random �����ϱ�
	//int randomNumber1,randomNumber2, randomNumber3 = 0;
	//randomNumber1 = rand() % 11;
	//randomNumber2 = rand() % 11;
	//randomNumber3 = rand() % 11;
	//printf("���� ����?? %d \n", randomNumber1);
	//printf("���� ����?? %d \n", randomNumber2);
	//printf("���� ����?? %d \n", randomNumber3);

	
}

void comdiceeasy()// �ֻ����� 2���� ���� Ȧ¦�� ����ϴ� �Լ�
{
	srand(time(NULL));

	int firstdice = rand() % 6 + 1;
	int seconddice = rand() % 6 + 1;
	int sumdice;

	printf("�ֻ����� ���ڴ� ���� %d, %d �Դϴ� \n", firstdice, seconddice);
	sumdice = firstdice + seconddice;
	printf("�ֻ����� ���� %d�Դϴ�.\n",sumdice);
	oddeven(sumdice);
	

}

void comdiceNomal() //�ֻ��� 2���� ������ Ȧ¦�� �÷��̾ ���ߴ� �Լ�
{
	srand(time(NULL));


	int sumdice;
	int answer;
	int oddevennum;
	char quit;



	while (true)
	{
		printf("\n�ֻ��� 2���� ���Ƚ��ϴ�.(Ȧ = 1,¦ = 2,���� = 0) \n Ȧ���� ¦���� ���纸���� ->  ");
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
			printf("\nù��° �ֻ��� : %d , �ι�° �ֻ��� %d,\n �ֻ����� �� : %d    ", firstdice, seconddice, sumdice);
			oddevennum == 1 ? printf("���� : Ȧ��   \n�����մϴ�! �����Դϴ�.\n") : printf("���� : Ȧ��   \nƲ�Ƚ��ϴ�.. �����Դϴ�.\n");
		}
		else if (answer == 2)
		{
			printf("\nù��° �ֻ��� : %d , �ι�° �ֻ��� %d,\n �ֻ����� �� : %d    ", firstdice, seconddice, sumdice);
			oddevennum == 0 ? printf("���� : ¦��   \n�����մϴ�! �����Դϴ�.\n") : printf("���� : ¦��   \nƲ�Ƚ��ϴ�.. �����Դϴ�.\n");
		}
		else
		{
			printf("�ٽ� �Է����ּ���.\n\n");
		}

	}
}

void oddeven(int num) // mod����� �̿��� Ȧ¦�����Լ�
{
	if (num % 2)
	{
		printf("�ֻ����� ���� ���� %d�� Ȧ���Դϴ�.\n\n", num);
	}
	else
	{
		printf("�ֻ����� ���� ���� %d�� ¦���Դϴ�.\n\n", num);
	}
}