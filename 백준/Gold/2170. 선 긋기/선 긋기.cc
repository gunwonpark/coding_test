#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, left, right, result = 0;
	int x, y;
	vector<pair<int,int>> v;

	cin >> N;

	v.reserve(N);

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x,y));
	}

	//백터 정렬 x의 값에 대하여 오름차순으로 정렬
	sort(v.begin(), v.end(), [](pair<int, int>a, pair<int, int>b) {return a.first < b.first;});

	//선분 길이 계산
	left = v[0].first;
	right = v[0].second;

	for (int i = 0; i < N; i++) {
		int _left = v[i].first;
		int _right = v[i].second;
	
		if (_left <= right) {
			right = max(right, _right);
		}
		//선분이 끈어진 경우 새롭게 선분 배정
		else {
			result += right - left;
			left = _left;
			right = _right;
		}
	}
	result += right - left;

	cout << result;
}

