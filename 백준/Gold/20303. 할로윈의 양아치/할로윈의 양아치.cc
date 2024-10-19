#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cmath>
#include <unordered_map>

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long ll;

using namespace std;

vector<int> parent;
vector<pair<int, int>> Group;
vector<pair<int, int>> group;

int n, m, k;

int dp[3001][30001];

int find(int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return;

    if(a > b) swap(a, b);
	parent[b] = a;

    group[a].first += group[b].first;
	group[a].second += group[b].second;
	group[b] = {0, 0};
}

int main() {
    FAST;
    
    cin >> n >> m >> k;

    parent.resize(n + 1);
    group.resize(n + 1);

    // 부모 캔디 소지개수 초기화
    for (int i = 1; i <= n; i++) {
        int candy;
        cin >> candy;
		parent[i] = i;
        // 총 캔디의 개수 와 그룹 인원 
        group[i] = { candy, 1 };
	}

    //그룹 초기화
    for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
        merge(a, b);
	}

    //남은 그룹 확인
    for (int i = 1; i <= n; i++) {
		if (group[i].first == 0) continue;
		
        Group.push_back({ group[i].first , group[i].second});
	}

    sort(Group.begin(), Group.end(), [](pair<int, int>& a, pair<int, int>& b){
        if(a.second == b.second) return a.first > b.first;
        return a.second < b.second;
        });



    for (int i = 1; i <= Group.size(); i++) {
		int candy = Group[i - 1].first;
        int people = Group[i - 1].second;

        for (int j = 1; j <= k; j++) {
            if (people >= j) dp[j][i] = dp[j][i - 1];
            else dp[j][i] = max(dp[j][i - 1], dp[j - people][i - 1] + candy);
        }
	}
  
    cout << dp[k][Group.size()] << "\n";
    return 0;
}