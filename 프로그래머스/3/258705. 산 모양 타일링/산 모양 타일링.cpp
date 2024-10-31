#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> tops) {
    int answer = 0;
    vector<int> dp(2 * n + 2);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i < dp.size(); i++){
        //짝수번째 이면서 위에 삼각형이 있는경우
        if((i & 1) == 0 && tops[i / 2 - 1] == 1){
            dp[i] = 2 * dp[i - 1] + dp[i - 2];    
        }
        else{
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
    
        dp[i] %= 10007;
    }
    
    answer = dp.back();
    return answer;
}