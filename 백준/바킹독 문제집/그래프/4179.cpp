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


	// ����, �� �迭 �ʱ�ȭ
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


	// ������ �˻��ϱ�
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
// ���� ���忡��, �������� ���忡�� �� �� bfs�� ����
// ���ÿ� ���� bfs�� ������ ���� ���� �� ����

// ���� ���� ������ ������ �� �ִٴ� �� ����
// �������� Ż�� ���� ��ο� ���� ������ �ʴ� ��쵵 ������ �˻����ֱ�