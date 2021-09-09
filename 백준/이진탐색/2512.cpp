#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX = 10010;

int N, M;

int arr1[MAX];

int maxResult = 0;

void binarySearch(int start, int end) {

	if (start > end)
		return;

	int middle = (start + end) / 2;

	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (arr1[i] > middle)
			sum += middle;
		else
			sum += arr1[i];
	}

	if (sum > M) {
		binarySearch(start, middle - 1);
	}
	else {
		maxResult = middle;
		binarySearch(middle + 1, end);
	}


}



int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr1[i]);

	scanf("%d", &M);

	sort(arr1, arr1 + N);

	int Sum = 0;

	for (int i = 0; i < N; i++)
		Sum += arr1[i];

	if (Sum <= M) {
		printf("%d\n", arr1[N - 1]);
		return 0;
	}

	binarySearch(1, arr1[N - 1]);


	printf("%d\n", maxResult);


	return 0;
}


// 요청 액수들의 합이 국가예산 총액보다 같거나 작다면 요청 상태 그대로 배정 -> 오름차순 정렬된 배열에서 제일 마지막 원소를 출력

// 위의 경우가 아니라면 배정 가능한 예산은 최대 요청 예산보다 작아진다 -> 이진 탐색 범위 = 1 ~ 최대요청 예산값

// 이진탐색을 진행하며 최대로 배정한 가능한 예산 값을 탐색한다 / 현재 예산 값으로 배정 시 총 합이 국가 예산 보다 작으면 더 큰 범위에서 가능한 예산을 탐색해본다