#include <iostream>
#include <stdio.h>

int rsp(int hand)
{
    int si = 1;
    int ro = 2;
    int pa = 3;
    int com = 2;


    hand > 2 ? printf("승리!\n") : hand > 1 ? printf("무승부입니다\n") : printf("패배했습니다.\n");
    return 0;
}

int main() 
{
        int myhand = 0;
        printf("가위바위보를 1,2,3으로 결정해주세요.\n 가위 : 1 바위 : 2 보 : 3\n");
        scanf_s("%d", &myhand);
        rsp(myhand);

}