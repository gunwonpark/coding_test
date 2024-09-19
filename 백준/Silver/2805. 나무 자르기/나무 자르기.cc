#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<queue>

#define Fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

typedef long long ll;



int main() {   
    int n, m;
    vector<int> arr;

    int Min = 0, Max = 0;
    
    cin >> n >> m;
    arr.resize(n);

   

    for (int i = 0; i < n; i++) {
		cin >> arr[i];
        Max = max(Max, arr[i]);
	}

    int result = 0;

    while (Min < Max) {
        int mid = (Min + Max) / 2;

        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += max(0, arr[i] - mid);
        }
        
        if (sum >= m) {
            Min = mid + 1;
            result = max(result, mid);
        }
        else {
            Max = mid;
        }
    }

    cout << result;

    return 0;
}
