#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int N;

int main() {

	scanf("%d", &N);

	int mid; // 중간값

	priority_queue <int, vector<int>, greater<int>> minpq; // 중간값 보다 큰 애들이 들어가는 min heap  / 최소값이 루트에 위치
	priority_queue <int> maxpq; // 중간값 보다 작은 애들이 들어가는 max heap

	for (int i = 0; i < N; i++) {
		int newNum;
		scanf("%d", &newNum);

		if (i == 0) { // 제일 처음 수
			mid = newNum;
		}
		else {
			if (mid == newNum) {
				if (maxpq.size() >= minpq.size()) {  // 두 힙의 개수 차이 최소화
					minpq.push(newNum);
				}
				else {
					maxpq.push(newNum);
				}
			}
			else if (newNum > mid) {
				minpq.push(newNum);
				if (minpq.size() - maxpq.size() >= 2) {
					maxpq.push(mid);
					mid = minpq.top();
					minpq.pop();
				}
			}
			else {
				maxpq.push(newNum);
				if (maxpq.size() - minpq.size() >= 1) {  // 짝수 개수인 경우 작은게 중간값이 되므로 >= 1
					minpq.push(mid);
					mid = maxpq.top();
					maxpq.pop();
				}
			}

		}

		printf("%d\n", mid);
	}


	return 0;
}

// 중간값의 좌우로 두 힙이 있다고 생각하자!