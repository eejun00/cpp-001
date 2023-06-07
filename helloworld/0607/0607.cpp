#include <iostream>
#include <time.h>
#include <windows.h>

void Description001();
void Description002();
void Description003();
void Description004();
void DescShuffle();
void ShuffleOnce(int* firstNumber, int* secondNumber);
void trumphcard();

void AlphabetScan();

using namespace std;


int main()
{
    trumphcard();

}

void Description001()
{
    char string_[15] = "Good morning!\n";
    char string2[] = "Good morning! \n";


    printf("%d\n", sizeof(string_));
    printf("문자열 배열 2번째 것의 크기 %d \n", sizeof(string2));
    printf("%s", string2);
}

void Description002()
{
    char str[300] = { 0, };
    printf("문자열을 입력하시오(200자 이내로) : ");
    std::cin >> str;

    printf("제대로 입력을 받았는지? -> %s", str);
}

void Description003()
{
    char str[10] = "Hello";
    char temp = '\0';

    temp = str[0];
    str[0] = str[4];
    str[4] = temp;

    printf("str의 0번째 값 : %c , str의 4번째 값 : %c \n", str[0], str[4]);

}

void Description004()
{
    //포인터 직접 쳐보기
    int number = 100;
    int* ptrNumber = &number;

    printf("number 변수의 주소는 : %p, 할당된 값은 : %d \n", &number, number);
    printf("ptrNumber 변수의 주소는 : %p, 할당된 값은 %p, 역참조한 값 : %d \n", &ptrNumber, ptrNumber, *ptrNumber);
}

void DescShuffle()
{
    int numbers[50] = { 0, };
    for (int i = 0; i < 45; i++)
    {
        numbers[i] = i + 1;
    }    //배열의 선언과 초기화

    //배열의 출력
    /*printf("셔플 하기 전 \n\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",numbers[i]);
    }
    printf("\n\n");*/


    const int shuffleCount = 500;
    int randomIdx1, randomIdx2 = 0;
    srand(time(NULL));

    for (int i = 0; i < shuffleCount; i++)
    {
        randomIdx1 = rand() % 45 ;
        randomIdx2 = rand() % 45 ;
        ShuffleOnce(&numbers[randomIdx1], &numbers[randomIdx2]);
    }
    //셔플 로직
    printf("\n");

    //배열의 출력
    printf("이번주의 로또 번호는? \n\n");
    for (int i = 0; i < 7; i++)
    {
        if (i < 6)
        {
            printf("%d ", numbers[i]);
            Sleep(500);
        }
        else
        {
            printf("\n보너스 %d", numbers[i]);
        }
    }
   



        
}

void trumphcard() //트럼프 카드 1장을 랜덤하게 뽑아서 출력하는 함수
{
    int cards[52] = { 0, };
    char cardpatterns[4][4] = {"♠","◆","♥","♣"};
    //char cardPatterns[4][4] = {'S','D','h','c'};

    int onecard = 0;

    for (int i = 0; i < 52; i++)
    {
        if ((i % 13) == 0) 
        {
            cards[i] = 'A';
        }
        else if ((i % 13) == 10)
        {
            cards[i] = 'J';
        }
        else if ((i % 13) == 11)
        {
            cards[i] = 'Q';
        }
        else if ((i % 13) == 12)
        {
            cards[i] = 'K';
        }
        else
        {
            cards[i] = i % 13 +1;
        }

    }    //배열의 선언과 초기화



    const int shuffleCount = 500;
    int randomIdx1, randomIdx2 = 0;
    srand(time(NULL));

    //for (int i = 0; i < shuffleCount; i++)
    //{
    //    randomIdx1 = rand() % 52;
    //    randomIdx2 = rand() % 52;
    //    ShuffleOnce(&cards[randomIdx1], &cards[randomIdx2]);
    //}
    ////셔플 로직
    printf("\n");

    //배열의 출력
    printf("52가지의 트럼프 카드중 1장을 뽑습니다. \n\n");
    
    onecard = rand() % 52 +1;
    
    
    
        if (cards[onecard] < 15)
        {
            if (onecard < 13)
            {
                printf("%s / %d ", cardpatterns[0], cards[onecard]);
            }
            else if (onecard < 26)
            {
                printf("%s / %d ", cardpatterns[1], cards[onecard]);
            }
            else if (onecard < 39)
            {
                printf("%s / %d ", cardpatterns[2], cards[onecard]);
            }
            else
            {
                printf("%s / %d ", cardpatterns[3], cards[onecard]);
            }
        }
        else
        {
            if (onecard < 13)
            {
                printf("%s / %c ", cardpatterns[0], cards[onecard]);
            }
            else if (onecard < 26)
            {
                printf("%s / %c ", cardpatterns[1], cards[onecard]);
            }
            else if (onecard < 39)
            {
                printf("%s / %c ", cardpatterns[2], cards[onecard]);
            }
            else
            {
                printf("%s / %c ", cardpatterns[3], cards[onecard]);
            }
        }
    

    /*for (int i = 0; i < 52; i++)
    {
        if (cards[i] < 15)
        {
            if (i < 13)
            {
                printf("%s / %d \n", cardpatterns[0], cards[i]);
            }
            else if (i < 26)
            {
                printf("%s / %d \n", cardpatterns[1], cards[i]);
            }
            else if (i < 39)
            {
                printf("%s / %d \n", cardpatterns[2], cards[i]);
            }
            else
            {
                printf("%s / %d \n", cardpatterns[3], cards[i]);
            }
        }
        else
        {
            if (i < 13)
            {
                printf("%s / %c \n", cardpatterns[0], cards[i]);
            }
            else if (i < 26)
            {
                printf("%s / %c \n", cardpatterns[1], cards[i]);
            }
            else if (i < 39)
            {
                printf("%s / %c \n", cardpatterns[2], cards[i]);
            }
            else
            {
                printf("%s / %c \n", cardpatterns[3], cards[i]);
            }
        }
    }*/
   




}

void ShuffleOnce(int* firstNumber, int* secondNumber)
{
    int temp = 0;
    temp = *firstNumber;
    *firstNumber = *secondNumber;
    *secondNumber = temp;
}


void AlphabetScan()
{
    char string[300] = { 0, };
    int count = 0;
    int reversecount = sizeof(string);
    int ex = 1;

    printf("문자열을 입력해주세요(200자 이내로) : ");
    std::cin >> string;

    while (count < 300)
    {
        if ((string[count] >= 65 && string[count] <= 90) || (string[count] >= 97 && string[count] <= 122))
        {
            if ((count+ex) % 2)
            {
                if (string[count] >= 97 && string[count] <= 122)
                {
                    string[count] = string[count] - 32;
                }
                else
                {
                    string[count] = string[count];
                }

            }
            else
            {
                if (string[count] >= 97 && string[count] <= 122)
                {
                    string[count] = string[count] - 32;
                }
                else
                {
                    string[count] = string[count];
                }
                if (string[count] >= 65 && string[count] <= 90)
                {
                    string[count] = string[count] + 32;
                }
                else
                {
                    string[count] = string[count];
                }
            }
        }
        else
        {
            ex += 1;
        }
        count += 1;
        
    }

    /*int reversecount = sizeof(string);
    printf("%d", reversecount);*/

  
    printf("\n바뀐 문자열을 출력합니다 -> %s\n", string);
    printf("바뀐 문자열을 거꾸로 출력합니다. ->  ");

    while (reversecount >= 0)
    {
        printf("%c", string[reversecount]);
        reversecount -= 1;
    }


}