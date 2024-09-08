#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>

#define Fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

typedef long long ll;  

int n;
vector<int> arr;
vector<int> calc_sign;
int sign[4];
int max_result = -1000000001;
int min_result = 1000000001;

int calc(int i, int a, int b) {
    if (i == 0) {
        return a + b;
	}
	else if (i == 1) {
		return a - b;
	}
	else if (i == 2) {
		return a * b;
	}
	else {
		return a / b;
    }
}

void sol(int count, int value) {
    if (count == n) {
        max_result = max(max_result, value);
        min_result = min(min_result, value);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        if (sign[i] > 0) {
            sign[i]--;
            int res = calc(i, value, arr[count]);
            sol(count + 1, res);
            sign[i]++;
        }
    }
}

int main() {
    Fast;
    cin >> n;
    arr.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < 4; ++i) {
        cin >> sign[i];
	}

    sol(1, arr[0]);
    cout << max_result << "\n";
    cout << min_result << "\n";
    
    return 0;
}