#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int N, M, K;

int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

struct Fireball
{
	int m; // 질량
	int s; // 속력
	int d; // 방향
};

vector<Fireball> board[51][51];
vector<Fireball> newBoard[51][51];

void boardUpdate()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			board[i][j] = newBoard[i][j];
		}
	}
}

void clearNewBoard()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			newBoard[i][j].clear();
			vector<Fireball>().swap(newBoard[i][j]);
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
	cin >> K;

	for (int i = 0; i < M; i++)
	{
		int y, x, m, s, d;
		cin >> y;
		cin >> x;
		cin >> m;
		cin >> s;
		cin >> d;

		board[y - 1][x - 1].push_back(Fireball{m, s, d});
	}

	for (int i = 0; i < K; i++)
	{
		// 파이어볼 이동 -> newBoard에 저장하기
		for (int l = 0; l < N; l++)
		{
			for (int m = 0; m < N; m++)
			{
				if (board[l][m].size() >= 1)
				{
					for (int n = 0; n < board[l][m].size(); n++)
					{
						int curS = board[l][m][n].s;
						int curD = board[l][m][n].d;
						int curM = board[l][m][n].m;

						int move = curS % N; // 나머지연산
						int nextY = l + dy[curD] * move;
						int nextX = m + dx[curD] * move;

						// 이동 후 좌표 벗어난 경우 처리해주기
						if (nextY < 0)
							nextY += N;
						if (nextX < 0)
							nextX += N;
						if (nextY >= N)
							nextY -= N;
						if (nextX >= N)
							nextX -= N;

						// cout << "nexty : " << nextY << ", nextx : " << nextX << "\n";

						// newBoard에 저장
						newBoard[nextY][nextX].push_back(Fireball{curM, curS, curD});
					}
				}
			}
		}

		// 2개 이상 있는 파이어볼 있는지 확인하고 4개로 나누기, 질량 0 되면 삭제하기 -> newBoard에서
		for (int l = 0; l < N; l++)
		{
			for (int m = 0; m < N; m++)
			{
				if (newBoard[l][m].size() >= 2)
				{
					int sumM = 0;
					int sumS = 0;
					bool isSame = true;
					for (int n = 0; n < newBoard[l][m].size(); n++)
					{
						int curM = newBoard[l][m][n].m;
						int curS = newBoard[l][m][n].s;
						int curD = newBoard[l][m][n].d;

						sumM += curM;
						sumS += curS;

						if (n > 0)
						{
							int pre = newBoard[l][m][n - 1].d % 2;
							int cur = curD % 2;
							if (pre != cur)
								isSame = false;
						}
					}

					sumM /= 5;
					sumS /= newBoard[l][m].size();

					if (sumM <= 0)
					{
						newBoard[l][m].clear();
						vector<Fireball>().swap(newBoard[l][m]);
					}
					else
					{
						newBoard[l][m].clear();
						vector<Fireball>().swap(newBoard[l][m]);

						if (isSame)
						{
							newBoard[l][m].push_back(Fireball{sumM, sumS, 0});
							newBoard[l][m].push_back(Fireball{sumM, sumS, 2});
							newBoard[l][m].push_back(Fireball{sumM, sumS, 4});
							newBoard[l][m].push_back(Fireball{sumM, sumS, 6});
						}
						else
						{
							newBoard[l][m].push_back(Fireball{sumM, sumS, 1});
							newBoard[l][m].push_back(Fireball{sumM, sumS, 3});
							newBoard[l][m].push_back(Fireball{sumM, sumS, 5});
							newBoard[l][m].push_back(Fireball{sumM, sumS, 7});
						}
					}
				}
			}
		}

		// newBoard -> board 업데이트, newBoard clear
		boardUpdate();
		clearNewBoard();
	}

	int totalM = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j].size() > 0)
			{
				for (int k = 0; k < board[i][j].size(); k++)
				{
					totalM += board[i][j][k].m;
				}
			}
		}
	}

	cout << totalM;

	return 0;
}