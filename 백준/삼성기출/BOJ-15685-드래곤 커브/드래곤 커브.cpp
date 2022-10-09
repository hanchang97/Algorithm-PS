#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N;
int board[105][105] = {0}; // 1이면 드래곤 커브 지나간 자리

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

int changeDir(int dir)
{
	if (dir == 3)
		return 0;
	return dir + 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x, y, d, g;

		cin >> x;
		cin >> y;
		cin >> d;
		cin >> g;

		// 0 세대는 바로 그리기
		board[y][x] = 1;

		y += dy[d];
		x += dx[d];
		board[y][x] = 1;

		vector<int> vDir;
		vDir.push_back(d);

		while (g >= 1)
		{

			int size = vDir.size();
			for (int j = size - 1; j >= 0; j--)
			{
				int nextD = changeDir(vDir[j]);
				vDir.push_back(nextD);
				y += dy[nextD];
				x += dx[nextD];
				board[y][x] = 1;
			}

			g--;
		}
	}

	int cnt = 0;
	for (int i = 0; i <= 99; i++)
	{
		for (int j = 0; j <= 99; j++)
		{
			if (board[i][j] == 1 && board[i + 1][j] == 1 && board[i][j + 1] == 1 && board[i + 1][j + 1] == 1)
				cnt++;
		}
	}

	cout << cnt;

	return 0;
}