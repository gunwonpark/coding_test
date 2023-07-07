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

    vector<int> mem(n);

    for (int i = 0; i < n; i++)
    {
        cin >> mem[i];
    }   

    sort(mem.begin(), mem.end());

    //do solution   
    //홀 - 홀 = 짝 
    //홀 - 짝 = 홀
    //짝 - 짝 = 짝
    int odd_result = -1;
    int even_result = -1;

    //작은 짝수 찾기
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (((mem[j] - mem[i]) & 1) == 0) {
                if (even_result != -1)
                    even_result = min(even_result, mem[j] - mem[i]);
                else
                    even_result = mem[j] - mem[i];
                break;
            }
        }
    }

    //작은 홀수 찾기
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (((mem[j] - mem[i]) & 1) == 1) {
                if (odd_result != -1)
                    odd_result = min(odd_result, mem[j] - mem[i]);
                else
                    odd_result = mem[j] - mem[i];
                break;
            }
        }
    }
   
    cout << even_result << " " << odd_result;
    return 0;
}