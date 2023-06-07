#include <iostream>
#include <conio.h>

//함수 전방 선언
void ZeroInStar();


int main()
{
    ZeroInStar();
}

void ZeroInStar()
{
    char board[5] = { 0, };
    char keyInput = 0;
    int count = -1;


    while(count < 5)
    {
        for (int i = 0; i < 5; i++) //'*' 5개로 배열을 초기화
        {
            board[i] = '*';
        }



        keyInput = _getch(); //키입력을 받고 확인하는 내용
        system("cls");
        switch (keyInput)
        {
        case 'a':   //a가 입력되었을경우
            if (count <= 0)
            {
                printf("'0'이 배열을 벗어났습니다.\n"); 
                if (count == 0)
                {
                    count -= 1;
                }
                break;
            }
            else
            {
                count -= 1;
                board[count] = '0'; //배열안에 count의 숫자에따라 0를 넣어준다.
          
            }
            for (int i = 0; i < 5; i++) //완성된 배열을 출력하는 반복문
            {
                printf("%c ", board[i]);
            }
            break;
        case 'd':   //d가 입력되었을 경우
            if (count < 4)
            {
                board[++count] = '0';   //배열안에 count의 숫자에따라 0를 넣어준다.
            }
            else
            {
                printf("프로그램이 종료됩니다.\n");   // 배열을 벗어난곳으로 갈경우 프로그램 종료
                exit(0);
            }
            for (int i = 0; i < 5; i++) //완성된 배열을 출력하는 반복문
            {
                printf("%c ", board[i]);
            }
            break;
        default:            //입력이 a와d가 아닐경우
            printf("\n\n입력이 잘못되었습니다.\n");
        }
    }
}