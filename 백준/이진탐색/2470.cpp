#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <iostream>


using namespace std;

int N;
int arr[100010];

int Min = 2000000001;  // 원소 최대값은 10억

int min1 = 1000000000;  //  정답이 될 두 원소의 값
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

	if (find * -1 == arr[start]) {  // 자기 자신이 경우에 포함되는 경우
		return end;
	}
	else if (find * -1 == arr[end]) {
		return start;
	}
	else {
		int a = arr[start] - find;
		int b = arr[end] - find;

		if (abs(a) > abs(b)) // 차이가 작은 경우의 인덱스를 리턴
			return end;
		else
			return start;
	}


}


int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + N); // 오름차순 정렬


	for (int i = 0; i < N; i++) {  // 각 원소별로 더했을 때 합이 0과 최대한 가까워지는 원소를 이진 탐색으로 찾기

		int current = arr[i];

		int index1 = i;
		int index2 = -1;

		if (current == 0) { // 0 인경우 1: 처음에 위치하면 다음 원소와 더한 것, 2: 마지막에 위치하면 전 원소와 더한 것,  3: 1,2 가 아니면 앞뒤 원소와 비교
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
			temp *= -1;   // 두 수의 차이를 비교하기 위함

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


// 오름차순 정렬 후 각 원소별로  자신의 값에 -1을 곱한 값과 최대한 가까운 것을 찾는다 -> 더했을때 0에 가장 가깝게 되므로!!