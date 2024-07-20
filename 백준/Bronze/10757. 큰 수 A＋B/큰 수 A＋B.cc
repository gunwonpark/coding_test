#include <iostream>
#include <vector>
#include <string>

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;

using namespace std;

struct BigInteger {
    vector<ll> nums;
    static const short maxLen = 18;
    static const ll base = 1000000000000000000LL;

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
        int maxSize = max(nums.size(), b.nums.size());
        int minSize = min(nums.size(), b.nums.size());
        ll carry = 0;

        for (int i = 0; i < minSize; i++) {
            ll sum = nums[i] + b.nums[i] + carry;
            carry = sum / base;
            sum %= base;
            result.nums.push_back(sum);
        }

        for (int i = minSize; i < maxSize; i++) {
            if (i < nums.size()) {
                ll sum = nums[i] + carry;
                carry = sum / base;
                sum %= base;
                result.nums.push_back(sum);
            } else {
                ll sum = b.nums[i] + carry;
                carry = sum / base;
                sum %= base;
                result.nums.push_back(sum);
            }
        }

        if (carry != 0) {
            result.nums.push_back(carry);
        }

        return result;
    }

    void Print() const {
        if (nums.empty()) {
            cout << "0";
            return;
        }
        cout << nums.back();
        for (int i = nums.size() - 2; i >= 0; i--) {
            cout.width(maxLen);
            cout.fill('0');
            cout << nums[i];
        }
        cout << endl;
    }
};

int main() {
    FAST;

    string a, b;
    cin >> a >> b;
    BigInteger N(a);
    BigInteger M(b);

    BigInteger result = N + M;

    result.Print();

    return 0;
}