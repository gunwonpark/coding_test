#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> GetPartialMatch(const string& p) {
    int n = p.size();
    vector<int> pi(n, 0);

    int begin = 1, matched = 0;

    while (begin + matched < n) {
        if (p[begin + matched] == p[matched]) {
            matched++;
            pi[begin + matched - 1] = matched;
        }
        else {
            if (matched == 0) {
                begin++;
            }
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return pi;
}

int main() {
    string T;

    getline(cin, T);

    string P;
    getline(cin, P);

    if (P.size() > T.size()) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> pi = GetPartialMatch(P);

    int begin = 0, matched = 0;

    int res = 0;
    vector<int> pos;

    while (begin <= T.size() - P.size()) {

        if (matched < P.size() && T[begin + matched] == P[matched]) {
            matched++;
            if (matched == P.size()) {
                res++;
                pos.push_back(begin + 1);
            }
        }
        else {
            if (matched == 0) {
                begin++;
            }
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }

    cout << res << endl;
    for (int i = 0; i < pos.size(); i++) {
        cout << pos[i] << " ";
    }

    return 0;
}