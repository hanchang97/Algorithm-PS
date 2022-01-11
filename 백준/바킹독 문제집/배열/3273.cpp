#include <stdio.h>
#include <iostream>

using namespace std;

bool arr[2000010] = { 0, };
int numInput[100000] = { 0, }; // 입력값들은 모두 서로 다른 자연수

int main() {

	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);

		arr[a] = true;
		numInput[i] = a;
	}

	int x;
	scanf("%d", &x);

	int answerCnt = 0; // 정답 수

	for (int i = 0; i < N; i++) {
		int current = numInput[i];
		if (arr[current] == true && x > current) {  // 음수 인덱스 방지, 같은 수가 쌍이 되는 것 방지 ex> (4, 4)
			if (arr[x - current] == true && (current + current) != x) {
				arr[current] = false;
				arr[x - current] = false;
				answerCnt++;
			}
		}
	}

	printf("%d\n", answerCnt);

	return 0;
}


// 처음에는 가능한 수의 최대가 1000000 이라 배열의 크기를 여유 포함해서 1000010 으로 설정하니 런타임 에러가 발생하였다
// 생각을 해보니 가능한 합의 최대값이 2000000 이므로  (1 + 1999999) 의 경우가 나올 수 있으므로 배열의 크기를 이백만 이상으로 설정을 해줬다

// arr배열은 인덱스에 해당하는 수가 입력값으로 들어왔으면 true를 할당!!
// 짝이 지어지는 경우 두 수의 인덱스에 해당하는 값은 false 할당!!
