#include <iostream>
#include <stdio.h>

int heal2(int heal);
void Info(int age);
float ct(int dm);
int plusnum(int num1, int num2);
int minusnum(int num1, int num2);
int mulnum(int num1, int num2);
int nanum(int num1, int num2);
int namunum(int num1, int num2);
int rsp(int hand);
//함수의 전방선언

int main()
{
    int myhand = 0;
    printf("가위바위보를 1,2,3으로 결정해주세요.\n 가위 : 1 바위 : 2 보 : 3\n");
    scanf_s("%d",&myhand);
    rsp(myhand);



    int inputnumber = 0;
    printf("숫자 값을 입력해주세요 ->  ");
    scanf_s("%d", &inputnumber);
    printf("입력 받은 값은 %d 입니다.\n", inputnumber);
    
    
    
    
    
    
    
    float numv = 1.6;
    //Info(25);
    //printf("%f\n", numv);

    ct(150);

    int num1 = 9; int num2 = 2;
    printf("%d + %d = %d \n", num1, num2, num1 + num2);
    printf("%d - %d = %d \n", num1, num2, num1 - num2);
    printf("%d * %d = %d \n", num1, num2, num1 * num2);
    printf("%d / %d = %d \n", num1, num2, num1 / num2);
    printf("%d %% %d = %d \n", num1, num2, num1 % num2);

    int num3 = 2;
    int num4 = 3;


    printf("\n%d + %d ,계산값은 %d입니다.\n",num3,num4, plusnum(num3, num4));
    printf("%d - %d ,계산값은 %d입니다.\n", num3, num4, minusnum(num3, num4));
    printf("%d * %d ,계산값은 %d입니다.\n", num3, num4, mulnum(num3, num4));
    printf("%d / %d ,계산값은 %d입니다.\n", num3, num4, nanum(num3, num4));
    printf("%d %% %d ,계산값은 %d입니다.\n", num3, num4, namunum(num3, num4));

    printf("\n힐 후 체력은 %d입니다.", heal2(10));


    /*int num1 = 10;
    int num2 = 12;
    int result1, result2, result3;

    result1 = (num1 == 10 && num2 == 12);
    result2 = (num1 < 12 || num2 > 12);*/
    //result3 = (!num1);
}//중괄호 안을 스코프라고 부른다.


int heal2(int heal)
{
    int MaxHp = 50;
    int CurruntHp = 20;
    int Hp = CurruntHp + heal;

    return Hp > 50 ? MaxHp : Hp;

}

void Info(int age)
{
    printf("이름 : 이준영\n나이 : %d\n전화번호 : 01033470532\n", age);
}

float ct(int dm)
{
    //float cdm = 1.5;
    printf("크리티컬 데미지! : %f\n", dm * 1.5);
    return 0;
}

int plusnum(int num1, int num2)
{
    return num1 + num2;
}

int minusnum(int num1, int num2)
{
    return num1 - num2;
}

int mulnum(int num1, int num2)
{
    return num1 * num2;
}

int nanum(int num1, int num2)
{
    return num1 / num2;
}

int namunum(int num1, int num2)
{
    return num1 % num2;
}


int rsp(int hand)
{
    int si = 1;
    int ro = 2;
    int pa = 3;
    int com = 2;


    hand > 2 ? printf("승리!\n") : hand > 1 ? printf("무승부입니다\n") : printf("패배했습니다.\n");
    return 0;
}