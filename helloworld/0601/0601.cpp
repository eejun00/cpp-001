

#include <iostream>
int calthreenum(int num1, int num2, int num3);
int calthreenumfinal(int num1, int num2, int num3);
float circlearea(int radius);
int isnotalphabet(char alphabet);
int isexclamationmark(char letter);
void makesquare(int count);

int main()
{
    /*
    // 변수 선언부 {
    int result;
    int num1, num2;
    // } 변수 선언부


    // 사용자 입력받는 로직 {
    printf("정수 one :");
    //scanf_s("%d", &num1);
    printf("정수 two :");
    scanf_s("%d, %d", &num1, &num2);
    //} 사용자 입력 받는 로직

    // { 실제 연산하는 로직 / 플러스 연산
    result = num1 + num2;
    printf("%d + %d = %d \n", num1, num2, result);
    //} 실제 연산하는 로직 / 플러스 연산
    */
    
    /*int num1, num2, num3;

    printf("정수 3개를 차례대로 입력해주세요 예시(1,2,3) ->");
    scanf_s("%d,%d,%d", &num1, &num2, &num3);
    printf("\n결과값은 %d + %d * %d = %d 입니다.",num1,num2,num3, calthreenum(num1, num2, num3));
    printf("\n변형 계산식의 결과값은(%d -%d) * (%d + %d) * (%d %% %d) = %d 입니다.",num1,num2,num2,num3,num3,num1, calthreenumfinal(num1, num2, num3));
    */
    

    /*
    //정수형 데이터 타입
    char charValue = 'A';   //문자 하나를 저장하기 위한 데이터 타입
    short shortValue = 10;  //int 보다 작은수를 저장하기 위한 데이터 타입
    int intValue = 100;     //가장 만만한 수를 저장하기 위한 데이터 타입
    long longValue = 200;   //int가 커져서 이제 잘 안쓰는 데이터 타입
    long long longlongValue = 1000;    //int보다 큰 수를 저장하기 위한 데이터 타입

    //실수형 데이터 타입
    float floatValue = 10.1;        //가장 만만한 실수를 저장하기 위한 데이터 타입
    double doubleValue = 100.1;     //float 보다 큰 실수를 저장하기 위한 데이터 타입
    long double longdoubleValue = 200.1; //double 보다 큰 실수를 저장하기 위한 데이터타입

    printf("char 의 크기는? %d byte\n", sizeof(charValue));
    printf("short의 크기는? %d byte \n", sizeof(shortValue));
    printf("int의 크기는? %d byte \n", sizeof(intValue));
    printf("long의 크기는? %d byte \n", sizeof(longValue));
    printf("long long의 크기는? %d byte \n", sizeof(longlongValue));

    printf("float의 크기는? %d byte \n", sizeof(floatValue));
    printf("double의 크기는? %d byte \n", sizeof(doubleValue));
    printf("long double의 크기는? %d byte \n", sizeof(longdoubleValue));
    */

    
    /* //원의 넓이 구하기
    const float PI = 3.141592f;
    int radius = 0;

    printf("원의 반지름을 입력해주세요 -> ");
    scanf_s("%d", &radius);
    printf("원의 넓이는 %f입니다.", circlearea(radius));
    */

    /*char charValue = 'A';

    printf("char 출력할 때는 C로 해보자 -> %d\n", charValue);

    bool isSame = ('A' == 65);

    char someAlphabet = 'a';
    bool isBigAlphabet = ('A' <= someAlphabet && someAlphabet <= 'Z');
    printf("\n some alphabet은 대문자인가?? %d \n", isBigAlphabet);
    printf("진짜로 같은가?? %d \n", isSame);
    */
    
    //char somechar;

    //printf("문자를 입력해주세요 ->");
    //scanf_s("%c", &somechar);
    ////(isnotalphabet(somechar) == 1) ? printf("특수문자가 아닙니다.") : printf("특수문자입니다.");      //이지모드
    //(isexclamationmark(somechar) == 1) ? printf("특수문자입니다.") : printf("특수문자가 아닙니다.");    //하드모드

    int size = 0;
    printf("원하시는 사각형의 사이즈를 입력해주세요 ->");
    scanf_s("%d", &size);
    makesquare(size);
    
    /*int whilecount = size * size;
    int savecount = size;

    while (whilecount >= 1)
    {
        while (savecount >= 1)
        {
            printf("* ");
            savecount -= 1;
            whilecount -= 1;
        }
        printf("\n");
        savecount = size;
    }*/

    return 0;
}   //main()

int calthreenum(int num1, int num2, int num3)
{
    int result = num1 + num2 * num3;
    return result;  
} 

int calthreenumfinal(int num1, int num2, int num3)
{
    int result = (num1 - num2) * (num2 + num3) * (num3 % num1);
    return result;
}

float circlearea(int radius)
{
    const float PI = 3.141592f;
    return radius* radius * PI;
}

int isnotalphabet(char alphabet)
{       
   return bool('A' <= alphabet && alphabet <= 'Z' || 'a' <= alphabet && alphabet <= 'z');
}

int isexclamationmark(char letter)
{
    return bool('!' <= letter && letter <= '/' || ':' <= letter && letter <= '@' || '[' <= letter && letter <= 96 || '{' <= letter && letter <='~');
}

void makesquare(int count)
{
    int whilecount = count * count;
    int savecount = count;

    while (whilecount >= 1)
    {
        while (savecount >= 1)
        {
            printf("* ");
            savecount -= 1;
            whilecount -= 1;
        }
        printf("\n");
        savecount = count;
    }
}