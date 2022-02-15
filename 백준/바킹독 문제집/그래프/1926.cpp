#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int Map[505][505] = { 0, };
bool check[505][505] = { 0, };

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int Count = 0;
int Max = 0;

int N, M;

int bfs(pair<int, int> start) {
	queue<pair<int, int>> Q;
	int Width = 0;

	check[start.first][start.second] = true;
	Q.push(start);
	Width++;

	while (!Q.empty()) {

		pair<int, int> current = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nY = current.first + dy[i];
			int nX = current.second + dx[i];

			if (nY < 0 || nY >= N || nX < 0 || nX >= M) continue;
			if (check[nY][nX] == true || Map[nY][nX] != 1) continue;

			check[nY][nX] = true;
			Q.push(make_pair(nY, nX));
			Width++;
		}

	}
	return Width;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Map[i][j] == 1 && check[i][j] == false) {
				int width = bfs(make_pair(i, j));
				if (width > Max)
					Max = width;
				Count++;
			}
		}
	}

	cout << Count << "\n" << Max;

	return 0;
}

// BFS
// 배열 범위 체크와 방문 여부 체크 잘 하기