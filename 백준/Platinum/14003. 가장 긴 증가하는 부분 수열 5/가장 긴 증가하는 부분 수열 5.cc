#include<bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

using namespace std;

typedef long long ll;

int dp[1000001];
int tracing[1000001];

int main() {
    FAST;

    int n;
    cin >> n;

    int stack = 0;
    fill(dp, dp + n, 1000000001);

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
        int index = lower_bound(dp, dp + stack, input) - dp;
        tracing[i] = index;
        dp[index] = input;
        
        if (dp[stack] != 1000000001) {
            stack++;
        }
    }

    cout << stack;
    cout << '\n';

    vector<int> answer;
    int key = stack - 1;
    for (int i = arr.size() - 1; i >= 0; i--) {
        if (key ==tracing[i]) {
            answer.push_back(arr[i]);
            key--;
        }
    }

    for (int i = answer.size() - 1; i >= 0;i--) {
        cout << answer[i] << " ";
    }
    return 0;
}