//(top down O(2W)).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int max(int a, int b);
int knapsack(int n, int W);

int w[] = { 2,3,4,5 };
int v[] = { 1,4,5,7 };
int DP[2][7];

int main()
{
	memset(DP, 0, sizeof(DP));
	cout << knapsack(4, 7);
}

int knapsack(int n, int W)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			if (i % 2 == 0)
			{
				if (w[i] > j)
				{
					DP[1][j] = DP[0][j];
				}
				else
					DP[1][j] = max(v[i] + DP[0][j - w[i]], DP[0][j]);
			}
			else
			{
				if (w[i] > j)
					DP[0][j] = DP[1][j];
				else
					DP[0][j] = max(v[i] + DP[1][j - w[i]], DP[1][j]);
			}
		}
	}
	if (n % 2 == 0)
		return DP[1][W];
	else
		return DP[0][W];
}

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}