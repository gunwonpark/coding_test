#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count_num(int num) {
	int length = 0;
	while (num >= 1) {
		num /= 10;
		length += 1;
	}
	return length;
}

int get_max_length(int x, int y) {
	int num;

	if (abs(x) >= abs(y)) {
		if (x < 0)
			num = ((x + x) * (x + x)) + 1 + (x - y);
		else
			num = ((x + x + 1) * (x + x + 1)) - (x - y);
	}
	else {
		if (y < 0) {
			num = ((y + y) * (y + y)) + 1 + (x - y);
		}
		else {
			num = ((y + y) * (y + y)) + 1 - 2 * y - (x + y);
		}
	}

	return count_num(num);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int r1, c1, r2, c2;

	int num;

	cin >> r1 >> c1 >> r2 >> c2;

	//줄 간격을 맞추기 위한 가장 긴 수의 길이
	int max_length = max(get_max_length(r1, c1), get_max_length(r2, c2));

	//x의 값의 음양 y의 값의 음양에따라 값의 변화를 계산해 준다
	for (int x = r1; x <= r2; x++) {
		for (int y = c1; y <= c2; y++) {
			if (x == 0 && y == 0) {
				num = 1;
			}
			else {
				if (abs(x) >= abs(y)) {
					if (x < 0)
						num = ((x + x) * (x + x)) + 1 + (x - y);
					else
						num = ((x + x + 1) * (x + x + 1)) - (x - y);
				}
				else {
					if (y < 0) {
						num = ((y + y) * (y + y)) + 1 + (x - y);
					}
					else {
						num = ((y + y) * (y + y)) + 1 - 2 * y - (x + y);
					}
				}
			}
			//숫자의 간격을 맞추기위한 방법
			int temp = max_length - count_num(num);
			if (temp != 0)
				for(int i = 0; i < temp; i++)
					cout << " ";
			cout << num << " ";
		}
		if(x != r2)
			cout << endl;
	}
}

