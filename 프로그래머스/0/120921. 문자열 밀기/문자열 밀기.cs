using System;

public class Solution {
    public int solution(string A, string B)
{
    int answer = 0;
    int length = A.Length;
    for (int i = 0; i < length; i++)
    {
        if (A == B)
        {
            return answer;
        }
        char temp = A[length - 1];
        A = temp + A.Substring(0, length - 1);
        answer++;
    }
    return -1;
}
}