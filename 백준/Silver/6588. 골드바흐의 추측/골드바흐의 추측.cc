#include <bits/stdc++.h>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;

bool arr[1000001];
vector<int> primes;

bool isPrime(int n) {
	if (arr[n]) return false;
	return true;
}


void preCalc() {
	arr[1] = true;

	int n = sqrt(1000000);
	for (int i = 2; i <= n; i++) {
		if (!arr[i]) {
			primes.push_back(i);
			for (int j = i * i; j <= 1000000; j += i) {
				arr[j] = true;
			}
		}
	}
}


int main() {
	FAST;

	fill(arr, arr + 1000001, false);

	preCalc();
	
	while (true) {
		int n; cin >> n;
		if (n == 0) break;

		for (int i = 1; i < primes.size(); i++) {
			int prime = primes[i];
			int left = n - prime;

			if (left < prime) break;

			if (isPrime(left)) {
				cout << n << " = " << prime << " + " << left << "\n";
				break;
			}
		}
	}

	


    return 0;
}