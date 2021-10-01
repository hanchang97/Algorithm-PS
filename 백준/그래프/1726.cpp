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

int dy[5] = { 0, 0,0,1,-1 };  // �� �� �� �� ����
int dx[5] = { 0, 1,-1,0,0 };  // 1~4 �ε��� ����ϱ� ����


struct Point {
	int y;
	int x;
	int dir;
	int command; // ��� Ƚ�� -> ����� = 0
};

Point Start;
Point End;

bool visited[110][110][5] = { 0, };

int getLeftDir(int dir) {  // ���� ȸ�� �� ���� ����
	if (dir == 1)
		return 4;
	else if (dir == 2)
		return 3;
	else if (dir == 3)
		return 1;
	else
		return 2;
}

int getRightDir(int dir) { // ������ ȸ�� �� ���� ����
	if (dir == 1)
		return 3;
	else if (dir == 2)
		return 4;
	else if (dir == 3)
		return 2;
	else
		return 1;
}

int getTurnAdd(int curDir, int endDir) {  // ���� �� ������� �ϼ���Ű�� ����
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

		// ���� ���⿡�� ���� 1ĭ,2ĭ,3ĭ  üũ
		for (int i = 1; i <= 3; i++) {
			int nextY = curY + dy[curDir] * i;
			int nextX = curX + dx[curDir] * i;

			bool isPossible = true;

			if (i == 2) {   // 2ĭ �̵��Ϸ� �� ��  �� ���� 0�̾�� ��
				int next1Y = curY + dy[curDir];
				int next1X = curX + dx[curDir];

				if (next1Y >= 0 && next1Y < N && next1X >= 0 && next1X < M) {
					if (Map[next1Y][next1X] != 0)
						isPossible = false;
				}
			}
			if (i == 3) { // 3ĭ �̵��Ϸ� �� �� �� ��, ���� ��� 0 �̾�� ����
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
				if (nextY == End.y && nextX == End.x) { // ���������� ������ ���

					if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < M) {
						int nextCommand = curCommand + 1;

						int turnAdd = getTurnAdd(curDir, End.dir);

						nextCommand += turnAdd;

						if (nextCommand < Min_dist)
							Min_dist = nextCommand;
					}

				}
				else { // 0 �̸鼭 �̹湮 ������ ���

					if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < M) { // �迭 ���� üũ
						if (Map[nextY][nextX] == 0 && visited[nextY][nextX][curDir] == false) {
							visited[nextY][nextX][curDir] = true;
							Point next = { nextY, nextX, curDir, curCommand + 1 };
							Q.push(next);
						}
					}
				}
			}
		}

		// ���� ��ǥ���� ��,��� ȸ���� ���� üũ
		int leftDir = getLeftDir(curDir);
		int rightDir = getRightDir(curDir);

		if (visited[curY][curX][leftDir] == false) {  // ���� ȸ�� ����
			Point next = { curY, curX, leftDir, curCommand + 1 };
			Q.push(next);
			visited[curY][curX][leftDir] = true;
		}
		if (visited[curY][curX][rightDir] == false) { // ������ ȸ�� ����
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

	// ����� �Է�
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	Start.y = a - 1;
	Start.x = b - 1;
	Start.dir = c;
	Start.command = 0;

	// ������ �Է�
	int d, e, f;
	scanf("%d %d %d", &d, &e, &f);
	End.y = d - 1;
	End.x = e - 1;
	End.dir = f;



	// ����� ��ǥ�� ������ ��ǥ�� ���� ��츦 �������� �Ѵ�!!
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


// ���� �̵� ��ǥ�� 5���� ��츦 �����ؾ� �Ѵ�!
// 1. 1ĭ �̵� (���� ����)
// 2. 2ĭ �̵� (���� ����)
// 3. 3ĭ �̵� (���� ����)
// 4. ���� ��ǥ���� ������ 90�� ȸ��
// 5. ���� ��ǥ���� ���� 90�� ȸ��


// 2,3ĭ �̵��ϴ� ���� �� �� ��ǥ���� ��� 0�̾�� �پ�Ѵ°� �����ϹǷ� �˻� �ʼ�!