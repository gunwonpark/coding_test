#include <bits/stdc++.h>

#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;

struct Trie {
	vector<Trie*> datas;
	bool isterminate;

	Trie() {
		datas.resize(10);
		isterminate = false;
	}
	~Trie() {
		for (int i = 0; i < 10; i++) {
			if (datas[i] != nullptr)
				delete datas[i];
		}
	}

	bool Travel(const char* str) {
		if (*str == '\0') {
			return true;
		}

		int index = *str - '0';

		if (datas[index] == nullptr) {
			return false;
		}

		if (datas[index]->isterminate) {
			return true;
		}

		return datas[index]->Travel(str + 1);
	}

	void set(const char* str) {
		if (*str == '\0') {
			isterminate = true;
			return;
		}
		int index = *str - '0';

		if (datas[index] == nullptr) {
			datas[index] = new Trie();
		}

		datas[index]->set(str + 1);
	}
};
int main() {
	FAST;	

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		Trie* root = new Trie();
		bool flag = false;
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			if (flag) continue;
			if (root->Travel(s.c_str())) {
				cout << "NO" << '\n';
				flag = true;
			}
			root->set(s.c_str());
		}

		if (!flag) {
			cout << "YES" << '\n';
		}

		delete root;
	}
	

	return 0;
}