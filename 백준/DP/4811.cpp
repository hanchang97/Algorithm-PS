#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;


int main() {

	long long int dp[31][31] = { 0, };

	for (int i = 1; i <= 30; i++) {
		dp[0][i] = 1;
	}

	for (int i = 1; i <= 30; i++) {
		for (int j = 0; j <= 30; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j + 1];
			}
			else {
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j + 1];
			}
		}
	}


	while (1) {
		int tc;
		scanf("%d", &tc);

		if (tc == 0)
			break;

		printf("%lld\n", dp[tc][0]);
	}

	return 0;
}


//  dp문제!! 반쪽 개수, 완전체 개수를 행과 열로 해서 테이블에 memoization 하기