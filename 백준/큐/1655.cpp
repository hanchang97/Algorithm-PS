#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int N;

int main() {

	scanf("%d", &N);

	int mid; // �߰���

	priority_queue <int, vector<int>, greater<int>> minpq; // �߰��� ���� ū �ֵ��� ���� min heap  / �ּҰ��� ��Ʈ�� ��ġ
	priority_queue <int> maxpq; // �߰��� ���� ���� �ֵ��� ���� max heap

	for (int i = 0; i < N; i++) {
		int newNum;
		scanf("%d", &newNum);

		if (i == 0) { // ���� ó�� ��
			mid = newNum;
		}
		else {
			if (mid == newNum) {
				if (maxpq.size() >= minpq.size()) {  // �� ���� ���� ���� �ּ�ȭ
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
				if (maxpq.size() - minpq.size() >= 1) {  // ¦�� ������ ��� ������ �߰����� �ǹǷ� >= 1
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

// �߰����� �¿�� �� ���� �ִٰ� ��������!