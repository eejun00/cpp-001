#include <iostream>
#include <stdio.h>

int heal2(int heal);


//�̷��� �Լ��� �����̴�.


void Info(int age)
{
    printf("�̸� : ���ؿ�\n���� : %d\n��ȭ��ȣ : 01033470532\n", age);
}

float ct(int dm)
{
    //float cdm = 1.5;
    printf("ũ��Ƽ�� ������! : %f\n", dm*1.5 );
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

int heal(int heal)
{
    int chp = 20;
    int MAXhp = 50;
    int hhp = chp + heal;
    int minus = heal - 30;
    int a = heal / 50;
    int b = a - 1;
    int d = hhp - 50;
    int c = d / 50;
    int e = 50 * c;
    int f = (hhp + 50) / 50;
    int over = hhp % 50;
    int overl = over * c;
    int all = hhp * a;


   

    printf("%d,%d,%d,%d,%d\n",c,hhp,e,f, over);
    return hhp - (e + over) ;
    //return all-(e+over)*c;
}

int rsp(int hand)
{
    int si = 1;
    int ro = 2;
    int pa = 3;
    int com = 2;


    hand > 2 ? printf("�¸�!\n") : hand > 1 ? printf("���º��Դϴ�\n") : printf("�й��߽��ϴ�.\n");
    return 0;
}



int main()
{
    int myhand = 0;
    printf("������������ 1,2,3���� �������ּ���.\n ���� : 1 ���� : 2 �� : 3\n");
    scanf_s("%d",&myhand);
    rsp(myhand);



    int inputnumber = 0;
    printf("���� ���� �Է����ּ��� ->  ");
    scanf_s("%d", &inputnumber);
    printf("�Է� ���� ���� %d �Դϴ�.\n", inputnumber);
    
    
    
    
    
    
    
    float numv = 1.6;
    //Info(25);
    //printf("%f\n", numv);

    printf("%d\n",heal(10));
    ct(150);

    int num1 = 9; int num2 = 2;
    printf("%d + %d = %d \n", num1, num2, num1 + num2);
    printf("%d - %d = %d \n", num1, num2, num1 - num2);
    printf("%d * %d = %d \n", num1, num2, num1 * num2);
    printf("%d / %d = %d \n", num1, num2, num1 / num2);
    printf("%d %% %d = %d \n", num1, num2, num1 % num2);

    int num3 = 2;
    int num4 = 3;


    printf("\n%d + %d ,��갪�� %d�Դϴ�.\n",num3,num4, plusnum(num3, num4));
    printf("%d - %d ,��갪�� %d�Դϴ�.\n", num3, num4, minusnum(num3, num4));
    printf("%d * %d ,��갪�� %d�Դϴ�.\n", num3, num4, mulnum(num3, num4));
    printf("%d / %d ,��갪�� %d�Դϴ�.\n", num3, num4, nanum(num3, num4));
    printf("%d %% %d ,��갪�� %d�Դϴ�.\n", num3, num4, namunum(num3, num4));

    printf("\n�� �� ü���� %d�Դϴ�.", heal2(10));


    /*int num1 = 10;
    int num2 = 12;
    int result1, result2, result3;

    result1 = (num1 == 10 && num2 == 12);
    result2 = (num1 < 12 || num2 > 12);*/
    //result3 = (!num1);
}//�߰�ȣ ���� ��������� �θ���.


int heal2(int heal)
{
    int MaxHp = 50;
    int CurruntHp = 20;
    int Hp = CurruntHp + heal;

    return Hp > 50 ? MaxHp : Hp;

}