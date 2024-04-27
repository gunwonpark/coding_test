using System;

public class Solution {
   public int solution(int n, int k)
{
    int answer = 0;

    string kNumber = "";
    while (n > 0)
    {
        kNumber = (n % k).ToString() + kNumber;
        n /= k;
    }

    string[] kNumberArray = kNumber.Split('0');
    foreach (string number in kNumberArray)
    {
        if (number == "") continue;
        if (number == "1") continue;
        if (IsPrime(long.Parse(number), k))
        {
            answer++;
        }
    }
    
    return answer;
}
    public bool IsPrime(long number, int k)
    {
        for (int i = 2; i <= Math.Sqrt(number); i++)
        {
            if (number % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}