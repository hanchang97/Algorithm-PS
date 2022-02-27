#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int Map[1005][1005] = { 0, };

int Jihoon[1005][1005] = { 0, };
bool JihoonVisit[1005][1005] = { 0, };

int Fire[1005][1005] = { 0, };
bool FireVisit[1005][1005] = { 0, };

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int R, C;


void bfs(int arr[1005][1005], bool arrVisit[1005][1005], int value) {
	queue<pair<int, int>> Q;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == value) {
				Q.push({ i,j });
				arrVisit[i][j] = true;
				arr[i][j] = 0;
			}
		}
	}


	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];

			if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
			if (arrVisit[ny][nx] || arr[ny][nx] < 0) continue;

			arrVisit[ny][nx] = true;
			arr[ny][nx] = arr[cur.first][cur.second] + 1;
			Q.push({ ny, nx });
		}


	}

}

int main() {
	/*ios::sync_with_stdio(0);
	cin.tie(0);*/

	scanf("%d %d", &R, &C);

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char a;
			scanf(" %c", &a);

			if (a == '#') {
				Map[i][j] = -1;
			}
			else if (a == '.') {
				Map[i][j] = 0;
			}
			else if (a == 'J') {
				Map[i][j] = -2;
			}
			else if (a == 'F') {
				Map[i][j] = -3;
			}
		}
	}


	// 지훈, 불 배열 초기화
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (Map[i][j] == -2) {
				Fire[i][j] = 0;
				Jihoon[i][j] = Map[i][j];
			}
			else if (Map[i][j] == -3) {
				Fire[i][j] = Map[i][j];
				Jihoon[i][j] = 0;
			}
			else {
				Fire[i][j] = Map[i][j];
				Jihoon[i][j] = Map[i][j];
			}
		}
	}


	bfs(Jihoon, JihoonVisit, -2);
	bfs(Fire, FireVisit, -3);


	// 끝에만 검사하기
	int Min = 10000000;
	bool isPossible = false;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (i == 0 || i == R - 1 || j == 0 || j == C - 1) {

				if (JihoonVisit[i][j] && FireVisit[i][j]) {
					if (Jihoon[i][j] < Fire[i][j]) {
						if (Jihoon[i][j] < Min && Jihoon[i][j] >= 0) {
							Min = Jihoon[i][j];
							isPossible = true;
						}
					}
				}
				else if (JihoonVisit[i][j] && !FireVisit[i][j]) {
					if (Jihoon[i][j] < Min) {
						Min = Jihoon[i][j];
						isPossible = true;
					}
				}

			}
		}
	}

	if (isPossible)
		printf("%d\n", Min + 1);
	else
		printf("IMPOSSIBLE");


	return 0;
}

// bfs
// 불의 입장에서, 지훈이의 입장에서 두 번 bfs를 수행
// 동시에 같이 bfs를 진행할 수도 있을 것 같다

// 불이 여러 군데서 시작할 수 있다는 점 주의
// 지훈이의 탈출 성공 경로에 불이 번지지 않는 경우도 있으니 검사해주기