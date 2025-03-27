#include <bits/stdc++.h>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;

int w, n;
vector<int> arr;
bool sums[800001]{};

int main() {
    FAST;

    cin >> w >> n;
    arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

    for (int i = 2; i <= n - 2; i++) {
        for (int j = 0; j < i - 1; j++) {
            sums[arr[i - 1] + arr[j]] = true;
        }

        for (int j = i + 1; j < n; j++) {
            int value = w - arr[i] - arr[j];

            if (value <= 0) break;
            if (sums[value]) {
                cout << "YES";
                return 0;
            }
        }
    }

	cout << "NO";

    return 0;
}