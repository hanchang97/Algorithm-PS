#include <stdio.h>
#include <iostream>
#include <cmath>   // sqrt ��� ����

using namespace std;

int N, M;

int numArray[1000010] = { 0, };

int main() {

	scanf("%d %d", &M, &N);

	int large = N;
	int small = M;

	// ���� �迭 ä���
	for (int i = 1; i <= large; i++)
		numArray[i] = i;

	// large ������ �Ҽ��� ��� ���Ѵ� -> �Ҽ��� �ڽ��� �� �Ҵ�,  �Ҽ��� �ƴϸ� 0���� �Ҵ�!!  // �ڿ��� 1�� �Ҽ� �ƴϴ�
	for (int i = 2; i <= sqrt(large); i++) {  // �ݺ� Ƚ���� ���Ϸ��� ���� ���� ������ -> ��� ������ ������� �Ǵ��ϹǷ� ���������� ������ �ݺ��Ͽ�
												// �Ҽ��� �ƴ� ���� ��� ã�� �� �ִ�!!
		if (numArray[i] != 0) {

			int count = 2;
			int mul = numArray[i] * count;

			while (mul <= large) {
				numArray[mul] = 0; // �Ҽ��� �ƴ� �� -> 0 �Ҵ�

				count++;
				mul = numArray[i] * count;
			}
		}
	}

	for (int j = small; j <= large; j++) {

		if (numArray[j] != 0 && numArray[j] != 1)
			printf("%d\n", numArray[j]);
	}

	return 0;
}


// �����佺�׳׽��� ü ���� ����
// 1929 - �Ҽ����ϱ�
// https://www.acmicpc.net/problem/1929