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

	priority_queue <int, vector<int>, greater<>> pq;  // min-heap // 최소값이 루트

	// 첫 줄은 모두 넣기
	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		pq.push(a);
	}


	for (int i = 0; i < N*N - N; i++) { // 첫 줄 제외한 나머지 개수
		int a;
		scanf("%d", &a);

		if (a > pq.top()) {
			pq.push(a);
			pq.pop();
		}
	}

	printf("%d", pq.top());

}

// 슬라이딩 윈도우 느낌 적용
// min-heap에서 top 보다 크면 넣고 top을 빼면 N개 유지되며 결과적으로 top에는 N번째로 큰 수가 들어간다
// https://www.acmicpc.net/problem/2075 