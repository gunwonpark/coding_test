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

    vector<pair<int, int>> mem(n);

    for (int i = 0; i < n; i++)
    {
        cin >> mem[i].first >> mem[i].second;
    }   

    //do solution
    bool map[100][100] = { false, };

    //채워진 영역을 체크한다
    for (int i = 0; i < n; i++) {
        int x = mem[i].first;
        int y = mem[i].second;
        for (int j = y; j < y + 10; j++) {
            for (int k = x; k < x + 10; k++) {
                map[j][k] = true;
            }
        }
    }

    int result = 0;
    //채워진 영역의 수로 넓이를 구한다
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (map[i][j] == true)
                result += 1;
        }
    }

    cout << result;
    return 0;
}