#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAX 999999999

struct BabyShark
{
	int y;
	int x;
	int size;
	int eatCount;
};

struct Point
{
	int y;
	int x;
};

int N;
int board[21][21] = {0};
int timeBoard[21][21] = {0};
int visited[21][21] = {0};

BabyShark bbs;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void clear()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visited[i][j] = 0;
			timeBoard[i][j] = 0;
		}
	}
}

bool compare(const Point &fir, const Point &sec)
{
	if (fir.y == sec.y)
		return fir.x < sec.x;
	return fir.y < sec.y;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	bbs.size = 2; // 최초 크기
	bbs.eatCount = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int a;
			cin >> a;
			board[i][j] = a;
			if (a == 9)
			{
				bbs.y = i;
				bbs.x = j;
				board[i][j] = 0; // board는 물고기 정보를 나타낼 것이므로 아기상어 위치만 파악하고 0으로 할당하기
			}
		}
	}

	int totalTime = 0;
	while (true)
	{
		clear();

		queue<Point> q;
		q.push(Point{bbs.y, bbs.x});
		visited[bbs.y][bbs.x] = 1;

		vector<Point> vPossible;

		int minTime = MAX;

		while (!q.empty())
		{
			int curY = q.front().y;
			int curX = q.front().x;
			int curTime = timeBoard[curY][curX];
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nextY = curY + dy[i];
				int nextX = curX + dx[i];
				int nextTime = curTime + 1;

				if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
					continue;
				if (visited[nextY][nextX] || bbs.size < board[nextY][nextX]) // 자기보다 큰 물고기 있는데는 못 지나간다
					continue;

				visited[nextY][nextX] = 1;
				timeBoard[nextY][nextX] = nextTime;
				q.push(Point{nextY, nextX});

				if (bbs.size > board[nextY][nextX] && board[nextY][nextX] != 0)
				{
					if (nextTime < minTime)  // 처음 이곳에 온 시간이 최소시간
					{
						minTime = nextTime;
						vPossible.push_back(Point{nextY, nextX});
					}
					else if (nextTime == minTime) // 최소시간 같다면 후보로 등록
					{
						vPossible.push_back(Point{nextY, nextX});
					}
				}
			}
		}

		if (minTime == MAX)
		{ // 먹을 물고기가 없었다
			break;
		}
		else
		{
			totalTime += minTime;
			sort(vPossible.begin(), vPossible.end(), compare); // 우선순위 맞게 후보 물고기들 정렬

			board[vPossible[0].y][vPossible[0].x] = 0; // 먹은 물고기 없애기
			bbs.y = vPossible[0].y;	// 아기상어 위치 갱신
			bbs.x = vPossible[0].x;
			bbs.eatCount += 1; // 먹은 개수 증가
			if (bbs.eatCount == bbs.size)
			{ // 먹은 개수 크기와 같으면 크기 1증가, 먹은 개수는 다시 0
				bbs.size += 1;
				bbs.eatCount = 0;
			}
		}
	}

	cout << totalTime;

	return 0;
}