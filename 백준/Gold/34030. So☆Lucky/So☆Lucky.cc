#include <bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
typedef long long ll;

using namespace std;


ll GetSum(vector<ll>& culSum, int s, int e)
{
	return culSum[e + 1] - culSum[s];
}

struct Data
{
	ll index, value;
	Data() : index(0), value(0) {}
	Data(ll i, ll v) : index(i), value(v) {}
};

int main()
{
	FAST;
	int n; cin >> n;

	vector<ll> culSum(n + 1);
	// 짝수는 1 홀수는 0의 값을 가진다
	vector<Data> arr(n);
	
	int odd = 0;
	int even = 0;
	bool firstCase = true;

	for(int i = 0; i < n; i++)
	{
		ll value; cin >> value;
		arr[i] = Data(i, value);

		if (value % 2 == 0)
		{
			if (even > value)
			{
				firstCase = false;
			}
			else
			{
				even = value;
			}

			culSum[i + 1] = culSum[i] + 1;
		}
		else
		{
			if (odd > value)
			{
				firstCase = false;
			}
			else
			{
				odd = value;
			}
			culSum[i + 1] = culSum[i];
		}
	}

	sort(arr.begin(), arr.end(), [](const Data& a, const Data& b) {
		return a.value < b.value;
		});

	// 첫번째 경우 찾기 -> 홀수 홀수,  짝수 짝수 끼리는 인덱스가 역전될 수 없다
	



	// 두번째 경우 찾기 -> 홀수 짝수의 인덱스는 역전될 수가 없다
	bool secondCase = true;
	for (int i = 0; i < n; i++)
	{
		int endIndex = arr[i].index;
		int startIndex = i;

		if (endIndex < startIndex)
		{
			swap(startIndex, endIndex);
		}

		ll keyValue = arr[i].value % 2 == 0 ? 1 : 0; // 짝수면 1, 홀수면 0
		ll totalValue = GetSum(culSum, startIndex, endIndex);

		if (keyValue == 1)
		{
			if (totalValue != endIndex + 1 - startIndex)
			{
				secondCase = false;
			}
		}
		else
		{
			if (totalValue != 0)
			{
				secondCase = false;
			}
		}
	}

	cout << (firstCase ? "So Lucky" : "Unlucky") << '\n';
	cout << (secondCase ? "So Lucky" : "Unlucky") << '\n';

	return 0;
}

