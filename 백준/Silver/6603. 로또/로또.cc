#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<stack>
#define Fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

typedef long long ll;  

int n;
vector<int> arr;
vector<int> result;


void sol(int count) {
    if (result.size() == 6) {
        for (auto& i : result) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = count; i < n; ++i) {
        result.push_back(arr[i]);
        sol(i + 1);
        result.pop_back();
    }
}

int main() {
    Fast;
    while (cin >> n) {
        arr.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        
        sol(0);
        cout << '\n';
    }

       
    return 0;
}