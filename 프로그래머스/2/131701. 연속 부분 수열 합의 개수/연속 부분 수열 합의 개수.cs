using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
        public int solution(int[] elements)
{
    List<int> sums = new List<int>();
    // elements를 원형 수열이라 가정하고 연속적인 수의 합들을 구해본다
    for (int k = 1; k <= elements.Length; k++)
    {
        for (int i = 0; i < elements.Length; i++)
        {
            int sum = 0;
            for (int j = i; j < i + k; j++)
            {
                sum += elements[j % elements.Length];
            }
            sums.Add(sum);
        }
    }

    sums = sums.Distinct().ToList();
    
    return sums.Count;
}
    
}