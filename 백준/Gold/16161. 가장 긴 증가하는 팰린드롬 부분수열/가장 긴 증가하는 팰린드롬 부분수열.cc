#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int main() {
    FAST;

    int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

    int m = -1;
    int answer = 1;
    int num = 1;
    bool same_once = false;

    for (int i = 1; i < n; i++)
    {
		int prev = a[i - 1];
		int cur = a[i];

        if (cur > prev)
        {
            num = 1;
            m = i;
            same_once = false;
        }
        else if (cur == prev)
        {
            if (same_once == false)
            {
                same_once = true;
                answer = max(answer, 2);
                if (num != 1)
                {
                    m = -1;
                    num = 1;
                }
            }
            else {
                m = -1;
            }
        }
        else if (cur < prev)
        {
            if (m != -1 && a[i] == a[m - num])
            {
				answer = max(answer, i - (m - num) + 1);
                num++;
            }
            else
            {
                num = 1;
                m = -1;

            }
            same_once = false;
        }
    }

	cout << answer << "\n";

    return 0;
}
