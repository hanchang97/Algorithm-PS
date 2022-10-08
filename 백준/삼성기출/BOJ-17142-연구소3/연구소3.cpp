#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

#define MAX 100000000

int N, M;

int board[51][51] = {0};
int curBoard[51][51] = {0};
int visited[51][51] = {0};

int totalMinTime = MAX;

vector<pair<int, int>> vVirus;
vector<pair<int, int>> vActivatedVirus;
vector<pair<int, int>> vInActivatedVirus;
vector<int> vVisited;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void clearVisited()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visited[i][j] = 0;
		}
	}
}

void clearCurBoard()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			curBoard[i][j] = board[i][j];
		}
	}
}

void spreadVirus()
{
	clearVisited();
	clearCurBoard();

	queue<pair<int, int>> q;
	for (int i = 0; i < vActivatedVirus.size(); i++)
	{ // 활성화시킨 바이러스 넣기 = 1로 시작 -> 마지막에 최대 시간에서 1 다시 빼주기
		int y = vActivatedVirus[i].first;
		int x = vActivatedVirus[i].second;

		curBoard[y][x] = 1;
		q.push(make_pair(y, x));
		visited[y][x] = 1;
	}

	while (!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;
		int curTime = curBoard[curY][curX];
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];
			int nextTime = curTime + 1;

			if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
				continue;
			if (visited[nextY][nextX])
				continue;

			if (curBoard[nextY][nextX] == 0 || curBoard[nextY][nextX] == -2)
			{ // 처음보는 빈칸 || 비활성 바이러스 방문 시
				visited[nextY][nextX] = 1;
				curBoard[nextY][nextX] = nextTime;
				q.push(make_pair(nextY, nextX));
			}
		}
	}

	int curMaxTime = 0;
	bool isAll = true;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			bool isInActivatedVirus = false;
			for (int k = 0; k < vInActivatedVirus.size(); k++)
			{
				if (i == vInActivatedVirus[k].first && j == vInActivatedVirus[k].second)
				{
					isInActivatedVirus = true;
					break;
				}
			}

			if (!isInActivatedVirus)
			{
				if (curBoard[i][j] > curMaxTime)
				{
					curMaxTime = curBoard[i][j];
				}

				if (curBoard[i][j] == 0)
				{
					isAll = false;
				}
			}
		}
	}

	if (isAll)
	{
		if (curMaxTime < totalMinTime)
			totalMinTime = curMaxTime;
	}
}

void getResult(int toChoose, int startInx)
{
	if (toChoose == 0)
	{
		// 활성화시킬 바이러스 저장
		vActivatedVirus.clear();
		vInActivatedVirus.clear();

		for (int i = 0; i < vVisited.size(); i++)
		{
			if (vVisited[i])
			{
				vActivatedVirus.push_back(make_pair(vVirus[i].first, vVirus[i].second));
			}
			else
			{
				vInActivatedVirus.push_back(make_pair(vVirus[i].first, vVirus[i].second));
			}
		}

		spreadVirus();
	}
	else
	{
		for (int i = startInx; i < vVirus.size(); i++)
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
		for (int j = 0; j < N; j++)
		{
			int a;
			cin >> a;
			if (a == 2)
			{
				vVirus.push_back(make_pair(i, j));
				vVisited.push_back(0);
				board[i][j] = -2;
			}
			else if (a == 1)
			{
				board[i][j] = -1;
			}
			else
			{
				board[i][j] = 0;
			}
		}
	}

	getResult(M, 0);

	if (totalMinTime == MAX)
		cout << -1;
	else
		cout << totalMinTime - 1;

	return 0;
}