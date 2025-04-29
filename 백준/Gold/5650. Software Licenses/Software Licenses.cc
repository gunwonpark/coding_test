#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<double> prices(n);
    vector<double> rates(n);
    
    // 라이센스 정보 입력
    for (int i = 0; i < n; i++) {
        cin >> prices[i] >> rates[i];
    }
    
    double totalCost = 0.0;
    vector<bool> purchased(n, false);
    
    // 각 월마다 구매할 라이센스 결정
    for (int month = 0; month < n; month++) {
        int bestIndex = -1;
        double maxSavings = -1.0;
        
        // 아직 구매하지 않은 모든 라이센스를 검사
        for (int i = 0; i < n; i++) {
            if (!purchased[i]) {
                // 이 라이센스를 한 달 더 기다릴 경우의 추가 비용 계산
                double currentPrice = prices[i] * pow(rates[i], month);
                double nextMonthPrice = prices[i] * pow(rates[i], month + 1);
                double savings = nextMonthPrice - currentPrice;
                
                // 가장 많은 절약을 할 수 있는 라이센스 선택
                if (savings > maxSavings) {
                    maxSavings = savings;
                    bestIndex = i;
                }
            }
        }
        
        // 선택한 라이센스 구매
        double cost = prices[bestIndex] * pow(rates[bestIndex], month);
        totalCost += cost;
        purchased[bestIndex] = true;
    }
    
    // 결과 출력 (소수점 2자리까지)
    cout << fixed << setprecision(2) << totalCost << endl;
    
    return 0;
}