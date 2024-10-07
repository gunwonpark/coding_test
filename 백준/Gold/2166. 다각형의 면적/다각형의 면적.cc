#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<deque>
#include<unordered_set>
#include<unordered_map>
#include<cmath>

#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

typedef long long ll;

int main() {
	Fast;
	int n;
	
	double prev_x, prev_y, last_x, last_y;
	cin >> n >> prev_x >> prev_y;

	last_x = prev_x;
	last_y = prev_y;

	double result = 0;

	for (int i = 0; i < n - 1; i++) {
		double cur_x, cur_y;
		cin >> cur_x >> cur_y;

		result += prev_x * cur_y - prev_y * cur_x;
		prev_x = cur_x;
		prev_y = cur_y;
	}

	result += prev_x * last_y - prev_y * last_x;

	result = abs(result) / 2;
	cout << fixed;
	cout.precision(1);
	cout << result << endl;
	return 0;
	
}