#include<bits/stdc++.h>

#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;


struct Node {
    int w, h;
    Node(int w, int h) :w(w), h(h) {};
    Node() { w = 0; h = 0; };

    bool operator < (const Node& cmp) {
        if (w == cmp.w) return h < cmp.h;
        return (w < cmp.w);
    }
};


int main() {
    Fast;
 
    int n;
    cin >> n;

    vector<Node> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].w >> arr[i].h;
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        cout << arr[i].w << " " << arr[i].h << '\n';
    }

    return 0;
}