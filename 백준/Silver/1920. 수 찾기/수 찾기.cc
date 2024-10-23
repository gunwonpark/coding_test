#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    unordered_map<int, bool> numbers;
    
    for(int i = 0; i < n; i++){
        int number;
        cin >> number;
        numbers[number] = true;
    }
    
    int m;
    cin >> m;
    
    for(int i = 0; i < m; i++){
        int number;
        cin >> number;
        if(numbers.find(number) != numbers.end()){
            cout << 1 << '\n';
        }
        else{
            cout << 0 << '\n';
        }
    }
    
    
    return 0;
}