#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

struct Point {
    int x, y;

	Point() : x(0), y(0) {}
	Point(int x, int y) : x(x), y(y) {}
    
    ll Dist(const Point &p) const {
        return (ll)(x - p.x) * (x - p.x) + (ll)(y - p.y) * (y - p.y);
	}

};

bool CompareX(const Point &a, const Point &b) {
    return a.x < b.x;
}

bool CompareY(const Point &a, const Point &b) {
    return a.y < b.y;
}


int n;
vector<Point> points;

ll Find(int start, int end)
{
    if (end - start <= 3)
    {
        ll minDist = 1e18;
        for (int i = start; i <= end; i++)
            for (int j = i + 1; j <= end; j++)
				minDist = min(minDist, points[i].Dist(points[j]));

		return minDist;
    }

	int mid = (start + end) / 2;
	ll leftDist = Find(start, mid);
	ll rightDist = Find(mid + 1, end);
	ll minDist = min(leftDist, rightDist);

    vector<Point> temp;
    for (int i = start; i <= end; i++)
    {
		ll dx = (ll)points[i].x - points[mid].x;
        if (dx * dx < minDist)
        {
			temp.push_back(points[i]);
        }
    }

	sort(temp.begin(), temp.end(), CompareY);
    for (int i = 0; i < temp.size(); i++)
    {
        for (int j = i + 1; j < temp.size(); j++)
        {
			ll dy = (ll)temp[j].y - temp[i].y;
            if (dy * dy >= minDist) break;
		    minDist = min(minDist, temp[i].Dist(temp[j]));
        }
    }

    return minDist;
}

int main() {
    FAST;

	cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back({ x, y });
	}

	sort(points.begin(), points.end(), CompareX);
    
    ll answer = Find(0, n - 1);

	cout << answer;

    return 0;
}
