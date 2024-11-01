#include<bits/stdc++.h>

#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;


using namespace std;

int main() {
    Fast;
    int T;
    cin >> T;

    while (T--) {
        int n, index;
        cin >> n >> index;

        queue<pair<int, int>> q;

        int rank[10]{};

        for (int i = 0; i < n; i++) {
            int input;
            cin >> input;
            
            rank[input]++;
            q.push({ input, i });
        }

        int rank_index = 9;
        int count = 0;
        while (true) {
            int _rank = rank_index;
            count++;

            for (int i = _rank; i >= 1; i--) {
                rank_index = i;
                if (rank[i] != 0) break;
            }

            while (q.front().first < rank_index) {
                pair<int,int> top = q.front();
                q.pop();
                q.push(top);
            }

            pair<int, int> top = q.front();
            if (top.second == index) {
                cout << count << '\n';
                break;
            }
            rank[rank_index]--;
            q.pop();
        }
    }
    return 0;
}