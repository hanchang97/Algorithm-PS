#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;  // 세로, 가로 길이

char Map[11][11];

pair<int, int > Red;  // 빨간 구슬 (y,x)
pair<int, int> Blue; // 파란 구슬 (y,x)

struct Point {
	int RedY;
	int RedX;
	int BlueY;
	int BlueX;
	int depth;
};

Point P; // 초기 구슬 위치

int MinDist = 99999999; // 최종 최단거리


int dy[4] = { -1,1,0,0 };  // 상하좌우 이동에 사용 / 순서대로 0,1,2,3
int dx[4] = { 0,0,-1,1 };

bool visited[11][11][11][11] = { 0, };


//  반대 방향 알려주는 함수
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


			// Red 구슬 이동 / 이동횟수 같이 체크하기
			while (1) {   // @@@ 구멍을 만나거나 벽을 만날때 까지 현재 방향으로 최대한 이동한다 @@@

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

			// Blue 구슬 이동 / 이동횟수 같이 체크하기
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

			// 구멍에 어떤 구슬 들어갔는지 판단
			if (isBlueInHole == true) {
				continue;
			}
			else {
				if (isRedInHole == true) {
					if (curDepth < MinDist)
						MinDist = curDepth;

					continue;
				}
				else { // 둘 다 구멍에 빠지지 x
					int inverse = getInverse(i);  // 현재 상태에서 반대 방향 알아야 한다

					if (nextRedY == nextBlueY && nextRedX == nextBlueX) { // 두 구슬이 겹친 경우 -> 이동거리 많은 구슬은 반대로 1칸 다시 옮기기
						if (redMoveCount > blueMoveCount) {
							nextRedY += dy[inverse];
							nextRedX += dx[inverse];
						}
						else {
							nextBlueY += dy[inverse];
							nextBlueX += dx[inverse];
						}
					}

					// 큐에 넣기
					Point nextPoint;
					nextPoint.RedY = nextRedY;
					nextPoint.RedX = nextRedX;
					nextPoint.BlueY = nextBlueY;
					nextPoint.BlueX = nextBlueX;
					nextPoint.depth = curDepth + 1;

					if (visited[nextRedY][nextRedX][nextBlueY][nextBlueX] == false) {  // 미방문 지점 방문처리 해주기!
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
			scanf(" %c", &Map[i][j]);   // 붙은 문자 하나씩 입력 받는 경우!
		}
	}

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%c", Map[i][j]);
		}
		printf("\n");
	}*/

	// R, B 위치 찾고 좌표로만 판단할 것이므로 '.' 으로 만들어 주기
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

	P.depth = 1;  // 초기 상태에서 depth = 1


	getResult();

	if (MinDist <= 10)
		printf("%d\n", MinDist);
	else
		printf("-1\n");

	return 0;
}


// 1. 최단 거리 -> bfs 기반
// 2. 파란 구슬이 구멍 들어갔는지 먼저 체크
// 3. 두 구슬이 같이 이동한다 -> 우선 각 구슬이 혼자 존재한다고 가정하고 이동 -> 최종 위치 겹치면 이동 거리 많은 구슬을 반대로 1칸 되돌린다