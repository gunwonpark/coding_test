
using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int solution(int[] ingredient) {
        int answer = 0;

        Stack<int> stack = new Stack<int>();
        List<int> arr = new List<int>(){ 1, 3, 2, 1 };

        for (int i = 0; i < ingredient.Length; i++)
        {
            bool canMake = false;
            stack.Push(ingredient[i]);
            if(stack.Count >= arr.Count)
            {
                for (int j = 0; j < arr.Count; j++)
                {
                    if (stack.ElementAt(j) == arr[j])
                    {
                        canMake = true;
                    }
                    else
                    {
                        canMake = false;
                        break;
                    }
                }
            }
            if (canMake)
            {
                stack.Pop();
                stack.Pop();
                stack.Pop();
                stack.Pop();
                answer++;
            }
        }
        return answer;
    }
}