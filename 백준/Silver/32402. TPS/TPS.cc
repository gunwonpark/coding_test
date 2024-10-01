#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<queue>

#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

typedef long long ll;


enum Direction {
	UP = 0,
	RIGHT = 1,
	DOWN = 2,
	LEFT = 3
};

// 0 : up, 1 : right, 2 : down, 3 : left
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

int get_direction(int direction, int _dir) {
	if (direction == UP) return _dir;
	else if(direction == RIGHT) return (_dir + 1) % 4;
	else if (direction == DOWN) return (_dir + 2) % 4;
	else return (_dir + 3) % 4;
}

int change_direction(int direction, string key) {
	if(key == "MR") return (direction + 1) % 4;
	else return (direction + 3) % 4;
}

int main() {
	Fast;
	int n;
	cin >> n;

	pair<int, int> player = { 0,0 };
	pair<int, int> camera = { 0,-1 };
	int direction = UP;

	for (int i = 0; i < n; i++){
		string input;
		cin >> input;
		int _dir = 0;
		bool add_pos = true;
		if (input == "A") {
			_dir = get_direction(direction, LEFT);
		}
		else if (input == "D") {
			_dir = get_direction(direction, RIGHT);
		}
		else if (input == "S") {
			_dir = get_direction(direction, DOWN);
		}
		else if (input == "W") {
			_dir = get_direction(direction, UP);
		}
		else {
			direction = change_direction(direction, input);
			if (direction == UP) {
				camera.first = player.first;
				camera.second = player.second - 1;
			}
			else if (direction == RIGHT) {
				camera.first = player.first - 1;
				camera.second = player.second;
			}
			else if (direction == DOWN) {
				camera.first = player.first;
				camera.second = player.second + 1;
			}
			else {
				camera.first = player.first + 1;
				camera.second = player.second;
			}
			add_pos = false;
		}

		if (add_pos) {
			player.first += dir[_dir][1];
			player.second += dir[_dir][0];
			camera.first += dir[_dir][1];
			camera.second += dir[_dir][0];
		}
		

		
		cout << player.first << " " << player.second << " " << camera.first << " " << camera.second << endl;
	}
	return 0;
	
}