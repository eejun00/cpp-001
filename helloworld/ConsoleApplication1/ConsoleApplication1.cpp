// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>

void MyNewPrint(int number)
{
    printf("입력 값은 %d 입니다. \n", number);
}

int PlusTwoNumbers(int number1, int number2)
{
    printf("입력 값은 %d, %d 입니다. \n", number1, number2);
    return number1 + number2;
}

int Tn(int number1, int number2, int number3)
{
    printf("입력 값은 %d, %d, %d 입니다. \n", number1, number2, number3);
    return number1 * number2 * number3;
}

int main()
{
    std::cout << "Hello World!\n";
    printf("Hello World! \n");

    MyNewPrint(100); // 실제로 함수를 사용하는 줄에서 함수를 부른다. (call)
    printf("두 수의 합은 %d 입니다.\n", PlusTwoNumbers(5, 7));
    printf("세 수의 곱은 %d 입니다. \n", Tn(4, 5, 6));
    
    //comment 주석 이 라인은 프로그램에 영향을 주지않는다. 이것은 한줄 주석이다.
    /*
    이걸 여러줄 주석이라고 한다. 
    */
}
