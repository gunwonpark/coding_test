#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    vector<int> ans;
    int win;
    
    Node(vector<int> ans, int win):ans(ans), win(win){};
    Node(){ win = 0;};
};

int dice_num;
vector<int> cur_dice;
Node result;
vector<int> my_dice;
vector<int> partner_dice;
vector<int> p_dice;
vector<vector<int>> _dice;

void calc(int sum1, int sum2, int depth){
    if(depth == cur_dice.size() - 1){
        for(int i = 0; i < 6; i++){
            my_dice.push_back(sum1 + _dice[cur_dice[depth]][i]);
            p_dice.push_back(sum2 + _dice[partner_dice[depth]][i]);
        }
        return;
    }
    for(int i = 0; i < 6; i++){
        int index = cur_dice[depth];
        int index2 = partner_dice[depth];
        sum1 += _dice[index][i];
        sum2 += _dice[index2][i];
        calc(sum1, sum2, depth + 1);
        sum1 -= _dice[index][i];
        sum2 -= _dice[index2][i];
    }
}
void do_cmp(){
    int win = 0;
    for(int i = 0; i < my_dice.size(); i++){
        for(int j = 0; j < p_dice.size(); j++){
            if(my_dice[i] > p_dice[j])
                win++;
        }
    }
    cout << win << '\n';
    if(result.win < win){
        result.ans = cur_dice;
        result.win = win;
    }
    return;
}
void dfs(int start, int depth){
    if(cur_dice.size() == dice_num / 2){
        // 계산 시작
        my_dice.clear();
        p_dice.clear();
        partner_dice.clear();
        for(int i = 0; i < dice_num;i++){
            if(find(cur_dice.begin(), cur_dice.end(), i) == cur_dice.end()){
                partner_dice.push_back(i);
            }
        }
        calc(0, 0, 0);
        do_cmp();
        return;
    }
    for(int i = start; i < dice_num; i++){
        cur_dice.push_back(i);
        dfs(i + 1, depth + 1);
        cur_dice.pop_back();
    }
}
vector<int> solution(vector<vector<int>> dice) {
    _dice = dice;
    vector<int> answer;
    dice_num = dice.size();
    dfs(0, 0);
    
    for(int i = 0; i < result.ans.size(); i++){
        result.ans[i]++;
    }
    return result.ans;
}