#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

char map[55][55];
bool waterVisit[55][55] = { 0, }; // 고슴도치, 물 공용
bool hedgeVisit[55][55] = { 0, };

int waterTime[55][55] = { 0, }; // 좌표 별 시간 저장
int hedgeTime[55][55] = { 0, };

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int R, C;

struct Point {
	int y;
	int x;
	int time;
};


queue <Point> waterQ;
queue <Point> hedgeQ;

bool isPossible = false;  // 도착지점 못가면 그대로 false 예정
int MinTime = 99999999;

bool isWater = false;

void waterMove() {

	while (!waterQ.empty()) {
		int curY = waterQ.front().y;
		int curX = waterQ.front().x;
		int curTime = waterQ.front().time;

		waterQ.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];
			int nextTime = curTime + 1;

			if (nextY >= 0 && nextY < R && nextX >= 0 && nextX < C) {
				if (map[nextY][nextX] == '.' && waterVisit[nextY][nextX] == false) {
					waterVisit[nextY][nextX] = true;
					Point nextWater = { nextY, nextX, nextTime };
					waterQ.push(nextWater);
					waterTime[nextY][nextX] = nextTime;
				}
			}

		}
	}
}


void hedgeMove() {
	while (!hedgeQ.empty()) {

		int curY = hedgeQ.front().y;
		int curX = hedgeQ.front().x;
		int curTime = hedgeQ.front().time;

		hedgeQ.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];
			int nextTime = curTime + 1;

			if (nextY >= 0 && nextY < R && nextX >= 0 && nextX < C) {

				if (map[nextY][nextX] == 'D') {
					MinTime = nextTime;
					isPossible = true;
					return;
				}

				if (map[nextY][nextX] == '.' && hedgeVisit[nextY][nextX] == false) {
					// 해당 좌표의 시간이 물 이동시간 보다 작아야 한다
					if (waterVisit[nextY][nextX] == true) {
						// 물이 지나간 곳이라면 시간 비교해야 한다
						if (nextTime < waterTime[nextY][nextX]) {
							hedgeVisit[nextY][nextX] = true;
							Point hedge = { nextY, nextX, nextTime };
							hedgeQ.push(hedge);
							hedgeTime[nextY][nextX] = nextTime;
						}
					}
					else { // 물이 갈 수 없는 곳이었으면 
					// 고슴도치는 물 상관없이 인접 경로 모두 고려
						hedgeVisit[nextY][nextX] = true;
						Point hedge = { nextY, nextX, nextTime };
						hedgeQ.push(hedge);
						hedgeTime[nextY][nextX] = nextTime;
					}

				}
			}

		}

	}
}



int main() {

	scanf("%d %d", &R, &C);

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%1s", &map[i][j]);
		}
	}

	// 배열 입력 체크
   /* for(int i = 0; i<R; i++){
	  for(int j = 0; j<C; j++){
		printf("%c", map[i][j]);
	  }
	  printf("\n");
	}*/



	// 고슴도치 출발, 도착지점 저장 &&  초반 물의 위치 큐에 넣기
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {

			if (map[i][j] == 'S') {
				Point hedge = { i,j,0 };
				hedgeQ.push(hedge);
				hedgeVisit[i][j] = true;
				map[i][j] = '.';
			}
			if (map[i][j] == '*') {
				Point water = { i,j,0 };
				waterQ.push(water);
				waterVisit[i][j] = true;
				isWater = true;
			}
		}
	}



	// 물의 이동먼저 체크하기
	if (isWater)
		waterMove();

	// 물 이동 시간 확인
	/*for(int i = 0; i<R; i++){
	  for(int j = 0; j<C; j++){
		printf("%d ", waterTime[i][j]);
	  }
	  printf("\n");
	}*/



	// 고슴도치 이동 -> 다음 이동 위치의 시간이 물의 이동시간 보다 작으면 이동 가능
	hedgeMove();

	/*for(int i = 0; i<R; i++){  // 고슴도치 경로 별 시간 확인
	  for(int j = 0; j<C; j++){
		printf("%d ", hedgeTime[i][j]);
	  }
	  printf("\n");
	}*/



	if (isPossible == true)
		printf("%d\n", MinTime);
	else
		printf("KAKTUS\n");


	return 0;
}


// 놓칠 수 있는 부분
// 1. 물이 애초에 존재하지 않을 수 있다
// 2. 물이 있는 경우 고슴도치와 물의 시간비교가 필요한데 이 때 애초에 물은 가지 못하고 고슴도치만 갈 수 있는 경로라면
//     시간 비교 없이 진행해야 한다