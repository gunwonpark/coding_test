using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] array, int[,] commands) {
        List<int> answer = new List<int>();
        
        for (int index = 0; index < commands.GetLength(0); index++)
        {
            int i = commands[index, 0];
            int j = commands[index, 1];
            int k = commands[index, 2];

            
            List<int> temp = new List<int>();
            for (int iter = i-1; iter < j ; iter++)
            {
                temp.Add(array[iter]);
            }
            temp.Sort();
            answer.Add(temp[k-1]);
        }
        return answer.ToArray();

    }
}