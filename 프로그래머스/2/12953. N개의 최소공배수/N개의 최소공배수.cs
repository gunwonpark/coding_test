using System.Linq;

public class Solution {
    public int solution(int[] arr) {
        int answer = arr.Max();        
        while(true){
            bool IsSolved = true;
            for(int i = 0; i < arr.Length; i++){
                if(answer % arr[i] != 0){
                    IsSolved = false;
                    break;
                }
            }
            if(IsSolved)
                break;
            else
                answer++;
        }

        return answer;
    }
}