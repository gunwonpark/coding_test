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
vector<int> smallDp;
vector<int> bigDp;
int mod = 1000000007;

int main() {
	FAST; 	
	cin >> n;
	smallDp.resize(1001, 0);
	bigDp.resize(1001, 0);

	smallDp[0] = 1;
	smallDp[1] = 2;
	smallDp[2] = 4;
	smallDp[3] = smallDp[2] + smallDp[1] + 1;

	for (int i = 4; i <= n; i++) {
		smallDp[i] = (smallDp[i] + smallDp[i - 1]) % mod;
		smallDp[i] = (smallDp[i] + smallDp[i - 2]) % mod;
		smallDp[i] = (smallDp[i] + smallDp[i - 3]) % mod;
	}

	bigDp[1] = 0;
	bigDp[2] = 1;
	bigDp[3] = 4;
	bigDp[4] = 10;
	for (int i = 5; i <= n; i++) {
		bigDp[i] = (bigDp[i] + bigDp[i - 1]) % mod;
		bigDp[i] = (bigDp[i] + bigDp[i - 2]) % mod;
		bigDp[i] = (bigDp[i] + smallDp[i - 3]) % mod;
		bigDp[i] = (bigDp[i] + smallDp[i - 4]) % mod;
		bigDp[i] = (bigDp[i] + bigDp[i - 2]) % mod;
		bigDp[i] = (bigDp[i] + smallDp[i - 4]) % mod;
		bigDp[i] = (bigDp[i] + bigDp[i - 3]) % mod;
		bigDp[i] = (bigDp[i] + bigDp[i - 3]) % mod;
		bigDp[i] = (bigDp[i] + bigDp[i - 3]) % mod;
	}

	cout << bigDp[n] << "\n";

	return 0;
}


