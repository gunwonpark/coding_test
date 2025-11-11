#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int main() {
    FAST;
	
    int n; cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
		arr.push_back(x);
    }

    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j]) count++;
        }
    }

    if((count & 1) == 0) cout << "Yes\n";
	else cout << "No\n";

    return 0;
}
