#include <iostream>
#include <stdio.h>

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
        scanf_s("%d", &myhand);
        rsp(myhand);

}