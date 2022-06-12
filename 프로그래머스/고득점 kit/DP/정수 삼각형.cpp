#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = 0;

	vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), 0));

	//vector<int> first;
	//first.push_back(triangle[0][0]);
	//dp.push_back(first);

	dp[0][0] = triangle[0][0];

	//cout << dp[0][0] << "\n";

	for (int i = 1; i < triangle.size(); i++) {
		int currentHeight = i;

		for (int j = 0; j <= currentHeight; j++) {
			if (j == 0) {
				dp[currentHeight][0] = dp[currentHeight - 1][0] + triangle[currentHeight][0];
			}
			else if (j > 0 && j < currentHeight) {
				dp[currentHeight][j] = max(dp[currentHeight - 1][j - 1], dp[currentHeight - 1][j]) + triangle[currentHeight][j];
			}
			else {
				dp[currentHeight][currentHeight] = dp[currentHeight - 1][currentHeight - 1] + triangle[currentHeight][currentHeight];
			}
		}

	}

	sort(dp[triangle.size() - 1].begin(), dp[triangle.size() - 1].end());
	answer = dp[triangle.size() - 1][triangle.size() - 1];

	return answer;
}