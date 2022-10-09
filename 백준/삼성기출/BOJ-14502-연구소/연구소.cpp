#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Point
{
	int y;
	int x;
};

int N, M;
int board[10][10] = {0};
int newBoard[10][10] = {0};
int visited[10][10] = {0};

vector<Point> vPoint; // 벽 후보
vector<Point> vVirus;
vector<int> vVisited;
vector<Point> vSelected; // 벽 세울 3지점 저장

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int maxZeroCnt = 0;

void init()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			newBoard[i][j] = board[i][j];
			visited[i][j] = 0;
		}
	}
}

void setWall()
{
	init();
	queue<Point> q;
	for (int i = 0; i < vSelected.size(); i++)
	{
		int y = vSelected[i].y;
		int x = vSelected[i].x;
		newBoard[y][x] = 1;
	}

	for (int i = 0; i < vVirus.size(); i++)
	{
		q.push(vVirus[i]);
		visited[vVirus[i].y][vVirus[i].x] = 1;
	}

	while (!q.empty())
	{
		int curY = q.front().y;
		int curX = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];

			if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
				continue;
			if (visited[nextY][nextX] || newBoard[nextY][nextX] != 0)
				continue;

			visited[nextY][nextX] = 1;
			newBoard[nextY][nextX] = 2;
			q.push(Point{nextY, nextX});
		}
	}

	int zeroCnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (newBoard[i][j] == 0)
				zeroCnt++;
		}
	}

	if (zeroCnt > maxZeroCnt)
		maxZeroCnt = zeroCnt;
}

void getResult(int toChoose, int inx)
{
	if (toChoose == 0)
	{
		vSelected.clear();
		for (int i = 0; i < vVisited.size(); i++)
		{
			if (vVisited[i] == 1)
			{
				vSelected.push_back(Point{vPoint[i].y, vPoint[i].x});
			}
		}
		setWall();
	}
	else
	{
		for (int i = inx; i < vPoint.size(); i++)
		{
			vVisited[i] = 1;
			getResult(toChoose - 1, i + 1);
			vVisited[i] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cin >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int a;
			cin >> a;
			board[i][j] = a;
			if (a == 0)
			{
				vPoint.push_back(Point{i, j});
				vVisited.push_back(0);
			}
			else if (a == 2)
			{
				vVirus.push_back(Point{i, j});
			}
		}
	}

	getResult(3, 0);

	cout << maxZeroCnt;

	return 0;
}