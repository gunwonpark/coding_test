#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int main() {
    FAST;
    int n, m; cin >> n >> m;
    set<int> horizontalCuts;
    set<int> verticalCuts;
    int h; cin >> h;

    for (int i = 0; i < h; i++) {
        int cut; cin >> cut;
        horizontalCuts.insert(cut);
    }
    int v; cin >> v;
    for (int i = 0; i < v; i++) {
        int cut; cin >> cut;
        verticalCuts.insert(cut);
    }

    ll answer = 1;
    int intervalCount = 0;
    int insideCount = 0;
    bool isInterval = false;
    bool isFirst = true;

    for (auto& cut : horizontalCuts)
    {
        int horizontalCut = cut;

        if (horizontalCut >= -m && horizontalCut <= m)
        {
            insideCount++;
            isInterval = true;
        }
        else
        {
            intervalCount++;
            isInterval = false;
        }

        if (isInterval)
        {
            if (isFirst)
            {
                answer += 1;
                isFirst = false;
            }
            else
            {
                answer += 2;
            }
        }
        else
        {
            answer += 1;
        }
    }

    isInterval = false;
    isFirst = true;

    for (auto& cut : verticalCuts)
    {
        int verticalCut = cut;
        if (verticalCut >= -m && verticalCut <= m)
        {
            isInterval = true;
        }
        else
        {
            isInterval = false;
        }

        if (isInterval)
        {
            if (isFirst)
            {
                if (insideCount > 0)
                {
					answer += 2 + intervalCount;
                }
                else
                {
					answer += 1 + intervalCount;
                }
                isFirst = false;
            }
            else
            {
                answer += 2 + intervalCount;
            }
        }
        else
        {
            answer += horizontalCuts.size() + 1;
        }
    }

    cout << answer << "\n";

    return 0;
}
