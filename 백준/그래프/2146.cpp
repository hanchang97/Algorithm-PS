
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int N; // 지도 크기
int map[110][110] = { 0, }; // 지도

// 방문체크
bool visited[110][110] = { 0, };

int dy[4] = { -1, 1, 0, 0 };  // 상하좌우 순서
int dx[4] = { 0,0,-1,1 };

int Min_dist = 99999999;  // 모든 경우에서 최소 거리 = 정답

struct Point {
	int y;
	int x;
	int dist; // 시작점으로부터의 거리
};


// 섬 별로 고유 번호 매기기
void numbering(int Num, int y, int x) {

	visited[y][x] = true; // 넘버링 시작 지점 방문체크
	map[y][x] = Num; // 번호 매기기

	pair<int, int> start = { y,x };

	queue<pair<int, int>> Q;
	Q.push(start);

	while (!Q.empty()) {

		int currentY = Q.front().first;
		int currentX = Q.front().second;

		Q.pop();  // pop 빼먹지 않기

		for (int i = 0; i < 4; i++) {
			int nextY = currentY + dy[i];
			int nextX = currentX + dx[i];

			if (nextY < N && nextY >= 0 && nextX < N && nextX >= 0) { // 인덱스 범위 체크
				if (map[nextY][nextX] == 1 && visited[nextY][nextX] == false) {
					visited[nextY][nextX] = true; // 방문체크
					map[nextY][nextX] = Num; // 번호매기기

					pair<int, int> next = { nextY, nextX };
					Q.push(next);
				}
			}

		}

	}

}


// 다른 섬으로의 최소거리 구하기
void getMinDist(int y, int x) {
	bool checked[110][110] = { 0, };

	int curNum = map[y][x]; // 0이 아니면서 curNum이 아닌 다른 섬의 좌표를 찾아야 한다

	Point startPoint = { y,x,0 }; // 시작 좌표에서의 거리는 0

	checked[y][x] = true;

	queue<Point> Q;
	Q.push(startPoint);

	while (!Q.empty()) {

		int curY = Q.front().y;
		int curX = Q.front().x;
		int curDist = Q.front().dist;

		Q.pop();

		for (int i = 0; i < 4; i++) {

			int nextY = curY + dy[i];
			int nextX = curX + dx[i];

			if (nextY < N && nextY >= 0 && nextX < N && nextX >= 0) {
				if (checked[nextY][nextX] == false) {
					if (map[nextY][nextX] == 0) {   // 0이면 지나가야 하므로 큐에 넣기
						checked[nextY][nextX] = true;
						Point nextP = { nextY, nextX, curDist + 1 };
						Q.push(nextP);
					}
					else if (map[nextY][nextX] != 0 && map[nextY][nextX] != curNum) {  // 0이 아니면서 현재 섬이 아닌 다른 섬의 값인 경우를 찾기 위함
						if (Min_dist > curDist) {
							Min_dist = curDist;
						}
					}

				}
			}



		}

	}

}





int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	// 섬 별로 번호 매기기
	// 섬 번호는 2 부터 시작!

	int number = 2;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == false && map[i][j] == 1) {
				numbering(number, i, j);
				number++;
			}
		}
	}

	// 넘버링 제대로 되었는지 체크
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}*/

	// 방문체크 초기화
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}


	// 모든 섬의 좌표 돌면서 다른 대륙으로의 최소 거리 구하기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != 0)
				getMinDist(i, j);  // 섬인 곳에서만 탐색을 시작해야한다
		}
	}

	printf("%d\n", Min_dist);



	return 0;
}


// 섬마다 번호를 매겨서 구분을 한다
