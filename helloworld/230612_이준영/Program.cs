﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.Security.Cryptography;
using System.Collections;
using static System.Net.Mime.MediaTypeNames;

namespace _0609cs
{
    public class Cardgame
    {

        static void Main(string[] args)
        {
            Trumph();
        }


        static void Trumph()
        {
            int point = 100;
            int[] cards = new int[52];
            int[] cardnum = new int[52];
            string[] cardpatterns = { "♠", "◆", "♥", "♣" };
            int[] pickcards = new int[4];

            for (int i = 0; i < cardnum.Length; i++)
            {
                cardnum[i] = i;
            }   //카드 순서 적은 배열 선언

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
                    cards[i] = i % 13 + 1;
                }
            } // 카드 배열 내용 선언

            while (true)
            {

                if (point > 3000)
                {
                    Console.WriteLine("당신이 가진 포인트는 무려 {0}입니다!");
                    Console.WriteLine("축하합니다!! 게임에서 승리했습니다!!");
                    return;
                }
                else
                {


                    string strpoint;
                    int bettingpoint = 0;
                    Console.Clear();
                    Console.WriteLine("현재 가지고 있는 포인트 : {0}", point);

                    Random random = new Random();
                    int count = cardnum.Length;
                    while (count > 1)
                    {
                        int k = random.Next(count--);
                        int temp = cardnum[count];
                        cardnum[count] = cardnum[k];
                        cardnum[k] = temp;
                    }       // 카드 순서 배열 셔플






                    // 뽑은 2개의 카드 출력하는 부분
                    for (int i = 0; i < 3; i++)
                    {
                        if (i < 2)
                        {
                            Console.WriteLine("컴퓨터의 {0}번째 카드", i + 1);
                        }
                        else
                        {
                            Console.WriteLine("배팅할 금액을 입력해 주세요  ");
                            strpoint = Console.ReadLine();
                            bettingpoint = Int32.Parse(strpoint);
                            Console.WriteLine("\n나의 카드는?");
                        }

                        if (cards[cardnum[i]] < 15)
                        {
                            if (cardnum[i] < 13)
                            {
                                Console.Write("{0} / {1} \n", cardpatterns[0], cards[cardnum[i]]);
                            }
                            else if (cardnum[i] < 26)
                            {
                                Console.Write("{0} / {1} \n", cardpatterns[1], cards[cardnum[i]]);
                            }
                            else if (cardnum[i] < 39)
                            {
                                Console.Write("{0} / {1} \n", cardpatterns[2], cards[cardnum[i]]);
                            }
                            else
                            {
                                Console.Write("{0} / {1} \n", cardpatterns[3], cards[cardnum[i]]);
                            }
                        }
                        else
                        {
                            if (cardnum[i] < 13)
                            {
                                Console.Write("{0} / {1} \n", cardpatterns[0], (char)cards[cardnum[i]]);
                            }
                            else if (cardnum[i] < 26)
                            {
                                Console.Write("{0} / {1} \n", cardpatterns[1], (char)cards[cardnum[i]]);
                            }
                            else if (cardnum[i] < 39)
                            {
                                Console.Write("{0} / {1} \n", cardpatterns[2], (char)cards[cardnum[i]]);
                            }
                            else
                            {
                                Console.Write("{0} / {1} \n", cardpatterns[3], (char)cards[cardnum[i]]);
                            }
                        }
                        Console.WriteLine();
                    }




                    for (int i = 0; i < 3; i++)
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

                    int comcard1 = cards[cardnum[0]];
                    int comcard2 = cards[cardnum[1]];
                    int mycard = cards[cardnum[2]];



                    if ((comcard1 < mycard) && (comcard2 > mycard))
                    {
                        Console.WriteLine("승리하여 배팅한 포인트가 2배가 됩니다.");
                        point = point + bettingpoint * 2;
                    }
                    else
                    {
                        if ((point -= bettingpoint) > 0)
                        {
                            Console.WriteLine("패배하여 포인트가 배팅한만큼 깎입니다..");
                            //point = point - bettingpoint;
                        }
                        else
                        {
                            Console.WriteLine("패배하셨습니다..");
                            return;
                        }

                    }

                    Console.WriteLine("\n아무키나 입력하시면 다시 시작합니다.");
                    Console.ReadLine();
                }
            }


        }

    }
}