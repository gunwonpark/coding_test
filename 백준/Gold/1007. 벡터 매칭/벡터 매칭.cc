#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <cmath>

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;

using namespace std;

int T, N;
ll sum1, sum2 = 0;

vector<int> test;
double result;
vector<pair<int, int>> v;


void Combination(int n, int k, int count, int pre) {
	if (count == k) {
		result = min(result, sqrt(pow(sum1, 2) + pow(sum2, 2)));
		return;
	}

	for (int i = pre + 1; i < n; i++) {
		sum1 -= v[i].first * 2;
		sum2 -= v[i].second * 2;
		Combination(n, k, count + 1, i);
		sum1 += v[i].first * 2;
		sum2 += v[i].second * 2;
	}
}

void Solution() {
	v.resize(N);
	result = numeric_limits<double>::max();

	sum1 = 0;
	sum2 = 0;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v[i] = { a , b };
	}

	for (int i = 0; i < N; i++) {
		sum1 += v[i].first;
		sum2 += v[i].second;
	}

	Combination(N, N / 2, 0, -1);

	cout << fixed;
	cout.precision(8);
	cout << result << endl;
}

int main() {
	FAST;
	cin >> T;

	while (T--) {
		cin >> N;
		Solution();
	}

	return 0;
}


