using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int k, int[] score) {
        int[] answer = new int[score.Length];
        List<int> temp = new List<int>();

        for (int i = 0; i < score.Length; i++)
        {
            temp.Add(score[i]);
            temp.Sort();
            if (i < k) answer[i] = temp[0];
            else answer[i] = temp[temp.Count - k];
        }
        return answer;
    }
}