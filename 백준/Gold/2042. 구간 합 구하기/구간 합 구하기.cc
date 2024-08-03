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

int n, m, k;
vector<ll> arr;

struct Sub {
	vector<ll> sub;

	Sub(int _size) {
		sub.resize(_size * 4);
	}

	ll init(int left, int right, int idx) {
		if (left == right) return sub[idx] = arr[left];

		int mid = (left + right) / 2;

		ll leftValue = init(left, mid, idx * 2 + 1);
		ll rightValue = init(mid + 1, right, idx * 2 + 2);

		return sub[idx] = leftValue + rightValue;
	}

	ll query(int left, int right, int curLeft, int curRight, int idx) {
		if (right < curLeft || left > curRight) return 0;
		if (left <= curLeft && right >= curRight) return sub[idx];

		int mid = (curLeft + curRight) / 2;
		ll result = query(left, right, curLeft, mid, idx * 2 + 1) + query(left, right, mid + 1, curRight, idx * 2 + 2);

		return result;
	}

	void update(int idx, ll value, int curLeft, int curRight, int realIdx) {
		if (idx >= curLeft && idx <= curRight) {
			sub[realIdx] += value;
			int mid = (curLeft + curRight) / 2;
			if (curLeft != curRight) {
				update(idx, value, curLeft, mid, realIdx * 2 + 1);
				update(idx, value, mid + 1, curRight, realIdx * 2 + 2);
			}
		}
		return;
	}
};

int main() {
	FAST; 	

	cin >> n >> m >> k;
	arr.resize(n);
	
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	Sub sub(n);
	sub.init(0, n - 1, 0);

	for (int i = 0; i < m + k; ++i) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			// b번째 수를 c로 바꾸기
			ll diff = c - arr[b - 1];
			sub.update(b - 1, diff, 0, n - 1, 0);
			arr[b - 1] = c;
		}
		else {
			// b번째 수부터 c번째 수까지의 합 구하기
			cout << sub.query(b - 1, c - 1, 0, n - 1, 0) << "\n";
		}
	}

	return 0;
}


