using System.Linq;

public class Solution {
    public int solution(int[] arr) {
        int answer = 1;
            int max = arr.Max();

            for (int i = 2; i <= max; i++)
            {
                if (!IsPrime(i))
                    continue;

                if (arr.Max() == 1)
                    break;

                
                while (true)
                {
                    bool tmp = false;
                    int j = 0;
                    foreach (var num in arr)
                    {
                        if (num % i == 0)
                        {
                            tmp = true;
                            arr[j] /= i;
                        }
                        j++;
                    }
                    if (tmp)
                        answer *= i;
                    else
                        break;
                }
               
                
            }
            return answer;
        }

        bool IsPrime(int num)
        {
            for (int i = 2; i < num; i++)
            {
                if (num % i == 0)
                    return false;
            }
            return true;
        }
}