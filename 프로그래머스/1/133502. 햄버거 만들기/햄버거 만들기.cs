
using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int solution(int[] ingredient) {
        int answer = 0;
        int[] aa = {1,3,2,1};
        Stack<int> temp = new Stack<int>();               
           for(int i=0; i < ingredient.Length; i++)
           {
                bool result = false;
                temp.Push(ingredient[i]);
                for(int j=0; j < aa.Length; j++)
                {                    
                    if(temp.Count >= aa.Length)
                    {
                        if(temp.ElementAt(j) == aa[j])
                        {
                            result = true;
                        }
                        else
                        {
                            result = false;
                            break;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                if(result)
                {
                    temp.Pop();
                    temp.Pop();
                    temp.Pop();
                    temp.Pop();
                    answer++;
                }
           }
        return answer;
    }
}