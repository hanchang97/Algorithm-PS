#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int arrTime[25] = {0};
	int arrProfit[25] = {0};
	int dp[25] = {0};

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int t, p;
		cin >> t;
		cin >> p;

		arrTime[i] = t;
		arrProfit[i] = p;
	}

	for (int i = N; i > 0; i--)
	{
		int curT = arrTime[i];
		int curP = arrProfit[i];

		if (i + curT - 1 > N)
		{
			dp[i] = dp[i + 1];
		}
		else
		{
			dp[i] = (curP + dp[i + curT] >= dp[i + 1]) ? curP + dp[i + curT] : dp[i + 1];
		}
	}

	cout << dp[1];

	return 0;
}