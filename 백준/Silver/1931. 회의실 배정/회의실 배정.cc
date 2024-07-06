#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);    

    int n;
    cin >> n;

    vector<pair<int, int>> vec(n);

    for (int i = 0; i < n; ++i)
    {
		cin >> vec[i].first >> vec[i].second;
	}


    sort(vec.begin(), vec.end(), [](pair<int, int>& a, pair<int, int>& b) {
        if (a.first == b.first) {
				return a.second > b.second;
			}
        return a.first > b.first;
        });

    int res = 1;

    int end = vec[0].first;

    for(size_t i = 1; i < vec.size(); ++i)
    {
        if (vec[i].second <= end) {
            end = vec[i].first;
            res++;
        }
	}
    
    cout << res << '\n';

	return 0;
}



