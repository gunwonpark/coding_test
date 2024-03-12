using System;
using System.Text;

public class Solution {
    public string solution(string X, string Y) {
        StringBuilder answer = new StringBuilder(10000);
        int[] x = new int[10];
        int[] y = new int[10];
        foreach (char c in X)
        {
            int number = int.Parse(c.ToString());
            x[number]++;
        }
        foreach (char c in Y)
        {
            int number = int.Parse(c.ToString());
            y[number]++;
        }
        for (int i = 9; i >= 0; i--)
        {
            int minValue = Math.Min(x[i], y[i]);
            if (answer.Length == 0 && i == 0 && minValue > 0)
            {
                answer.Append(0);
                break;
            }
            for (int j = 0; j < minValue; j++)
            {
                answer.Append(i.ToString());
            }
        }
        if (answer.Length == 0) answer.Append("-1");
        return answer.ToString();
    }
}