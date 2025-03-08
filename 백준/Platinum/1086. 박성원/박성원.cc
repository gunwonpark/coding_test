#include <bits/stdc++.h>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;

ll p, q;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll n, k, ansCount = 0;

// 0, 10, 100, 1000...을 k로 나눈 나머지를 미리 구해둔다.
ll remainders[751];
// dp[i][j] i는 사용한 집합의 위치를 체크해 주며 j는 나머지를 나타낸다. 
ll dp[1 << 15][100];
vector<string> numbers;
vector<ll> numberRemainders;

ll dfs(ll index, ll remainder, ll mul) {
	if (index == ((ll)1 << n) - 1) {
		if (remainder == 0) return 1;
		return 0;
	}

	if (dp[index][remainder] != -1) return dp[index][remainder];

	dp[index][remainder] = 0;

	for (int i = 0; i < n; i++) {
		if (index & ((ll)1 << i)) continue;
		ll nextRemainder = (numberRemainders[i] * remainders[mul] + remainder) % k;
		ll nextMul = mul + numbers[i].size();
		ll nextIndex = index | ((ll)1 << i);

		dp[index][remainder] += dfs(nextIndex, nextRemainder, nextMul);
	}

	return dp[index][remainder];
}

void calcRemainders() {
	remainders[0] = 1;
	for (int i = 1; i <= 751; i++) {
		remainders[i] = (remainders[i - 1] * 10) % k;
	}
}

void calcNumberRemainders() {
	for (int i = 0; i < n; i++) {
		ll numberRemainder = 0;
		ll numberSize = numbers[i].size();
		for (int j = numberSize - 1; j >= 0; j--) {
			numberRemainder = (numberRemainder + (numbers[i][j] - '0') * remainders[numberSize - 1 - j]) % k;
		}
		numberRemainders.push_back(numberRemainder);
	}
}

ll factorial(ll n) {
	return n == 1 ? 1 : n * factorial(n - 1);
}

int main() {
    FAST;

	cin >> n;
	numbers.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}

	cin >> k;

	fill(&dp[0][0], &dp[0][0] + ((ll)1 << 15) * 100, -1);

	calcRemainders();
	calcNumberRemainders();

	p = dfs(0, 0, 0);
	q = factorial(n);

	ll _gcd = gcd(p, q);
	p /= _gcd;
	q /= _gcd;

	cout << p << "/" << q << endl;
    return 0;
}

