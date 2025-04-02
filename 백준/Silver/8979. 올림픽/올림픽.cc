#include <bits/stdc++.h>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;

struct Point {
	int index, g, s, b;
	Point() {}
	Point(int index, int g, int s, int b) : index(index), g(g), s(s), b(b) {}
};

int n, k;

vector<Point> arr;


int main() {
	FAST;
	cin >> n >> k;
	arr.resize(n);

	for (int i = 0; i < n; i++) cin >> arr[i].index >> arr[i].g >> arr[i].s >> arr[i].b;

	sort(arr.begin(), arr.end(), [](Point a, Point b) {
		if (a.g == b.g) {
			if (a.s == b.s) {
				return a.b > b.b;
			}
			return a.s > b.s;
		}
		return a.g > b.g;
		});
	

	int cnt = 1;
	for (int i = 0; i < n; i++) {
		if (arr[i].index == k) {
			cout << cnt;
			return 0;
		}
		if (i != n - 1 && 
			arr[i].g == arr[i + 1].g && arr[i].s == arr[i + 1].s && arr[i].b == arr[i + 1].b) continue;
		cnt = i + 2;
	}
	

    return 0;
}