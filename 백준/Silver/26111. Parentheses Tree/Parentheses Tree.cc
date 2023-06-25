#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    int count = -1;
    bool is_rise, pre = true;

    long long result = 0;

    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        //깊이를 count를 통하여 측정한다
        if (str[i] == '(') {
            count++;
            is_rise = true;
            pre = true;
        }
        else{
            count--;
            is_rise = false;
        }
        //정점일 때에만 값을 더해준다
        if (pre && is_rise == false) {
            result += count + 1;
            pre = false;
        }
    }
    cout << result;
    return 0;
}