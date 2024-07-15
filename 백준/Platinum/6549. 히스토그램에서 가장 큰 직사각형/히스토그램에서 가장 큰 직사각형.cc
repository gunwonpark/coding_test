#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;

using namespace std;

ll GetMaxRectangle(int _arrLength)
{
    vector<int> arr(_arrLength + 2, 0);

    for (size_t i = 1; i < _arrLength + 1; i++)
    {
        cin >> arr[i];
    }

    stack<int> index;
    index.push(0);

    int length = arr.size();
    ll res = 0;

    for (int i = 1; i < length; i++)
    {
        if (arr[index.top()] <= arr[i]) {
            index.push(i);
        }
        else {
            while (arr[index.top()] > arr[i]) {
                int height = arr[index.top()];
                index.pop();

                int length = i - index.top() - 1;

                res = max(res, (ll)height * length);
            }
            index.push(i);
        }
    }

    return res;
}

int main() {
    FAST;

    while (true) {
        int n;
        cin >> n;

        if (n == 0) break;

        cout << GetMaxRectangle(n) << "\n";
    }
    

    return 0;
}


