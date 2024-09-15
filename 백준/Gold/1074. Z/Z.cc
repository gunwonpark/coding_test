#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<queue>

#define Fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

typedef long long ll;

int n, r, c;
ll result = 0;

void solve(int xStart, int xEnd, int yStart , int yEnd ,int length) {
    if (length == 1) {
        return;
    }

    int midX = (xStart + xEnd) / 2;
    int midY = (yStart + yEnd) / 2;

    int size = length * length / 4;

    //1사분면
    if (r <= midY && c <= midX) {
        solve(xStart, midX, yStart, midY, length / 2);
    }
    //2사분면
    else if (r <= midY && c > midX) {
        result += size;
        solve(midX + 1, xEnd, yStart, midY, length / 2);
	}
	//3사분면
    else if (r > midY && c <= midX) {
		result += size * 2;
        solve(xStart, midX, midY + 1, yEnd, length / 2);
	}
	//4사분면
    else {
		result += size * 3;
        solve(midX + 1, xEnd, midY + 1, yEnd, length / 2);
	}
   
    
}


int main() {    
    cin >> n >> r >> c;
    int length = 1 << n;
    solve(0, length - 1, 0, length - 1, length);

    cout << result;
    return 0;
}