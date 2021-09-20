#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;  // ����, ���� ����

char Map[11][11];

pair<int, int > Red;  // ���� ���� (y,x)
pair<int, int> Blue; // �Ķ� ���� (y,x)

struct Point {
	int RedY;
	int RedX;
	int BlueY;
	int BlueX;
	int depth;
};

Point P; // �ʱ� ���� ��ġ

int MinDist = 99999999; // ���� �ִܰŸ�


int dy[4] = { -1,1,0,0 };  // �����¿� �̵��� ��� / ������� 0,1,2,3
int dx[4] = { 0,0,-1,1 };

bool visited[11][11][11][11] = { 0, };


//  �ݴ� ���� �˷��ִ� �Լ�
int getInverse(int preDir) {
	if (preDir == 0)
		return 1;
	else if (preDir == 1)
		return 0;
	else if (preDir == 2)
		return 3;
	else if (preDir == 3)
		return 2;
	else
		return -1;
}


void getResult() {

	visited[P.RedY][P.RedX][P.BlueY][P.BlueX] = true;
	queue<Point> queue;
	queue.push(P);

	while (!queue.empty()) {

		Point current = queue.front();
		queue.pop();

		int curRedY = current.RedY;
		int curRedX = current.RedX;
		int curBlueY = current.BlueY;
		int curBlueX = current.BlueX;
		int curDepth = current.depth;

		for (int i = 0; i < 4; i++) {

			bool isRedInHole = false;
			bool isBlueInHole = false;

			int redMoveCount = 0;
			int blueMoveCount = 0;

			int nextRedY = curRedY;
			int nextRedX = curRedX;
			int nextBlueY = curBlueY;
			int nextBlueX = curBlueX;


			// Red ���� �̵� / �̵�Ƚ�� ���� üũ�ϱ�
			while (1) {   // @@@ ������ �����ų� ���� ������ ���� ���� �������� �ִ��� �̵��Ѵ� @@@

				if (Map[nextRedY + dy[i]][nextRedX + dx[i]] == '#') {
					//printf("red met #\n");
					break;
				}
				if (Map[nextRedY + dy[i]][nextRedX + dx[i]] == 'O') {
					isRedInHole = true;
					//printf("red met O\n");
					break;
				}

				nextRedY += dy[i];
				nextRedX += dx[i];
				redMoveCount++;
			}

			// Blue ���� �̵� / �̵�Ƚ�� ���� üũ�ϱ�
			while (1) {
				if (Map[nextBlueY + dy[i]][nextBlueX + dx[i]] == '#') {
					//printf("blue met #\n");
					break;
				}
				if (Map[nextBlueY + dy[i]][nextBlueX + dx[i]] == 'O') {
					isBlueInHole = true;
					//printf("blue met O\n");
					break;
				}

				nextBlueY += dy[i];
				nextBlueX += dx[i];
				blueMoveCount++;

			}

			// ���ۿ� � ���� ������ �Ǵ�
			if (isBlueInHole == true) {
				continue;
			}
			else {
				if (isRedInHole == true) {
					if (curDepth < MinDist)
						MinDist = curDepth;

					continue;
				}
				else { // �� �� ���ۿ� ������ x
					int inverse = getInverse(i);  // ���� ���¿��� �ݴ� ���� �˾ƾ� �Ѵ�

					if (nextRedY == nextBlueY && nextRedX == nextBlueX) { // �� ������ ��ģ ��� -> �̵��Ÿ� ���� ������ �ݴ�� 1ĭ �ٽ� �ű��
						if (redMoveCount > blueMoveCount) {
							nextRedY += dy[inverse];
							nextRedX += dx[inverse];
						}
						else {
							nextBlueY += dy[inverse];
							nextBlueX += dx[inverse];
						}
					}

					// ť�� �ֱ�
					Point nextPoint;
					nextPoint.RedY = nextRedY;
					nextPoint.RedX = nextRedX;
					nextPoint.BlueY = nextBlueY;
					nextPoint.BlueX = nextBlueX;
					nextPoint.depth = curDepth + 1;

					if (visited[nextRedY][nextRedX][nextBlueY][nextBlueX] == false) {  // �̹湮 ���� �湮ó�� ���ֱ�!
						visited[nextRedY][nextRedX][nextBlueY][nextBlueX] = true;
						queue.push(nextPoint);
					}

				}
			}




		}




	}


}


int main() {

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &Map[i][j]);   // ���� ���� �ϳ��� �Է� �޴� ���!
		}
	}

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%c", Map[i][j]);
		}
		printf("\n");
	}*/

	// R, B ��ġ ã�� ��ǥ�θ� �Ǵ��� ���̹Ƿ� '.' ���� ����� �ֱ�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Map[i][j] == 'R') {
				P.RedY = i;
				P.RedX = j;
				Map[i][j] = '.';
			}
			if (Map[i][j] == 'B') {
				P.BlueY = i;
				P.BlueX = j;
				Map[i][j] = '.';
			}
		}
	}

	P.depth = 1;  // �ʱ� ���¿��� depth = 1


	getResult();

	if (MinDist <= 10)
		printf("%d\n", MinDist);
	else
		printf("-1\n");

	return 0;
}


// 1. �ִ� �Ÿ� -> bfs ���
// 2. �Ķ� ������ ���� ������ ���� üũ
// 3. �� ������ ���� �̵��Ѵ� -> �켱 �� ������ ȥ�� �����Ѵٰ� �����ϰ� �̵� -> ���� ��ġ ��ġ�� �̵� �Ÿ� ���� ������ �ݴ�� 1ĭ �ǵ�����