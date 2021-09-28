
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int N, I, M;

struct Fish { // (y,x) = (1,1)이 제일 좌측 상단
	int y;
	int x;
};


int main() {

	scanf("%d %d %d", &N, &I, &M);

	Fish fishArr[110];

	// 물고기 입력받기
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
	h = I - 1;  // 초기 그물 값 

	while (w <= I - 1 && h >= 1) {

		//printf("w %d h %d\n", w, h);

		for (int i = 0; i < M; i++) { // 물고기 개수 만큼

			int curFishY = fishArr[i].y;
			int curFishX = fishArr[i].x;

			if (curFishY + h <= N) { // 현재 물고기에서 그물 h만큼 밑으로 내렸을때 범위 체크 

				int start, end; //그물 상단 좌우 이동범위

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

					for (int k = 0; k < M; k++) { // 현재 그물 위치에서 어떤 물고기들이 범위내에 존재하는지 체크!

						if (fishArr[k].x >= j && fishArr[k].x <= j + w && fishArr[k].y >= curFishY && fishArr[k].y <= curFishY + h) {
							count++;
						}
					}

					if (count > MAX) {
						MAX = count;
					}

				}

			}

			if (curFishY - h >= 1) { // 현재 물고기에서 그물 h만큼 올렸을 때 (현재 물고기 좌표가 그물 하단에 위치하는 경우 체크)

				int start, end; //그물 상단 좌우 이동범위

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

					for (int k = 0; k < M; k++) { // 현재 그물 위치에서 어떤 물고기들이 범위내에 존재하는지 체크!

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

		// 다음 그물 값
		w++;
		h--;
	}


	printf("%d\n", MAX);

	return 0;
}


// 1. 현재 물고기 좌표가 그물의 상단에 포함되면서 좌우로 이동 + 그물의 하단에 포함되면서 좌우로 이동 => 이 경우를 모두 살펴야 함
// 2. 물고기 좌표가 좌측, 우측에 포함되어 그물 상하이동 하는 것은 필요x ->  다른 물고기좌표의 이동1에서 커버가 되기 때문

// 더 간단한 방법 찾아보기
