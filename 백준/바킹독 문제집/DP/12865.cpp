#include<iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int table[105][100005] = { 0, };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	vector<pair<int, int>> dataV;

	for (int i = 0; i < N; i++) {
		int w, v;
		cin >> w >> v;

		dataV.push_back({ w, v });
	}

	sort(dataV.begin(), dataV.end());


	/*for (int i = 0; i < dataFilteredV.size(); i++) {
		cout << dataFilteredV[i].first << " " << dataFilteredV[i].second << "\n";
	}*/

	//
	int Max = 0;

	for (int j = 0; j <= K; j++) {
		if (j < dataV[0].first) table[0][j] = 0;
		else table[0][j] = dataV[0].second;

		if (table[0][j] > Max) Max = table[0][j];
	}

	for (int i = 1; i < dataV.size(); i++) {
		int curWeight = dataV[i].first;
		int curValue = dataV[i].second;

		for (int j = 0; j <= K; j++) {

			if (j - curWeight < 0) table[i][j] = table[i - 1][j];
			else {
				if (table[i - 1][j - curWeight] + curValue > table[i - 1][j]) table[i][j] = table[i - 1][j - curWeight] + curValue;
				else table[i][j] = table[i - 1][j];
			}

			if (table[i][j] > Max) Max = table[i][j];
		}
	}

	cout << Max;

	return 0;
}

// 전형적인 배낭 DP 문제
// 2차원 DP table 사용으로 간단하게 풀이 가능!!