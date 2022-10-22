#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int T;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

struct Point
{
	int y, x;
};

int solve(int board[50][50], int N, int M)
{
	int totalCount = 0;

	int visited[50][50] = {0};

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 1 && visited[i][j] == 0)
			{
				visited[i][j] = 1;
				totalCount++;

				queue<Point> q;
				q.push(Point{i, j});

				while (!q.empty())
				{
					int cy = q.front().y;
					int cx = q.front().x;
					q.pop();
					for (int d = 0; d < 4; d++)
					{
						int ny = cy + dy[d];
						int nx = cx + dx[d];
						if (ny < 0 || ny >= N || nx < 0 || nx >= M)
							continue;
						if (board[ny][nx] == 0 || visited[ny][nx])
							continue;
						visited[ny][nx] = 1;
						q.push(Point{ny, nx});
					}
				}
			}
		}
	}

	return totalCount;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int M, N, K;
		cin >> M >> N >> K;

		int board[50][50] = {0};
		for (int k = 0; k < K; k++)
		{
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;
		}

		int totalCount = solve(board, N, M);
		cout << totalCount << "\n";
	}

	return 0;
}
