using System;


namespace MyApp // Note: actual namespace depends on the project name.
{
    
    internal class Program
    {
        static void Main(string[] args)
        {
                int length = int.Parse(Console.ReadLine());
            int[] nums = Console.ReadLine().Split(" ").Select(int.Parse).ToArray();

            int maxCount = 1;
            // 특정 포인트를 기준으로 최고의 길이를 찾아보자
            // 가장 긴 부분수열 문제를 풀어보자
            int[] dpUp = new int[length];
            Array.Fill(dpUp, 1);

            for (int i = 1; i < length; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (nums[i] > nums[j])
                        dpUp[i] = Math.Max(dpUp[i], dpUp[j] + 1);
                }
            }

            // 반대 방향에서 확인하여 보자
            int[] dpDown = new int[length];
            Array.Fill(dpDown, 1);

            for (int i = length - 2; i >= 0; i--)
            {
                for (int j = length - 1; j > i; j--)
                {
                    if (nums[i] > nums[j])
                        dpDown[i] = Math.Max(dpDown[i], dpDown[j] + 1);
                }
            }

            for (int i = 0; i < length; i++)
            {
                maxCount = Math.Max(maxCount, dpUp[i] + dpDown[i] - 1);
            }
        
        Console.WriteLine(maxCount);
        }
    }
}