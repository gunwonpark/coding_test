#include <bits/stdc++.h>
#include <unordered_set>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

typedef long long ll;

using namespace std;

int main() {
	FAST;

	char x; cin >> x;

	vector<vector<int>> group(5, vector<int>(4));

	for(int i = 1; i <= 20; i++){
		group[(i - 1) / 4][(i - 1) % 4] = i;
	}

	for (int i = 0; i < 15; i++) {
		int index = (i % 5);
		int index2 = (i + 1) % 5;

		if (index > index2) swap(index, index2);

		for (auto& num : group[index]) {
			cout << num << " ";
		}

		for (auto& num : group[index2]) {
			cout << num << " ";
		}

		cout << '\n';
	}
	 



	return 0;
}