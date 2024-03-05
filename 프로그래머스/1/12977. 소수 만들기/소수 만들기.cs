using System;

class Solution
{
    public int solution(int[] nums)
    {
        int answer = 0;
        int pickUpNumber = 3;
        
        int[] temp = new int[pickUpNumber];
        
        // 조합 계산
        int i = 0;
        while (i >= 0)
        {
            temp[i]++;
            if (temp[i] >= nums.Length + 1) i--;
            else if (i == pickUpNumber - 1)
            {
                int tempSum = 0;
                for (int j = 0; j < pickUpNumber; j++){
                    tempSum += nums[temp[j]-1];
                }
                
                // 합이 소수인지 확인
                for(int j = 2; j < tempSum; j++){
                    if(tempSum % j == 0){
                        tempSum = -1;
                        break;
                    } 
                }
                if(tempSum != -1) answer++;
            }
            else
            {
                i++;
                temp[i] = temp[i - 1];
            }
        }

        return answer;
    }   
}