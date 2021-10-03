#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <iostream>


using namespace std;

int N;
int arr[100010];

int Min = 2000000001;  // ���� �ִ밪�� 10��

int min1 = 1000000000;  //  ������ �� �� ������ ��
int min2 = 1000000000;

int getResult(int find) {
	int start = 0;
	int end = N - 1;

	while (start + 1 < end) {

		int mid = (start + end) / 2;

		if (find == arr[mid])
			return mid;
		else if (find > arr[mid])
			start = mid;
		else
			end = mid;
	}

	if (find * -1 == arr[start]) {  // �ڱ� �ڽ��� ��쿡 ���ԵǴ� ���
		return end;
	}
	else if (find * -1 == arr[end]) {
		return start;
	}
	else {
		int a = arr[start] - find;
		int b = arr[end] - find;

		if (abs(a) > abs(b)) // ���̰� ���� ����� �ε����� ����
			return end;
		else
			return start;
	}


}


int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + N); // �������� ����


	for (int i = 0; i < N; i++) {  // �� ���Һ��� ������ �� ���� 0�� �ִ��� ��������� ���Ҹ� ���� Ž������ ã��

		int current = arr[i];

		int index1 = i;
		int index2 = -1;

		if (current == 0) { // 0 �ΰ�� 1: ó���� ��ġ�ϸ� ���� ���ҿ� ���� ��, 2: �������� ��ġ�ϸ� �� ���ҿ� ���� ��,  3: 1,2 �� �ƴϸ� �յ� ���ҿ� ��
			if (i == 0) {
				index2 = 1;
			}
			else if (i == N - 1) {
				index2 = N - 2;
			}
			else {
				int a = current - arr[i - 1];
				int b = arr[i + 1] - current;

				if (a > b)
					index2 = i + 1;
				else
					index2 = i - 1;
			}
		}
		else {

			int find = current * -1;

			index2 = getResult(find);

		}

		int temp = arr[index1] + arr[index2];

		if (temp < 0)
			temp *= -1;   // �� ���� ���̸� ���ϱ� ����

		if (temp < Min) {
			Min = temp;

			if (arr[index1] < arr[index2]) {
				min1 = arr[index1];
				min2 = arr[index2];
			}
			else {
				min1 = arr[index2];
				min2 = arr[index1];
			}

		}

	}


	printf("%d %d\n", min1, min2);

	return 0;


}


// �������� ���� �� �� ���Һ���  �ڽ��� ���� -1�� ���� ���� �ִ��� ����� ���� ã�´� -> �������� 0�� ���� ������ �ǹǷ�!!