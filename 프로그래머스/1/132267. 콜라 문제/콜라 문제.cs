using System;

public class Solution {
    public int solution(int a, int b, int n) {
        int answer = 0;
        int remain = n;
        int temp = (remain / a) * b;
        
        while(temp > 0){
            temp = (remain / a) * b;
            answer += temp;    
            remain = temp + (remain % a);
        }
        
        return answer;
    }
}