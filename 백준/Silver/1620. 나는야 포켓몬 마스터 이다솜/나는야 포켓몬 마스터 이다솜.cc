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
#include<unordered_map>

#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

typedef long long ll;

bool isInterger(string &str) {
	try {
		stoi(str);
	}
	catch (exception e) {
		return false;
	}

	return true;
}


int main() {
	Fast;
	int n, m;
	cin >> n >> m;

	unordered_map<string, int> um;
	vector<string> index(n);

	for(int i = 0; i < n; i++){
		string input;
		cin >> input;
		index[i] = input;
		um[input] = i + 1;
	}

	for (int i = 0; i < m; i++) {
		string input;
		cin >> input;

		if (isInterger(input)) {
			cout << index[stoi(input) - 1] << "\n";
		}
		else {
			cout << um[input] << "\n";
		}
	}
	return 0;
	
}