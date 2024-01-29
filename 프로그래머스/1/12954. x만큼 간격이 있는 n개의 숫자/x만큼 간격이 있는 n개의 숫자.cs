using System.Collections.Generic;
using System.Linq;

public class Solution {
    public long[] solution(int x, int n) {
        List<long> answer = new List<long>();
        int addNumber = x;
        long number = x;
        for(int i = 0; i < n; i++){
            answer.Add(number);
            number += addNumber;
        }
        
        return answer.ToArray();
    }
}