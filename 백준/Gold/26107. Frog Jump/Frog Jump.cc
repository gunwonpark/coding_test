#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;

    cin >> n >> k;

    vector<pair<int, int>> line(n);
    long long* dp = new long long[n];
    
    for (int i = 0; i < n; i++) {
        cin >> line[i].first >> line[i].second;
    }

    int left = line[0].first;
    int right = line[0].second;

    for (int i = 1; i < n; i++) {
        int t_left = line[i].first;
        int t_right = line[i].second;

        if (t_left > right) {
            dp[i] = dp[i-1] + t_left - right;
            left = t_left;
            right = t_right;
        }
        else
        {
            if (t_right > right) {
                right = t_right;
            }
            dp[i] = dp[i - 1];
        }
    }
    
    vector<int> point;
    int num;

    point.push_back(1);

    // 입력값을 공백으로 구분하여 한 번에 입력받음
    while (cin >> num) {
        point.push_back(num);
    }

    long long result = 0;

    for (int i = 0; i < k; i++) {
        result += abs(dp[point[i + 1] - 1] - dp[point[i] - 1]);
    }

    cout << result;

    return 0;
}