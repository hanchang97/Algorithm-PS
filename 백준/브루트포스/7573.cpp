
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int N, I, M;

struct Fish { // (y,x) = (1,1)�� ���� ���� ���
	int y;
	int x;
};


int main() {

	scanf("%d %d %d", &N, &I, &M);

	Fish fishArr[110];

	// ����� �Է¹ޱ�
	for (int i = 0; i < M; i++) {
		int y, x;
		scanf("%d %d", &y, &x);

		fishArr[i].y = y;
		fishArr[i].x = x;
	}

	/*for (int i = 0; i < M; i++) {
		printf("%d %d\n", fishArr[i].y, fishArr[i].x);
	}*/

	int MAX = -10000;

	I /= 2;
	int w, h;
	w = 1;
	h = I - 1;  // �ʱ� �׹� �� 

	while (w <= I - 1 && h >= 1) {

		//printf("w %d h %d\n", w, h);

		for (int i = 0; i < M; i++) { // ����� ���� ��ŭ

			int curFishY = fishArr[i].y;
			int curFishX = fishArr[i].x;

			if (curFishY + h <= N) { // ���� ����⿡�� �׹� h��ŭ ������ �������� ���� üũ 

				int start, end; //�׹� ��� �¿� �̵�����

				if (curFishX - w >= 1)
					start = curFishX - w;
				else
					start = 1;

				if (curFishX + w <= N)
					end = curFishX;
				else
					end = curFishX - (curFishX + w - N);

				for (int j = start; j <= end; j++) {

					int count = 0;

					for (int k = 0; k < M; k++) { // ���� �׹� ��ġ���� � �������� �������� �����ϴ��� üũ!

						if (fishArr[k].x >= j && fishArr[k].x <= j + w && fishArr[k].y >= curFishY && fishArr[k].y <= curFishY + h) {
							count++;
						}
					}

					if (count > MAX) {
						MAX = count;
					}

				}

			}

			if (curFishY - h >= 1) { // ���� ����⿡�� �׹� h��ŭ �÷��� �� (���� ����� ��ǥ�� �׹� �ϴܿ� ��ġ�ϴ� ��� üũ)

				int start, end; //�׹� ��� �¿� �̵�����

				if (curFishX - w >= 1)
					start = curFishX - w;
				else
					start = 1;

				if (curFishX + w <= N)
					end = curFishX;
				else
					end = curFishX - (curFishX + w - N);

				for (int j = start; j <= end; j++) {

					int count = 0;

					for (int k = 0; k < M; k++) { // ���� �׹� ��ġ���� � �������� �������� �����ϴ��� üũ!

						if (fishArr[k].x >= j && fishArr[k].x <= j + w && fishArr[k].y <= curFishY && fishArr[k].y >= curFishY - h) {
							count++;
						}
					}

					if (count > MAX) {
						MAX = count;
					}

				}

			}
		}

		// ���� �׹� ��
		w++;
		h--;
	}


	printf("%d\n", MAX);

	return 0;
}


// 1. ���� ����� ��ǥ�� �׹��� ��ܿ� ���ԵǸ鼭 �¿�� �̵� + �׹��� �ϴܿ� ���ԵǸ鼭 �¿�� �̵� => �� ��츦 ��� ����� ��
// 2. ����� ��ǥ�� ����, ������ ���ԵǾ� �׹� �����̵� �ϴ� ���� �ʿ�x ->  �ٸ� �������ǥ�� �̵�1���� Ŀ���� �Ǳ� ����

// �� ������ ��� ã�ƺ���
