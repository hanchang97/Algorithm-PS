#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int N, M;

int arr[310][310];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct Point {
	int y;
	int x;
};

// ������ ��� ��Ҵ��� üũ
bool isMeltAll() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] > 0)
				return false;
		}
	}

	return true;
}

// ������ �͵� ��� �湮
void getIceberg(bool visited[310][310], int y, int x) {
	queue<Point> Q;
	Point p = { y,x };
	Q.push(p);

	visited[y][x] = true;

	while (!Q.empty()) {
		int curY = Q.front().y;
		int curX = Q.front().x;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];

			if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < M) {
				if (visited[nextY][nextX] == false && arr[nextY][nextX] > 0) {
					visited[nextY][nextX] = true;
					Point next = { nextY, nextX };
					Q.push(next);
				}
			}
		}


	}


}

int main() {

	// �Է�
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	int Year = 0;

	// ���� �� ���������� �ݺ�
	while (isMeltAll() == false) {

		// 1. ���� ������ ���� ����
		int count = 0;

		bool visited[310][310] = { 0, };

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] != 0 && visited[i][j] == false) {
					getIceberg(visited, i, j);
					count++;
				}
			}
		}

		// ������ ���� Ȯ��
		//printf("count : %d\n", count);


		if (count >= 2) {  // ��� ���� 2 �̻��̸� ����
			printf("%d\n", Year);
			return 0;
		}


		// 2. ���� ������Ʈ
		Year++; // �� ����

		int check[310][310] = { 0, };

		for (int i = 0; i < N; i++) {  // ������ 0 ���� ����
			for (int j = 0; j < M; j++) {
				if (arr[i][j] != 0) {
					for (int k = 0; k < 4; k++) {
						int checkY = i + dy[k];
						int checkX = j + dx[k];

						if (checkY >= 0 && checkY < N && checkX >= 0 && checkX < M) {
							if (arr[checkY][checkX] == 0)
								check[i][j]++;
						}

					}
				}
			}
		}

		// ���� 
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] != 0) {
					arr[i][j] -= check[i][j];
					if (arr[i][j] < 0)
						arr[i][j] = 0; // ������� 0���� ó��
				}
			}
		}



	}

	// �� ��Ƽ� while�� Ż�� �� ���
	printf("0");

	return 0;
}


// bfs�� ���� �ų⸶�� �������� ������ üũ
// �ų� ���ϻ��� ������Ʈ
// https://www.acmicpc.net/problem/2573