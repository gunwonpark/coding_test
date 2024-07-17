#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <map>
#include <cmath>

#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;

using namespace std;

int n, m;

vector<int> parent;
vector<bool> isParent;

int FindParent(int a) {
    int curIndex = a;
    int parentIndex;
    stack<int> path;
    while (true) {
        path.push(curIndex);
        if (parent[curIndex] == curIndex) {
            while (!path.empty()) {
                int top = path.top();
                path.pop();
                parent[top] = curIndex;
            }
            return curIndex;
        }
        parentIndex = parent[curIndex];
        curIndex = parentIndex;
    }
}


int main() {
    FAST;    
    
    scanf("%d %d", &n, &m);

    parent.resize(n + 1);

    for (int i = 0; i < n + 1; i++) {
        parent[i] = i;
	}


    for (int i = 0; i < m; i++) {
		int key, a, b;
		scanf("%d %d %d", &key, &a, &b);

        int aParent = FindParent(a);
        int bParent = FindParent(b);

        if (key == 0) {
            if (aParent != bParent) {
				parent[bParent] = aParent;
			}
        }
        else {
            if (aParent != bParent) {
                printf("NO\n");
            }
            else {
                printf("YES\n");
            }
        }
	}

    return 0;
}


