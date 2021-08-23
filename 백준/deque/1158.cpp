#include <stdio.h>   
#include <deque>
#include <vector>

using namespace std;

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	int arr[5010] = { 0, };

	deque<int> dq;

	for (int i = 1; i <= n; i++)
		dq.push_back(i);


	vector <int> result;

	int order = k;
	while (1) {

		result.push_back(dq[order - 1]);   //order번째 뽑기

		dq.erase(dq.begin() + order - 1, dq.begin() + order);  // order번째 덱에서 삭제

		if (dq.empty() == true)
			break;

		order = order - 1 + k;  // 업데이트 된 덱 기준 다음 순서

		while (order > dq.size())   // 덱 크기 보다 순서 값 큰 경우 처리
			order = order - dq.size();
	}


	printf("<");
	for (int i = 0; i < result.size(); i++) {
		if (i == 0)
			printf("%d", result[i]);
		else
			printf(", %d", result[i]);
	}
	printf(">");

	return 0;
}