using System;
using System.Linq;
using System.Collections.Generic;
public class Solution {
    public int[] solution(int[] answers) {
        List<int> answer = new List<int>();
        int[] correctAnswer = new int[]{0,0,0};
        int[][] wayToPickNumber = new int[][]{
            new int[] {1,2,3,4,5},
            new int[] {2,1,2,3,2,4,2,5},
            new int[] {3,3,1,1,2,2,4,4,5,5}
        };
        for (int i = 0; i < 3; i++)
        {
            int length = wayToPickNumber[i].Length;
            for (int j = 0; j < answers.Length; j++)
            {
                if (wayToPickNumber[i][j % length] == answers[j])
                    correctAnswer[i]++;
            }
        }

        int maxNumber = correctAnswer.Max();
        for (int i = 0; i < 3; i++)
        {
            if (correctAnswer[i] == maxNumber)
                answer.Add(i + 1);
        }
        return answer.ToArray();
    }
}