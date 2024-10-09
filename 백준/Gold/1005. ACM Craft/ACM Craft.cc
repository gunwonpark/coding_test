#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long ll;

using namespace std;


int main() {
    FAST;

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<int> delay(N + 1);

        for (int i = 1; i <= N; i++) {
            cin >> delay[i];
        }

        vector <vector<int>> graph(N + 1);
        vector<int> indegree(N + 1, 0);

        for (int i = 0; i < K; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            indegree[b]++;
        }

        int End;
        cin >> End;

        int Start;
        vector<int> dp(N + 1, 0);

        for (int i = 1; i <= N; i++) {
            if (indegree[i] == 0) {
                Start = i;
                queue<int> q;
                q.push(Start);
                dp[Start] = delay[Start];

                while (!q.empty()) {
                    int cur = q.front();
                    q.pop();

                    for (int i = 0; i < graph[cur].size(); i++) {
                        int next = graph[cur][i];
                        dp[next] = max(dp[next], dp[cur] + delay[next]);
                        indegree[next]--;
                        if (indegree[next] == 0) {
                            indegree[next] = -1;
                            q.push(next);
                        }
                    }
                }
            }
        }

        cout << dp[End] << '\n';
    }
    return 0;
}