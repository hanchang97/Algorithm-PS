#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;

	deque<pair<int, int>> dq; // < location(inx), priority >

	for (int i = 0; i < priorities.size(); i++) {
		dq.push_back({ i, priorities[i] });
	}

	vector<pair<int, int>> sortedV; // �μ� ������ ���� ���ĵ� ����

	while (!dq.empty()) {

		int isPrintPossible = true;
		for (int i = 1; i < dq.size(); i++) {
			if (dq[0].second < dq[i].second) {
				isPrintPossible = false;
				break;
			}
		}

		if (isPrintPossible) {
			sortedV.push_back({ dq[0].first, dq[0].second });
			dq.pop_front();
		}
		else {
			dq.push_back({ dq[0].first, dq[0].second });
			dq.pop_front();
		}

	}
	 
	for (int i = 0; i < sortedV.size(); i++) { // sortedV ���� '�ε��� + 1' �� �� �μ� ����
		if (sortedV[i].first == location) return i + 1;
	}

}