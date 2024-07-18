#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <cmath>

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;

using namespace std;

float GetScore(string grade) {
	if (grade == "A+") {
		return 4.5;
	}
	else if (grade == "A0") {
		return 4.0;
	}
	else if (grade == "B+") {
		return 3.5;
	}
	else if (grade == "B0") {
		return 3.0;
	}
	else if (grade == "C+") {
		return 2.5;
	}
	else if (grade == "C0") {
		return 2.0;
	}
	else if (grade == "D+") {
		return 1.5;
	}
	else if (grade == "D0") {
		return 1.0;
	}
	else if (grade == "F") {
		return 0.0;
	}
	return 0.0;
}

int main() {
	FAST;
	string name;
	float score;
	string grade;
	float res = 0;
	int count = 0;
	for (size_t i = 0; i < 20; i++)
	{
		cin >> name >> score >> grade;
		
		if (grade != "P") {
			float tScore = GetScore(grade);;
			res += tScore * score;
			count += score;
		}
	}

	cout << fixed;
	cout.precision(5);	
	cout << res / count << "\n";

	return 0;
}


