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

int n, u, d;
ll u_count = 0, d_count = 0;
int A[300000];
int B[300000];
ll result = 0;
priority_queue<pair<int, int>> pq;

void Change(int i) {
	while (!pq.empty()) {
		int idx = pq.top().second;
		int count = -pq.top().first;

		if (count + 1 != i) return;

		pq.pop();

		result -= (count - idx) * u;
		result += (count - idx) * d;
		result -= A[idx];
		result += B[idx];

		u_count--;
		d_count++;
	}

	return;
}

void sol() {
	result = 0;

	if (A[0] < B[0]) {
		u_count++;
		result = A[0];
	}
	else if (A[0] > B[0]) {
		d_count++;
		result = B[0];
	}
	
	cout << result << endl;

	for (int i = 1; i < n; i++) {
		//f(i + 1)
		result += u_count * u + d_count * d;
		if (A[i] < B[i]) {
			u_count++;
			result += A[i];
		}
		else if (A[i] >= B[i]) {
			d_count++;
			result += B[i];
		}

		Change(i + 1);
		printf("%lld\n", result);
	}
}

int main() {
	Fast;

	scanf("%d %d %d", &n, &u, &d);

	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &B[i]);
	}

	// A[i] < B[i]인 경우에 대하여 저장한다
	// A[i] 에 u를 몇번 더하고 B[i]에 d를 몇번 더하면 관계가 역전되는지 인덱스와 그 값을 저장한다.
	d = -d;

	for (int i = 0; i < n; i++) {
		if (A[i] < B[i]) {
			int diff = B[i] - A[i];
			int rate = u + -d;
			int idx = i;

			int count = diff / rate + 1 + idx;
			if(diff % rate == 0) count--;

			// 즉 f(count + 1) 부터는 관계가 역전된다는 말이다
			pq.push({ -count, i });
		}
	}

	sol();

	return 0;
	
}