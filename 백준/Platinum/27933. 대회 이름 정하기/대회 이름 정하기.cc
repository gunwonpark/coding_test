#include <iostream>
#include<algorithm>
#include<typeinfo>
#include <vector>

using namespace std;

bool comp(pair<int, string> a, pair<int, string> b) {
    return a.first < b.first;
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //연 = Y, 고 = K
    //Y는 연고연고연고 = YKYKYK
    //K는 고연고연고연 = KYKYKY
    int n;
    cin >> n;

    string card_set;
    cin >> card_set;

    vector<pair<char, int>> card(n);
    for (int i = 0; i < card_set.size(); i++) {
        card[i].first = card_set[i];
        cin >> card[i].second;
    }
    
    int t;
    cin >> t;

    int l, r;
    long long y_player = 0, k_player = 0;

    for (int i = 0; i < t; i++)
    {
        cin >> l >> r;
        //doSolution
        int y_tmp = 0;
        int x_tmp = 0;
        bool y_flag = true;
        bool x_flag = true;

        //y_player에 대한 점수계산
        for (int j = l-1; j <= r-1; j++) {
            if (card[j].first == 'Y') {
                if (x_flag == false) {
                    y_player += y_tmp + x_tmp;
                    y_tmp = 0;
                    x_tmp = 0;
                    x_flag = true;
                }
                y_tmp = max(card[j].second, y_tmp);
                y_flag = false;
            }
            else if(card[j].first == 'K' && !y_flag){
                x_tmp = max(card[j].second, x_tmp);
                x_flag = false;
            }
        }

        //K로 끝날경우 마지막 경우를 더해준다
        if(y_flag != true && x_flag == false)
            y_player += y_tmp + x_tmp;

        y_tmp = 0;
        x_tmp = 0;
        y_flag = true;
        x_flag = true;

        //x_player에 대한 점수계산
        for (int j = l - 1; j <= r - 1; j++) {
            if (card[j].first == 'K') {
                if (x_flag == false) {
                    k_player += y_tmp + x_tmp;
                    y_tmp = 0;
                    x_tmp = 0;
                    x_flag = true;
                }
                y_tmp = max(card[j].second, y_tmp);
                y_flag = false;
            }
            else if (card[j].first == 'Y' && !y_flag) {
                x_tmp = max(card[j].second, x_tmp);
                x_flag = false;
            }
        }

        //Y로 끝날경우 마지막 경우를 더해준다
        if (y_flag != true && x_flag == false)
            k_player += y_tmp + x_tmp;
        
        if (y_player > k_player)
            cout << "Y " << y_player << endl;
        else if (y_player < k_player)
            cout << "K " << k_player << endl;
        else
            cout << "YK " << y_player << endl;

        y_player = 0;
        k_player = 0;
    }
    return 0;
}