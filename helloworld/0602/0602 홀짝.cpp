#include <iostream>


void oddeven(int num);

int main()
{  
    char quit = 0;

    printf("프로그램을 종료하기 위해선 q or Q 를 입력해주세요.\n\n"); // 시작전 안내문

    while (15651) 
    {
        int num ; //반복문 시작전 num을 -1로 초기화 (문자와 구별하기 위해)

        printf("홀짝을 구별할 숫자를 입력해주세요 -> "); //반복되는 안내문
        scanf_s("%d", &num);    //숫자일 경우 num에 저장
        scanf_s("%c", &quit);   //문자일 경우 위의 num에 저장되지않기때문에 %c로 문자를 다시받아온다.
        
        if (quit == 'q' || quit == 'Q') //받은 내용이 문자인지 숫자인지 구별하는 if문
        {
            quit = 'q';
        }
        else if (num < 0)
        {
            quit = 1;
        }
        else
        {
            quit = 0;
        }                               // if문 종료

        // 받은 내용이 문자,숫자,0,종료인지 구분하는 if문
        if (quit == 'q' || quit == 'Q')     // q,Q 입력시 break로 반복문 종료
        {
            printf("프로그램을 종료합니다.");  
            break;
        }
        else if (num == 0)                  // 0일경우 0이라고 출력 후 반복
        {
            printf("입력하신 숫자는 0입니다.\n\n");

        }
        else if (quit > 0)                  // 문자를 받았을경우 출력 후 반복
        {
            printf("입력하신 내용은 숫자가 아닙니다.\n\n");
        }
        else   // 0이 아닌 숫자일경우 홀짝구별함수 실행                             
        {
            oddeven(num);
            continue;
        }
    }

}

void oddeven (int num) // mod계산을 이용한 홀짝구별함수
{
    if (num % 2)
    {
        printf("입력하신 %d는 홀수입니다.\n\n", num);
    }
    else 
    {
        printf("입력하신 %d는 짝수입니다.\n\n",num);
    }
}

