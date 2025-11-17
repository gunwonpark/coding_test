#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int main() {
	FAST;

	int roomSize, elementCount; cin >> roomSize >> elementCount;

	vector<int> elements(elementCount);
	for(int i = 0; i < elementCount; i++) {
		cin >> elements[i];
	}

	sort(elements.begin(), elements.end());

	vector<int> roomVisited(roomSize);
	int nowVisited = 0;
	int result = 0;
	for(int i = 0 ; i < roomSize; i++) {
		cin >> roomVisited[i];
		if (roomVisited[i] == 0) nowVisited++;
	}

	result = nowVisited;

	stack<int> requireStack;
	int added = 0;
	
	for (int i = roomSize - 1; i >= 0; i--)
	{
		if (roomVisited[i] == 0)
		{
			nowVisited--;
		}
		else
		{
			int index = upper_bound(elements.begin(), elements.end(), nowVisited - 1) - elements.begin();
			if (index != elementCount)
			{
				int value = elements[index];
				requireStack.push(value - nowVisited);
			}
		}
	}

	while(!requireStack.empty())
	{
		int need = requireStack.top();
		requireStack.pop();

		if (need <= added)
		{
			result++;
			added++;
		}
	}

	cout << roomSize - result << "\n";
	return 0;
}
