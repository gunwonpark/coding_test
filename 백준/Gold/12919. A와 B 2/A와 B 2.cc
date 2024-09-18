#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<queue>

#define Fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

typedef long long ll;

string s, t;
bool result = false;
void sol(string temp) {
    if (temp.size() == s.size()) {
        if (s == temp) {
            result = true;
        }
        return;
    }



    if (temp[temp.size() - 1] == 'A') {
        temp.pop_back();
        sol(temp);
        temp.push_back('A');
	}
    
    if (temp[0] == 'B') {
        reverse(temp.begin(), temp.end());
        temp.pop_back();
        sol(temp);
    }
}

int main() {    
    cin >> s >> t;

    sol(t);
    cout << result;
    
    return 0;
}
