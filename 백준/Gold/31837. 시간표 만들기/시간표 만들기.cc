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

struct lecture {
	int s_h;
	int s_m;
	int e_h;
	int e_m;
	int score;
};

vector<vector<vector<lecture>>> arr;
vector<vector<lecture>> temp;
vector<bool> visited;
int tScore = 0;
int answer = 0;
int n;

bool can_add(lecture _lec, int day) {
	for (size_t i = 0; i < temp[day].size(); i++)
	{
		if (_lec.s_h > temp[day][i].e_h || ( _lec.s_h == temp[day][i].e_h && _lec.s_m >= temp[day][i].e_m)) {
			continue;
		}
		else if (_lec.e_h < temp[day][i].s_h || (_lec.e_h == temp[day][i].s_h && _lec.e_m <= temp[day][i].s_m)) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}

void solution(int day, int group, int _tScore) {
	if (day == 8) {
		if (_tScore == 22) {
			answer++;
		}
		return;
	}

	if (group == n + 1) {
		solution(day + 1, 1, _tScore);
		return;
	}

	if (visited[group] == true) {
		solution(day, group + 1, _tScore);
		return;
	}

	if (arr[day][group].size() == 1) {
		solution(day, group + 1, _tScore);
		return;
	}
	//day 1
	for (size_t i = 0; i < arr[day][group].size(); i++)
	{
		if (!can_add(arr[day][group][i], day)) {
			continue;
		}
		if (i != 0) {
			temp[day].push_back(arr[day][group][i]);
			visited[group] = true;
		}
		_tScore += arr[day][group][i].score;
		
		solution(day, group + 1, _tScore);
		_tScore -= arr[day][group][i].score;
		if (i != 0) {
			temp[day].pop_back();
			visited[group] = false;
		}
	}

	return;
}

int main() {
	FAST; 	

	cin >> n;

	arr.resize(8, vector<vector<lecture>>(n + 1, vector<lecture>(1)));
	for (size_t i = 1; i < 8; i++)
	{
		for (size_t j = 1; j <= n; j++)
		{
			arr[i][j][0] = { 0, 0, 0, 0, 0 };
		}
	}

	visited.resize(n + 1, false);
	temp.resize(8);
	for (size_t i = 1; i <= n; i++)
	{
		int subjects;
		cin >> subjects;

		for (size_t j = 1; j <= subjects; j++)
		{
			int score, day;
			string start, end;
			cin >> score >> day >> start >> end;
			int start_h = stoi(start.substr(0, 2));
			int start_m = stoi(start.substr(3, 2));
			int end_h = stoi(end.substr(0, 2));
			int end_m = stoi(end.substr(3, 2));

			arr[day][i].push_back({ start_h, start_m, end_h, end_m, score });
		}
	}

	solution(1, 1, 0);

	cout << answer << endl;

	return 0;
}


