using System;

public class Solution {
    public double solution(int[] numbers) {
        double answer = 0;
        
        foreach(int number in numbers){
            answer += number;
        }
        answer /= numbers.Length;
        return answer;
    }
}