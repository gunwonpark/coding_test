#include <bits/stdc++.h>
#include <unordered_map>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;



int main() {
    FAST;

    ll a, b; cin >> a >> b;

    ll target = a - b + 1;

    if (target <= 0) {
        cout << -1 << " " << -1;
        return 0;
    }

    ll n; cin >> n;
    vector<pair<ll, ll>> l(n);
    vector<pair<ll, ll>> r(n);

    ll diff = 1e18;
    pair<ll, ll> answer = { -1, -1 };

    for (int i = 0; i < n; i++) {
        cin >> l[i].first >> r[i].first;
        l[i].second = i;
        r[i].second = i;
        if (l[i].first >= target && diff > l[i].first - target) {
            diff = l[i].first - target;
            answer = { i + 1, -1 };
        }

        if (r[i].first >= target && diff > r[i].first - target) {
            diff = r[i].first - target;
            answer = { -1, i + 1};
        }

    }

    sort(l.begin(), l.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
        });

    sort(r.begin(), r.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
        });



    for (int i = 0; i < n; i++) {
        ll firstValue = l[i].first;
        ll firstIndex = l[i].second;

        ll left = 0; ll right = n - 1;

        while (left <= right) {
            ll mid = (left + right) / 2;
            ll secondIndex = r[mid].second;
            ll secondValue = r[mid].first;

            ll value = secondValue + firstValue;
            if (secondIndex == firstIndex) {
                if (left == right) {
                    break;
                }
                mid++;
				secondIndex = r[mid].second;
				secondValue = r[mid].first;
				value = secondValue + firstValue;
            }
            

            if (value == target) {
                answer = { firstIndex, secondIndex };
                cout << answer.first + 1 << " " << answer.second + 1;
                return 0;
            }
            else if (value < target) {
                left = mid + 1;
            }
            else {
                if (diff > value - target) {
                    diff = value - target;
                    answer = { firstIndex + 1, secondIndex + 1 };
                }
                right = mid - 1;
            }
        }
    }

    if (answer.first == -1 && answer.second == -1) {
        cout << "No";
    }
    else {
        cout << answer.first << " " << answer.second;
    }

    return 0;
}