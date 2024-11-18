#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using ll = long long;
using namespace std;

int main() {
    Fast;

    int r, c;
    cin >> r >> c;
    vector<string> a(r);
    ll result = 0;

    for (int i = 0; i < r; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < c - 1; i++) {
        vector<int> active_rows(r, 1); // 유효한 행을 추적하는 배열
        int left = i, right = i + 1;

        while (left >= 0 && right < c) {
            ll count = 0;

            for (int j = 0; j < r; j++) {
                if (active_rows[j] && a[j][left] == a[j][right]) {
                    count++;
                } else {
                    result += count * (count + 1) / 2;
                    count = 0;
                    active_rows[j] = 0; // 비활성화
                }
            }

            result += count * (count + 1) / 2; // 남은 카운트 처리
            left--;
            right++;
        }
    }

    cout << result;
    return 0;
}