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

char dp[100001];

int main() {
	Fast;
	ll n;
	cin >> n;

	int num;
	cin >> num;
	vector<int> keys(num);
	for(int i = 0; i < num; i++)
		cin >> keys[i];

	for(int i = 0; i < 100000; i++)
		dp[i] = 'C';

	for (int i = 1; i <= 100000; i++) {
		for (int j = 0; j < keys.size(); j++) {
			if (i - keys[j] > 0) {
				if (dp[i - keys[j]] == 'C') {
					dp[i] = 'S';
				}
			}
			else if (i - keys[j] == 0) {
				dp[i] = 'S';
			}
		}
	}
	
	if (n <= 10000) {
		int count = 0;
		for(int i = 1; i <= n; i++)
			if(dp[i] == 'C')
				count++;
		cout << count << endl;
	}
	else {
		int result = 0;
		for(int i = 1; i <= 10000; i++)
			if(dp[i] == 'C')
				result++;

		int cycle = 1;		
		for (int i = 2; i <= 3000; i++) {
			bool find_cycle = true;
			for (int j = 10001; j < 10001 + 3000; j++) {
				if (dp[j] != dp[i + j]) {
					find_cycle = false;
					break;
				}
			}
			if (find_cycle) {
				cycle = max(cycle, i);
			}
		}

		int count = 0;
		for (int i = 10001; i < 10001 + cycle; i++) {
			if (dp[i] == 'C')
				count++;
		}

		result += (n - 10000) / cycle * count;
		int left = (n - 10000) % cycle;

		for (int i = 10001; i < 10001 + left; i++) {
			if (dp[i] == 'C')
				result++;
		}

		cout << result << endl;
	}

	return 0;
	
}