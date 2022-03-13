#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 1;

	deque<pair<int, int>> dq; // <�켱���� ��, location ��>

	for (int i = 0; i < priorities.size(); i++) {
		dq.push_back({ priorities[i], i });
	}


	while (true) {
		int current = dq[0].first; // �� �� ������ �켱����
		bool isPrintPossible = true;

		for (int i = 1; i < dq.size(); i++) {
			if (current < dq[i].first) { // �ڱ⺸�� �ϳ��� ũ�� false
				isPrintPossible = false;
				break;
			}
		}

		if (isPrintPossible) {
			if (dq[0].second == location) { // ã������ location �� ��ġ �� ����
				return answer;
			}
			else {
				answer++;
				dq.pop_front();
			}
		}
		else {
			int first = dq[0].first;
			int second = dq[0].second;
			dq.pop_front();
			dq.push_back({ first, second });
		}

	}
}