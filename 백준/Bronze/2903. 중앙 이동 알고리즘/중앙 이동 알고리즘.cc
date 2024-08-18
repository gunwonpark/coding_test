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
#include <set>

#define FAST ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
typedef long long ll;

using namespace std;


int n;


int main() {
	FAST; 	

	cin >> n;

	cout << (ll)pow((1 + pow(2, n)), 2);
	return 0;
}


