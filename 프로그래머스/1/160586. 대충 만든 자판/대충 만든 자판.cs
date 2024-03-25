using System;


public class Solution {
    public int[] solution(string[] keymap, string[] targets) {
        int[] answer = new int[targets.GetLength(0)];

            for (int i = 0; i < targets.GetLength(0); i++)
            {
                for (int j = 0; j < targets[i].Length; j++)
                {
                    int temp = int.MaxValue;
                    foreach (string key in keymap)
                    {
                        int a = key.IndexOf(targets[i][j]);
                        if (a != -1)
                            temp = Math.Min(temp, a);
                    }
                    if (temp == int.MaxValue)
                    {
                        answer[i] = -1;
                        break;
                    }
                    answer[i] += temp + 1;
                }
            }

            return answer;
    }
}