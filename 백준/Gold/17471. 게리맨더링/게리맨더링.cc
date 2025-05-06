#include<bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

int n;
int totalCount = 0;
int curCount = 0;
int answer = -1;

vector<int> people;
vector<vector<int>> adj;
vector<int> dfsVisited;

int bfs(int start, int crit) {
    queue<int> pos;
    pos.push(start);
    vector<int> bfsVisited(n + 1, 0);
    bfsVisited[start] = 1;
    int count = 1;

    while (!pos.empty()) {
        int cur = pos.front();
        pos.pop();

        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i];

            if (bfsVisited[next] || dfsVisited[next] == crit) continue;
            bfsVisited[next] = 1;

            pos.push(next);
            count++;
        }
    }

    return count;
}

int main(){ 
    FAST;
    cin >> n;

    people.resize(n + 1);
    adj.resize(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> people[i + 1];
    }

    for (int i = 1; i <= n; i++) {
        int input; cin >> input;
        for (int j = 0; j < input; j++) {
            int num; cin >> num;
            adj[i].push_back(num);
        }
    }

    for (int i = 1; i < (1 << n) - 1; i++) {
        dfsVisited.clear();
        dfsVisited.resize(n + 1, 0);

        int firstIndex{};
        int secondIndex{};
        int firstCount{};
        int secondCount{};

        int div{};

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                dfsVisited[j + 1] = 1;
                secondIndex = j + 1;
                div += people[j + 1];
            }
            else {
                firstIndex = j + 1;
                div -= people[j + 1];
            }
        }

        div = abs(div);

        int fi = bfs(firstIndex, 1);
        int se = bfs(secondIndex, 0);

        if (fi + se == n) {
            if (answer == -1)
                answer = div;
            answer = min(answer, div);
        }
    }

   
    cout << answer;
    
   
    return 0;
}