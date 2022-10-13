#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int N, Q;
int board[65][65] = {0};

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void rotate(int cy, int cx, int len, int unit)
{ // cy, cx 는 현재 unit 에서 좌측 상단
	if (len == unit)
	{ // unit 은 쪼갤 단위
		int tempBoard[65][65] = {0};
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
			{
				tempBoard[cy + j][cx + len - 1 - i] = board[cy + i][cx + j];
				// [i][j] 에서 90 도 돌리면 [j][N-i-1] (inx 가 0부터 시작한다면)
				// 실제 좌표가 아닌 현재 구역에서의 상대적인 i, j 위치를 사용!
			}
		}

		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
			{
				board[cy + i][cx + j] = tempBoard[cy + i][cx + j];
			}
		}

		return;
	}

	len /= 2; // 한 번 쪼깰때 마다 4구역으로 나뉨
	rotate(cy, cx, len, unit);
	rotate(cy + len, cx, len, unit);
	rotate(cy, cx + len, len, unit);
	rotate(cy + len, cx + len, len, unit);
}

void melt()
{
	int len = (1 << N);
	int tempBoard[65][65] = {0};
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			int cnt = 0;
			for (int k = 0; k < 4; k++)
			{
				int nextY = i + dy[k];
				int nextX = j + dx[k];

				if (nextY < 0 || nextY >= len || nextX < 0 || nextX >= len)
					continue;
				if (board[nextY][nextX] == 0)
					continue;

				cnt++;
			}

			if (cnt >= 3 || board[i][j] == 0)
			{ // 원래 얼음이 없던 곳은 계산에서 제외
				tempBoard[i][j] = board[i][j];
			}
			else
			{
				tempBoard[i][j] = board[i][j] - 1;
			}
		}
	}

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			board[i][j] = tempBoard[i][j];
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> Q;

	int len = (1 << N);

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			int a;
			cin >> a;
			board[i][j] = a;
		}
	}

	while (Q--)
	{ // Q번 반복
		int L;
		cin >> L;

		if (L > 0)
		{ // L == 0 -> 원 상태 그대로,  2^0 = 1
			rotate(0, 0, len, (1 << L));
		}
		melt();
	}

	int totalIce = 0;
	int maxSize = 0;
	int visited[65][65] = {0};

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			totalIce += board[i][j];
			if (visited[i][j] == 0 && board[i][j] != 0)
			{
				visited[i][j] = 1;
				int cnt = 1;
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));

				while (!q.empty())
				{
					int curY = q.front().first;
					int curX = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++)
					{
						int nextY = curY + dy[k];
						int nextX = curX + dx[k];

						if (nextY < 0 || nextY >= len || nextX < 0 || nextX >= len)
							continue;
						if (board[nextY][nextX] == 0 || visited[nextY][nextX])
							continue;

						cnt++;
						q.push(make_pair(nextY, nextX));
						visited[nextY][nextX] = 1;
					}
				}

				if (cnt > maxSize)
					maxSize = cnt;
			}
		}
	}

	cout << totalIce << "\n"
		 << maxSize;

	return 0;
}