using System;
using System.Linq;
public class Solution {
    public int[] solution(string s) {
        //이진 변환의 횟수와  제거한 0의 개수
            int[] answer = new int[2];

            while (true)
            {
                //1. 문자열에서 0을 제거한다
                int curLength = s.Length;
                int preLength = s.Where(x => x == '1').Count();
                answer[1] += curLength - preLength;
                //2. 문자열의 길이를 이진수로 변환한다
                string temp = "";
                do
                {
                    int remain = preLength % 2;
                    preLength /= 2;
                    temp += remain.ToString();
                    
                }while (preLength > 0);
                s = new string(temp.Reverse().ToArray());
                answer[0] += 1;
                //3. 값이 1이 아니면 다시 1.으로 돌아간다
                if (s == "1")
                    break;
            }

            return answer;
    }
}