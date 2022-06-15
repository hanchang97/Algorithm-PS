#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> money) {  // money 의 크기는 3 이상 !
	int answer = 0;

	int mSize = money.size();

	vector<int> dp1(money.size(), 0);
	vector<int> dp2(money.size(), 0);
	vector<int> dp3(money.size(), 0);
	vector<int> dp4(money.size(), 0);


	dp1[0] = money[0];
	dp1[1] = money[0];

	dp2[1] = money[1];
	dp2[2] = money[1];

	dp3[mSize - 1] = money[mSize - 1];
	dp3[mSize - 2] = money[mSize - 1];

	dp4[mSize - 2] = money[mSize - 2];
	dp4[mSize - 3] = money[mSize - 2];

	for (int i = 2; i < money.size() - 1; i++) {
		dp1[i] = max(dp1[i - 2] + money[i], dp1[i - 1]);
	}

	for (int i = 3; i < money.size(); i++) {
		dp2[i] = max(dp2[i - 2] + money[i], dp2[i - 1]);
	}

	for (int i = mSize - 3; i > 0; i--) {
		dp3[i] = max(dp3[i + 2] + money[i], dp3[i + 1]);
	}

	for (int i = mSize - 4; i >= 0; i--) {
		dp4[i] = max(dp4[i + 2] + money[i], dp4[i + 1]);
	}

	answer = max(dp1[money.size() - 2], dp2[money.size() - 1]);

	vector<int> result;
	result.push_back(dp1[mSize - 2]);
	result.push_back(dp2[mSize - 1]);
	result.push_back(dp3[1]);
	result.push_back(dp4[0]);

	sort(result.begin(), result.end());
	answer = result[3];

	return answer;
}