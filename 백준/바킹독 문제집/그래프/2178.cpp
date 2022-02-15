#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int Map[105][105] = { 0, };
bool Visit[105][105] = { 0, };

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int N, M;

int bfs() {
	queue<pair<pair<int, int>, int>> Q;

	Visit[0][0] = true;
	Q.push({ {0,0}, 1 });

	while (!Q.empty()) {

		pair<pair<int, int>, int> current = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nY = current.first.first + dy[i];
			int nX = current.first.second + dx[i];

			if (nY < 0 || nY >= N || nX < 0 || nX >= M) continue;
			if (Visit[nY][nX] == true || Map[nY][nX] != 1) continue;

			if (nY == N - 1 && nX == M - 1)
				return current.second + 1;

			Visit[nY][nX] = true;
			Q.push({ {nY, nX}, current.second + 1 });
		}

	}

}

int main() {
	//ios::sync_with_stdio(0);
	//cin.tie(0);

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &Map[i][j]);
		}
	}

	printf("%d\n", bfs());

	return 0;
}

// bfs
// 큐에는 좌표와 현재 좌표가 배열의 [0][0] 으로 부터의 거리를 저장
// 방문 배열의 값들을 [0][0]으로 부터의 거리로 설정하는 풀이도 가능