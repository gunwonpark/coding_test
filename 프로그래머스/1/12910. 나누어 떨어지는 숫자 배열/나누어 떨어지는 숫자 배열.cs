using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] arr, int divisor) {
        List<int> answer = new List<int>();

        foreach (int num in arr)
        {
            if (num % divisor == 0) answer.Add(num);
        }
        if(answer.Count == 0) return new int[] {-1};
        answer.Sort();
        return answer.ToArray();
    }
}