#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <cmath>
#include <string>
#include <map>

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;

using namespace std;


ll ModuleFactorial(ll n, ll module) {
	
	if (n == 0) return 1;
	if (n == 1) return 1;

	return (n * ModuleFactorial(n - 1, module)) % module;
}

ll FastPow(ll base, ll exp, ll module) {
	ll result = 1;
	while (exp > 0) {
		if ((exp & 1) == 1) {
			result = (result * base) % module;
		}
		base = (base * base) % module;
		exp >>= 1;
	}
	return result;
}

int main() {
	FAST;

	int n, k;
	cin >> n >> k;

	ll module = 1000000007;
	ll a = ModuleFactorial(n, module);
	ll b = ModuleFactorial(k, module);
	ll c = ModuleFactorial(n - k, module);

	ll temp = FastPow((b * c) % module, module - 2, module);

	ll result = (a * temp) % module;

	cout << result;
	return 0;
}


