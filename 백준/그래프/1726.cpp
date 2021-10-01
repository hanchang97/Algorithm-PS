#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <iostream>


using namespace std;

int N, M;

int Min_dist = 100000000;

int Map[110][110];

int dy[5] = { 0, 0,0,1,-1 };  // 동 서 남 북 순서
int dx[5] = { 0, 1,-1,0,0 };  // 1~4 인덱스 사용하기 위함


struct Point {
	int y;
	int x;
	int dir;
	int command; // 명령 횟수 -> 출발지 = 0
};

Point Start;
Point End;

bool visited[110][110][5] = { 0, };

int getLeftDir(int dir) {  // 왼쪽 회전 후 방향 리턴
	if (dir == 1)
		return 4;
	else if (dir == 2)
		return 3;
	else if (dir == 3)
		return 1;
	else
		return 2;
}

int getRightDir(int dir) { // 오른쪽 회전 후 방향 리턴
	if (dir == 1)
		return 3;
	else if (dir == 2)
		return 4;
	else if (dir == 3)
		return 2;
	else
		return 1;
}

int getTurnAdd(int curDir, int endDir) {  // 도착 후 방향까지 완성시키기 위함
	if (curDir == endDir)
		return 0;
	else {
		if (curDir == 1) {
			if (endDir == 2)
				return 2;
			else
				return 1;
		}
		else if (curDir == 2) {
			if (endDir == 1)
				return 2;
			else
				return 1;
		}
		else if (curDir == 3) {
			if (endDir == 4)
				return 2;
			else
				return 1;
		}
		else { // curDir == 4
			if (endDir == 3)
				return 2;
			else
				return 1;
		}
	}
}


void getResult() {

	visited[Start.y][Start.x][Start.dir] = true;

	queue<Point> Q;
	Q.push(Start);

	while (!Q.empty()) {
		int curY = Q.front().y;
		int curX = Q.front().x;
		int curDir = Q.front().dir;
		int curCommand = Q.front().command;

		Q.pop();

		// 현재 방향에서 다음 1칸,2칸,3칸  체크
		for (int i = 1; i <= 3; i++) {
			int nextY = curY + dy[curDir] * i;
			int nextX = curX + dx[curDir] * i;

			bool isPossible = true;

			if (i == 2) {   // 2칸 이동하려 할 때  그 전도 0이어야 함
				int next1Y = curY + dy[curDir];
				int next1X = curX + dx[curDir];

				if (next1Y >= 0 && next1Y < N && next1X >= 0 && next1X < M) {
					if (Map[next1Y][next1X] != 0)
						isPossible = false;
				}
			}
			if (i == 3) { // 3칸 이동하려 할 때 그 전, 전전 모두 0 이어야 가능
				int next1Y = curY + dy[curDir];
				int next1X = curX + dx[curDir];

				int next2Y = curY + dy[curDir] * 2;
				int next2X = curX + dx[curDir] * 2;

				if (next1Y >= 0 && next1Y < N && next1X >= 0 && next1X < M && next2Y >= 0 && next2Y < N && next2X >= 0 && next2X < M) {
					if (Map[next1Y][next1X] != 0 || Map[next2Y][next2X] != 0)
						isPossible = false;
				}
			}

			if (isPossible) {
				if (nextY == End.y && nextX == End.x) { // 도착지점에 도달한 경우

					if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < M) {
						int nextCommand = curCommand + 1;

						int turnAdd = getTurnAdd(curDir, End.dir);

						nextCommand += turnAdd;

						if (nextCommand < Min_dist)
							Min_dist = nextCommand;
					}

				}
				else { // 0 이면서 미방문 상태인 경우

					if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < M) { // 배열 범위 체크
						if (Map[nextY][nextX] == 0 && visited[nextY][nextX][curDir] == false) {
							visited[nextY][nextX][curDir] = true;
							Point next = { nextY, nextX, curDir, curCommand + 1 };
							Q.push(next);
						}
					}
				}
			}
		}

		// 현재 좌표에서 좌,우로 회전한 상태 체크
		int leftDir = getLeftDir(curDir);
		int rightDir = getRightDir(curDir);

		if (visited[curY][curX][leftDir] == false) {  // 왼쪽 회전 상태
			Point next = { curY, curX, leftDir, curCommand + 1 };
			Q.push(next);
			visited[curY][curX][leftDir] = true;
		}
		if (visited[curY][curX][rightDir] == false) { // 오른쪽 회전 상태
			Point next = { curY, curX, rightDir, curCommand + 1 };
			Q.push(next);
			visited[curY][curX][rightDir] = true;
		}


	}
}




int main() {

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &Map[i][j]);
		}
	}

	// 출발지 입력
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	Start.y = a - 1;
	Start.x = b - 1;
	Start.dir = c;
	Start.command = 0;

	// 도착지 입력
	int d, e, f;
	scanf("%d %d %d", &d, &e, &f);
	End.y = d - 1;
	End.x = e - 1;
	End.dir = f;



	// 출발지 좌표와 도착지 좌표가 같은 경우를 고려해줘야 한다!!
	if (Start.y == End.y && Start.x == End.x) {
		int startDir = Start.dir;
		int endDir = End.dir;

		Min_dist = getTurnAdd(startDir, endDir);
	}
	else {
		getResult();
	}

	printf("%d\n", Min_dist);



	return 0;


}


// 다음 이동 좌표로 5가지 경우를 생각해야 한다!
// 1. 1칸 이동 (방향 유지)
// 2. 2칸 이동 (방향 유지)
// 3. 3칸 이동 (방향 유지)
// 4. 현재 좌표에서 오른쪽 90도 회전
// 5. 현재 좌표에서 왼쪽 90도 회전


// 2,3칸 이동하는 경우는 그 전 좌표들이 모두 0이어야 뛰어넘는게 가능하므로 검사 필수!