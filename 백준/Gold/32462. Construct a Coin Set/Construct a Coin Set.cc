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

int arr[100000001];

int main() {
	Fast;

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		
		if (n <= 5) {
			cout << -1 << '\n';
			continue;
		}

		if (n % 2 == 0) {
			cout << 3 << '\n';
			cout << 1 << " " <<  n / 2 << " " << n - 2 << '\n';
		}
		else {
			cout << 4 << '\n';
			cout << 1 << " " << 3 << " " << n - 3 << " " << n - 2 << '\n';
		}
	}
	

	return 0;
	
}