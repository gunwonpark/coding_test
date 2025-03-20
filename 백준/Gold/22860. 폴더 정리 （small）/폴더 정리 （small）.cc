#include <bits/stdc++.h>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;

class Tree {
public:
	Tree() {
		name = "";
		folders = map<string, Tree*>();
		files = map<string, int>();
	}

	string name;
	map<string, Tree*> folders;
	map<string, int> files;
};

map<string, Tree*> gFolders;

vector<string> split(string s, char delimiter) {
	vector<string> result;
	int curIndex = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == delimiter) {
			result.push_back(s.substr(curIndex, i - curIndex));
			curIndex = i + 1;
		}
	}
	result.push_back(s.substr(curIndex, s.size() - curIndex));
	return result;
}



// main부터 시작
Tree* dfs(Tree* root) {
	map<string, Tree*>& folders = root->folders;

	if (folders.size() == 0) {
		return root;
	}

	for (auto it = folders.begin(); it != folders.end(); it++) {
		string name = it->first;
		auto iter = gFolders.find(name);

		if (iter != gFolders.end()) {
			Tree* tree = iter->second;
			Tree* temp = dfs(tree);
			root->folders[name] = temp;
		}
	}

	return root;
}

Tree* find(Tree* root, vector<string>& path) {
	Tree* cur = root;

	for (int i = 1; i < path.size(); i++) {
		string name = path[i];
		auto it = cur->folders.find(name);
		cur = it->second;
	}

	return cur;
}

void findAndLink(Tree* root, Tree* target, vector<string>& path) {
	if (path.size() == 1) return;

	Tree* cur = root;
	Tree* prev = root;

	for (int i = 1; i < path.size(); i++) {
		string name = path[i];
		auto it = cur->folders.find(name);
		cur = it->second;
		if (i == path.size() - 2) {
			prev = cur;
		}
	}
	
	target->folders.insert(cur->folders.begin(), cur->folders.end());
	target->files.insert(cur->files.begin(), cur->files.end());

	if (prev != nullptr) {
		prev->folders.erase(path[path.size() - 1]);
	}

	delete cur;
}

map<string, pair<int, int>> gTreeInfo;

pair<set<string>, int> SetTreeInfo(Tree* root) {
	map<string, Tree*>& folders = root->folders;
	map<string, int>& files = root->files;
	set<string> s;
	int cnt = 0;
	for (auto it = folders.begin(); it != folders.end(); it++) {
		auto temp = SetTreeInfo(it->second);
		s.insert(temp.first.begin(), temp.first.end());
		cnt += temp.second;
	}
	for (auto it = files.begin(); it != files.end(); it++) {
		s.insert(it->first);
		cnt++;
	}
	gTreeInfo[root->name] = { s.size(), cnt};
	return { s, cnt };
}

int main() {
	FAST;
	int n, m; cin >> n >> m;
	cin.ignore();

	// 현재 존재하는 파일의 정보를 저장해 줍니다.
	for (int i = 0; i < n + m; i++) {

		string s; getline(cin, s);
		vector<string> tokens = split(s, ' ');

		string first = tokens[0];
		string second = tokens[1];
		string keyCode = tokens[2];

		auto it = gFolders.find(first);
		if (keyCode == "1") {
			//폴더입니다.
			if (it == gFolders.end()) {
				Tree* tree = new Tree();
				tree->name = first;
				tree->folders[second] = new Tree();
				gFolders[first] = tree;
			}
			else {
				Tree* tree = it->second;
				tree->folders[second] = new Tree();
			}
		}
		else {
			//파일입니다.
			if (it == gFolders.end()) {
				Tree* tree = new Tree();
				tree->name = first;
				tree->files[second] = 1;
				gFolders[first] = tree;
			}
			else {
				Tree* tree = it->second;
				tree->files[second] = 1;
			}
		}
	}
	
	// 파일을 Root가 main인 공간으로 저장해 줍니다.
	Tree* root = gFolders["main"];

	dfs(root);

	//// 폴더를 이동해 줍니다.
	//int k; cin >> k;
	//cin.ignore();
	//for (int i = 0; i < k; i++) {
	//	string s; getline(cin, s);
	//	vector<string> tokens = split(s, ' ');
	//	vector<string> path1 = split(tokens[0], '/');
	//	vector<string> path2 = split(tokens[1], '/');
	//	Tree* target = find(root, path2);

	//	// target폴더 아래에 해당 폴더들과 파일들을 넣어준다.
	//	findAndLink(root, target, path1);
	//}

	//파일의 개수를 찾아줍니다
	SetTreeInfo(root);

	int q; cin >> q;
	cin.ignore();
	for (int i = 0; i < q; i++) {
		string s; getline(cin, s);
		vector<string> path = split(s, '/');
		Tree* cur = find(root, path);
		int uniqueFile = gTreeInfo[cur->name].first;
		int totalFile = gTreeInfo[cur->name].second;
		
		cout << uniqueFile << " " << totalFile << "\n";
	}

	return 0;
}

