#include <iostream>
#include <conio.h>

void Desc001();
void ArrayFunc(int* ptrArray);
void ArrayFunc2(int array_[], int arraySize);
void SwapArray(int* firstarray, int *secondarray);
void Desc002();
void printmap(char char_[][6]);


int main()
{
    
    Desc002();




}

void Desc002()
{
    char keyInput = 0;
    int x_axis = 3;
    int y_axis = 3;
    char char2_[6][6] ={     0,   };

    for (int y = 0; y < 6; y++)
    {
        for (int x = 0; x < 6; x++)
        {
            if (x == 3 && y == 3)
            {
                char2_[3][3] = '0';
                continue;
            }
            if ((x == 0 || y == 0)|| (x == 5 || y == 5))
            {
                char2_[y][x] = '#';
                continue;
            }

            char2_[y][x] = '*';
        }
    }

    //출력 부분
    for (int y = 0; y < 6; y++)
    {
        for (int x = 0; x < 6; x++)
        {
            printf("%c ", char2_[y][x]);
        }
        printf("\n");
    }

    while(1)
    {


        keyInput = _getch(); //키입력을 받고 확인하는 내용
        system("cls");
        switch (keyInput)
        {
        case 'a':
            if (x_axis <= 1)
            {
                printmap(char2_);
                printf("\n벽에 막혀 더이상 갈 수 없습니다.");
                break;
            }
            else
            {
                char2_[y_axis][x_axis] = '*';
                char2_[y_axis][--x_axis] = '0';
                printmap(char2_);
            }
            break;
        case 'd':
            if (x_axis < 4)
            {
                char2_[y_axis][x_axis] = '*';
                char2_[y_axis][++x_axis] = '0';

                printmap(char2_);
            }
            else
            {
                printmap(char2_);
                printf("\n벽에 막혀 더이상 갈 수 없습니다.");
            }

            break;


        case 'w':
            if (y_axis <= 1)
            {
                printmap(char2_);
                printf("\n벽에 막혀 더이상 갈 수 없습니다.");

                break;
            }
            else
            {
                char2_[y_axis][x_axis] = '*';
                char2_[--y_axis][x_axis] = '0';
                printmap(char2_);
            }
            break;



        case 's':
            if (y_axis < 4)
            {
                char2_[y_axis][x_axis] = '*';
                char2_[++y_axis][x_axis] = '0';

                printmap(char2_);
            }
            else
            {

                printmap(char2_);

                printf("\n벽에 막혀 더이상 갈 수 없습니다.");
            }
            break;

        default:
            printf("\n\n입력이 잘못되었습니다.\n");
        }
    }
}

void printmap(char char_[][6])
{
    for (int y = 0; y < 6; y++)
    {
        for (int x = 0; x < 6; x++)
        {
            printf("%c ", char_[y][x]);
        }
        printf("\n");
    }
}


void SwapArray(int* firstarray, int *secondarray)
{
    int temp = 0;
    temp = *secondarray;
    *secondarray = *firstarray;
    *firstarray = temp;
}

void Desc001()
{
    int numbers[10] = { 0, };

    for (int i = 0; i < 10; i++)
    {
        numbers[i] = (i + 1)*10;
    }



    for (int i = 0; i < 10; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    int* ptrNumber = &numbers[2];

    printf("3번째 자리에 있는 값 + 1 -> %d\n", *(ptrNumber - 1));
    printf("numbers가 들고 있는 값 -> %p\n", numbers);
    printf("numbers[0]의 주소 값 -> %p\n", &numbers[0]);

    printf("\n\n");

    printf("numbers 의 Size : %d \n", sizeof(numbers));

    ArrayFunc(numbers);
    ArrayFunc2(numbers, sizeof(numbers));
}

void ArrayFunc(int* ptrArray)
{
    printf("ptrArray 역참조 값 : %d \n", *(ptrArray));
    printf("ptrArray + 1 주소의 역참조 값 : %d \n", *(ptrArray + 1));

}

void ArrayFunc2(int array_[], int arraySize)
{
    printf("함수에서 찍어 본 numbers의 Size : %d \n", sizeof(array_));
    for (int i = 0; i < arraySize; i++)
    {

    }
}

//int array[5] = { 21, 59, 36, 99, 17 };
    //int min = 0;
    //int count = 0;

    //while (count < 5)
    //{
    //     

    //    //삽입정렬 완성
    //    for (int i = 0; i < 5; i++) // 21, 59, 36, 99 , 17
    //    {
    //        if (i <= count && array[count-i-1] > array[count-i])
    //        {
    //            SwapArray(&array[count-i-1], &array[count-i]);
    //        }
    //    }



    //    for (int i = 0; i < 5; i++)
    //    {
    //        printf("%d ", array[i]);
    //    }
    //    printf("\n\n");
    //    count += 1;
    //    
    //}

    //for (int i = 0; i < 5; i++)
    //{
    //    printf("%d ", array[i]);
    //}
    //printf("\n");
//혼종정렬
         /*for (int i = 0; i < 4-count; i++)
         {

             if (array[i] > array[i+1])
             {
                 SwapArray(&array[i], &array[i+1]);

             }
         }*/

         ////선택 정렬 스왑 반복문
          /* for (int i = 0+count; i < 5; i++)
         {
             if (array[i] < array[count])
             {
                 SwapArray(&array[i], &array[count]);

             }
         }*/

         ////제대로된 선택 정렬 (최솟값 탐색후 변경)
         //min = array[count];

         //for (int i = 0+count; i < 5; i++)
         //{
         //  if (array[i] < array[count])
         //  {
         //      min = array[i];
         //  }
         //}
         //for (int j = 0 + count; j < 5; j++)
         //{
         //    if (min == array[j])
         //    {
         //        SwapArray(&array[count], &array[j]);
         //    }
         //}

////main 함수에 넣으면 됨