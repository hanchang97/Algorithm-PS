#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 1;

	deque<pair<int, int>> dq; // <우선순위 값, location 값>

	for (int i = 0; i < priorities.size(); i++) {
		dq.push_back({ priorities[i], i });
	}


	while (true) {
		int current = dq[0].first; // 맨 앞 원소의 우선순위
		bool isPrintPossible = true;

		for (int i = 1; i < dq.size(); i++) {
			if (current < dq[i].first) { // 자기보다 하나라도 크면 false
				isPrintPossible = false;
				break;
			}
		}

		if (isPrintPossible) {
			if (dq[0].second == location) { // 찾으려는 location 과 일치 시 리턴
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