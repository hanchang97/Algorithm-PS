#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int visited[105][105] = {0,};
int n, m = 0;

void bfs(vector<vector<int>> maps)
{
	n = maps.size() - 1;
	m = maps[0].size() - 1;

	visited[0][0] = 1;

	queue<pair<int, int>> q;
	q.push({0, 0});

	while (!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];

			if (nextY < 0 || nextY > n || nextX < 0 || nextX > m)
				continue;
			if (maps[nextY][nextX] == 0 || visited[nextY][nextX] != 0)
				continue;

			visited[nextY][nextX] = visited[curY][curX] + 1;
			q.push({nextY, nextX});
			if (nextY == n && nextX == m)
				return;
		}
	}
}

int solution(vector<vector<int>> maps)
{
	bfs(maps);

	if (visited[n][m] == 0)
		return -1;
	else
		return visited[n][m];
}