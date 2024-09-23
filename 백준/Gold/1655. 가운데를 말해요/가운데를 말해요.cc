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

int N;

int main() {
    Fast;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> g_pq;
	priority_queue<int, vector<int>, less<int>> l_pq;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		
		g_pq.push(a);

		if (i % 2 == 0) {
			int top = g_pq.top();
			g_pq.pop();
			l_pq.push(top);
			cout << l_pq.top() << "\n";
		}
		else {
			int gtop = g_pq.top();
			int ltop = l_pq.top();
			if (gtop < ltop) {
				g_pq.pop();
				l_pq.pop();
				g_pq.push(ltop);
				l_pq.push(gtop);
			}
			cout << l_pq.top() << "\n";
		}
	}
	return 0;
}