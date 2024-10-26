#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n, -1000000001);
    int result = 0;
    for (int i = 0; i < n; i++) {
        int in;
        cin >> in;
        arr[lower_bound(arr.begin(), arr.begin() + result, in) - arr.begin()] = in;

        if (arr[result] != -1000000001) result++;
	}
    
    cout << result << endl;
    return 0;
}