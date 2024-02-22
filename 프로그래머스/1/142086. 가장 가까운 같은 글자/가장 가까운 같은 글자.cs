using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(string s) {
        List<int> answer = new List<int>();
        Dictionary<char, int> dic = new Dictionary<char, int>();
        int iter = 0;
        foreach (char c in s)
        {
            if (dic.ContainsKey(c))
            {
                answer.Add(iter - dic[c]);
                dic[c] = iter;
            }
            else
            {
                dic[c] = iter;
                answer.Add(-1);
            }
            iter++;
        }
        return answer.ToArray();
    }
}