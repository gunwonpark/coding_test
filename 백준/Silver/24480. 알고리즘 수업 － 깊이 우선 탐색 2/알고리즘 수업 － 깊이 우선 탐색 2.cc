#include <iostream>
#include <vector>
#include <algorithm>
#define sync ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;


class Graph {
private:
    int N, M, R; //정점수, 간선의 수, 시작노드
    vector<vector<int>> vec;
    vector<bool> visited;
    vector<int> result;
    vector<int> _solution;
    int u, v;

    void dfs(int R) {
        if (vec[R].size() == 0) {
            return;
        }
        visited[R] = true;

        vector<int>& start = vec[R];

        for (auto& next : start) {
            if (visited[next] != true) {
                result.push_back(next);
                dfs(next);
            }
        }
    }

public:
    void Init() {
        cin >> N >> M >> R;

        vec.resize(N + 1);
        visited.resize(N + 1, false);
        _solution.resize(N + 1, 0);

        for (int i = 0; i < M; i++) {
            cin >> u >> v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        for (int i = 0; i <= N; i++)
        {
            sort(vec[i].begin(), vec[i].end(), greater<int>());
        }

        result.push_back(R);
    }

    //just for Debug
    /*template <typename T>
    void printVector(vector<vector<T>>& vec) {
        for (int i = 0; i < vec.size(); i++) {
            for (int j = 0; j < vec[i].size(); j++) {
                cout << i << " " << vec[i][j] << " ";
            }
            cout << "\n";
        }
    }*/

    template <typename T>
    void printVector(vector<T>& vec, int start = 0) {
        for (int i = start; i < vec.size(); i++) {
            cout << vec[i] << "\n";
        }
        cout << "\n";
    }

    void solution() {
        dfs(R);
        int count = 1;
        for (auto& res : result) {
            _solution[res] = count++;
        }
        printVector(_solution, 1);
    }
};








int main() {
    sync;
    Graph g;
    g.Init();
    g.solution();
    return 0;
}

