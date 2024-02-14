using System;

public class Solution {
    public int solution(int n) {
        int answer = 0;
        string temp = "";
        while(n != 0)
        {
            temp += (n % 3).ToString();
            n /= 3;
        }
        for(int i = 0; i < temp.Length; i++){
            answer += int.Parse(temp[i].ToString()) * ((int)Math.Pow(3, temp.Length - 1 - i));
        }
        return answer;
    }
}