using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

public class Solution {
    public string solution(string s, string skip, int index) {
        List<char> strs = new List<char> { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t'
            ,'u','v','w','x','y','z'};
            foreach (char c in skip)
            {
                strs.Remove(c);
            }

            int length = strs.Count;

            StringBuilder temp = new StringBuilder(s.Length);

            foreach (char c in s)
            {
                int tempIndex = strs.IndexOf(c);
                tempIndex = (tempIndex + index) % length;
                temp.Append(strs[tempIndex]);
            }

            return temp.ToString();
    }
}