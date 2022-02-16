#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int Map[1005][1005] = { 0, };
bool Visit[1005][1005] = { 0, };

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int N, M;

int Min = 0;

void bfs() {
	queue<pair<int, int>> Q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Map[i][j] == 1) {
				Q.push({ i, j });
			}
		}
	}

	while (!Q.empty()) {

		pair<int, int> current = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nextDay = Map[current.first][current.second] + 1;
			int nY = current.first + dy[i];
			int nX = current.second + dx[i];


			if (nY < 0 || nY >= N || nX < 0 || nX >= M) continue;
			if (Map[nY][nX] != 0) continue;

			Q.push({ nY, nX });
			Map[nY][nX] = nextDay;

			if (nextDay > Min)
				Min = nextDay;
		}

	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
		}
	}

	bool isAlready = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Map[i][j] == 0) {
				isAlready = false;
				break;
			}
		}
	}

	if (isAlready) {
		cout << "0";
		return 0;
	}


	bfs();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Map[i][j] == 0) {
				cout << "-1";
				return 0;
			}
		}
	}

	cout << Min - 1;

	return 0;
}

// bfs
// Min - 1  -> 첫 날 익는 것들의 값은 1 이어야 하는데  현재 코드에서는 시작 시 기존에 익어있던 것들의 1 값에 1을 더하게 되어 2가 되므로 마지막에 1 빼주기!!
// 시작 시, bfs 후 배열 체크하면서 문제 요구 사항 지키는 부분 중요