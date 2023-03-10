//(top down memoization).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int max(int a, int b);
int knapsack(int n, int W);

int w[] = { 2,3,4,5 };
int v[] = { 1,4,5,7 };
int DP[4][7];

int main()
{
	memset(DP[0], -1, sizeof(DP[0]));

	cout << knapsack(3, 7) << endl<<endl;
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j <= 7; j++)
			cout << DP[i][j] << " ";
		cout << endl;
	}
	cout << endl << endl;
}

int knapsack(int n, int W)
{
	static int count = 0;
	if (DP[n][W] >= 0)
		return DP[n][W];
	
	if (n == 0 || W == 0)
		return DP[n][W] = max(0,v[0]);
	else if(w[n]>W)
		return DP[n][W] = knapsack(n - 1, W);
		
	return DP[n][W] = max(knapsack(n - 1, W - w[n]) + v[n], knapsack(n - 1, W));
}

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}