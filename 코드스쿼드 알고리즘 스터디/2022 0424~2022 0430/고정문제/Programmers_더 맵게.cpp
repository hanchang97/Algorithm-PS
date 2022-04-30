#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;

	priority_queue<int, vector<int>, greater<int>> pq; // �ּ���

	for (int i = 0; i < scoville.size(); i++) {
		pq.push(scoville[i]);
	}

	bool isPossible = false;
	while (!pq.empty()) {
		if (pq.top() >= K) { // �ּҰ��� K �̻��̸� �� �̻� ���� �ʾƵ� ��
			isPossible = true;
			break;
		}
		else if (pq.size() <= 1) {  // �ּҰ��� K���� ������ �� �̻� ���� �� ���� ���
			break;
		}
		else { // ����
			int food1 = pq.top();
			pq.pop();
			int food2 = pq.top();
			pq.pop();
			pq.push(food1 + food2 * 2);
			answer++;
		}
	}

	if (!isPossible) answer = -1;

	return answer;
}