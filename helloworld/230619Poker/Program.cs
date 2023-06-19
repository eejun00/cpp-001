using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Remoting.Lifetime;
using System.Text;
using System.Threading.Tasks;

namespace _230619Poker
{
    public class Program
    {
        static void Main(string[] args)
        {


            Poker();


        }

        static void Poker()
        {
            Win win1 = new Win();


            int[] cards = new int[52];
            int[] cardnum = new int[52];
            string[] cardpatterns = { "♠", "◆", "♥", "♣" };
            string[] mypatterns = new string[7];
            int[] mycards = new int[5];
            int[] comcards = new int[20];
            string[] compatterns = new string[20];
            int point = 500;

            int compareScore;

            for (int i = 0; i < 52; i++)
            {
                if ((i % 13 +1) == 1)
                {
                    cards[i] = 'A';
                }
                else if ((i % 13 + 1) == 11)
                {
                    cards[i] = 'J';
                }
                else if ((i % 13 + 1) == 12)
                {
                    cards[i] = 'Q';
                }
                else if ((i % 13 + 1) == 13)
                {
                    cards[i] = 'K';
                }
                else
                {
                    cards[i] = i % 13 + 1;
                }
            } // 카드 배열 내용 선언

            for (int i = 0; i < cardnum.Length; i++)
            {
                cardnum[i] = i;
            }   //카드 순서 적은 배열 선언


            while (true)
            {

                if (point > 3000)
                {
                    Console.WriteLine("당신이 가진 포인트는 무려 {0}입니다!", point);
                    Console.WriteLine("축하합니다!! 게임에서 승리했습니다!!");
                    return;
                }
                else
                {


                    string strpoint;
                    int bettingpoint = 0;
                    Console.Clear();
                    Console.WriteLine("현재 가지고 있는 포인트 : {0}\n", point);

                    Random random = new Random();
                    int count = cardnum.Length;
                    while (count > 1)
                    {
                        int k = random.Next(count--);
                        int temp = cardnum[count];
                        cardnum[count] = cardnum[k];
                        cardnum[k] = temp;
                    }       // 카드 순서 배열 셔플




                    int iredraw = default;
                    int th1, th2;;

                    // 나의 5개의 카드를 뽑고, 출력하는 부분
                    for (int i = 0; i < 5; i++)
                    {

                        Console.WriteLine("나의 {0}번째 카드", i + 1);

                        PrintCard(cards, cardpatterns,ref mypatterns, cardnum, i);
                        mycards[i] = cards[cardnum[i]];                        
                    }

                    // 컴퓨의 7개의 카드를 뽑고, 출력하는 부분
                    for (int i = 0; i < 7; i++)
                    {

                        Console.WriteLine("컴퓨터의 {0}번째 카드", i + 1);

                        PrintCard(cards, cardpatterns, ref compatterns, cardnum, i+7);
                        comcards[i+7] = cards[cardnum[i+7]];
                    }

                    Console.Write("배팅할 금액을 입력해 주세요  ");
                    strpoint = Console.ReadLine();
                    bettingpoint = Int32.Parse(strpoint);
                    Console.WriteLine("\n카드를 교체하시겠습니까?? (Y,N)");
                    string redraw = Console.ReadLine();

                    switch (redraw)
                    {
                        case "y":
                            Console.WriteLine("카드를 몇장 바꾸시겠습니까?");
                            redraw = Console.ReadLine();
                            iredraw = Int32.Parse(redraw);


                            for (int j = 0; j< iredraw; j++)
                            {
                                if (j == 0)
                                {
                                    Console.Write("몇번째 카드를 바꾸시겠습니까?");
                                    redraw = Console.ReadLine();
                                    th1 = Int32.Parse(redraw);
                                    mycards[th1-1] = default;
                                    Console.SetCursorPosition(0, th1*3-1);
                                    Console.WriteLine("바뀐 나의 {0}번째 카드", th1);
                                    PrintCard(cards, cardpatterns, ref mypatterns, cardnum, 5);
                                    mycards[th1-1] = cards[cardnum[5]];
                                    Console.SetCursorPosition(0, 23);
                                }
                                else
                                {
                                    Console.Write("이번엔 몇번째 카드를 바꾸시겠습니까?");
                                    redraw = Console.ReadLine();
                                    th2 = Int32.Parse(redraw);
                                    mycards[th2-1] = default;
                                    Console.SetCursorPosition(0, th2*3-1);
                                    Console.WriteLine("바뀐 나의 {0}번째 카드", th2);
                                    PrintCard(cards, cardpatterns, ref mypatterns, cardnum, 6);
                                    mycards[th2-1] = cards[cardnum[6]];
                                    Console.SetCursorPosition(0, 25);
                                }
                            }

                            break;
                        default:
                            break;
                    }

                    

                    // 문양 숫자로 변환
                    for (int i = 0; i < 14; i++)
                    {
                        if (cards[cardnum[i]] == 65)
                        {
                            cards[cardnum[i]] = 1;
                        }
                        else if (cards[cardnum[i]] == 74)
                        {
                            cards[cardnum[i]] = 11;
                        }
                        else if (cards[cardnum[i]] == 75)
                        {
                            cards[cardnum[i]] = 13;
                        }
                        else if (cards[cardnum[i]] == 81)
                        {
                            cards[cardnum[i]] = 12;
                        }
                    }
                    
                    if(win1.RoyalStFlush(mycards,mypatterns))
                    {
                        compareScore = 10;
                    }
                    else if(win1.StFlush(mycards, mypatterns))
                    {
                        compareScore = 9;
                    }
                    else if(win1.FourCard(mycards, mypatterns))
                    {
                        compareScore = 8;
                    }
                    else if(win1.fullhouse(mycards,mypatterns))
                    {
                        compareScore = 7;
                    }
                    else if(win1.Flush(mycards, mypatterns))
                    {
                        compareScore = 6;
                    }
                    else if(win1.Straight(mycards, mypatterns))
                    {
                        compareScore = 5;
                    }
                    else if(win1.Triple(mycards, mypatterns))
                    {
                        compareScore = 4;
                    }
                    else if(win1.TwoPair(mycards, mypatterns))
                    {
                        compareScore = 3;
                    }
                    else if(win1.Pair(mycards, mypatterns))
                    {
                        compareScore = 2;
                    }
                    else
                    {
                        compareScore = 1;
                    }















                        ConsoleKeyInfo keyInput;

                    Console.WriteLine("\n아무키나 입력하시면 다시 시작합니다. Q를 입력할시, 게임을 종료합니다.");
                    keyInput = Console.ReadKey();

                    switch (keyInput.Key)
                    {
                        case ConsoleKey.Q:
                            return;
                        default:
                            break;
                    }


                }
            }
        }

        static void PrintCard(int[] cards, string[] cardpatterns, ref string[] mypatterns, int[] cardnum, int i)
        {
            if (cards[cardnum[i]] < 15)
            {
                if (cardnum[i] < 13)
                {
                    Console.Write("{0} / {1} \n", cardpatterns[0], cards[cardnum[i]]);
                    mypatterns[i] = cardpatterns[0];
                }
                else if (cardnum[i] < 26)
                {
                    Console.Write("{0} / {1} \n", cardpatterns[1], cards[cardnum[i]]);
                    mypatterns[i] = cardpatterns[1];
                }
                else if (cardnum[i] < 39)
                {
                    Console.Write("{0} / {1} \n", cardpatterns[2], cards[cardnum[i]]);
                    mypatterns[i] = cardpatterns[2];
                }
                else
                {
                    Console.Write("{0} / {1} \n", cardpatterns[3], cards[cardnum[i]]);
                    mypatterns[i] = cardpatterns[3];
                }
            }
            else
            {
                if (cardnum[i] < 13)
                {
                    Console.Write("{0} / {1} \n", cardpatterns[0], (char)cards[cardnum[i]]);
                    mypatterns[i] = cardpatterns[0];
                }
                else if (cardnum[i] < 26)
                {
                    Console.Write("{0} / {1} \n", cardpatterns[1], (char)cards[cardnum[i]]);
                    mypatterns[i] = cardpatterns[1];
                }
                else if (cardnum[i] < 39)
                {
                    Console.Write("{0} / {1} \n", cardpatterns[2], (char)cards[cardnum[i]]);
                    mypatterns[i] = cardpatterns[2];
                }
                else
                {
                    Console.Write("{0} / {1} \n", cardpatterns[3], (char)cards[cardnum[i]]);
                    mypatterns[i] = cardpatterns[3];
                }
            }
            Console.WriteLine();
        }
    }
}
