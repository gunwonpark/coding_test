using System;

public class Solution {
    public int solution(int number, int limit, int power)
        {
            int answer = 0;
            for (int i = 1; i <= number; i++)
            {
                int temp = CalcFactors(i);
                if(temp > limit)
                {
                    temp = power;
                }                
                answer += temp;
            }
            return answer;
        }
        public int CalcFactors(int number)
        {
            int temp = (int)Math.Sqrt(number);
            int tempAnswer = 0;
            
            for (int i = 1; i <= temp; i++)
            {
                if (number % i == 0) tempAnswer += 2;
                if(i * i == number) tempAnswer -= 1;
            }
            return tempAnswer;
        }
}