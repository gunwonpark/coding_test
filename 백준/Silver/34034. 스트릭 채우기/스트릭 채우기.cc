#include <iostream>
#include <vector>
#include <algorithm>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

int main() {
    FAST;

    int n;
    ll m, k; // M과 K는 N*d_i의 합만큼 커질 수 있으므로 long long이 안전할 수 있습니다.
    cin >> n >> m >> k;
    int target_k = k; // 원래 K값을 저장

    vector<pair<int, int>> problems(n);
    for (int i = 0; i < n; i++) {
        cin >> problems[i].first;  // 걸리는 날짜
        problems[i].second = i + 1; // 원래 문제 번호
    }

    // 걸리는 날짜(d_i) 기준으로 오름차순 정렬
    sort(problems.begin(), problems.end());

    vector<int> answer;
    
    // 가장 짧은 문제부터 해결 시도
    for (int i = 0; i < n; i++) {
        int days_needed = problems[i].first;
        int problem_id = problems[i].second;
        int freezes_needed = days_needed - 1;

        // 이 문제를 해결할 자원(날짜, 프리즈)가 충분한지 확인
        if (k >= days_needed && m >= freezes_needed) {
            // 자원을 한 번에 소모
            k -= days_needed;
            m -= freezes_needed;

            // 정답 배열에 기록
            for (int j = 0; j < freezes_needed; j++) {
                answer.push_back(0);
            }
            answer.push_back(problem_id);
        } else {
            // 이 문제조차 해결 못하면 더 긴 문제는 볼 필요 없음
            break;
        }
    }

    // 문제를 다 쓰고도 채워야 할 날짜가 남았다면 남은 프리즈로 채운다.
    if (k > 0 && m > 0) {
        int fill_with_freezes = min((ll)k, m);
        for (int i = 0; i < fill_with_freezes; i++) {
            answer.push_back(0);
        }
    }
    
    // 최종적으로 K일을 채웠는지 확인
    if (answer.size() < target_k) {
        cout << -1;
    } else {
        // target_k 만큼만 출력해야 함 (프리즈를 더 많이 쓸 수 있는 경우 방지)
        for (int i = 0; i < target_k; i++) {
            cout << answer[i] << " ";
        }
    }
    
    cout << "\n";

    return 0;
}