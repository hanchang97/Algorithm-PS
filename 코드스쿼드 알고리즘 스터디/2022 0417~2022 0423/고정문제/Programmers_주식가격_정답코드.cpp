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
				answer[S.top().first] = i - S.top().first;  // ���� ���� �ð� ��
				S.pop();
			}
			else {
				break;
			}

			if (S.empty()) break;
		}
		S.push({ i, prices[i] });
	}

	while (!S.empty()) {  // ���ÿ� �� �� ������ ��� �������� ���� �͵�
		answer[S.top().first] = prices.size() - 1 - S.top().first;
		S.pop();
	}

	return answer;
}