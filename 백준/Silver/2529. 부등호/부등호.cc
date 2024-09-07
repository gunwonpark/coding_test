#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

#define Fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

typedef long long ll;  

int n;
char* arr;
ll minres = 9999999999, maxres = 0;
ll pos[10];
int check[10];

void sol(int count, ll num) {
    if (count == n + 1) {
        minres = min(minres, num);
        maxres = max(maxres, num);
    }

    for (int i = 0; i <= 9; i++) {
        if (check[i]) continue;
        pos[count] = i;
        if (count == 0) {
            check[i] = 1;
            sol(count + 1, num + i);
            check[i] = 0;
        }
        if (arr[count - 1] == '<') {
            if (pos[count - 1] < pos[count]) {
                check[i] = 1;
                sol(count + 1, num * 10 + i);
                check[i] = 0;
            }
        }
        else {
            if (pos[count - 1] > pos[count]) {
                check[i] = 1;
				sol(count + 1, num * 10 + i);
                check[i] = 0;
			}
        }
    }
}

int main() {
    Fast;
    cin >> n;

    arr = new char[n];

    for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

    sol(0, 0);

    int iter = 1;
    for (int i = 0; i < n; i++) {
		iter *= 10;
	}

    cout << maxres << "\n";
    if (minres / iter == 0) cout << 0;
    cout << minres << "\n";

    return 0;
}