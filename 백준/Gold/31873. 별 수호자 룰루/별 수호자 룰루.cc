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

#define FAST ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
typedef long long ll;

using namespace std;

int n, k;

int main() {
	FAST; 	

	cin >> n >> k;
	vector<int> arr(n + 1);

	for (int i = 1; i < n + 1; ++i) {
		arr[i] = i;
	}

	int _col = n / k;

	if (k % 2 != 0) {
		if (_col == 1 || k == 1) {
			cout << "NO";
			return 0;
		}		
		else if(_col % 2 == 0){
			//짝수개 일 경우
			int _count = _col / 2;
			for (int i = 0; i < _count; ++i) {
				int first = i * k * 2 + 1;
				int second = i * k * 2 + k * 2 - 1;

				swap(arr[first], arr[second]);
			}
		}
		else {
			int _count = _col / 2;
			for (int i = 0; i < _count; ++i) {
				int first = i * k * 2 + 1;
				int second = i * k * 2 + k * 2 - 1;

				swap(arr[first], arr[second]);
			}
			int first = (_count - 1) * k * 2 + k * 2;
			int second = (_count) * k * 2 + k - 1;

			swap(arr[first], arr[second]);
		}
	}
	
	cout << "YES\n";
	for (int i = 1; i < n + 1; ++i) {
		cout << arr[i] << " ";
		if (i % k == 0) {
			cout << "\n";
		}
	}
	return 0;
}


