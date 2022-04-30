#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;

	priority_queue<int, vector<int>, greater<int>> pq; // 최소힙

	for (int i = 0; i < scoville.size(); i++) {
		pq.push(scoville[i]);
	}

	bool isPossible = false;
	while (!pq.empty()) {
		if (pq.top() >= K) { // 최소값이 K 이상이면 더 이상 섞지 않아도 됨
			isPossible = true;
			break;
		}
		else if (pq.size() <= 1) {  // 최소값이 K보다 작은데 더 이상 섞을 수 없는 경우
			break;
		}
		else { // 섞기
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