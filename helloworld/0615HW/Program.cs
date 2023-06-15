using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace _0615HW
{
    public class Program
    {
        static void Main(string[] args)
        {
            CoinGame();
        }

        static void CoinGame()
        {
            
            int size = default;
            int point = 0; ;    // 돌3개로 깰때마다 올라감
            DateTime nowDate = DateTime.Today;
            Console.WriteLine("게임을 시작하기 전, 맵의 크기를 입력하여 주세요(5~15)");
            size = int.Parse(Console.ReadLine());

            while (!((size >= 5) && (size <= 15)))
            {
                Console.WriteLine("잘못된 값입니다. 다시 입력해주세요.");
                size = int.Parse(Console.ReadLine());
            }
            // 맵 사이즈 입력받는 부분
            reset:
            int x_axis = (size/2);
            int y_axis = (size/2);
            char[,] char2_ = new char[size, size];

            for (int y = 0; y < size; y++)
            {
                for (int x = 0; x < size; x++)
                {
                    if (x == (size/2) && y == (size/2))
                    {
                        char2_[size/2, size/2] = '&';
                        continue;
                    }
                    if ((x == 0 || y == 0)|| (x == (size-1) || y == (size-1)))
                    {
                        char2_[y, x] = '#';
                        continue;
                    }

                    char2_[y, x] = '*';
                }
            }

            // 기본 맵 생성하는 부분

            //출력 부분
            printmap(char2_, size, point);

            int coinCount = 0;
            int coinX = 0;
            int coinY = 0;
            Random random = new Random();
            int savesec = default;
            bool noStone = true;    //돌이 필드에 있는지 없는지 체크하는 변수

            
            while (point < 5)
            {
                
                string second = System.DateTime.Now.ToString("ss");
                int coinsec = int.Parse(second);
                Console.WriteLine("{0} ", coinsec);

                //if (savesec > (50+coinsec))
                //{
                //    savesec = default;
                //}

                //if (coinsec > savesec)
                //{
                //    do
                //    {
                //        coinX = random.Next(1, (size-2));
                //        coinY = random.Next(1, (size-2));
                //    }
                //    while ((y_axis == coinY) && (x_axis == coinX));
                //    char2_[coinY, coinX] = '@';

                //    savesec = 2+coinsec;
                //}

                bool stone = false;     //돌을 밀때 그 건너에 돌이있을때 체크하는 변수
                int stoneLocation = 0;
                ConsoleKeyInfo keyInput = Console.ReadKey(true); //키입력을 받고 확인하는 내용


                if (noStone)  //돌생성 부분
                {
                    for (int i = 0; i <3; i++)
                    {
                        do
                        {
                            coinX = random.Next(1, (size-2));
                            coinY = random.Next(1, (size-2));
                        }
                        while (((y_axis == coinY) && (x_axis == coinX)) || char2_[coinY,coinX] == '@');
                        char2_[coinY, coinX] = '@';
                    }
                    noStone = false;
                }

                switch (keyInput.Key)
                {
                    case ConsoleKey.R:
                        goto reset;
                    
                    case ConsoleKey.LeftArrow:
                        if (x_axis <= 1)
                        {
                            
                            Console.WriteLine("\n벽에 막혀 더이상 갈 수 없습니다.");
                            break;
                        }
                        else
                        {
                            if (x_axis > 1) // 이동 가능할 경우
                            {
                                if (char2_[y_axis, (x_axis-1)] == '@') // 돌을 만났을 경우
                                {
                                    for (int i = (x_axis-2); i >= 0; i--) //돌 앞쪽에 돌이 있는지 확인
                                    {
                                        if (char2_[y_axis, i] == '@')
                                        {
                                            stoneLocation = i;
                                            stone = true;
                                            break;
                                        }
                                    }
                                    if (char2_[y_axis,stoneLocation] == '@' && stone) //돌이 돌에 막혔을경우의 출력문
                                    {
                                        char2_[y_axis, (x_axis-1)] = '*';
                                        char2_[y_axis, stoneLocation+1] = '@';                                        
                                    }
                                    else  // 돌에 막히지 않았을 경우의 출력문
                                    {                                       
                                        char2_[y_axis, (x_axis-1)] = '*';
                                        char2_[y_axis, 1] = '@';
                                    }
                                }
                                else
                                {
                                    char2_[y_axis, x_axis] = '*';
                                    char2_[y_axis, --x_axis] = '&';
                                }
                            }
                            
                            
                        }
                        break;
                    case ConsoleKey.RightArrow:
                        if (x_axis < (size-2)) // 이동 가능한 경우
                        {
                            if (char2_[y_axis, (x_axis+1)] == '@') // 돌을 만났을 경우
                            {
                                for (int i = (x_axis+2); i < size-1; i++) //돌 앞쪽에 돌이 있는지 확인
                                {
                                    if (char2_[y_axis, i] == '@')
                                    {
                                        stoneLocation = i;
                                        stone = true;
                                        break;
                                    }
                                }   
                                if (char2_[y_axis, stoneLocation] == '@' && stone) //돌이 돌에 막혔을경우의 출력문
                                {
                                    char2_[y_axis, (x_axis+1)] = '*';
                                    char2_[y_axis, stoneLocation-1] = '@';
                                }
                                else  // 돌에 막히지 않았을 경우의 출력문
                                {
                                    char2_[y_axis, (x_axis+1)] = '*';
                                    char2_[y_axis, size-2] = '@';
                                }
                            }
                            else
                            {
                                char2_[y_axis, x_axis] = '*';
                                char2_[y_axis, ++x_axis] = '&';
                            }
                            
                        }
                        else
                        {
                            
                            Console.WriteLine("\n벽에 막혀 더이상 갈 수 없습니다.");
                        }

                        break;


                    case ConsoleKey.UpArrow:
                        if (y_axis <= 1)
                        {
                            
                            Console.WriteLine("\n벽에 막혀 더이상 갈 수 없습니다.");

                            break;
                        }
                        else
                        {                         
                            if (char2_[(y_axis-1), x_axis] == '@') // 돌을 만났을 경우
                            {
                                for (int i = (y_axis-2); i >= 0; i--) //돌 앞쪽에 돌이 있는지 확인
                                {
                                    if (char2_[i, x_axis] == '@')
                                    {
                                        stoneLocation = i;
                                        stone = true;
                                        break;
                                    }
                                }
                                if (char2_[stoneLocation, x_axis] == '@' && stone) //돌이 돌에 막혔을경우의 출력문
                                {
                                    char2_[(y_axis-1),x_axis] = '*';
                                    char2_[stoneLocation+1,x_axis] = '@';
                                }
                                else  // 돌에 막히지 않았을 경우의 출력문
                                {
                                    char2_[(y_axis-1), x_axis] = '*';
                                    char2_[1, x_axis] = '@';
                                }
                            }
                            else
                            {
                                char2_[y_axis, x_axis] = '*';
                                char2_[--y_axis, x_axis] = '&';
                            }
                           
                        }
                        break;



                    case ConsoleKey.DownArrow:
                        if (y_axis < (size-2))
                        {
                            if (char2_[(y_axis+1), x_axis] == '@') // 돌을 만났을 경우
                            {
                                for (int i = (y_axis+2); i <= (size-2); i++) //돌 앞쪽에 돌이 있는지 확인
                                {
                                    if (char2_[i, x_axis] == '@')
                                    {
                                        stoneLocation = i;
                                        stone = true;
                                        break;
                                    }
                                }
                                if (char2_[stoneLocation, x_axis] == '@' && stone) //돌이 돌에 막혔을경우의 출력문
                                {
                                    char2_[(y_axis + 1), x_axis] = '*';
                                    char2_[stoneLocation-1, x_axis] = '@';
                                }
                                else  // 돌에 막히지 않았을 경우의 출력문
                                {
                                    char2_[(y_axis+1), x_axis] = '*';
                                    char2_[(size-2), x_axis] = '@';
                                }
                            }
                            else
                            {
                                char2_[y_axis, x_axis] = '*';
                                char2_[++y_axis, x_axis] = '&';
                            }
                            
                        }
                        else
                        {
                            Console.WriteLine("\n벽에 막혀 더이상 갈 수 없습니다.");
                        }
                        break;

                    default:
                        
                        Console.WriteLine("\n\n입력이 잘못되었습니다.\n");
                        break;
                }

                //돌 3개가 완성됐을 경우
                for(int i = 0; i < size; i++)
                {
                    for(int j = 0; j < size; j++)
                    {
                        if (char2_[i, j] == '@' && char2_[i, j+1] == '@'&& char2_[i, j+2] == '@')
                        {
                            char2_[i, j] = '*';
                            char2_[i, j+1] = '*';
                            char2_[i, j+2] = '*';
                            point += 1;
                            noStone = true;
                        }
                        if (char2_[i, j] == '@' && char2_[i+1, j] == '@'&& char2_[i+2, j] == '@')
                        {
                            char2_[i, j] = '*';
                            char2_[i+1, j] = '*';
                            char2_[i+2, j] = '*';
                            point += 1;
                            noStone = true;
                        }

                    }
                }

                printmap(char2_, size, point);



                coinCount += 1;
            }
            Console.Clear();
            printmap(char2_, size, point);
            Console.WriteLine("\n\n{0}번의 움직임으로 점수 {1}만큼을 달성했습니다!\n\n", coinCount, point);
        }

        static void printmap(char[,] map, int size, int point)
        {
            Console.Clear();
            Console.WriteLine("현재 나의 점수 : {0}\n\n", point);
            for (int y = 0; y < size; y++)
            {
                for (int x = 0; x < size; x++)
                {
                    if (map[y, x] == '@')
                    {
                        Console.ForegroundColor = ConsoleColor.Red;
                        Console.Write("{0} ", map[y, x]);
                        Console.ResetColor();
                        continue;
                    }
                    if (map[y, x] == '&')
                    {
                        Console.ForegroundColor = ConsoleColor.Green;
                        Console.Write("{0} ", map[y, x]);
                        Console.ResetColor();
                        continue;
                    }
                    Console.Write("{0} ", map[y, x]);
                }
                Console.WriteLine();
            }
        }
    }
}
