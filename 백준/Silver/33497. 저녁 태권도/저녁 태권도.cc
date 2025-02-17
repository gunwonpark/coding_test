#include <bits/stdc++.h>

#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

typedef long long ll;

using namespace std;


int main() {
	FAST;	

	int n, m; cin >> n >> m;

	vector<vector<char>> arr(m, vector<char>(n));

	int usedCount = 0;

	for (int i = 0; i < m; i++) {
		int morning, evening; cin >> morning >> evening;

		int total = morning + evening;

		if (total > n) {
			cout << "NO";
			return 0;
		}

		if (total < n && usedCount < n) {
			int canabsentCount = n - total;
			while (canabsentCount > 0) {
				arr[i][usedCount] = 'X';
				canabsentCount--;
				usedCount++;

				if (usedCount == n) {
					break;
				}
			}
		}

		int morningCount = morning;
		int index = 0;
		while (morningCount > 0) {
			if (arr[i][index] != 'X') {
				arr[i][index] = '+';
				morningCount--;
			}
			index++;
		}

		int eveningCount = evening;

		while (eveningCount > 0) {
			if (arr[i][index] != 'X') {
				arr[i][index] = '-';
				eveningCount--;
			}
			index++;
		}

		while (index < n) {
			if (arr[i][index] != 'X') {
				arr[i][index] = '+';
			}
			index++;
		}
	}

	if (usedCount < n) {
		cout << "NO";
		return 0;
	}

	cout << "YES" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[j][i];
		}
		cout << '\n';
	}


	return 0;
}