#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 소수 여부를 판단하기 위한 에라토스테네스의 체 함수
vector<bool> sieve(int limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= sqrt(limit); i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

int main() {
    int N, M;
    cin >> N >> M;

    const int LIMIT = 2000000;
    vector<bool> is_prime = sieve(LIMIT);

    // 소수가 아닌 수를 저장할 벡터
    vector<int> non_primes;
    for (int i = 1; i <= LIMIT; i++) {
        if (!is_prime[i]) {
            non_primes.push_back(i);
        }
    }

    // 등차수열을 찾기 위한 시도
    for (int i = 0; i < non_primes.size(); i++) {
        bool found = true;
        vector<int> sequence;
        for (int j = 0; j < N; j++) {
            int term = non_primes[i] + j * M;
            if (term > LIMIT || is_prime[term]) {
                found = false;
                break;
            }
            sequence.push_back(term);
        }
        if (found) {
            for (int k = 0; k < sequence.size(); k++) {
                cout << sequence[k] << (k == sequence.size() - 1 ? "\n" : " ");
            }
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}