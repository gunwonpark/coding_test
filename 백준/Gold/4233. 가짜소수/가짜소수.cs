using System;

namespace 알고리즘테스트
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            while (true)
            {
                string[] t = Console.ReadLine().Split(" ");
                int p = int.Parse(t[0]);
                int a = int.Parse(t[1]);

                if (p == 0 && a == 0)
                {
                    break;
                }

                bool isPrime = CheckIsPrime(p);

                if (isPrime)
                {
                    Console.WriteLine("no");
                }
                else
                {
                    if (a == FastModuler(a, p, p))
                    {
                        Console.WriteLine("yes");
                    }
                    else
                    {
                        Console.WriteLine("no");
                    }
                }
            }

            return;
        }

        /// <summary>
        /// 빠르게 모듈러 연산을 수행하는 함수
        /// </summary>
        /// <param name="a"></param>
        /// <param name="exp"></param>
        /// <param name="module"></param>
        private static int FastModuler(long a, long exp, int module)
        {
            long result = 1;

            for (; exp > 0; exp >>= 1)
            {
                if ((exp & 1) == 1)
                {
                    result = (result * a) % module;
                }
                a = (a * a) % module;
            }

            return (int)result;
        }

        private static bool CheckIsPrime(int p)
        {
            int sqrt = (int)Math.Sqrt(p);

            for (int i = 2; i < sqrt; i++)
            {
                if (p % i == 0)
                {
                    return false;
                }
            }

            return true;
        }
    }
}

