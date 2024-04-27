using System;

public class Solution {
     public int solution(int[] numbers, int target)
        {
            int answer = 0;

            for(int i = 0; i < Math.Pow(2,numbers.Length); i++)
            {
                int sum = 0;
                int temp = i;

                for (int j = 0; j < numbers.Length; j++)
                {
                    if(temp % 2 == 1)
                    {
                        sum -= numbers[j];
                    }
                    else
                    {
                        sum += numbers[j];
                    }
                    temp /= 2;
                }

                if(sum == target)
                {
                    answer++;
                }
            }

            return answer;
        }
}