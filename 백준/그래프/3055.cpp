#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

char map[55][55];
bool waterVisit[55][55] = { 0, }; // ����ġ, �� ����
bool hedgeVisit[55][55] = { 0, };

int waterTime[55][55] = { 0, }; // ��ǥ �� �ð� ����
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

bool isPossible = false;  // �������� ������ �״�� false ����
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
					// �ش� ��ǥ�� �ð��� �� �̵��ð� ���� �۾ƾ� �Ѵ�
					if (waterVisit[nextY][nextX] == true) {
						// ���� ������ ���̶�� �ð� ���ؾ� �Ѵ�
						if (nextTime < waterTime[nextY][nextX]) {
							hedgeVisit[nextY][nextX] = true;
							Point hedge = { nextY, nextX, nextTime };
							hedgeQ.push(hedge);
							hedgeTime[nextY][nextX] = nextTime;
						}
					}
					else { // ���� �� �� ���� ���̾����� 
					// ����ġ�� �� ������� ���� ��� ��� ���
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

	// �迭 �Է� üũ
   /* for(int i = 0; i<R; i++){
	  for(int j = 0; j<C; j++){
		printf("%c", map[i][j]);
	  }
	  printf("\n");
	}*/



	// ����ġ ���, �������� ���� &&  �ʹ� ���� ��ġ ť�� �ֱ�
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



	// ���� �̵����� üũ�ϱ�
	if (isWater)
		waterMove();

	// �� �̵� �ð� Ȯ��
	/*for(int i = 0; i<R; i++){
	  for(int j = 0; j<C; j++){
		printf("%d ", waterTime[i][j]);
	  }
	  printf("\n");
	}*/



	// ����ġ �̵� -> ���� �̵� ��ġ�� �ð��� ���� �̵��ð� ���� ������ �̵� ����
	hedgeMove();

	/*for(int i = 0; i<R; i++){  // ����ġ ��� �� �ð� Ȯ��
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


// ��ĥ �� �ִ� �κ�
// 1. ���� ���ʿ� �������� ���� �� �ִ�
// 2. ���� �ִ� ��� ����ġ�� ���� �ð��񱳰� �ʿ��ѵ� �� �� ���ʿ� ���� ���� ���ϰ� ����ġ�� �� �� �ִ� ��ζ��
//     �ð� �� ���� �����ؾ� �Ѵ�