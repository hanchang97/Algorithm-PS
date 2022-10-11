#include <string>
#include <vector>
#include <map>
#include <deque>
#include <iostream>

using namespace std;

int N, L;
int board[105][105] = {0};

int runwayCheckY[105][105] = {0}; // 행 판단용
int runwayCheckX[105][105] = {0};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cin >> L;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int a;
			cin >> a;
			board[i][j] = a;
		}
	}

	int cnt = 0; // 가능한 경로 개수

	// 행 판단
	for (int i = 0; i < N; i++)
	{
		bool isPossible = true;
		for (int j = 0; j < N - 1; j++)
		{
			if (board[i][j] != board[i][j + 1])
			{
				int gap = board[i][j + 1] - board[i][j];
				if (gap == 1)
				{
					int startInx = j - L + 1;
					if (startInx < 0)
					{
						isPossible = false;
						break;
					}
					else
					{
						for (int k = startInx; k <= j; k++)
						{
							if (runwayCheckY[i][k] == 1 || board[i][k] != board[i][j])
							{ // 이미 경사로 있음
								isPossible = false;
								break;
							}
							runwayCheckY[i][k] = 1;
						}
					}
				}
				else if (gap == -1)
				{
					int endInx = j + L;
					if (endInx >= N)
					{
						isPossible = false;
						break;
					}
					else
					{
						for (int k = j + 1; k <= endInx; k++)
						{
							if (runwayCheckY[i][k] == 1 || board[i][k] != board[i][j + 1])
							{ // 이미 경사로 있음
								isPossible = false;
								break;
							}
							runwayCheckY[i][k] = 1;
						}
					}
				}
				else
				{
					isPossible = false;
					break;
				}
			}
		}

		if (isPossible)
		{
			cnt++;
		}
	}

	// 열 판단
	for (int j = 0; j < N; j++)
	{
		bool isPossible = true;
		for (int i = 0; i < N - 1; i++)
		{
			if (board[i][j] != board[i + 1][j])
			{
				int gap = board[i + 1][j] - board[i][j];
				if (gap == 1)
				{
					int startInx = i - L + 1;
					if (startInx < 0)
					{
						isPossible = false;
						break;
					}
					else
					{
						for (int k = startInx; k <= i; k++)
						{
							if (runwayCheckX[k][j] == 1 || board[k][j] != board[i][j])
							{ // 이미 경사로 있음
								isPossible = false;
								break;
							}
							runwayCheckX[k][j] = 1;
						}
					}
				}
				else if (gap == -1)
				{
					int endInx = i + L;
					if (endInx >= N)
					{
						isPossible = false;
						break;
					}
					else
					{
						for (int k = i + 1; k <= endInx; k++)
						{
							if (runwayCheckX[k][j] == 1 || board[k][j] != board[i + 1][j])
							{
								// 이미 경사로 있음
								isPossible = false;
								break;
							}
							runwayCheckX[k][j] = 1;
						}
					}
				}
				else
				{
					isPossible = false;
					break;
				}
			}
		}

		if (isPossible)
		{
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}