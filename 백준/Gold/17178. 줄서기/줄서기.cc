#include <bits/stdc++.h>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;



int main() {
    FAST;

    int n; cin >> n;

    stack<int> s;
    vector<tuple<char,int, int>> arr(n * 5);
    vector<vector<int>> lines(n, vector<int>(5));
	vector<int> pos(n * 5);

    for (int i = 0; i < n * 5; i++) {
		string str; cin >> str;
		char c = str[0];
		int num = stoi(str.substr(2));

		get<0>(arr[i]) = c;
		get<1>(arr[i]) = num;
		get<2>(arr[i]) = i;
    }

	sort(arr.begin(), arr.end(), [](tuple<char, int, int> a, tuple<char, int, int> b) {
		if (get<0>(a) == get<0>(b)) return get<1>(a) < get<1>(b);
		return get<0>(a) < get<0>(b);
		});

    for (int i = 0; i < n * 5; i++) {
		int x = get<2>(arr[i]) / 5;
		int y = get<2>(arr[i]) % 5;

		lines[x][y] = i;
		pos[i] = x;
    }

    vector<queue<int>> q(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			q[i].push(lines[i][j]);
		}
	}

    int index = 0;

    while (index < n * 5) {
		int position = pos[index];

		if (position == -1) {
			if (!s.empty() && s.top() == index) {
				s.pop();
				index++;
			}
			else {
				cout << "BAD";
				return 0;
			}

			continue;
		}

		while (!q[position].empty() && q[position].front() != index) {
			s.push(q[position].front());
			pos[q[position].front()] = -1;
			q[position].pop();
		}

		q[position].pop();
		index++;
    }
   
	cout << "GOOD";

    return 0;
}