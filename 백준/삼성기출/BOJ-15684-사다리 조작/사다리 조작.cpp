#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

#define MAX 99999999

int N, M, H;
int board[32][12] = {0}; // 1 이면 가로선 존재

int minCnt = MAX;

bool checkLine()
{
	bool isPossible = true;
	for (int j = 1; j <= N; j++)
	{
		int lineNum = j;
		int y = 1;
		while (y <= H)
		{ // 0번 열은 무조건 0
			if (board[y][lineNum] == 1)
			{
				lineNum += 1;
			}
			else if (board[y][lineNum - 1] == 1)
			{
				lineNum -= 1;
			}
			y++;
		}

		if (lineNum != j)
		{
			isPossible = false;
			break;
		}
	}

	return isPossible;
}

void getResult(int toChoose, int cur, int startY, int startX)
{
	if (cur == toChoose)
	{
		if (checkLine())
		{
			if (toChoose < minCnt)
				minCnt = toChoose;
		}
		return;
	}
	else
	{
		for (int i = startY; i <= H; i++)
		{
			for (int j = startX; j <= N; j++)
			{
				if (board[i][j] == 0)
				{
					bool isPossible = true;
					if (j - 1 >= 1)
					{
						if (board[i][j - 1] == 1)
							isPossible = false;
					}
					if (j + 1 <= N)
					{
						if (board[i][j + 1] == 1)
							isPossible = false;
					}
					if (isPossible)
					{
						board[i][j] = 1;
						int tempY = i;
						int tempX = j;
						if (tempX + 1 > N)
						{
							tempY += 1;
						}

						getResult(toChoose, cur + 1, tempY, 1);
						// 1,1 부터 다시 체크할 필요 없으므로!
						board[i][j] = 0;
					}
				}
			}
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
	cin >> H;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a;
		cin >> b;
		board[a][b] = 1;
	}

	for (int i = 0; i <= 3; i++)
	{
		getResult(i, 0, 1, 1);
	}

	if (minCnt == MAX)
		minCnt = -1;

	cout << minCnt;

	return 0;
}