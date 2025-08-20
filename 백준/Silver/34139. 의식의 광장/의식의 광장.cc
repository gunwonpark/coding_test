#include<bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

struct Node
{
	int x, y, index;
	Node(int x, int y, int index) : x(x), y(y), index(index) {};
	Node() {};
};

int main()
{
	FAST;
	int h, n; cin >> h >> n;
	vector<Node> arr;

	for (int i = 0; i < n; i++)
	{
		int a, b; cin >> a >> b;
		arr.push_back({ a,b,i });
	}

	sort(arr.begin(), arr.end(), [](const Node& a, const Node& b) {
		return a.y < b.y;
		});

	cout << "YES\n";

	vector<int> answer;
	answer.resize(n);

	for (int i = 0; i < n; i++)
	{
		int index = arr[i].index;
		answer[index] = i + 1;
	}

	for (auto& ans : answer)
	{
		cout << ans << " ";
	}

	return 0;
}