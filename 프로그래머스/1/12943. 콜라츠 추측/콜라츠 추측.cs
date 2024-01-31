public class Solution {
    public int solution(int num) {
        long temp = num;
        for(int i = 0; i <= 500; i++){
            if(temp == 1) return i;
            if(temp % 2 == 0) temp /= 2;
            else temp = temp * 3 + 1;
        }
        return -1;
    }
}