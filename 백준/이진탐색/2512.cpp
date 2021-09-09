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


// ��û �׼����� ���� �������� �Ѿ׺��� ���ų� �۴ٸ� ��û ���� �״�� ���� -> �������� ���ĵ� �迭���� ���� ������ ���Ҹ� ���

// ���� ��찡 �ƴ϶�� ���� ������ ������ �ִ� ��û ���꺸�� �۾����� -> ���� Ž�� ���� = 1 ~ �ִ��û ���갪

// ����Ž���� �����ϸ� �ִ�� ������ ������ ���� ���� Ž���Ѵ� / ���� ���� ������ ���� �� �� ���� ���� ���� ���� ������ �� ū �������� ������ ������ Ž���غ���