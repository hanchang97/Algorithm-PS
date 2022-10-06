#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N;
int board[25][25] = {0};   // 자리
int student[410][5] = {0}; // 좋아하는 학생 정보 / inx 0 = 학생번호

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

struct Point
{
	int y;
	int x;
	int likeCnt;
	int emptyCnt;
};

bool compare(const Point &first, const Point &second)
{
	if (first.likeCnt > second.likeCnt)
		return true;
	else if (first.likeCnt < second.likeCnt)
		return false;
	else
	{
		if (first.emptyCnt > second.emptyCnt)
			return true;
		else if (first.emptyCnt < second.emptyCnt)
			return false;
		else
		{
			if (first.y == second.y)
				return first.x < second.x;
			return first.y < second.y;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N * N; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int a;
			cin >> a;
			student[i][j] = a;
		}
	}

	for (int k = 0; k < N * N; k++)
	{
		int curStudent = student[k][0];
		vector<Point> vPoint;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (board[i][j] != 0)
					continue;

				int likeCnt = 0;
				int emptyCnt = 0;
				for (int t = 0; t < 4; t++)
				{
					int nextY = i + dy[t];
					int nextX = j + dx[t];

					if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
						continue;

					if (board[nextY][nextX] == 0)
					{
						emptyCnt++;
						continue;
					}

					for (int q = 1; q <= 4; q++)
					{
						if (board[nextY][nextX] == student[k][q])
						{
							likeCnt++;
							break;
						}
					}
				}

				Point point;
				point.y = i;
				point.x = j;
				point.likeCnt = likeCnt;
				point.emptyCnt = emptyCnt;

				vPoint.push_back(point);
			}
		}

		sort(vPoint.begin(), vPoint.end(), compare);
		Point curPoint = vPoint[0];


		board[curPoint.y][curPoint.x] = curStudent;
	}

	int total = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int curStudent = board[i][j];

			int inx = 0;
			for (int u = 0; u < N * N; u++)
			{
				if (student[u][0] == curStudent)
				{
					inx = u;
					break;
				}
			}

			int cnt = 0;
			for (int k = 0; k < 4; k++)
			{
				int nextY = i + dy[k];
				int nextX = j + dx[k];

				if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
					continue;

				for (int t = 1; t <= 4; t++)
				{
					if (board[nextY][nextX] == student[inx][t])
					{
						cnt++;
						break;
					}
				}
			}

			if (cnt == 1)
				total += 1;
			else if (cnt == 2)
				total += 10;
			else if (cnt == 3)
				total += 100;
			else if (cnt == 4)
				total += 1000;
		}
	}

	cout << total << "\n";

	return 0;
}