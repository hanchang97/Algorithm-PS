
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int N; // ���� ũ��
int map[110][110] = { 0, }; // ����

// �湮üũ
bool visited[110][110] = { 0, };

int dy[4] = { -1, 1, 0, 0 };  // �����¿� ����
int dx[4] = { 0,0,-1,1 };

int Min_dist = 99999999;  // ��� ��쿡�� �ּ� �Ÿ� = ����

struct Point {
	int y;
	int x;
	int dist; // ���������κ����� �Ÿ�
};


// �� ���� ���� ��ȣ �ű��
void numbering(int Num, int y, int x) {

	visited[y][x] = true; // �ѹ��� ���� ���� �湮üũ
	map[y][x] = Num; // ��ȣ �ű��

	pair<int, int> start = { y,x };

	queue<pair<int, int>> Q;
	Q.push(start);

	while (!Q.empty()) {

		int currentY = Q.front().first;
		int currentX = Q.front().second;

		Q.pop();  // pop ������ �ʱ�

		for (int i = 0; i < 4; i++) {
			int nextY = currentY + dy[i];
			int nextX = currentX + dx[i];

			if (nextY < N && nextY >= 0 && nextX < N && nextX >= 0) { // �ε��� ���� üũ
				if (map[nextY][nextX] == 1 && visited[nextY][nextX] == false) {
					visited[nextY][nextX] = true; // �湮üũ
					map[nextY][nextX] = Num; // ��ȣ�ű��

					pair<int, int> next = { nextY, nextX };
					Q.push(next);
				}
			}

		}

	}

}


// �ٸ� �������� �ּҰŸ� ���ϱ�
void getMinDist(int y, int x) {
	bool checked[110][110] = { 0, };

	int curNum = map[y][x]; // 0�� �ƴϸ鼭 curNum�� �ƴ� �ٸ� ���� ��ǥ�� ã�ƾ� �Ѵ�

	Point startPoint = { y,x,0 }; // ���� ��ǥ������ �Ÿ��� 0

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
					if (map[nextY][nextX] == 0) {   // 0�̸� �������� �ϹǷ� ť�� �ֱ�
						checked[nextY][nextX] = true;
						Point nextP = { nextY, nextX, curDist + 1 };
						Q.push(nextP);
					}
					else if (map[nextY][nextX] != 0 && map[nextY][nextX] != curNum) {  // 0�� �ƴϸ鼭 ���� ���� �ƴ� �ٸ� ���� ���� ��츦 ã�� ����
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

	// �� ���� ��ȣ �ű��
	// �� ��ȣ�� 2 ���� ����!

	int number = 2;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == false && map[i][j] == 1) {
				numbering(number, i, j);
				number++;
			}
		}
	}

	// �ѹ��� ����� �Ǿ����� üũ
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}*/

	// �湮üũ �ʱ�ȭ
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}


	// ��� ���� ��ǥ ���鼭 �ٸ� ��������� �ּ� �Ÿ� ���ϱ�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != 0)
				getMinDist(i, j);  // ���� �������� Ž���� �����ؾ��Ѵ�
		}
	}

	printf("%d\n", Min_dist);



	return 0;
}


// ������ ��ȣ�� �Űܼ� ������ �Ѵ�
