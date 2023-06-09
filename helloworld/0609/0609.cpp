#include <iostream>

void Desc001();



int main()
{
   Desc001();
}

void Desc001()
{
    int userInput = -1;

    printf("원하는 크기 만큼 배열을 만들겠음. 크기를 입력하시오 : ");
    scanf_s("%d", &userInput);

    //new 동적할당
    int numbers[10] = { 0, };
    int* numbers2 = new int[userInput]; //new를 사용하면 heap에 배열을 할당한다.

    for (int i = 0; i < userInput; i++)
    {
        numbers2[i] = i + 1;
    }

    for (int i = 0; i < userInput; i++)
    {
        printf("i 값 : %d \n", numbers2[i]);
    }
    printf("\n\n");

    //프로그램 종료시에
    delete[] numbers2;
}