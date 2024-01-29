using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[] solution(long n) {
        List<int> answer = new List<int>();
        while(n > 0){
            long temp = n % 10;
            answer.Add((int)temp);
            n /= 10;
        }
        return answer.ToArray();
    }
}