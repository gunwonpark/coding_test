using System;

public class Solution {
    public int solution(int left, int right) {
        int answer = 0;
        int temp = 1;
        for(int i = 1; i < 32; i++){
            if(i * i >= left){
                temp = i;
                break;
            }
        }
        
        for(int i = left; i <= right; i++){
            if(i == temp * temp){
                answer -= i;
                temp++;
            }
            else answer += i;
        }
        return answer;
    }
}