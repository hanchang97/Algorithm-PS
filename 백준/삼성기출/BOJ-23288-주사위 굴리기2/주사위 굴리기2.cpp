#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int N, M, K;
int board[22][22] = {0};
int dice[7] = {0, 3, 4, 5, 2, 1, 6}; // inx 1 부터 동, 서, 남, 북, 위, 아래

int dy[4] = {0, 1, 0, -1}; // 동 남 서 북
int dx[4] = {1, 0, -1, 0};

void move(int dir)
{
	// dir = 방금 구른 방향
	int tDice[7] = {0};
	if (dir == 0)
	{ // 동
		tDice[1] = dice[5];
		tDice[2] = dice[6];
		tDice[3] = dice[3];
		tDice[4] = dice[4];
		tDice[5] = dice[2];
		tDice[6] = dice[1];
	}
	else if (dir == 1)
	{ // 남
		tDice[1] = dice[1];
		tDice[2] = dice[2];
		tDice[3] = dice[5];
		tDice[4] = dice[6];
		tDice[5] = dice[4];
		tDice[6] = dice[3];
	}
	else if (dir == 2)
	{ // 서
		tDice[1] = dice[6];
		tDice[2] = dice[5];
		tDice[3] = dice[3];
		tDice[4] = dice[4];
		tDice[5] = dice[1];
		tDice[6] = dice[2];
	}
	else
	{ // dir == 3 북
		tDice[1] = dice[1];
		tDice[2] = dice[2];
		tDice[3] = dice[6];
		tDice[4] = dice[5];
		tDice[5] = dice[3];
		tDice[6] = dice[4];
	}

	for (int i = 1; i <= 6; i++)
	{
		dice[i] = tDice[i];
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
		for (int j = 0; j < M; j++)
		{
			int a;
			cin >> a;
			board[i][j] = a;
		}
	}

	int curY = 0; // 시작 좌표
	int curX = 0;
	int curDir = 0; // 동쪽으로 시작
	int totalScore = 0;

	while (K--)
	{
		int ny = curY + dy[curDir];
		int nx = curX + dx[curDir];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
		{ // 다음칸이 범위 벗어나면 반대방향으로
			curDir += 2;
			if (curDir == 4)
				curDir = 0;
			else if (curDir == 5)
				curDir = 1;

			ny = curY + dy[curDir];
			nx = curX + dx[curDir];
		}

		curY = ny;
		curX = nx;

		move(curDir); // 주사위 curY, curX 로 이동

		// 다음 방향 정하기
		if (dice[6] > board[curY][curX])
			curDir++;
		else if (dice[6] < board[curY][curX])
			curDir--;

		if (curDir > 3)
			curDir = 0;
		else if (curDir < 0)
			curDir = 3;

		int cnt = 1;
		int visited[22][22] = {0};
		queue<pair<int, int>> q;
		visited[curY][curX] = 1;
		q.push(make_pair(curY, curX));

		while (!q.empty())
		{
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();
			for (int t = 0; t < 4; t++)
			{
				int nextY = cy + dy[t];
				int nextX = cx + dx[t];

				if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
					continue;
				if (board[nextY][nextX] != board[curY][curX] || visited[nextY][nextX])
					continue;

				cnt++;
				visited[nextY][nextX] = 1;
				q.push(make_pair(nextY, nextX));
			}
		}

		totalScore += cnt * board[curY][curX];
	}

	cout << totalScore;

	return 0;
}