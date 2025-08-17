#include<bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int n, m;
vector<int> arr;
vector<int> ans;

void travel(int count, vector<int>& ans)
{
    if (ans.size() == m)
    {
        for(int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
		return;
    }

    for (int i = count; i < n; i++)
    {
        ans.push_back(arr[i]);
        travel(i, ans);
        ans.pop_back();
    }
}
int main() {
    
    FAST;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
	}

	sort(arr.begin(), arr.end());
    
	travel(0, ans);
    

    return 0;
}
