public class Solution {
    public bool solution(int x) {
        bool answer = true;
        int originNumber = x;
        int tempNumber = 0;

        while (x > 0) {
            tempNumber += x % 10; 
            x = x / 10;           
        }

        if (originNumber % tempNumber == 0) {
            answer = true;
        } else {
            answer = false;
        }

        return answer;
    }
}