using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
        public int solution(int[] elements)
    {
        int n = elements.Length;
        HashSet<int> sum = new HashSet<int>();
        int[,] dp = new int[n, n+ 1];
        for(int i = 0; i < n; i++)
        {
            dp[i, 1] = elements[i];
            sum.Add(elements[i]);
        }
        for(int i = 2; i <= n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                dp[j, i] = dp[j, i - 1] + elements[(i + j - 1) % n];
                sum.Add(dp[j, i]);
            }
        }

        return sum.Count;
    }
}