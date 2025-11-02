#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

// 체크 -> 내보내기 -> 들어오기

int main() {
    FAST;
	int n, m; cin >> n >> m;
    vector<pair<int, int>> arr;
    for (int i = 0; i < m; i++)
    {
		int t, p; cin >> t >> p;
		arr.push_back({ t, p });
    }

    stable_sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b)
        {
			return a.first < b.first;
        });
    
    queue<pair<int, int>> q;
    queue<int> wait;

    int time = 0;
    int order = 0;
    int lastOrder = 0;

    while (order < m || !wait.empty())
    {
        while (!q.empty() && (time - q.front().first) >= q.front().second)
        {
            q.pop();
        }

        if (order >= m)
        {
            if (q.empty())
            {
                lastOrder = 0;
            }

            while (!wait.empty() && lastOrder < n)
            {
                q.push({ time, wait.front() });;
                lastOrder++;
				wait.pop();
            }
            time++;
            continue;
        }

        if (q.empty())
        {
            lastOrder = 0;

            if (!wait.empty())
            {
                while (!wait.empty() && lastOrder < n)
                {
                    q.push({ time, wait.front() });;
                    lastOrder++;
					wait.pop();
                }
            }
        }

        if (arr[order].first > time)
        {
            time++;
            continue;
        }

        if (lastOrder < n)
        {
			q.push({ time, arr[order].second });
            lastOrder++;
			order++;
        }
        else
        {
			wait.push(arr[order].second);
            order++;
        }

    }
    
    cout << lastOrder << '\n';

    return 0;
}
