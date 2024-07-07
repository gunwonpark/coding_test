#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);    

    int n, s;
    cin >> n >> s;

    vector<int> arr(n);

    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int left = 0, right = 0;
    int curSum = 0;
    int res = n + 1;

    while (right < n) {
        if (curSum < s) {
            curSum += arr[right];
        }

        while (curSum >= s && left < n) {
            res = min(res, right - left + 1);
            curSum -= arr[left];
            left++;
        }
        
        right++;
    }

    cout << (res == n + 1 ? 0 : res);

	return 0;
}


