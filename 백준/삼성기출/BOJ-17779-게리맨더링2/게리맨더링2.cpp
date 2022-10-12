#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N;
int board[22][22] = {0};
int checkBoard[22][22] = {0};

int minGap = 999999999;

void clearCheckBoard()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			checkBoard[i][j] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int a;
			cin >> a;
			board[i][j] = a;
		}
	}

	for (int y = 1; y <= N - 2; y++)
	{
		for (int x = 2; x <= N - 1; x++)
		{
			for (int d1 = 1; d1 <= x - 1; d1++)
			{
				for (int d2 = 1; d2 <= N - x; d2++)
				{
					if (d1 + d2 <= N - y)
					{
						// cout << "y : " << y << ", x: " << x << ", d1 : " << d1 << ", d2: " << d2 << "\n";

						clearCheckBoard();
						int population[10] = {0};

						// 5 채우기
						int tempy = y;
						bool plus1 = true;
						bool plus2 = true;
						int tempx1 = 0;
						int tempx2 = 0;

						while (tempy <= y + d1 + d2)
						{
							for (int tx = x - tempx1; tx <= x + tempx2; tx++)
							{
								checkBoard[tempy][tx] = 5;
								population[5] += board[tempy][tx];
							}

							if (plus1)
								tempx1++;
							else
								tempx1--;

							if (plus2)
								tempx2++;
							else
								tempx2--;

							if (tempx1 >= d1)
								plus1 = false;
							if (tempx2 >= d2)
								plus2 = false;

							tempy++;
						}

						// 1
						for (int u = 1; u < y + d1; u++)
						{
							for (int v = 1; v <= x; v++)
							{
								if (checkBoard[u][v] == 5)
									continue;
								checkBoard[u][v] = 1;
								population[1] += board[u][v];
							}
						}

						// 2
						for (int u = 1; u <= y + d2; u++)
						{
							for (int v = x + 1; v <= N; v++)
							{
								if (checkBoard[u][v] == 5)
									continue;
								checkBoard[u][v] = 2;
								population[2] += board[u][v];
							}
						}

						// 3
						for (int u = y + d1; u <= N; u++)
						{
							for (int v = 1; v < x - d1 + d2; v++)
							{
								if (checkBoard[u][v] == 5)
									continue;
								checkBoard[u][v] = 3;
								population[3] += board[u][v];
							}
						}

						// 4
						for (int u = y + d2 + 1; u <= N; u++)
						{
							for (int v = x - d1 + d2; v <= N; v++)
							{
								if (checkBoard[u][v] == 5)
									continue;
								checkBoard[u][v] = 4;
								population[4] += board[u][v];
							}
						}

						vector<int> pop;
						for (int p = 1; p <= 5; p++)
						{
							pop.push_back(population[p]);
						}
						sort(pop.begin(), pop.end());

						int minmin = pop[4] - pop[0];
						if (minmin < minGap)
							minGap = minmin;
					}
				}
			}
		}
	}

	cout << minGap;

	return 0;
}