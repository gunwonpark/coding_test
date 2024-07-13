#include <iostream>
#include <algorithm>
#include <vector>

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;


int main() {
    FAST;

    int n;
    cin >> n;

    vector<int> arr(n);

    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int left = 0;
    int right = n - 1;

    int lRes = 0;
    int rRes = 0;
    int res = 2000000000;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < res) {
			res = abs(sum);
			lRes = left;
			rRes = right;
		}

        if (sum == 0) {
            cout << arr[left] << " " << arr[right] << "\n";
            break;
        }

        if (sum > 0) {
            right--;
        }
        else if(sum < 0){
            left++;
        }
    }

    cout << arr[lRes] << " " << arr[rRes] << "\n";

    return 0;
}