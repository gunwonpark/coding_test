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

int main() {
	FAST;

	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n + 1, vector<int>(n + 1, 1e9));

	int result = 0;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}
	
	for (int i = 1; i <= n; i++) {
		arr[i][i] = 1;
	}

	for(int k = 1; k <=n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);

	for (int i = 1; i <= n; i++) {
		bool flag = true;
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 1e9 && arr[j][i] == 1e9) {
				flag = false;
				break;
			}
		}
		if (flag) result++;
	}
	cout << result;

	return 0;
}


