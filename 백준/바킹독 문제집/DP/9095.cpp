#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int dp[12] = { 0, };

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= 10; i++) dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;

		cout << dp[N] << "\n";
	}

	return 0;
}
