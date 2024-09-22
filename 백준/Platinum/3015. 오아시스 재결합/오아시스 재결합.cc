#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<queue>

#define Fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

typedef long long ll;

int n;
int arr[500001];
int arr_result[500001];


void sol() {
	stack<int> s;
	s.push(0);

	for (int i = 1; i < n; i++) {
		int count = 0;
		int prevNumber = -1;
		while(!s.empty() && arr[s.top()] < arr[i]) {
			count++;
			if (prevNumber != -1 && prevNumber != arr[s.top()]) {
				arr_result[s.top()] += count;
				count = 1;
				prevNumber = arr[s.top()];
				s.pop();
				continue;
			}
			arr_result[s.top()] += count;
			prevNumber = arr[s.top()];
			s.pop();
		}
		
		if (!s.empty() && prevNumber != -1) {
			arr_result[s.top()] += count;
		}
		s.push(i);
	}

	int prevNumber = arr[s.top()];
	int count = 0;
	s.pop();
	while (!s.empty()) {
		count++;
		if (prevNumber != arr[s.top()])
		{
			arr_result[s.top()] += count;
			count = 0;
			prevNumber = arr[s.top()];
			s.pop();
			continue;
		}
			
		arr_result[s.top()] += count;
		prevNumber = arr[s.top()];
		s.pop();
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sol();

	ll result = 0;

	for (int i = 0; i < n; i++) {
		
		result += arr_result[i];
	}

	cout << result;
	return 0;
}