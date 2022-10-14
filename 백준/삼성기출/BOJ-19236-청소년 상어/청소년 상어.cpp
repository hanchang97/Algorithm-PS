#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

#define DIE -1

int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int maxCnt = 0;

struct Fish
{
	int y;
	int x;
	int dir;
};

void getResult(int board[4][4], Fish fish[16], int sharkY, int sharkX, int sum)
{

	int tempBoard[4][4];
	Fish tempFish[16];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tempBoard[i][j] = board[i][j];
		}
	}
	for (int i = 0; i < 16; i++)
	{
		tempFish[i] = fish[i];
	}

	// 상어가 물고기 먹는다
	int fishNum = tempBoard[sharkY][sharkX];
	int sharkDir = tempFish[fishNum].dir; // 잡아먹은 물고기 방향으로 변경됨

	tempFish[fishNum].y = DIE;
	tempFish[fishNum].x = DIE;
	tempFish[fishNum].dir = DIE;
	tempBoard[sharkY][sharkX] = DIE;

	sum += (fishNum + 1);
	if (sum > maxCnt)
		maxCnt = sum;

	// 물고기들 이동
	for (int i = 0; i < 16; i++)
	{
		if (tempFish[i].y == DIE)
		{
			continue;
		}
		int cy = tempFish[i].y;
		int cx = tempFish[i].x;
		int cDir = tempFish[i].dir;

		int ny = cy + dy[cDir];
		int nx = cx + dx[cDir];
		int nDir = cDir;
		while (ny < 0 || ny >= 4 || nx < 0 || nx >= 4 || (ny == sharkY && nx == sharkX))
		{
			nDir = (nDir + 1) % 8;
			ny = cy + dy[nDir];
			nx = cx + dx[nDir];
		}

		if (tempBoard[ny][nx] != DIE)
		{ // 가려는 곳에 물고기 있다면
			int targetFish = tempBoard[ny][nx];
			tempFish[targetFish].y = cy;
			tempFish[targetFish].x = cx;

			tempFish[i].y = ny;
			tempFish[i].x = nx;
			tempFish[i].dir = nDir;

			tempBoard[ny][nx] = i;
			tempBoard[cy][cx] = targetFish;
		}
		else
		{ // 이동만
			tempFish[i].y = ny;
			tempFish[i].x = nx;
			tempFish[i].dir = nDir;

			tempBoard[ny][nx] = i;
			tempBoard[cy][cx] = DIE;
		}
	}

	// 상어가 이동
	for (int go = 1; go <= 3; go++)
	{
		int ny = sharkY + dy[sharkDir] * go;
		int nx = sharkX + dx[sharkDir] * go;

		if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4)
			break;

		if (tempBoard[ny][nx] != DIE)
		{ // 상어는 물고기가 있는 곳만 이동 가능
			getResult(tempBoard, tempFish, ny, nx, sum);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Fish fish[16];
	int board[4][4]; // 물고기 번호 저장

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int a, b;
			cin >> a >> b;
			a--;
			b--;

			fish[a].y = i;
			fish[a].x = j;
			fish[a].dir = b;
			board[i][j] = a;
		}
	}

	getResult(board, fish, 0, 0, 0); // 상어 초기위치, 먹은 총합

	cout << maxCnt;

	return 0;
}