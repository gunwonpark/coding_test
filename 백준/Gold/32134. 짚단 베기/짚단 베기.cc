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
#include <set>

#define FAST ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
typedef long long ll;

using namespace std;

long long n, h, s;
vector<int> f;

double calc(double _h) {
	double gap = _h / n;
	double cur_h = gap;
	double cuml_size = 0;
	double result1 = 0;
	double result2 = 0;

	for (int i = 0; i < n; ++i) {
		double size = cur_h / 2 * (i + 1) - cuml_size;
		cur_h += gap;
		cuml_size += size;

		result1 += size * f[i];
	}

	cuml_size = 0;
	cur_h = gap;

	for (int i = n - 1; i >= 0; --i) {
		double size = cur_h / 2 * (n - i) - cuml_size;
		cur_h += gap;
		cuml_size += size;

		result2 += size * f[i];
	}

	return min(result1, result2);
}



int main() {
	FAST;

	cin >> n >> h >> s;
	f.resize(n);

	for (size_t i = 0; i < n; i++)
	{
		cin >> f[i];
	}

	if ((double)s / n * 2 <= h)
		cout << calc((double)s / n * 2);
	else {
		double height = (double)s / n;
		double _gap = h - height;

		double result = 0;


		for (int i = 0; i < n; ++i) {
			result += (h - (_gap * 2)) * f[i];
		}

		cout << calc(_gap * 2) + result;
	}
	return 0;
}
