#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>

void Desc002();
void ShuffleOnce(int* firstNumber, int* secondNumber);

int main()
{
    Desc002();
}

void Desc002()
{
    char keyInput = 0;
    int char2_[6][6] = { 0, };
    int puzzlearea = 0;
    int count = 1;

    printf("슬라이딩 퍼즐의 크기를 입력해주세요 (3 ~ 6)");
    std::cin >> puzzlearea;

    int x_axis = puzzlearea-1;
    int y_axis = puzzlearea-1;

    for (int y = 0; y < puzzlearea; y++)
    {
        for (int x = 0; x < puzzlearea; x++)
        {
            if (x == puzzlearea - 1 && y == puzzlearea - 1)
            {
                char2_[y][x] = 0;
                continue;
            }
            char2_[y][x] = count++;
        }
    }


    const int shuffleCount = 500;
    int randomIdx1, randomIdx2, randomIdx3, randomIdx4 = 0;
    srand(time(NULL));

    for (int i = 0; i < shuffleCount; i++)
    {
        randomIdx1 = rand() % puzzlearea;
        randomIdx2 = rand() % (puzzlearea-1);
        randomIdx3 = rand() % (puzzlearea-1);
        randomIdx4 = rand() % puzzlearea;
        ShuffleOnce(&char2_[randomIdx1][randomIdx3], &char2_[randomIdx2][randomIdx4]);
    }
    //셔플 로직

    //출력 부분
    for (int y = 0; y < puzzlearea; y++)
    {
        for (int x = 0; x < puzzlearea; x++)
        {
            printf("%2d ", char2_[y][x]);
        }
        printf("\n");
    }

    while (1)
    {
        keyInput = _getch(); //키입력을 받고 확인하는 내용
        system("cls");
        switch (keyInput)
        {
        case 'a':
            if (x_axis <= 0)
            {                             
                break;
            }
            else
            {
                char2_[y_axis][x_axis] = char2_[y_axis][x_axis-1];
                char2_[y_axis][--x_axis] = 0;
                
            }
            break;
        case 'd':
            if (x_axis < puzzlearea)
            {
                char2_[y_axis][x_axis] = char2_[y_axis][x_axis + 1];
                char2_[y_axis][++x_axis] = 0;

                
            }
            else
            {
                
                break;
            }

            break;


        case 'w':
            if (y_axis < 1)
            {
               
               

                break;
            }
            else
            {
                char2_[y_axis][x_axis] = char2_[y_axis-1][x_axis];
                char2_[--y_axis][x_axis] = 0;
                
            }
            break;



        case 's':
            if (y_axis < puzzlearea)
            {
                char2_[y_axis][x_axis] = char2_[y_axis+1][x_axis];
                char2_[++y_axis][x_axis] = 0;

                
            }
            else
            {

                

                break;

            }
            break;

        default:
            printf("\n\n입력이 잘못되었습니다.\n");
        }
        for (int y = 0; y < puzzlearea; y++)
        {
            for (int x = 0; x < puzzlearea; x++)
            {
                printf("%2d ", char2_[y][x]);
            }
            printf("\n");
        }
    }
}

void ShuffleOnce(int* firstNumber, int* secondNumber)
{
    int temp = 0;
    temp = *firstNumber;
    *firstNumber = *secondNumber;
    *secondNumber = temp;
}