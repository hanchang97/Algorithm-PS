#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int n)
{
	long long dp[2010];
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = ((dp[i - 2] % 1234567) + (dp[i - 1] % 1234567)) % 1234567;
	}

	return dp[n];
}