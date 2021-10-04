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

// �����¿�, ���� , �Ʒ��� �̵� ����
int dy[6] = { -1,1,0,0,0,0 };
int dx[6] = { 0,0,-1,1,0,0, };
int dz[6] = { 0,0,0,0,-1, 1 };

int arr[110][110][110] = { 0, };  // ���� ���� ��Ÿ���� ���� 3���� �迭 ���
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

	// ó������ ��� �;����� 0 ��� �� ����
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
					arr[nextY][nextX][nextZ] = arr[curY][curX][curZ] + 1; // ù �� ���� �丶�� ���� 2�� �ǹǷ� ���߿� �������� ���� ��¥���� -1 ����� �Ѵ�!

					Point next = { nextY, nextX, nextZ };
					Q.push(next);
				}
			}
		}

	}


	// ��� �;����� �˻�
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


	// ������ ���� �� ã��
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


// 3���� �迭�� ����� ������ bfs ����