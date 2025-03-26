#include <bits/stdc++.h>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;

map<int, int> counterX;
map<int, int> counterY;


struct point {
	int x, y;
	point(int x, int y) : x(x), y(y) {}
	point() : x(0), y(0) {}

	point operator +(const point& p) {
		return point(x + p.x, y + p.y);
	}
};

struct Count {
	int left, right;
	Count(int left, int right) : left(left), right(right) {}
	Count() : left(0), right(0) {}
};

Count arrX[2000001], arrY[2000001];

point command(char key) {
	switch (key) {
	case 'S':
		return point(0, 1);
	case 'J':
		return point(0, -1);
	case 'I':
		return point(1, 0);
	case 'Z':
		return point(-1, 0);
	}
}


int main() {
	FAST;
	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		counterX[x]++;
		counterY[y]++;
	}

	int left = 0, right = n;

	for (int i = 0; i < 2000001; i++) {
		// 존재하는 좌표인 경우
		if (counterX.find(i - 1000000) != counterX.end()) {
			int l = left;
			int r = right - counterX[i - 1000000];

			arrX[i] = Count(l, r);
			left = left + counterX[i - 1000000];
			right = r;
		}
		else {
			arrX[i] = Count(left, right);
		}
	}

	left = 0, right = n;

	for (int i = 0; i < 2000001; i++) {
		// 존재하는 좌표인 경우
		if (counterY.find(i - 1000000) != counterY.end()) {
			int l = left;
			int r = right - counterY[i - 1000000];

			arrY[i] = Count(l, r);
			left = left + counterY[i - 1000000];
			right = r;
		}
		else {
			arrY[i] = Count(left, right);
		}
	}

	ll answerX = 0;
	ll answerY = 0;

	//한번은 미리 계산해둬야 된다
	for (auto x : counterX) {
		answerX += (ll)x.second * (ll)abs(x.first);
	}

	for (auto y : counterY) {
		answerY += (ll)y.second * (ll)abs(y.first);
	}


	string keys; cin >> keys;

	point curPos = point(0, 0);

	for (int i = 0; i < m; i++) {
		char key = keys[i];
		point p = command(key);

		int nextX = curPos.x + p.x;
		int nextY = curPos.y + p.y;

		int leftX = arrX[clamp(nextX + 1000000, 0, 2000000)].left;
		int rightX = arrX[clamp(nextX + 1000000, 0, 2000000)].right;

		int leftY = arrY[clamp(nextY + 1000000, 0, 2000000)].left;
		int rightY = arrY[clamp(nextY + 1000000, 0, 2000000)].right;

		if (p.x != 0) {
			if (p.x < 0)
				answerX += (ll)(rightX - leftX);
			else
				answerX += (ll)(leftX - rightX);

			if (counterX.find(nextX) != counterX.end())
				answerX -= (ll)counterX[nextX];
		}

		if (p.y != 0) {
			if (p.y < 0)
				answerY += (ll)(rightY - leftY);
			else
				answerY += (ll)(leftY - rightY);

			if(counterY.find(nextY) != counterY.end())
				answerY -= (ll)counterY[nextY];
		}

		curPos.x = nextX;
		curPos.y = nextY;

		cout << answerX + answerY << "\n";
	}

	return 0;
}
