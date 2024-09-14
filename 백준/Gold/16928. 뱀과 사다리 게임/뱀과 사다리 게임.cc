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

vector<vector<int>> board(101);
vector<int> visited(101);
int n, m;

int sol() {
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));

	while (true) {
		int cur = q.front().first;
		int count = q.front().second;
		
		if(cur == 100)
			return count;

		q.pop();

		for (int i = 0; i < board[cur].size(); i++) {
			int next = board[cur][i];
			if (visited[next] == 1)
				continue;
			
			q.push(make_pair(next, count + 1));
			
			visited[next] = 1;
		}
	}

	return -1;
}

int main() {
    Fast;

    cin >> n >> m;

	//사다리 위치 지정
    for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		board[x].push_back(y);
	}

	//뱀 위치 지정
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		board[x].push_back(y);
	}

	//현재 위치에서 갈 수 있는 보드 위치 지정
	for (int i = 1; i < 101; i++) {
		if (board[i].size() == 0) {
			for (int j = 1; j <= 6; j++) {
				if (i + j <= 100)
				{
					if(board[i + j].size() != 0)
						board[i].push_back(board[i + j][0]);
					else
						board[i].push_back(i + j);
				}
					
			}
		}
	}

	cout << sol();

    return 0;
}