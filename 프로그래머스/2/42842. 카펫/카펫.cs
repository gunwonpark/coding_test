using System;

public class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        int width = 0;
        int height = 0;
        int b = brown;
        int y = yellow;
        //x + y - 2 = brown / 2;
        //(x-2)(y-2) = yellow;
        
        width = ((2 + b / 2) + (int)Math.Sqrt(4 + (b * b) / 4 + 2 * b - 4 * b - 4 * y)) / 2;
        height = b / 2 + 2 - width;
        
        answer[0] = Math.Max(width, height);
        answer[1] = Math.Min(width, height);
        return answer;
    }
}