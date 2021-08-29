#include <stdio.h>
#include <vector>
#include <queue>


using namespace std;

int N, M, K;

int arr[110][110] = { 0, };
bool visited[110][110] = { 0, };

int dy[4] = { -1, 1, 0 ,0 };
int dx[4] = { 0,0,-1,1 };

int bfs(int y, int x, int count) {
	visited[y][x] = true;

	queue<pair<int, int>> q;

	pair<int, int> start = { y,x };
	q.push(start);
	count++;

	while (!q.empty()) {

		int currentY = q.front().first;
		int currentX = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = currentY + dy[i];
			int nextX = currentX + dx[i];

			if (nextY >= 0 && nextY <= N - 1 && nextX >= 0 && nextX <= M - 1) {
				if (arr[nextY][nextX] == 1 && visited[nextY][nextX] == false) {
					pair<int, int> next = { nextY, nextX };
					q.push(next);
					count++;
					visited[nextY][nextX] = true;
				}
			}
		}



	}

	return count;

}

int main() {

	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < K; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		a--;
		b--; // 배열의 인덱스 값으로 변경

		arr[a][b] = 1;
	}


	int max = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1 && visited[i][j] == false) {

				int count = bfs(i, j, 0);
				if (count > max)
					max = count;
			}
		}
	}

	printf("%d\n", max);

	return 0;
}