#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<deque>
#include<unordered_set>

#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

typedef long long ll;

int s;

void Add(int x) {
	s |= 1 << x;
}

void Remove(int x) {
	s &= ~(1 << x);
}

bool check(int x) {
	if (s & (1 << x)) {
		return true;
	}
	else {
		return false;
	}
}

void toggle(int x) {
	s ^= 1 << x;
}

void all() {
	s = (1 << 21) - 1;
}

void empty() {
	s = 0;
}

int main() {
	Fast;
	int n;
	cin >> n;

	string input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		
		if (input == "add") {
			int x;
			cin >> x;
			Add(x);
		}
		else if (input == "remove") {
			int x;
			cin >> x;
			Remove(x);
		}
		else if (input == "check") {
			int x;
			cin >> x;
			if (check(x)) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (input == "toggle") {
			int x;
			cin >> x;
			toggle(x);
		}
		else if (input == "all") {
			all();
		}
		else if (input == "empty") {
			empty();
		}
		
	}
	return 0;
	
}