#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int N, M, H;

struct Point {
	int y;
	int x;
	int z;
};

// 상하좌우, 위층 , 아래층 이동 위함
int dy[6] = { -1,1,0,0,0,0 };
int dx[6] = { 0,0,-1,1,0,0, };
int dz[6] = { 0,0,0,0,-1, 1 };

int arr[110][110][110] = { 0, };  // 높이 까지 나타내기 위해 3차원 배열 사용
bool visited[110][110][110] = { 0, };

queue <Point> Q;

int main() {

	scanf("%d %d %d", &M, &N, &H);

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				scanf("%d", &arr[j][k][i]);
			}
		}
	}

	// 처음부터 모두 익었으면 0 출력 후 종료
	bool all = true;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (arr[j][k][i] == 0) {
					all = false;
					break;
				}
			}
		}
	}

	if (all == true) {
		printf("0");
		return 0;
	}


	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (arr[j][k][i] == 1) {
					Point toma = { j,k,i };
					Q.push(toma);
					visited[j][k][i] = true;
				}
			}
		}
	}

	// bfs
	while (!Q.empty()) {
		int curY = Q.front().y;
		int curX = Q.front().x;
		int curZ = Q.front().z;

		Q.pop();

		for (int i = 0; i < 6; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];
			int nextZ = curZ + dz[i];

			if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < M
				&& nextZ >= 0 && nextZ < H) {
				if (visited[nextY][nextX][nextZ] == false && arr[nextY][nextX][nextZ] == 0) {
					visited[nextY][nextX][nextZ] = true;
					arr[nextY][nextX][nextZ] = arr[curY][curX][curZ] + 1; // 첫 날 익은 토마토 값이 2가 되므로 나중에 마지막에 익은 날짜에서 -1 해줘야 한다!

					Point next = { nextY, nextX, nextZ };
					Q.push(next);
				}
			}
		}

	}


	// 모두 익었는지 검사
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (arr[j][k][i] == 0) {
					printf("-1");
					return 0;
				}
			}
		}
	}


	// 마지막 익은 날 찾기
	int Max = -1000;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (arr[j][k][i] > Max)
					Max = arr[j][k][i];
			}
		}
	}

	printf("%d", Max - 1);


	return 0;
}


// 3차원 배열을 사용한 간단한 bfs 문제