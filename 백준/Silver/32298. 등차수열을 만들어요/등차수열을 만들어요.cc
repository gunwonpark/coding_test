#include<bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

using namespace std;

typedef long long ll;

bool is_prime[2000001];

int main() {
    FAST;
  
    int n, adder; cin >> n >> adder;

    //에라스토체네스의 체 -> 미리 1000까지의 수를 계산해 둔다
    
    memset(is_prime, true, sizeof(is_prime));
    is_prime[1] = false;

    int sq = sqrt(2000000);
    for (int i = 2; i <= sq; i++) {
        if (is_prime[i] == false) continue;
        int iter = i;
        while (i * iter <= 2000000) {
            is_prime[i * iter++] = false;
        }
    }

    if ((adder & 1) == 0) {
        //짝수 일 경우 4 부터 시작해 값을 구해주면 된다
        for (int i = 0; i < n; i++) {
            cout << 4 + adder * i << " ";
        }
    }
    else {
        vector<int> result;
        // 홀수일 경우 소수가 아닌 것부터 시작해서 adder - 1까지 탐색해본다음 없으면 -1을 cout한다
        for (int i = 1; i < 2000000; i++) {
            result.clear();            
            for (int iter = 0; iter < n; iter++) {
                if (is_prime[i + adder * iter]) break;
                result.push_back(i + adder * iter);
            }
            if (result.size() == n) break;
        }

        if (result.size() == n) {
            for (int i = 0; i < n; i++) {
                cout << result[i] << " ";
            }
        }
        else {
            cout << -1;
        }
    }

    

    return 0;
}