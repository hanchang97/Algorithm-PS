#include <stdio.h>
#include <iostream>

#include <string>
#include <deque>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;


int main() {

	scanf("%d", &N);

	priority_queue <int, vector<int>, greater<>> pq;  // min-heap // �ּҰ��� ��Ʈ

	// ù ���� ��� �ֱ�
	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		pq.push(a);
	}


	for (int i = 0; i < N*N - N; i++) { // ù �� ������ ������ ����
		int a;
		scanf("%d", &a);

		if (a > pq.top()) {
			pq.push(a);
			pq.pop();
		}
	}

	printf("%d", pq.top());

}

// �����̵� ������ ���� ����
// min-heap���� top ���� ũ�� �ְ� top�� ���� N�� �����Ǹ� ��������� top���� N��°�� ū ���� ����
// https://www.acmicpc.net/problem/2075 