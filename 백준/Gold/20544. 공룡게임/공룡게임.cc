#define _CRT_SECURE_NO_WARNINGS

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


int n;
vector<ll> smallDp;
vector<ll> bigDp;
int mod = 1000000007;

int main() {
	FAST; 	
	cin >> n;
	smallDp.resize(1001, 0);
	bigDp.resize(1001, 0);

	smallDp[0] = 0;
	smallDp[1] = 2;
	smallDp[2] = 4;
	smallDp[3] = smallDp[2] + smallDp[1] + 1;

	for (int i = 4; i <= n; i++) {
		smallDp[i] = smallDp[i - 1] + smallDp[i - 2] + smallDp[i - 3];
		smallDp[i] %= mod;
	}

	bigDp[1] = 1;
	bigDp[2] = 1;
	bigDp[3] = 4;
	bigDp[4] = 10;
	for (int i = 5; i <= n; i++) {
		bigDp[i] = bigDp[i - 1] + bigDp[i - 2] + smallDp[i - 3] + smallDp[i - 4] + bigDp[i - 2] + smallDp[i - 4] + bigDp[i - 3] * 3;
		bigDp[i] %= mod;
	}

	if(n == 1)
		cout << 0 << "\n";
	else
		cout << bigDp[n] << "\n";

	return 0;
}


