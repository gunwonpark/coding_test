#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long ll;

using namespace std;

int main() {
    FAST;

    int c, n; cin >> c >> n;

    vector<pair<int, int>> arr(n);
    int min_list[1201];
	fill(min_list, min_list + 1201, 100000000);
	min_list[0] = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    for (int i = 0; i < n; i++)
    {
		int value = arr[i].first;
		int count = arr[i].second;

        for (int j = 0; j <= 1100; j++)
        {
            if(min_list[j] != 100000000) {
				min_list[j + count] = min(min_list[j + count], min_list[j] + value);
			}
        }
    }

    int answer = 100000000;

    for (int i = c; i < c + 100; i++)
    {
		answer = min(answer, min_list[i]);
    }

    cout << answer;
    
    return 0;
}