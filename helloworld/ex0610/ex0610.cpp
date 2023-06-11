#include <iostream>

int sub(int a, int b)
{
	return a - b;
}

void main()
{
	int num1 = 4;
	int num2 = 3;	

	printf("\n\n");
	printf("함수 실행 결과 값 : %d \n", sub(num1, num2));
	printf("함수 실행 후 num1 : %d, num2 : %d \n\n", num1, num2);
}