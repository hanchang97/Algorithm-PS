#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int N, M, K;
vector<int> boardPq[12][12];
vector<int> boardDeath[12][12];
vector<pair<int, int>> vSpread;
int boardFood[12][12] = {0};
int s2d2[12][12] = {0};

int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cin >> M;
	cin >> K;

	// 초기 양분
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			boardFood[i][j] = 5;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int a;
			cin >> a;
			s2d2[i][j] = a;
		}
	}

	// 초기 나무 정보
	for (int i = 0; i < M; i++)
	{
		int y, x, z;
		cin >> y;
		cin >> x;
		cin >> z;
		boardPq[y][x].push_back(z);
	}

	// 봄 + 여름
	for (int k = 1; k <= K; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{

				// 봄
				sort(boardPq[i][j].begin(), boardPq[i][j].end());
				vector<int> vTemp;

				for (int l = 0; l < boardPq[i][j].size(); l++)
				{
					int curAge = boardPq[i][j][l];
					if (boardFood[i][j] >= curAge)
					{
						boardFood[i][j] -= curAge;
						vTemp.push_back(curAge + 1);

						if ((curAge + 1) % 5 == 0)
						{
							vSpread.push_back(make_pair(i, j));
						}
					}
					else
					{
						boardDeath[i][j].push_back(curAge);
					}
				}

				boardPq[i][j] = vTemp;

				// 여름
				for (int q = 0; q < boardDeath[i][j].size(); q++)
				{
					int deathFood = boardDeath[i][j][q];
					boardFood[i][j] += deathFood / 2;
				}
				boardDeath[i][j].clear();
			}
		}

		// 가을
		for (int i = 0; i < vSpread.size(); i++)
		{
			int curY = vSpread[i].first;
			int curX = vSpread[i].second;

			for (int j = 0; j < 8; j++)
			{
				int nextY = curY + dy[j];
				int nextX = curX + dx[j];

				if (nextY < 1 || nextY > N || nextX < 1 || nextX > N)
					continue;

				boardPq[nextY][nextX].push_back(1);
			}
		}

		//겨울
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				boardFood[i][j] += s2d2[i][j];
			}
		}

		vSpread.clear();
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cnt += boardPq[i][j].size();
		}
	}

	cout << cnt;

	return 0;
}