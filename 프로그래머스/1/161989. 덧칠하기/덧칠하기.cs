using System;

public class Solution {
    public int solution(int n, int m, int[] section) {
        int answer = 1;
        int temp = section[0];
        for (int i = 1; i < section.Length; i++)
        {
            if (section[i] >= temp + m)
            {
                temp = section[i];
                answer++;
            }
        }
        return answer;
    }
}