#include<bits/stdc++.h>

#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

int main() {
    Fast;

    int n, w, L;
    cin >> n >> w >> L;

    int cur_sum{};
    int result{};

    vector<int> cars;
    for (int i = 0; i < n; i++) {
        int in;
        cin >> in;

        cars.emplace_back(in);
    }

    deque<pair<int ,int>> dq;
    for (int i = 0; i < n; i++) {
        dq.push_back({ cars[i], w});
        cur_sum += cars[i];
        
        result += 1;
        
        if (i == n - 1) {
            result += w;
            continue;
        }


        if (dq.size() == w || cur_sum + cars[i + 1] > L) {
            while(dq.size() == w || cur_sum + cars[i + 1] > L) {
                pair<int, int> front = dq.front();
                dq.pop_front();

                int weight = front.first;
                int time = front.second;

                result += time;
                cur_sum -= weight;

                for (auto& iter : dq) {
                    iter.second -= time;
                }
            }
            result -= 1;
        }
        else {
            for (auto& iter : dq) {
                iter.second--;
            }

            if (dq.size() > 0 && dq.front().second == 0) {
                cur_sum -= dq.front().first;
                dq.pop_front();
            }
        }
    }

    cout << result;

    return 0;
}