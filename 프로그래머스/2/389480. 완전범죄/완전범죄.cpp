#include <string>
#include <vector>

using namespace std;

vector<vector<int>> info;
int dp[41][121][121]{};
int n, m;
int answer = -1;
int length;

void travel(int index, int a_left, int b_left)
{
    if(index == length)
    {
        if(answer == -1) answer = n - a_left;
        answer = min(answer, n - a_left);
        return;
    }
    
    if(dp[index][a_left][b_left]) return;
    
    dp[index][a_left][b_left] = 1;
    
    int a_value = info[index][0];
    int b_value = info[index][1];
    
    if(b_left - b_value > 0)
    {
        travel(index + 1, a_left, b_left - b_value);
    }
    
    if(a_left - a_value > 0)
    {
        travel(index + 1, a_left - a_value, b_left);
    }
}

int solution(vector<vector<int>> in, int a, int b) {
    info = in;
    n = a;
    m = b;
    length = info.size();
    
    travel(0, n , m);
    
    return answer;
}