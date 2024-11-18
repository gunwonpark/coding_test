#include<bits/stdc++.h>

#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

using ll = long long;

using namespace std;


int main() {
    Fast;
    
    int r, c;
    cin >> r >> c;
    vector<string> a(r);    
    ll result = 0;

    for (int i = 0; i < r; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < c - 1; i++) {
        // set 초기화
        set<int> s;
        for (int j = 0; j < r; j++) {
            s.insert(j);
        }
        int left = i, right = i + 1;

        while (left >= 0 && right < c && !s.empty()) {
            ll count = 0;
            int prev = *s.begin() - 1;
            set<int> t_se = s;
            for (auto& se : t_se) {
                int cur = se;

                if (cur - prev != 1) {
                    result += count * (count + 1) / 2;
                    count = 0;
                }

                if (a[se][left] == a[se][right]) {
                    count++;
                }
                else {
                    s.erase(se);
                    result += count * (count + 1) / 2;
                    count = 0;
                }
                prev = cur;
            }

            result += count * (count + 1) / 2;
            left -= 1;
            right += 1;
        }
    }

    cout << result;
    return 0;
}