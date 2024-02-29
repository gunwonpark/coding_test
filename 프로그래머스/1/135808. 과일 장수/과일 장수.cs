using System;

public class Solution {
    public int solution(int k, int m, int[] score) {
        int answer = 0;
        Array.Sort(score);
        Array.Reverse(score);
        
        for (int i = m-1; i < score.Length; i += m)
        {
            answer += score[i] * m;
        }
        return answer;
    }
}