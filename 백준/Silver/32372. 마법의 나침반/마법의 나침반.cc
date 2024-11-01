#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<queue>

#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

typedef long long ll;

int n, m;

int main() {
	Fast;

	cin >> n >> m;

	vector<int> cant_x(n);
	vector<int> cant_y(n);
	

	while(m--){
		int x, y, dir;
		cin >> x >> y >> dir;

		--x;
		--y;
		
		if (dir == 1) {
			for (int i = 0; i < n; i++) {
				if (i == y) continue;
				cant_y[i] = true;
			}
			for (int i = n - 1; i >= x; i--) {
				cant_x[i] = true;
			}
		}
		else if (dir == 2) {
			for (int i = 0; i <= y; i++) {
				cant_y[i] = true;
			}
			for (int i = n - 1; i >= x; i--) {
				cant_x[i] = true;
			}
		}
		else if (dir == 3) {
			for (int i = 0; i <= y; i++) {
				cant_y[i] = true;
			}
			for (int i = 0; i < n; i++) {
				if (i == x) continue;
				cant_x[i] = true;
			}
		}
		else if (dir == 4) {
			for (int i = 0; i <= y; i++) {
				cant_y[i] = true;
			}
			for (int i = 0; i <= x; i++) {
				cant_x[i] = true;
			}
		}
		else if (dir == 5) {
			for (int i = 0; i < n; i++) {
				if (i == y) continue;
				cant_y[i] = true;
			}
			for (int i = 0; i <= x; i++) {
				cant_x[i] = true;
			}
		}
		else if (dir == 6) {
			for (int i = n - 1; i >= y; i--) {
				cant_y[i] = true;
			}
			for (int i = 0; i <= x; i++) {
				cant_x[i] = true;
			}
		}
		else if (dir == 7) {
			for (int i = n - 1; i >= y; i--) {
				cant_y[i] = true;
			}
			for (int i = 0; i < n; i++) {
				if (i == x) continue;
				cant_x[i] = true;
			}
		}
		else if (dir == 8) {
			for (int i = n - 1; i >= y; i--) {
				cant_y[i] = true;
			}
			for (int i = n-1; i >= x; i--) {
				cant_x[i] = true;
			}
		}
	}

	int x;
	int y;
	for (int i = 0; i < n; i++) {
		if (cant_y[i] == false) y = i;
		if (cant_x[i] == false) x = i;
	}

	cout << x + 1 << " " << y + 1;


	return 0;

}