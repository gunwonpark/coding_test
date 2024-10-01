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

int work[10001] = { 0, };

int main() {
	Fast;

	int n;
	cin >> n;

	int result = 0;

	for (int i = 1; i <= n; i++) {
		int cost, pre_work;
		cin >> cost >> pre_work;
		work[i] = cost;

		for (int j = 0; j < pre_work; j++) {
			int pre;
			cin >> pre;
			work[i] = max(work[i], cost + work[pre]);
		}

		result = max(result, work[i]);
	}
	
	cout << result;
	return 0;
	
}