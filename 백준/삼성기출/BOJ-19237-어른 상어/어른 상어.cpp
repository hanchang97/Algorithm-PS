#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

struct Shark
{
	int y;
	int x;
	int dir;
	int priority[4][4];
};

int N, M, K;
int board[21][21][3] = {0}; // 0 = 상어 번호, 1 = 냄새 주인 상어 번호, 2 = 냄새의 강도
Shark shark[400];

int totalTime;

void solve()
{
	int time = 0;
	int killCount = 0;

	while (time <= 1000)
	{
		time++;

		// 냄새 -1 하기
		int newBoard[21][21][3] = {0};
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				newBoard[i][j][0] = board[i][j][0];
				newBoard[i][j][2] = board[i][j][2];
				if (newBoard[i][j][2] > 0)
				{
					newBoard[i][j][2] -= 1; // 냄새 -1
				}
				if (newBoard[i][j][2] > 0)
				{
					newBoard[i][j][1] = board[i][j][1]; // 냄새 아직 존재하면 주인 복사
				}
			}
		}

		// 상어 이동
		for (int i = 0; i < M; i++)
		{
			int cy = shark[i].y;
			int cx = shark[i].x;
			int cDir = shark[i].dir;
			if (cy == -1)
			{
				continue; // 죽은 상어라면 스킵
			}

			bool isMoved = false;
			for (int d = 0; d < 4; d++)
			{
				int nd = shark[i].priority[cDir][d]; // 우선순위에 따른 방향, 애초에 우선순위에 따라 탐색한다
				int ny = cy + dy[nd];
				int nx = cx + dx[nd];
				if (ny < 0 || ny >= N || nx < 0 || nx >= N || board[ny][nx][2] != 0)
				{			  // 냄새 없는 곳 우선 살펴보기
					continue; // 이동 후 냄새 뿌리므로  냄새 없는 곳 판단 시 board 사용
				}

				isMoved = true;
				newBoard[cy][cx][0] = 0; // 이동해서 살든 죽든 현재 보드판에서는 없어짐
				if (newBoard[ny][nx][0] == 0)
				{								 // 보드에는 실제 상어 번호 저장하므로 +1
					newBoard[ny][nx][0] = i + 1; // 상어 번호
					newBoard[ny][nx][1] = i + 1; // 냄새 주인
					newBoard[ny][nx][2] = K;	 // 냄새 갱신

					shark[i].y = ny;
					shark[i].x = nx;
					shark[i].dir = nd;
				}
				else
				{ // 이동시킬 공간에 상어가 있는 경우
					//현재 낮은 상어 번호부터 검사하고 있으므로 가려는 곳에 상어가 있다면 무조건 자기보다 낮은 번호임
					killCount++;
					shark[i].y = -1;
				}
				break; // 이동했으므로
			}

			if (!isMoved)
			{ // 주위에 빈칸이 1개도 없었으면 여기로 온다
				for (int d = 0; d < 4; d++)
				{
					int nd = shark[i].priority[cDir][d];
					int ny = cy + dy[nd];
					int nx = cx + dx[nd];
					if (ny < 0 || ny >= N || nx < 0 || nx >= N)
					{
						continue;
					}
					if (board[ny][nx][2] != 0 && board[ny][nx][1] != i + 1)
					{ // 사실 자기 냄새는 반드시 한 곳에는 있다!!!
						continue;
					}
					isMoved = true;
					newBoard[cy][cx][0] = 0;
					if (newBoard[ny][nx][0] == 0)
					{
						newBoard[ny][nx][0] = i + 1; // 상어 번호
						newBoard[ny][nx][1] = i + 1; // 냄새 주인
						newBoard[ny][nx][2] = K;	 // 냄새 갱신

						shark[i].y = ny;
						shark[i].x = nx;
						shark[i].dir = nd;
					}
					else
					{
						killCount++;
						shark[i].y = -1;
					}
					break;
				}
			}
		}

		if (killCount == M - 1)
		{ // 번호 가장 작은 상어 하나만 남음
			break;
		}

		// 한 턴 끝나면 기존 board 갱신
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				board[i][j][0] = newBoard[i][j][0];
				board[i][j][1] = newBoard[i][j][1];
				board[i][j][2] = newBoard[i][j][2];
			}
		}
	}
	if (time <= 1000)
	{
		totalTime = time;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int a;
			cin >> a;
			board[i][j][0] = a;
			if (a != 0)
			{
				int sharkInx = board[i][j][0] - 1;
				shark[sharkInx].y = i;
				shark[sharkInx].x = j;
				board[i][j][1] = board[i][j][0];
				board[i][j][2] = K;
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		int d;
		cin >> d;
		d--;
		shark[i].dir = d;
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int d1, d2, d3, d4;
			cin >> d1 >> d2 >> d3 >> d4;
			d1--;
			d2--;
			d3--;
			d4--;
			shark[i].priority[j][0] = d1;
			shark[i].priority[j][1] = d2;
			shark[i].priority[j][2] = d3;
			shark[i].priority[j][3] = d4;
		}
	}

	totalTime = -1;
	solve();

	cout << totalTime;

	return 0;
}