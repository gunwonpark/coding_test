using System;

public class Solution {
    public string solution(string[] cards1, string[] cards2, string[] goal) {
        string answer = "Yes";
        int left = 0;
        int right = 0;
        int i = 0;

        while (true)
        {
            if (i == goal.Length) break;
            if (left < cards1.Length && cards1[left] == goal[i])
            {
                left++;
                i++;
            }
            else if (right < cards2.Length && cards2[right] == goal[i])
            {
                right++;
                i++;
            }
            else
            {
                answer = "No";
                break;
            }
        }
        return answer;
    }
}