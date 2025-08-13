#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long ll;

using namespace std;

int main() {
    FAST;

    string str; cin >> str;

    int number = 0;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '*') {
            number = i;
        }
	}

    int answer = 0;

    if (number == str.size() - 1)
    {
        for(int i = 0; i < str.size() - 1; i++) {
            if(i % 2 == 0) {
                answer += (str[i] - '0') * 1;
            } else {
				answer += (str[i] - '0') * 3;
			}
		}
        answer %= 10;
        answer = 10 - answer;
    }
    else
    {
        int cul = 0;
        for (int i = 0; i < str.size() - 1; i++) {
            if(i == number) {
                continue;
			}

            if (i % 2 == 0) {
                cul += (str[i] - '0') * 1;
            }

            else {
                cul += (str[i] - '0') * 3;
            }
        }
		int target = str[str.size() - 1] - '0';
        target = (10 - target) % 10;

        for (int i = 0; i <= 9; i++)
        {
            if((cul + i * (number % 2 == 0 ? 1 : 3)) % 10 == target) {
                answer = i;
                break;
			}
        }
    }
    cout << answer;
    
    return 0;
}