#include <iostream>

void typeCasting();
void Description003();
void Description004();

int main()
{
    Description004();
}

void typeCasting()
{
    char char_ = 'A';
    int int_ = (int)char_;
    float floatValue = 100.123;

    int_ = (int)floatValue; // floatValue를 int형으로 강제 형변환

    printf("int_ 변수 안에 무슨 값이 들어있나? %f \n", (float)int_);
}

void Description003()
{
    //배열이란 무엇인지 실습
    int numbers[5];     //5개의 변수를 선언한 것이다.
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 4;
    numbers[4] = 5;

    for (int i = 0; i < 5; i++)
    {
        numbers[i] = (i + 1) * 100;
    }

    int numbers2[5] = { 10, 20, 30, 40, 50 }; //연속으로 선언
    int numbers3[5] = { 0, };   // 전부 0으로 초기화

    printf("배열의 값 앞은 (인덱스, 뒤는 값) : (%d, %d)\n", 0, numbers[0]);
    printf("배열의 값 앞은 (인덱스, 뒤는 값) : (%d, %d)\n", 1, numbers[1]);
    printf("배열의 값 앞은 (인덱스, 뒤는 값) : (%d, %d)\n", 2, numbers[2]);
    printf("배열의 값 앞은 (인덱스, 뒤는 값) : (%d, %d)\n", 3, numbers[3]);
    printf("배열의 값 앞은 (인덱스, 뒤는 값) : (%d, %d)\n", 4, numbers[4]);

}

void Description004()
{
    //구구단 출력하는 프로그램 만들기
    int lineCount[9] = {0, };
    int gugudan[9] = { 0, };
    int count = 2;
 

    while (count <= 9)
    {
        for (int i = 0; i < 9; i++)
        {
            lineCount[i] = i + 1;
            gugudan[i] = (i+1) * count ;
            printf("구구단 출력 %d * %d = %d\n",count, lineCount[i], gugudan[i]);
        }
        printf("\n\n");
        count += 1;
    }
    
}

void shiftzero()
{
    for (int)
}