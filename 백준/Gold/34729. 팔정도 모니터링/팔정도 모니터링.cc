#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int main() {
    FAST;
	
	int n, r; cin >> n >> r;
    vector<pair<int, int>> arr;

    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        arr.push_back({x, y});
	}

    int left = -r, right = r;
    int result = 0;
    while (left < right)
    {
        int mid = (left + right) / 2;

        int up = 0;
        int down = 0;

        for(int i = 0; i < n; i++)
        {
            int x = arr[i].first;
            int y = arr[i].second;

            // y먼저 확인
            if (y > mid)
            {
                up -= 2;
				down += 2;
            }
            else if (y == mid)
            {
                up += 2;
				down += 2;
            }
            else
            {
                up += 2;
				down -= 2;
            }

            if (y > -mid)
            {
                up += 1;
				down -= 1;
            }
            else if (y == -mid)
            {
                up += 1;
				down += 1;
            }
            else
            {
                up -= 1;
				down += 1;
            }
            // x 확인
            if (x > mid)
            {
                up -= 3;
                down += 3;
            }
            else if (x == mid)
            {
                up += 3;
                down += 3;
            }
            else
            {
                up += 3;
                down -= 3;
            }
		}

        //cout << mid << " " << up << " " << down << "\n";

        if (up >= 0 && down >= 0)
        {
            result = mid;
            break;
        }

        if (up < down)
        {
            left = mid + 1;
            result = left;
        }
        else
        {
            right = mid - 1;
			result = right;
        }
    }

    ll value = 0;

    for(int i = 0; i < n; i++)
    {
        ll x = (ll)arr[i].first;
        ll y = (ll)arr[i].second;
        
		value += abs(x) + 2 * abs(y - result) + abs(y + result) + 3 * abs(x - result) + abs(y);
    }

	cout << value << "\n";

    return 0;
}
