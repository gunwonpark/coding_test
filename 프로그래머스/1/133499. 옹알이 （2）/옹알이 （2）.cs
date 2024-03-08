using System;

public class Solution {
    public int solution(string[] babbling) {
        int answer = 0;

        foreach(string str in babbling){
            bool temp = false;
            char pre =' ';
            for (int i = 0; i < str.Length; i++)
            {
                if (str[i] == 'a' && pre != 'a')
                {
                    pre = 'a';
                    if (i <= str.Length - 3 && str[++i] == 'y' && str[++i] == 'a')
                    {
                        temp = true;
                    }
                    else
                    {
                        temp = false;
                        break;
                    }
                }
                else if (str[i] == 'y' && pre != 'y')
                {
                    pre = 'y';
                    if (i <= str.Length - 2 && str[++i] == 'e')
                    {
                        temp = true;
                    }
                    else
                    {
                        temp = false;
                        break;
                    }
                }
                else if (str[i] == 'w' && pre != 'w')
                {
                    pre = 'w';
                    if (i <= str.Length - 3 && str[++i] == 'o' && str[++i] == 'o')
                    {
                        temp = true;
                    }
                    else
                    {
                        temp = false;
                        break;
                    }
                }
                else if (str[i] == 'm' && pre != 'm')
                {
                    pre = 'm';
                    if (i <= str.Length - 2 && str[++i] == 'a')
                    {
                        temp = true;
                    }
                    else
                    {
                        temp = false;
                        break;
                    }
                }
                else
                {
                    temp = false;
                    break;
                }
                
            }
            if (temp) answer++;
        }
        return answer;
    }
}