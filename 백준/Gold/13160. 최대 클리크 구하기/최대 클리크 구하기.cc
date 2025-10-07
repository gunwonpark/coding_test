#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;



int main() {
    FAST;
    int n; cin >> n;

	vector<pair<int, int>> arr(n);
	vector<pair<int, int>> original(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
		original[i] = arr[i];
	}

	sort(arr.begin(), arr.end());

	priority_queue<int, vector<int>, greater<int>> pq;

	int maxPoint = -1;
	int maxCount = 0;

	for (int i = 0; i < n; i++) {
		int start = arr[i].first;
		int end = arr[i].second;

		while(!pq.empty() && pq.top() < start) {
			pq.pop();
		}

		pq.push(end);

		if(pq.size() > maxCount) {
			maxCount = pq.size();
			maxPoint = start;
		}
	}

	cout << maxCount << '\n';

	for (int i = 0; i < n; i++)
	{
		int start = original[i].first;
		int end = original[i].second;
		if(start <= maxPoint && maxPoint <= end) {
			cout << i + 1 << ' ';
		}
	}

    return 0;
}
