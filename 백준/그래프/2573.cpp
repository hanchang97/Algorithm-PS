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

// 빙산이 모두 녹았는지 체크
bool isMeltAll() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] > 0)
				return false;
		}
	}

	return true;
}

// 인접한 것들 모두 방문
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

	// 입력
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	int Year = 0;

	// 빙산 다 녹을때까지 반복
	while (isMeltAll() == false) {

		// 1. 빙산 연결요소 개수 세기
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

		// 연결요소 개수 확인
		//printf("count : %d\n", count);


		if (count >= 2) {  // 덩어리 개수 2 이상이면 종료
			printf("%d\n", Year);
			return 0;
		}


		// 2. 상태 업데이트
		Year++; // 값 증가

		int check[310][310] = { 0, };

		for (int i = 0; i < N; i++) {  // 인접한 0 개수 세기
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

		// 빼기 
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] != 0) {
					arr[i][j] -= check[i][j];
					if (arr[i][j] < 0)
						arr[i][j] = 0; // 음수라면 0으로 처리
				}
			}
		}



	}

	// 다 녹아서 while문 탈출 한 경우
	printf("0");

	return 0;
}


// bfs를 통해 매년마다 연결요소의 개수를 체크
// 매년 빙하상태 업데이트
// https://www.acmicpc.net/problem/2573