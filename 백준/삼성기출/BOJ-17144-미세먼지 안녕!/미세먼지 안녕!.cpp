#include <string>
#include <vector>
#include <iostream>

using namespace std;

int R, C, T;
int board[51][51] = {0};

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int airUpY, airX;
int airDownY;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> R;
	cin >> C;
	cin >> T;

	bool check = true;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			int a;
			cin >> a;
			board[i][j] = a;
			if (a == -1 && check)
			{
				airUpY = i;
				airX = j;
				airDownY = i + 1;
				check = false;
			}
		}
	}


	while (T > 0)
	{

		int nBoard[51][51] = {0};
		nBoard[airUpY][airX] = -1;
		nBoard[airDownY][airX] = -1;

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (board[i][j] > 0)
				{
					int spreadCnt = 0;

					for (int k = 0; k < 4; k++)
					{
						int nextY = i + dy[k];
						int nextX = j + dx[k];

						if (nextY < 0 || nextY >= R || nextX < 0 || nextX >= C)
							continue;
						if ((nextY == airUpY && nextX == airX) || (nextY == airDownY && nextX == airX))
							continue;

						spreadCnt++;
						nBoard[nextY][nextX] += board[i][j] / 5;
					}

					nBoard[i][j] += (board[i][j] - (board[i][j] / 5 * spreadCnt));
				}
			}
		}

		// 공기청정기 위쪽
		// 1. 공기청정기 위 0열 라인
		for (int i = airUpY - 1; i > 0; i--)
		{
			nBoard[i][airX] = nBoard[i - 1][airX];
		}

		// 2. 0행 라인
		for (int j = 0; j < C - 1; j++)
		{
			nBoard[0][j] = nBoard[0][j + 1];
		}

		// 3. C-1열 라인
		for (int i = 0; i < airUpY; i++)
		{
			nBoard[i][C - 1] = nBoard[i + 1][C - 1];
		}

		// 4. 공기청정기 위쪽 행 라인
		for (int j = C - 1; j >= 2; j--)
		{
			nBoard[airUpY][j] = nBoard[airUpY][j - 1];
		}
		nBoard[airUpY][1] = 0;

		//////

		// 공기청정기 아래쪽
		// 1. 공기청정기 아래 0열 라인
		for (int i = airDownY + 1; i < R - 1; i++)
		{
			nBoard[i][airX] = nBoard[i + 1][airX];
		}

		// 2. R-1행 라인
		for (int j = 0; j < C - 1; j++)
		{
			nBoard[R - 1][j] = nBoard[R - 1][j + 1];
		}

		// 3. C-1열 라인
		for (int i = R - 1; i > airDownY; i--)
		{
			nBoard[i][C - 1] = nBoard[i - 1][C - 1];
		}

		// 4. 공기청정기 아래쪽 행 라인
		for (int j = C - 1; j >= 2; j--)
		{
			nBoard[airDownY][j] = nBoard[airDownY][j - 1];
		}
		nBoard[airDownY][1] = 0;

		// board update
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				board[i][j] = nBoard[i][j];
			}
		}

		T--;
	}

	// total
	int total = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (board[i][j] > 0)
				total += board[i][j];
		}
	}

	cout << total;

	return 0;
}