#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <cmath>
#include <string>
#include <map>

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;

using namespace std;

int n;
char input;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

struct Value {
	ll denominator; // 분모
	ll numerator; // 분자

	Value(ll _denominator, ll _numerator) {
		denominator = _denominator;
		numerator = _numerator;

		ll _gcd = gcd(denominator, numerator);
		denominator /= _gcd;
		numerator /= _gcd;
	}

	Value operator+(const Value& v) {
		ll _lcm = lcm(denominator, v.denominator);
		return Value(_lcm, numerator * (_lcm / denominator) + v.numerator * (_lcm / v.denominator));
	}
	Value operator/(const Value& v) {
		return Value(denominator * v.numerator, numerator * v.denominator);
	}
};


int main() {
	FAST; 	

	cin >> n;

	stack<Value> _stack;
	for (int i = 0; i < n; ++i) {
		cin >> input;
		if (input == ')') {
			if (_stack.size() < 3) {
				cout << -1 << endl;
				return 0;
			}
			Value a = _stack.top();
			_stack.pop();
			Value b = _stack.top();
			_stack.pop();
			Value c = _stack.top();
			_stack.pop();

			Value result = c + b / a;

			_stack.push(result);
		}
		else if (input != '(') {
			_stack.push(Value(1, (ll)(input - '0')));
		}
	}

	if (_stack.size() > 1) {
		cout << -1 << endl;
		return 0;
	}
	else {
		cout << _stack.top().numerator << " " << _stack.top().denominator << endl;
	}


	return 0;
}


