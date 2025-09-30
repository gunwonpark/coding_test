#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

map<int, int> mp;
priority_queue<int, vector<int>, greater<int>> min_pq;
priority_queue<int> max_pq;

int main() {
    FAST;

    int t; cin >> t;
    while (t--)
    {
        string order; cin >> order;
        int n; cin >> n;
        string arr; cin >> arr;
        deque<int> dq;

        arr = arr.substr(1, arr.size() - 2);

        vector<string> tokens;
        string temp = "";
        for (int i = 0; i < arr.size(); i++)
        {
			char c = arr[i];
            if (c == ',')
            {
				tokens.push_back(temp);
                temp = "";
            }
            else
            {
                temp += c;
            }
        }

        if (temp != "")
        {
            tokens.push_back(temp);
        }

        for (int i = 0; i < tokens.size(); i++)
        {
			int num = stoi(tokens[i]);
			dq.push_back(num);
        }

        bool reversed = false;
		bool error_flag = false;

        for (int i = 0; i < order.size(); i++)
        {
            if (order[i] == 'R')
            {
				reversed = !reversed;
            }
            else
            {
                if (dq.empty())
                {
                    cout << "error\n";
                    error_flag = true;
					break;
                }

                if (reversed)
                {
                    dq.pop_back();
                }
                else
                {
                    dq.pop_front();
				}
		    }
        }

        if(!error_flag)
        {
            if (reversed)
            {
                reverse(dq.begin(), dq.end());
            }
            cout << "[";
            for (int i = 0; i < dq.size(); i++)
            {
                cout << dq[i];
                if (i != dq.size() - 1)
                {
                    cout << ",";
                }
            }
            cout << "]\n";
		}
    }

        
    return 0;
}
