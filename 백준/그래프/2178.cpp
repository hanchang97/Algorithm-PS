#include <stdio.h>   
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int arr[110][110] = { 0, };

bool visited[110][110] = { 0, };  // 방문 체크
int dist[110][110] = { 0, }; // 배열 좌표 (0,0)을 포함한 거리 / ex> (1,0) = 2

int N, M;

int dy[4] = { -1, 1, 0 , 0 };
int dx[4] = { 0, 0, -1, 1 };


void bfs(int y, int x) {  // 최단거리이므로 dfs 보다는 bfs 사용

	queue<pair<int, int>> q;

	visited[y][x] = true;
	dist[y][x] = 1;


	pair<int, int> first = { y, x };
	q.push(first);

	while (!q.empty()) {
		pair<int, int> current;
		current = { q.front().first, q.front().second };
		q.pop();

		for (int i = 0; i < 4; i++) {

			int nextY = current.first + dy[i];
			int nextX = current.second + dx[i];

			if (nextY >= 0 && nextY <= N - 1 && nextX >= 0 && nextX <= M - 1) {

				if (visited[nextY][nextX] == false && arr[nextY][nextX] == 1) {
					visited[nextY][nextX] = true;
					dist[nextY][nextX] = dist[current.first][current.second] + 1;

					if (nextY == N - 1 && nextX == M - 1) {   // 도달
						return;
					}

					pair<int, int> next = { nextY, nextX };
					q.push(next);
				}

			}
		}
	}


}

int main() {

	scanf("%d %d", &N, &M);


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}


	bfs(0, 0);

	printf("%d\n", dist[N - 1][M - 1]);

	return 0;
}