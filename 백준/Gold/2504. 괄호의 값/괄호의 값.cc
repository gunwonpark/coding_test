#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void Solution()
{
   
    string str;
    cin >> str;
   
    stack<char> s;

    int temp = 1;
    int res = 0;

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == '(') {
            s.push(str[i]);
            temp *= 2;
        }
        else if (str[i] == '[') {
            s.push(str[i]);
			temp *= 3;
        }
        else if (str[i] == ')') {
            if (s.empty() || s.top() != '(') {
				cout << 0 << endl;
				return;
			}
            if (str[i - 1] == '(') {
                res += temp;
                
            }
            temp /= 2;
            s.pop();
        }
        else if (str[i] ==']'){
            if (s.empty() || s.top() != '[') {
				cout << 0 << endl;
				return;
			}
            if (str[i - 1] == '[') {
				res += temp;
			}
            temp /= 3;
            s.pop();
        }
    }

    if (!s.empty()) {
		cout << 0 << endl;
		return;
    }

    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);    

    Solution();

   


    return 0;
}



