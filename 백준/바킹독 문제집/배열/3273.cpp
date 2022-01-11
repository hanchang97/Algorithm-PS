#include <stdio.h>
#include <iostream>

using namespace std;

bool arr[2000010] = { 0, };
int numInput[100000] = { 0, }; // �Է°����� ��� ���� �ٸ� �ڿ���

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

	int answerCnt = 0; // ���� ��

	for (int i = 0; i < N; i++) {
		int current = numInput[i];
		if (arr[current] == true && x > current) {  // ���� �ε��� ����, ���� ���� ���� �Ǵ� �� ���� ex> (4, 4)
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


// ó������ ������ ���� �ִ밡 1000000 �̶� �迭�� ũ�⸦ ���� �����ؼ� 1000010 ���� �����ϴ� ��Ÿ�� ������ �߻��Ͽ���
// ������ �غ��� ������ ���� �ִ밪�� 2000000 �̹Ƿ�  (1 + 1999999) �� ��찡 ���� �� �����Ƿ� �迭�� ũ�⸦ �̹鸸 �̻����� ������ �����

// arr�迭�� �ε����� �ش��ϴ� ���� �Է°����� �������� true�� �Ҵ�!!
// ¦�� �������� ��� �� ���� �ε����� �ش��ϴ� ���� false �Ҵ�!!
