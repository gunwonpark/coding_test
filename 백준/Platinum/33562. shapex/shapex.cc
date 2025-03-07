#include <bits/stdc++.h>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;

vector<vector<char>> shapes;
vector<vector<char>> colors;
vector<char> s_reg;
vector<char> c_reg;

vector<bool> isNone;

// 도형인지 판단한다
bool isShape(int index) {
    for (int i = 0; i < 4; i++) {
        bool hasBlock = false;
        for (int j = 0; j < 4; j++) {
            if (shapes[index][i * 4 + j] != '-') {
                hasBlock = true;
                break;
            }
        }
        if (hasBlock) return true; 
    }
    return false;
}

// 도형을 압축한다
void compress(int i) {
    int curFloor = 0;

    for (int iter = 0; iter < 4; iter++) {
        bool isEmpty = true;
        for (int j = 0; j < 4; j++) {
            if (shapes[i][iter * 4 + j] != '-') {
                isEmpty = false;
                break;
            }
        }

        if (!isEmpty) {
			if (curFloor == iter) {
				curFloor++;
				continue;
			}

            for (int j = 0; j < 4; j++) {
                shapes[i][curFloor * 4 + j] = shapes[i][iter * 4 + j];
				colors[i][curFloor * 4 + j] = colors[i][iter * 4 + j];

				shapes[i][iter * 4 + j] = '-';
				colors[i][iter * 4 + j] = '-';
            }

            curFloor++;
        }
    }
}

void Slice(int i, int j, int k) {
    if (isNone[i]) {
        isNone[j] = true;
        isNone[k] = true;
        return;
    }

	s_reg = shapes[i];
	c_reg = colors[i];

    for (int iter = 0; iter < 16; iter++) {
        bool isWest = iter % 4 >= 2;

        if (isWest) {
            shapes[j][iter] = s_reg[iter];
			colors[j][iter] = c_reg[iter];
			shapes[k][iter] = '-';
			colors[k][iter] = '-';
        }
        else {
			shapes[k][iter] = s_reg[iter];
			colors[k][iter] = c_reg[iter];
			shapes[j][iter] = '-';
			colors[j][iter] = '-';
        }
    }


    compress(j);
    compress(k);

	isNone[j] = false;
	isNone[k] = false;

	if (!isShape(j)) {
		isNone[j] = true;
	}

	if (!isShape(k)) {
		isNone[k] = true;
	}

}

void Rotate(int i, int j, int k) {
    if (isNone[i]) {
        isNone[j] = true;
        return;
    }

    s_reg = shapes[i];
    c_reg = colors[i];

    for (int iter = 0; iter < 16; iter++) {
        int x = iter / 4;
        int y = (iter + (4 - k)) % 4;

		shapes[j][iter] = s_reg[x * 4 + y];
		colors[j][iter] = c_reg[x * 4 + y];
    }

    isNone[j] = false;
}

void Combine(int i, int j, int k) {
    if (isNone[i] || isNone[j]) {
        isNone[k] = true;
        return;
    }
    
	s_reg = shapes[i];
	c_reg = colors[i];

    int combineFloor = -1;
 
    for (int cur_floor = 0; cur_floor < 4; cur_floor++) {
        bool canCombine = true;
        for (int floor = 3; floor >= 3 - cur_floor; floor--) {
            int downFloor = floor;
            int upFloor = floor - 3 + cur_floor;

            for (int iter = 0; iter < 4; iter++) {
                if (shapes[i][downFloor * 4 + iter] != '-' &&
                    shapes[j][upFloor * 4 + iter] != '-') {
                    canCombine = false;
                    break;
                }
            }

			if (!canCombine)
				break;
        }

        if (!canCombine)
            break;

        combineFloor = cur_floor;
    }

    for (int cur_floor = 0; cur_floor <= combineFloor; cur_floor++) {
        for (int iter = 0; iter < 4; iter++) {
            if (s_reg[(3 - combineFloor + cur_floor) * 4 + iter] == '-') {
			    s_reg[(3 - combineFloor + cur_floor) * 4 + iter] = shapes[j][cur_floor * 4 + iter];
				c_reg[(3 - combineFloor + cur_floor) * 4 + iter] = colors[j][cur_floor * 4 + iter];
            }
        }
    }

    for (int cur_floor = 0; cur_floor < 4; cur_floor++) {
        for (int iter = 0; iter < 4; iter++) {
            shapes[k][cur_floor * 4 + iter] = s_reg[cur_floor * 4 + iter];
			colors[k][cur_floor * 4 + iter] = c_reg[cur_floor * 4 + iter];
        }
    }

	isNone[k] = false;
}

void Coloring(int i, int j, char k) {
    if (isNone[i]) {
        isNone[j] = true;
        return;
    }
    
	s_reg = shapes[i];

	for (int iter = 0; iter < 16; iter++) {
		if (s_reg[iter] != '-') {
			shapes[j][iter] = s_reg[iter];
			colors[j][iter] = k;
		}
        else {
			shapes[j][iter] = '-';
			colors[j][iter] = '-';
        }
	}

	isNone[j] = false;
}

int main() {
    FAST;

    //100개의 저장소에 4 * 4 크기의 저장소가 있다.
    shapes.resize(101, vector<char>(16, '-'));
	colors.resize(101, vector<char>(16, '-'));
    s_reg.resize(16);
    c_reg.resize(16);
    isNone.resize(101, true);

    int shapeCount; cin >> shapeCount;
    int orderCount; cin >> orderCount;

    for (int i = 1; i <= shapeCount; i++) {
        isNone[i] = false;

        for (int j = 0; j < 4; j++) {
            cin >> shapes[i][j];
            cin >> colors[i][j];
        }
    }

    while (orderCount--) {
        int order, i, j; cin >> order >> i >> j;
        int i_k;
        char c_k;



        switch (order) {
        case 1:
			cin >> i_k;
            Slice(i, j, i_k);
            break;
        case 2:
			cin >> i_k;
            Rotate(i, j, i_k);
            break;
        case 3:  
			cin >> i_k;
            Combine(i, j, i_k);
            break;
        case 4:
			cin >> c_k;
            Coloring(i, j, c_k);
            break;
        }
    }

	if (isNone[100]) {
		cout << "None";
		return 0;
	}

	if (!isShape(100)) {
		cout << "None";
		return 0;
	}

    int travelCount = -1;

    for (int i = 0; i < 4; i++) {
        bool isEmpty = true;

        for (int j = 0; j < 4; j++) {
            if (shapes[100][i * 4 + j] != '-') {
                isEmpty = false;
                break;
            }
        }

        if (isEmpty)
            break;

        travelCount = i;
    }

    for (int i = 0; i <= travelCount; i++){
		for (int j = 0; j < 4; j++) {
			cout << shapes[100][i * 4 + j];
			cout << colors[100][i * 4 + j];
		}
        if (i != travelCount)
            cout << ":";
    }

    return 0;
}