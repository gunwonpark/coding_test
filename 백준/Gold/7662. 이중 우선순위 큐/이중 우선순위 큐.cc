#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

map<int, int> mp;
priority_queue<int, vector<int>, greater<int>> min_pq;
priority_queue<int> max_pq;

int main() {
    FAST;
    int t; cin >> t;
    while (t--)
    {
        int size = 0;
        int q; cin >> q;
        while (q--)
        {
            char c; int n; cin >> c >> n;

            if (c == 'I')
            {
                //삽입
				min_pq.push(n);
				max_pq.push(n);
				mp[n]++;
                size++;
            }
            else
            {
                if (size == 0) continue;

                if (n == 1)
                {
                    // 최대값 삭제
                    while (!max_pq.empty())
                    {
                        int num = max_pq.top();
                        if (mp[num] > 0)
                        {
                            mp[num]--;
                            size--;
                            max_pq.pop();
                            break;
                        }

                        max_pq.pop();
                    }
                }
                else
                {
                    // 최소값 삭제
                    while(!min_pq.empty())
                    {
                        int num = min_pq.top();
                        if (mp[num] > 0)
                        {
                            mp[num]--;
                            size--;
                            min_pq.pop();
                            break;
                        }
						min_pq.pop();
					}
                }
            }
        }

        while (!min_pq.empty())
        {
            int num = min_pq.top();
            if (mp[num] > 0) break;
            min_pq.pop();
        }

        while (!max_pq.empty())
        {
            int num = max_pq.top();
            if (mp[num] > 0) break;
            max_pq.pop();
        }

        if (size == 0) {
            cout << "EMPTY\n";
        }
        else {
            cout << max_pq.top() << ' ' << min_pq.top() << '\n';
        }

        mp.clear();
        while (!min_pq.empty()) min_pq.pop();
        while (!max_pq.empty()) max_pq.pop();
    }

        
    return 0;
}
