#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;

	for (int i = 0; i < prices.size(); i++) answer.push_back(0);

	stack<pair<int, int>> S; // <index, value>
	S.push({ 0, prices[0] });

	for (int i = 1; i < prices.size(); i++) {
		while (true) {
			if (S.top().second > prices[i]) {
				answer[S.top().first] = i - S.top().first;  // 가격 유지 시간 값
				S.pop();
			}
			else {
				break;
			}

			if (S.empty()) break;
		}
		S.push({ i, prices[i] });
	}

	while (!S.empty()) {  // 스택에 들어간 후 가격이 계속 떨어지지 않은 것들
		answer[S.top().first] = prices.size() - 1 - S.top().first;
		S.pop();
	}

	return answer;
}