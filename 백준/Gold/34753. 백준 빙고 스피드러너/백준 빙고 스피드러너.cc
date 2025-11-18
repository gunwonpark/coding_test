#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int main() {
	FAST;

	int n; cin >> n;
	vector<vector<int>> board(n, vector<int>(n));

	for(int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	vector<ll> rowSum(n, 0);
	vector<ll> colSum(n, 0);
	ll leftDiagonalSum = 0;
	ll rightDiagonalSum = 0;

	for(int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			rowSum[i] += board[i][j];
			colSum[j] += board[i][j];
			if (i == j) {
				leftDiagonalSum += board[i][j];
			}
			if (i + j == n - 1) {
				rightDiagonalSum += board[i][j];
			}
		}
	}

	int prevZero = 0;
	int curZero = 0;
	ll totalSum = 0;

	while(curZero < 2 * n + 2)
	{
		prevZero = curZero;
		curZero = 0;
		int x = 0, y = 0;
		int method = 0;
		ll minValue = 1e18;
		for(int i = 0; i < n; i++) {
			if (minValue > rowSum[i] && rowSum[i] != 0)
			{
				minValue = rowSum[i];
				x = i;
				method = 0;
			}
		}

		for(int i = 0; i < n; i++) {
			if (minValue > colSum[i] && colSum[i] != 0)
			{
				minValue = colSum[i];
				x = i;
				method = 1;
			}
		}

		if (leftDiagonalSum != 0 && minValue > leftDiagonalSum)
		{
			minValue = leftDiagonalSum;
			method = 2;
		}

		if (rightDiagonalSum != 0 && minValue > rightDiagonalSum)
		{
			minValue = rightDiagonalSum;
			method = 3;
		}

		totalSum += minValue;

		switch (method)
		{
			case 0:
				rowSum[x] = 0;
				for (int i = 0; i < n; i++)
				{
					if (board[x][i] != 0)
					{
						colSum[i] -= board[x][i];
						if(x == i)
						{
							leftDiagonalSum -= board[x][i];
						}
						if(x + i == n - 1)
						{
							rightDiagonalSum -= board[x][i];
						}
						board[x][i] = 0;
					}
				}
				break;
			case 1:
				colSum[x] = 0;
				for (int i = 0; i < n; i++)
				{
					if (board[i][x] != 0)
					{
						rowSum[i] -= board[i][x];
						if(i == x)
						{
							leftDiagonalSum -= board[i][x];
						}
						if(i + x == n - 1)
						{
							rightDiagonalSum -= board[i][x];
						}
						board[i][x] = 0;
					}
				}
				break;
			case 2:
				leftDiagonalSum = 0;
				for (int i = 0; i < n; i++)
				{
					if (board[i][i] != 0)
					{
						rowSum[i] -= board[i][i];
						colSum[i] -= board[i][i];
						if (i + i == n - 1)
						{
							rightDiagonalSum -= board[i][i];
						}
						board[i][i] = 0;
					}
				}
				break;
			case 3:
				rightDiagonalSum = 0;
				for (int i = 0; i < n; i++)
				{
					if (board[i][n - 1 - i] != 0)
					{
						rowSum[i] -= board[i][n - 1 - i];
						colSum[n - 1 - i] -= board[i][n - 1 - i];
						if (i + i == n - 1)
						{
							leftDiagonalSum -= board[i][n - 1 - i];
						}
						board[i][n - 1 - i] = 0;
					}
				}
				break;
		}

		for(int i = 0; i < n; i++) {
			if (rowSum[i] == 0) curZero++;
			if (colSum[i] == 0) curZero++;
		}

		if (leftDiagonalSum == 0) curZero++;
		if (rightDiagonalSum == 0) curZero++;

		for (int i = prevZero; i < curZero; i++)
		{
			cout << totalSum << '\n';
		}
	}

	return 0;
}
