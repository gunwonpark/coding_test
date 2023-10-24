#include <iostream>
using namespace std;
#include <string>

double Factorial(int n){
    double result = 1;
    for(int i = 1; i <= n; i++){
        result *= i;
    }
    return result;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //반복 횟수
    int n;
    cin >> n; 
    
    for(int i = 0; i < n; i++){
        //경우의수
        double result = 0;
        
        //서쪽과 동쪽의 site수
        int N ,M;
        cin >> N >> M;
        
        result = Factorial(M)/(Factorial(M-N)*Factorial(N));
        cout << stoi(to_string(result)) << "\n";
    }
    return 0;
}
