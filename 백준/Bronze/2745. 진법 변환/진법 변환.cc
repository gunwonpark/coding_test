#include<iostream>
#include<string>

using namespace std;

int main() {
    string s;
    int n;

    cin >> s >> n;

    int start = 1;
    int result = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        char c = s[i];

        if ('0' <= c && c <= '9') {
            result += (c - '0') * start;
        }
        else {
            result += (c - 'A' + 10) * start;
        }

        start *= n;
    }

    cout << result;
}