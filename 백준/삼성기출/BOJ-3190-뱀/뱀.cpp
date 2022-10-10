#include <string>
#include <vector>
#include <map>
#include <deque>
#include <iostream>

using namespace std;

struct Point
{
	int y;
	int x;
};

int N, K, L;
int board[105][105] = {0}; // 1 = 뱀, 2 = 사과

int dy[4] = {0, 1, 0, -1}; // 우 하 좌 상
int dx[4] = {1, 0, -1, 0}; // 오른쪽 회전 = +1, 왼쪽 회전 = -1

map<int, char> mRotate; // <시간, 회전방향>
deque<Point> dPoint;

int dir = 0; // 최초 방향은 오른쪽

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int y, x;
		cin >> y;
		cin >> x;
		y--;
		x--;
		board[y][x] = 2;
	}

	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int time;
		char rotate;
		cin >> time;
		cin >> rotate;
		mRotate[time] = rotate;
	}

	board[0][0] = 1;
	dPoint.push_back(Point{0, 0});
	int time = 0;

	while (true)
	{
		time++;
		int curHeadY = dPoint.front().y;
		int curHeadX = dPoint.front().x;
		int nextHeadY = curHeadY + dy[dir];
		int nextHeadX = curHeadX + dx[dir];

		if (nextHeadY < 0 || nextHeadY >= N || nextHeadX < 0 || nextHeadX >= N)
			break;
		if (board[nextHeadY][nextHeadX] == 1)
			break;

		if (board[nextHeadY][nextHeadX] == 2)
		{
			board[nextHeadY][nextHeadX] = 1;
			dPoint.push_front(Point{nextHeadY, nextHeadX});
		}
		else if (board[nextHeadY][nextHeadX] == 0)
		{
			int tailY = dPoint.back().y; // 꼬리 제거
			int tailX = dPoint.back().x;
			dPoint.pop_back();
			board[tailY][tailX] = 0;

			dPoint.push_front(Point{nextHeadY, nextHeadX});
			board[nextHeadY][nextHeadX] = 1;
		}

		if (mRotate[time] != 0)
		{
			if (mRotate[time] == 'D')
			{
				dir += 1;
			}
			else
			{
				dir -= 1;
			}

			if (dir > 3)
				dir = 0;
			else if (dir < 0)
				dir = 3;
		}
	}

	cout << time;

	return 0;
}