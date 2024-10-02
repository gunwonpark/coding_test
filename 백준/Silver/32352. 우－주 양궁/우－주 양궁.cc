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
int xl, xh, yl, yh, zl, zh, xl2, xh2, yl2, yh2, zl2, zh2;

bool isOut(){
	if(xh <= xl2 || xl >= xh2) return true;
	if(yh <= yl2 || yl >= yh2) return true;
	return false;
}

int main() {
	Fast;

	cin >> xl >> xh >> yl >> yh >> zl >> zh;
	cin >> xl2 >> xh2 >> yl2 >> yh2 >> zl2 >> zh2;

	if (isOut()) {
		cout << -1;
	}
	else {
		if (zh <= zl2) cout << -1;
		else if (zh2 > zl) cout << 0;
		else cout << zl - zh2 + 1;
	}

		
	return 0;
	
}