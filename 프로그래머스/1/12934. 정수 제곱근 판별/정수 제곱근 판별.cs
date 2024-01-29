using System;
public class Solution {
    public long solution(long n) {
        long answer;
        double temp = Math.Sqrt(n);
        if(temp == (long)temp) return ((long)temp+1) * ((long)temp+1);        
        return -1;
    }
}