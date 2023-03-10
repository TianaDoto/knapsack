//(bottom up DP O(nW)).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int knapsack(int n, int W);
int max(int a, int b);

int w[] = { 2,3,4,5 };
int v[] = { 1,4,5,7 };
int DP[4][7];

int main()
{
	//memset(DP[0], 0, sizeof(DP[0]));
	cout << knapsack(3, 7) << endl << endl;
	for (int i = 0; i <= 4; i++)
	{
		for (int j = 0; j <= 7; j++)
			cout << DP[i][j] << " ";
		cout << endl;
	}

}

int knapsack(int n, int W)
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (i == 0 || j == 0)
				DP[i][j] = 0;
			else if (w[i] > W)
			{
				DP[i][j] = DP[i - 1][j];
			}
			else
			{
				DP[i][W] = max(DP[i - 1][j - w[i]] + v[i], DP[i - 1][j]);
			}
		}
	}
	return DP[n][W];
}

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}