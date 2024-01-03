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
            for (int k = 0; k < length; k++)
            {
                // 가장 긴 부분수열 문제를 풀어보자
                int[] dpUp = new int[k + 1];
                Array.Fill(dpUp, 1);

                for (int i = 1; i < k + 1; i++)
                {
                    for (int j = 0; j < i; j++)
                    {
                        if (nums[i] > nums[j])
                            dpUp[i] = Math.Max(dpUp[i], dpUp[j] + 1);
                    }
                }

                // 반대 방향에서 확인하여 보자
                int[] dpDown = new int[length - k];
                Array.Fill(dpDown, 1);

                for (int i = length - k - 2; i >= 0; i--)
                {
                    for (int j = length - k - 1; j > i; j--)
                    {
                        if (nums[i + k] > nums[j + k])
                            dpDown[i] = Math.Max(dpDown[i], dpDown[j] + 1);
                    }
                }

                // Console.WriteLine($"{(dpUp.Length > 0 ? nums[k] : 0)} : {(dpUp.Length > 0 ? dpUp[k] : 0)} ||| {(dpDown.Length > 0 ? dpDown[0] : 0)}");
                maxCount = Math.Max(maxCount, (dpUp.Length > 0 ? dpUp[k] : 0) + (dpDown.Length > 0 ? dpDown[0] : 0) );
            }
            Console.WriteLine(maxCount - 1);
        }
    }
}