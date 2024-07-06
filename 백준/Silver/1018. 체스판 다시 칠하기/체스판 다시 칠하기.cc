#include <iostream>
#include <vector>
#include <queue>
#include <stack>


#define ll long long

using namespace std;

vector<vector<int>> MakeTable(vector < vector<int>>& table) {
    vector<vector<int>> result(table.size(), vector<int>(table[0].size(), 0));

    for (int i = 1; i < table.size(); ++i)
    {
        for (int j = 1; j < table[0].size(); ++j)
        {
			result[i][j] = result[i - 1][j] + result[i][j - 1] - result[i - 1][j - 1] + table[i][j];
		}
	}

    return result;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);    

    int n, m;
    cin >> n >> m;

    vector<vector<int>> blackFirstTable(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> whiteFirstTable(n + 1, vector<int>(m + 1, 0));
    string input;

    for (int i = 0; i < n; ++i)
    {
		cin >> input;
        for (int j = 0; j < m; ++j)
        {
            if ((i + j) % 2 == 0) {
                if(input[j] == 'B')
                    whiteFirstTable[i + 1][j + 1] = 1;
                else
                    blackFirstTable[i + 1][j + 1] = 1;
					
            }
            else {
                if(input[j] == 'B')
                    blackFirstTable[i + 1][j + 1] = 1;
                else
                    whiteFirstTable[i + 1][j + 1] = 1;
            }
		}
	}

    vector<vector<int>> blackFirstSumTable = MakeTable(blackFirstTable);
    vector<vector<int>> whiteFirstSumTable = MakeTable(whiteFirstTable);

    int res = 2500;

    for (int i = 8; i < n + 1; ++i)
    {
        for (int j = 8; j < m + 1; ++j)
        {
            int blackFirstSum = blackFirstSumTable[i][j] - blackFirstSumTable[i - 8][j] - blackFirstSumTable[i][j - 8] + blackFirstSumTable[i - 8][j - 8];
            int whiteFirstSum = whiteFirstSumTable[i][j] - whiteFirstSumTable[i - 8][j] - whiteFirstSumTable[i][j - 8] + whiteFirstSumTable[i - 8][j - 8];
            res = min(res, blackFirstSum);
            res = min(res, whiteFirstSum);
		}	
	}
    
    cout << res;
    return 0;
}



