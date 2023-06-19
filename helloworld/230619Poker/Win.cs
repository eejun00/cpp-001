using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _230619Poker
{
    public class Win
    {
        public int pattern;
        public int number;

        public bool RoyalStFlush(int[] mycards, string[] mypatterns)
        {
            Array.Sort(mycards);    //카드 정렬
            for(int i = 0; i <mycards.Length-1; i++)
            {
                if (mypatterns[i] != mypatterns[i+1])
                {
                    return false;
                }
                else if (i < 3)
                {
                    continue;
                }
                else if(i == 4)
                {
                    for(int j = 1; j <mycards.Length-1; j++)
                    {
                        if(mycards[0] == 1)    //첫카드가 A
                        {
                            if (mycards[j] != j+9)   //두번째카드부터 +9(10,11,12,13)
                            {
                                return false;
                            }
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        }

        public bool StFlush(int[] mycards, string[] mypatterns)
        {
            Array.Sort(mycards);    //카드 정렬
            for (int i = 0; i <mycards.Length-1; i++)
            {
                if (mypatterns[i] != mypatterns[i+1])
                {
                    return false;
                }                
                
            }
            for(int i = 0;i <mycards.Length-1;i++)
            {
                if (mycards[0] == 1 && mycards[1] == 10 && mycards[2] == 11 && mycards[3] == 12 && mycards[4] == 13 ||
                    (mycards[0] == 1 && mycards[1] == 2 && mycards[2] == 11 && mycards[3] == 12 && mycards[4] == 13) ||
                    (mycards[0] == 1 && mycards[1] == 2 && mycards[2] == 3 && mycards[3] == 12 && mycards[4] == 13) ||
                    (mycards[0] == 1 && mycards[1] == 2 && mycards[2] == 3 && mycards[3] == 4 && mycards[4] == 13))
                {
                    return true;
                }
                else if (mycards[i] != mycards[i+1])
                {
                    return false;
                }
            }
            return true;
        }

        public bool FourCard(int[] mycards, string[] mypatterns)
        {
            Array.Sort(mycards);
            if (mycards[0] == mycards[3] || mycards[1] == mycards[4])
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public bool fullhouse(int[] mycards, string[] mypatterns)
        {
            Array.Sort(mycards);
            if ((mycards[0] == mycards[2] && mycards[3] == mycards[4]) || (mycards[0] == mycards[1] && mycards[2] == mycards[4]))
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public bool Flush(int[] mycards, string[] mypatterns)
        {
            Array.Sort(mycards);
            for (int i = 0; i <mycards.Length-1; i++)
            {
                if(mypatterns[i] != mypatterns[i+1])
                {
                    return false;
                }
                else
                {
                    continue;
                }
            }
            return true;
        }

        public bool Straight(int[] mycards, string[] mypatterns)
        {
            Array.Sort (mycards);
            for (int i = 0; i <mycards.Length-1; i++)
            {
                if (mycards[0] == 1 && mycards[1] == 10 && mycards[2] == 11 && mycards[3] == 12 && mycards[4] == 13 ||
                    (mycards[0] == 1 && mycards[1] == 2 && mycards[2] == 11 && mycards[3] == 12 && mycards[4] == 13) ||
                    (mycards[0] == 1 && mycards[1] == 2 && mycards[2] == 3 && mycards[3] == 12 && mycards[4] == 13) ||
                    (mycards[0] == 1 && mycards[1] == 2 && mycards[2] == 3 && mycards[3] == 4 && mycards[4] == 13))
                {
                    return true;
                }
                else if (mycards[i] != mycards[i+1])
                {
                    return false;
                }
            }
            return true;
        }

        public bool Triple(int[] mycards, string[] mypatterns)
        {
            Array.Sort(mycards);
            if (mycards[0] == mycards[2] || mycards[1] == mycards[3] || mycards[2] == mycards[4])
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public bool TwoPair(int[] mycards, string[] mypatterns)
        {
            Array.Sort(mycards);
            int count = 0;
            for(int i = 0; i < mycards.Length-1; i++)
            {
                if (mycards[i] ==  mycards[i+1])
                {
                    count += 1;
                    i += 1;                   
                }
            }
            if(count == 2)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public bool Pair(int[] mycards, string[] mypatterns)
        {
            Array.Sort(mycards);
            for (int i = 0; i < mycards.Length-1; i++)
            {
                if (mycards[i] ==  mycards[i+1])
                {
                    return true;
                }
            }
            return false;
        }

    }
}
