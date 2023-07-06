#include <iostream>
#include<algorithm>
#include <vector>

using namespace std;

bool comp(pair<int, string> a, pair<int, string> b) {
    return a.first < b.first;
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<pair<int, string>> seq(n);

    for (int i = 0; i < n; i++)
    {
        cin >> seq[i].first >> seq[i].second;
    }
   
   
    stable_sort(seq.begin(), seq.end(), comp);

    for (int i = 0; i < n; i++) {
        cout << seq[i].first << " " << seq[i].second << "\n";
    }

    return 0;
}