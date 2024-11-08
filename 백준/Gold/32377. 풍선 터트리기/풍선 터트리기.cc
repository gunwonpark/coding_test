#include<bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

using namespace std;

typedef long long ll;

int main() {
    FAST;
    ll N, a, b, c;
    cin >> N >> a >> b >> c;

    ll min_value = min({ a, b, c });
    
    ll T = N * min_value;

    ll left = 0, right = T;
    while (left < right) {
        ll mid = (left + right) / 2;
        //현재 시간에 얼만큼의 풍선을 터트릴수 있는지 확인한다
        ll sum = mid / a + mid / b + mid / c;

        if (sum < N) {
            left = mid + 1;
        }
        else if (sum >= N) {
            right = mid;
        }
    }

    T = left;

    ll count = T / a + T / b + T / c;
    
    a = a * (T / a);
    b = b * (T / b);
    c = c * (T / c);


    pair<char, ll> answer[3] = {{'A', a}, {'B', b}, {'C', c}};
   
    sort(answer, answer + 3, [](const pair<char, ll>& a, const pair<char, ll>& b) {
        if (a.second == b.second) return a.first > b.first;
        return a.second > b.second;
        });

    cout << answer[count - N].first << " win";
    return 0;
}
//4 5 3 6