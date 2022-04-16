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

	vector<pair<int, int>> sortedV; // ÀÎ¼â ¼ø¼­¿¡ µû¶ó Á¤·ÄµÈ º¤ÅÍ

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
	 
	for (int i = 0; i < sortedV.size(); i++) { // sortedV ¿¡¼­ 'ÀÎµ¦½º + 1' ´Â °ð ÀÎ¼â ¼ø¼­
		if (sortedV[i].first == location) return i + 1;
	}

}