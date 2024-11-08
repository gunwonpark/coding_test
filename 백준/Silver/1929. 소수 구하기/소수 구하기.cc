#include<bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

using namespace std;

typedef long long ll;

bool is_prime[1000001];

int main() {
    FAST;
  
    int n, m; cin >> n >> m;

    //에라스토체네스의 체 -> 미리 1000까지의 수를 계산해 둔다
    
    memset(is_prime, true, sizeof(is_prime));
    is_prime[1] = false;

    int sq = sqrt(1000000);
    for (int i = 2; i <= sq; i++) {
        if (is_prime[i] == false) continue;
        int iter = i;
        while (i * iter <= 1000000) {
            is_prime[i * iter++] = false;
        }
    }

    for(int i = n; i <= m; i++){
        if(is_prime[i]) cout << i << '\n';
    }

    

    return 0;
}