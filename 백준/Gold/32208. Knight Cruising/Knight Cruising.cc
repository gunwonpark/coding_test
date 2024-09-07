#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

#define Fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

typedef long long ll;  

int main() {
    Fast;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        ll x, y, z;  
        scanf("%lld %lld %lld", &x, &y, &z);

        ll sum = x + y + z;

        if (sum % 2 == 0) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}