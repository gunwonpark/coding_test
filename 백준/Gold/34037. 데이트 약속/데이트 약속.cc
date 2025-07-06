#include <bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

using namespace std;

int n, m;

vector<pair<int, int>> curse;
// i를 포함하지 않았을때 가능한 최대 값
vector<ll> rightValue;
// 모두다 포함했을 경우 값
vector<ll> leftValue;
vector<ll> sumValue;

ll answer = 0;

ll getValue(int index, ll subValue)
{
	if (index == m - 1) {
		return sumValue[n - curse[m - 2].first] - subValue;
	}

	int nextIndex = index + 1;
	int nextPos = curse[nextIndex].first;
	ll nextValue = curse[nextIndex].second;

	int curPos = curse[index].first;
	ll curValue = curse[index].second;

	// 다음 인덱스를 포함하지 않았을때 최대값
	ll firstValue = sumValue[nextPos - curPos - 1] + rightValue[nextPos] - subValue;
	// 다음 인덱스를 포함했을때 최대값
	ll secondValue = getValue(nextIndex, subValue + nextValue);

	return max(firstValue, secondValue);
}

void solve()
{
	for (int i = m - 1; i >= 0; i--)
	{
		int index = curse[i].first;
		ll value = curse[i].second;

		// i를 포함하지 않았을 때 가능한 최대 값
		if (i == curse.size() - 1)
		{
			ll r_value = sumValue[n - index];
			ll l_value = leftValue[index];
			rightValue[index] = r_value;
			answer = max(answer, r_value + l_value);
		}
		else {
			ll r_value = getValue(i, 0);
			ll l_value = leftValue[index];

			rightValue[index] = r_value;
			answer = max(answer, r_value + l_value);
		}
	}
}

int main()
{
	FAST;

	cin >> n >> m;

	sumValue.resize(n + 1, 0);
	rightValue.resize(n + 1, 0);
	leftValue.resize(n + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		sumValue[i] = sumValue[i - 1] + i;
	}

	for (int i = 0; i < m; i++)
	{
		ll index, value; cin >> index >> value;
		curse.push_back({ index, value });
	}

	ll subValue = 0;

	for (int i = 0; i < m; i++)
	{
		ll index, value;
		index = curse[i].first;
		value = curse[i].second;
		
		leftValue[index] = sumValue[index - 1] - subValue;
		subValue += value;
	}

	// 모두다 소화했을경우 값
	answer = sumValue[n] - subValue;
	
	solve();

	cout << answer;
	return 0;
}

