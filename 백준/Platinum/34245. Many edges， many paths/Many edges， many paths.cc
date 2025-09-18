#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

// 1개 약 9999
// 2개 약 4999
// .... 100개 약 99개

// 각각 약 9999개를 만들수 있으며 9999 * 100 = 999900 중복이 있는 경우를 제외한다 해도 600000은 넘을거로 예상

int n, m;

vector<bool> visited;

void travel(int& start, int step, int iter)
{
    vector<int> end_points(step);
    for (int i = 0; i < step; i++)
    {
		end_points[i] = (n - 1) - (n - 1 - i) % step;
    }

    while (iter--)
    {
        int current = start;
        int end_idx = start % step;
        int end_point = end_points[end_idx];

        while (end_point > current && visited[end_point])
        {
            end_point -= step;
        }

        if (end_point <= current)
        {
            cout << 3 << " ";
            cout << 1 << " " << current << " " << n; 
            cout << '\n';
            start++;
            continue;
        }

        visited[end_point] = true;

        int move = (end_point - current) / step; 
        int total_move = move + 3;

        cout << total_move << " ";
        cout << 1 << " ";
        for (int i = 0; i <= move; i++)
        {
            cout << current + step * i << " ";
        }

	    cout << n << '\n';
        start++;
    }
}



int main() {
    FAST;

    cin >> n >> m;

    visited.resize(n + 1, false);
    int start = 2;

    cout << 99 * (99 + 1) / 2 + 50 << '\n';

    for (int step = 1; step <= 99; step++) {
        travel(start, step, step);
    }

    travel(start, 100, 50);

    return 0;
}
