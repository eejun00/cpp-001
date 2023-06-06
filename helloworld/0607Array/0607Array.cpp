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
            //if (i == 0)
            //{
            //    board[i] = '0';
            //}
        }



        keyInput = _getch(); //키입력을 받고 확인하는 내용
        system("cls");
        switch (keyInput)
        {
        case 'a':
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
                board[count] = '0';
          
            }
            for (int i = 0; i < 5; i++)
            {
                printf("%c ", board[i]);
            }
            break;
        case 'd':
            if (count < 4)
            {
                board[++count] = '0';
            }
            else
            {
                printf("프로그램이 종료됩니다.\n");
                exit(0);
            }
            for (int i = 0; i < 5; i++)
            {
                printf("%c ", board[i]);
            }
            break;
        default:            
            printf("\n\n입력이 잘못되었습니다.\n");
        }
    }
}