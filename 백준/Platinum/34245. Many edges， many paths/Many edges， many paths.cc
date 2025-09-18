#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<bool> visited;

void travel(int& start, int step, int iter)
{
    // 각 residue class별 "가장 큰 end_point"를 맞춰서 초기화
    vector<int> end_points(step);
    for (int val = 0; val < step; val++) {
        end_points[val] = (n - 1) - ((n - 1 - val) % step);
    }

    while (iter--) {
        int current = start;
        int end_idx = current % step;
        int end_point = end_points[end_idx];

        // 아직 사용하지 않은 e를 찾기
        while (end_point >= 2 && visited[end_point]) {
            if (end_point < step) break;
            end_point -= step;
        }

        visited[end_point] = true;
        end_points[end_idx] = (end_point >= step ? end_point - step : 0);
        start++;

        int steps = (end_point >= current ? (end_point - current) / step : 0);
        int cnt = steps + 3; // 1, current, ..., end_point, n

        cout << cnt << " ";
        cout << 1 << " " << current << " ";

        int val = current;
        while (val + step <= end_point) {
            val += step;
            cout << val << " ";
        }

        cout << n << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    visited.resize(n + 1, false);

    int start = 2;

    // 경로 개수 출력
    cout << 99 * (99 + 1) / 2 + 98 << '\n';

    // FULL_D 블록 (d=1~99)
    for (int step = 1; step <= 99; step++) {
        travel(start, step, step);
    }

    // PARTIAL_D 블록 (d=100, 98개만)
    travel(start, 100, 98);

    return 0;
}