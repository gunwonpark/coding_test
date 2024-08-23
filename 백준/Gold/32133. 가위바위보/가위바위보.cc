#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <cmath>
#include <string>
#include <map>
#include <set>

#define FAST ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
typedef long long ll;

using namespace std;

const int MAX_V = 100; // 최대 정점 개수
const int INF = 987654321; // int 임시 최대값

struct node {
	int round;
	string ans;
	vector<string> friends;

	node(int _round, string _ans, vector<string> _friends) : round(_round), ans(_ans), friends(_friends) {}
};
int n, m, k;
vector<string> friends;
queue<node> s;
char keys[] = {'R', 'S', 'P'};

// false일때 상대방이 이겼다
bool comp(char key, char calc) {
	if (key == 'R') {
		if (calc == 'P') return false;
		else return true;
	}
	else if (key == 'S') {
		if (calc == 'R') return false;
		else return true;
	}
	else {
		if (calc == 'S') return false;
		else return true;
	}
}

void sol() {
	s.push(node(0, "", friends));
	int round = 0;
	vector<string> _friends = friends;
	string ans = "";
	while (!s.empty()) {
		round = s.front().round;
		_friends = s.front().friends;
		ans = s.front().ans;

		s.pop();

		if (round == m) {
			break;
		}

		if (_friends.size() == 0) continue;

		for (int i = 0; i < 3; ++i) {
			char key = keys[i];
			vector<string> temp;

			for (int j = 0; j < _friends.size(); j++) {
				if (comp(key, _friends[j][round]) == false) {
					temp.push_back(_friends[j]);
				}
			}

			if (1 <= temp.size() and temp.size() <= k) {
				cout << round + 1 << endl;
				cout << ans + key;
				return;
			}

			s.push({ round + 1, ans + key, temp});
		}
	}

	cout << -1;
	return;
}

int main() {
	FAST; 	

	cin >> n >> m >> k;

	
	string input;

	for (int i = 0; i < n; i++) {
		cin >> input;
		friends.push_back(input);
	}

	sol();

	return 0;
}


