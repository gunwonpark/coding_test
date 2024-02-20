using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] array, int[,] commands) {
        List<int> answer = new List<int>();
        List<int> temp = new List<int>(array);
        
        for (int index = 0; index < commands.GetLength(0); index++)
        {
            int i = commands[index, 0];
            int j = commands[index, 1];
            int k = commands[index, 2];

            
            List<int> newTemp = temp.Where((x, idx) => idx >= i - 1 && idx < j).OrderBy(x => x).ToList();
            answer.Add(newTemp[k - 1]);
        }
        return answer.ToArray();

    }
}