using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int solution(string s) {
        string answer = "";
                Dictionary<int, string> number = new Dictionary<int, string>()
                {
                    {0, "zero"},
                    {1, "one"},
                    {2, "two"},
                    {3, "three"},
                    {4, "four"},
                    {5, "five"},
                    {6, "six"},
                    {7, "seven"},
                    {8, "eight"},
                    {9, "nine"}
                };

                string temp = "";

                for (int i = 0; i < s.Length; i++)
                {
                    if (s[i] >= 48 && s[i] <= 57)
                    {
                        answer += s[i];
                    }
                    else
                    {
                        temp += s[i];
                        for (int j = 0; j <= 9; j++)
                        {
                            if(number[j] == temp)
                            {
                                temp = "";
                                answer += j.ToString();
                            }
                        }
                    }
                }

                return int.Parse(answer);
    }
}