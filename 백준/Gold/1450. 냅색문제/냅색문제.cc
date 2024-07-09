#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

vector<int> arr;

void dfs(int start, int end, ll sum, vector<ll>& part) {
    if (start > end) {
		part.push_back(sum);
		return;
	}

	dfs(start + 1, end, sum + arr[start], part);
	dfs(start + 1, end, sum, part);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);    

    int n, s;
    cin >> n >> s;
    
    for (size_t i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    vector <ll> leftPart, rightPart;

    dfs(0, n / 2 - 1, 0, leftPart);
    dfs(n / 2, n - 1, 0, rightPart);

    sort(rightPart.begin(), rightPart.end());
    
    int res = 0;
    for (size_t i = 0; i < leftPart.size(); i++)
    {
        ll temp = s - leftPart[i];
        res += upper_bound(rightPart.begin(), rightPart.end(), temp) - rightPart.begin();
    }

    cout << res;

	return 0;
}




