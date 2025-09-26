#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int n, p, k;
ll answer = 0;

int main() {
    FAST;

    vector<pair<int, int>> lines;
    vector<queue<int>> q(6);

    cin >> n >> p >> k;

    for (int i = 0; i < n; i++)
    {
        int t, numl; cin >> t >> numl;
		lines.push_back({ t, numl });
    }

    int iter = 0;
	sort(lines.begin(), lines.end());

	int start = lines[0].first;
    start = (start / p) * p;

    for (int i = start; i <= p * 1000500; i += p)
    {
        int remain = k;

        while (iter != n && lines[iter].first <= i)
        {
			q[lines[iter].second].push(lines[iter].first);
            iter++;
        }

        while (remain > 0)
        {
            int min_size = 1e9;
            int index = -1;
            bool find = false;

            for (int j = 1; j <= remain; j++)
            {
                if (!q[j].empty() && q[j].front() < min_size)
                {
                    index = j;
					min_size = q[j].front();
                    find = true;
				}
            }

            if (!find) break;

			q[index].pop();
            answer += i - min_size;
            remain -= index;
        }
    }


    cout << answer;



    return 0;
}
