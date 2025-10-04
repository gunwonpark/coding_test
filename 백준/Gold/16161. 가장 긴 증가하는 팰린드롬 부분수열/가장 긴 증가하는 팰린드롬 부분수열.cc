#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // 입출력 속도 향상
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    if (N == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }
    
    std::vector<int> S(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> S[i];
    }

    int max_len = 1;

    // 모든 가능한 중심에 대해 탐색
    for (int i = 0; i < N; ++i) {
        // 1. 홀수 길이 팰린드롬 (중심: i)
        int l = i - 1;
        int r = i + 1;
        int current_len = 1;
        while (l >= 0 && r < N && S[l] == S[r] && S[l] < S[l + 1]) {
            current_len += 2;
            l--;
            r++;
        }
        if (current_len > max_len) {
            max_len = current_len;
        }

        // 2. 짝수 길이 팰린드롬 (중심: i, i+1)
        if (i + 1 < N && S[i] == S[i + 1]) {
            l = i - 1;
            r = i + 2;
            current_len = 2;
            while (l >= 0 && r < N && S[l] == S[r] && S[l] < S[l + 1]) {
                current_len += 2;
                l--;
                r++;
            }
            if (current_len > max_len) {
                max_len = current_len;
            }
        }
    }

    std::cout << max_len << std::endl;

    return 0;
}