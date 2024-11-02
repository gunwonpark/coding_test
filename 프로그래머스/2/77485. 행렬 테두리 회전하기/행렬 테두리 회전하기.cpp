#include <string>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> board(rows, vector<int>(columns));
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            board[i][j] = i * columns + j + 1;
        }
    }
    
    for(int i = 0; i < queries.size(); i++){
        int r1,c1,r2,c2;
        r1 = queries[i][0] - 1;
        c1 = queries[i][1] - 1;
        r2 = queries[i][2] - 1;
        c2 = queries[i][3] - 1;
        
    
        int start_value = board[r1][c1];
        int min_value = start_value;
        for(int i = c1 + 1; i <=c2; i++){
            min_value = min(min_value, board[r1][i]);
            swap(start_value, board[r1][i]);
        }
        for(int i = r1 + 1; i <= r2; i++){
            min_value = min(min_value, board[i][c2]);
            swap(start_value, board[i][c2]);
        }
        for(int i = c2 - 1; i >= c1; i--){
            min_value = min(min_value, board[r2][i]);
            swap(start_value, board[r2][i]);
        }
        for(int i = r2 - 1; i >= r1; i--){
            min_value = min(min_value, board[i][c1]);
            swap(start_value, board[i][c1]);
        }
        
        answer.push_back(min_value);
    }
    
    return answer;
}