#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;

	vector<vector<long long int>> dp(n, vector<long long int>(m, 0));
	vector<vector<long long int>> puddleCheck(n, vector<long long int>(m, 0));

	for (int i = 0; i < puddles.size(); i++) {
		puddleCheck[puddles[i][1] - 1][puddles[i][0] - 1] = 1; // x,y 반대로 생각하기!
	}

	dp[0][0] = 0;

	for (int i = 1; i < n; i++) {
		if (puddleCheck[i][0] == 1) break;
		dp[i][0] = 1;
	}

	for (int j = 1; j < m; j++) {
		if (puddleCheck[0][j] == 1) break;
		dp[0][j] = 1;
	}


	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (puddleCheck[i][j] == 0) {
				if (i - 1 >= 0) {
					if (puddleCheck[i - 1][j] == 0) {
						dp[i][j] += dp[i - 1][j] % 1000000007;
					}
				}
				if (j - 1 >= 0) {
					if (puddleCheck[i][j - 1] == 0) {
						dp[i][j] += dp[i][j - 1] % 1000000007;
					}
				}

				dp[i][j] = dp[i][j] % 1000000007;
			}

		}
	}

	answer = dp[n - 1][m - 1];


	return answer;
}

// (0,0) 제외한 0행과 0열의 좌표들은 모두 1의 값을 가진다
// 자신의 위치에서 ( 위쪽 좌표의 값 + 왼쪽 좌표의 값 ) 
