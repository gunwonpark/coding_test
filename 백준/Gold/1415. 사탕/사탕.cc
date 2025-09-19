#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int n;
vector<ll> dp;
vector<bool> prime;
map<int, int> save;

void make_prime()
{
	prime[0] = prime[1] = false;
    for (int i = 2; i * i <= 500000; i++)
    {
        if (prime[i])
        {
            for(int j = i * i; j <= 500000; j += i)
				prime[j] = false;
        }
    }
}

int main() {
    FAST;

    cin >> n;
    dp.resize(500001, 0);
	prime.resize(500001, true);

    for (int i = 0; i < n; i++)
    {
		int a; cin >> a;
        save[a]++;
    }

    dp[0] = 1;

    for(auto& save_point : save)
    {
        vector<ll> prev_dp = dp;
        int node = save_point.first;
        int count = save_point.second;

        if (node == 0) continue;

        for (int i = node; i <= 500000; i++)
        {
            dp[i] += dp[i - node];
            if (i >= node + count * node)
            {
                dp[i] -= prev_dp[i - (count + 1) * node];
            }
        }
    }

	make_prime();

    ll ans = 0;
    ll zero_count = save[0];
    for (int i = 2; i <= 500000; i++)
    {
        if (prime[i] && dp[i])
            ans += dp[i];
	}

    if(zero_count != 0)
		ans *= (zero_count + 1);

    cout << ans;
    return 0;
}
