#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <cmath>
#include <string>

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;

using namespace std;


struct BigInteger {
	vector<ll> nums;
	short maxLen = 18;
	ll delimeter = 1000000000000000000;

	BigInteger() {}

	BigInteger(string s) {
		int len = s.length();

		while (len >= maxLen) {
			nums.push_back(stoll(s.substr(len - maxLen, maxLen)));
			len -= maxLen;
		}

		if (len > 0) {
			nums.push_back(stoll(s.substr(0, len)));
		}
	}

	BigInteger operator+(const BigInteger& b) const {
		BigInteger result;
		int maxLen = max(nums.size(), b.nums.size());
		int minLen = min(nums.size(), b.nums.size());
		int carry = 0;

		for (int i = 0; i < minLen; i++) {
			result.nums.push_back(nums[i] + b.nums[i] + carry);
			carry = result.nums[i] / delimeter;
			result.nums[i] %= delimeter;
		}
		
		for (int i = minLen; i < maxLen; i++) {
			if (nums.size() > b.nums.size()) {
				result.nums.push_back(nums[i]);
			}
			else {
				result.nums.push_back(b.nums[i]);
			}
			result.nums[i] += carry;
			carry = result.nums[i] / delimeter;
			result.nums[i] %= delimeter;
		}

		if (carry != 0) {
			result.nums.push_back(carry);
		}

		return result;
	}

	void Print() {
		for (int i = nums.size() - 1; i >= 0; i--) {
			if (i == nums.size() - 1) {
				cout << nums[i];
			}
			else {
				cout.width(maxLen);
				cout.fill('0');
				cout << nums[i];
			}
		}
	}

};

int main() {
	FAST;

	BigInteger N, M;
	string a, b;
	cin >> a >> b;
	N = BigInteger(a);
	M = BigInteger(b);
	
	BigInteger result = N + M;

	result.Print();

	return 0;
}


