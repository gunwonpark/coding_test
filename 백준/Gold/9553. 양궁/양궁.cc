#include <bits/stdc++.h>

#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

constexpr double PI = 3.1415926;

typedef long long ll;

using namespace std;

double calc(double x1, double y1, double x2, double y2) {
	double degree1 = atan2(y1, x1);
	double degree2 = atan2(y2, x2);

	double diff = degree2 - degree1;
	if (abs(diff) > PI) return 2 * PI - abs(diff);

	return abs(diff);
}

int main() {
	FAST;	
	int T{}; cin >> T;

	
	while (T--)
	{
		int n{};
		cin >> n;

		double exp{};

		for (int i = 0; i < n; i++) {
			double x1, y1, x2, y2;
			cin >> x1 >> y1>> x2 >> y2;

			exp += calc(x1, y1, x2, y2);
		}

		cout << fixed;
		cout.precision(5);

		cout << exp / (2 * PI) << '\n';
	}

	return 0;
}