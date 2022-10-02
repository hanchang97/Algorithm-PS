#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>

/*
1. 퍼즐 컨테이너 만들기 -> (0,0) 기준 딱맞게
2. board 에서 bfs 하면서 퍼즐 들어갈 공간 정보 추출하기
3. 들어갈 수 있는 퍼즐 판단하기 -> 4방향 체크 및 퍼즐 사용 체크 하기
*/

using namespace std;

#define MAX 55

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

vector<vector<pair<int, int>>> puzzleContainer;
int saveVisited[MAX][MAX];

int boardVisited[MAX][MAX];
map<int, int> mPuzzle;

bool comparePairFirst(pair<int, int> first, pair<int, int> second)
{
	return first.first < second.first;
}

bool comparePairSecond(pair<int, int> first, pair<int, int> second)
{
	return first.second < second.second;
}

void savePuzzle(vector<vector<int>> table)
{ // puzzleContainer에 퍼즐 저장, 퍼즐은 1을 체크해야함
	int tableSize = table.size();

	for (int i = 0; i < tableSize; i++)
	{
		for (int j = 0; j < tableSize; j++)
		{
			if (table[i][j] == 1 && saveVisited[i][j] == 0)
			{

				vector<pair<int, int>> vPuzzle;
				queue<pair<int, int>> q;

				q.push({i, j});
				vPuzzle.push_back({i, j});
				saveVisited[i][j] = 1;

				while (!q.empty())
				{
					int curY = q.front().first;
					int curX = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++)
					{
						int nextY = curY + dy[k];
						int nextX = curX + dx[k];

						if (nextY < 0 || nextY >= tableSize || nextX < 0 || nextX >= tableSize)
							continue;
						if (table[nextY][nextX] != 1 || saveVisited[nextY][nextX] == 1)
							continue;

						saveVisited[nextY][nextX] = 1;
						q.push({nextY, nextX});
						vPuzzle.push_back({nextY, nextX});
					}
				}

				// (0,0) 기준으로 맞추는 작업
				sort(vPuzzle.begin(), vPuzzle.end(), comparePairFirst);
				int minY = vPuzzle[0].first;

				sort(vPuzzle.begin(), vPuzzle.end(), comparePairSecond);
				int minX = vPuzzle[0].second;

				for (int t = 0; t < vPuzzle.size(); t++)
				{
					if (minY > 0)
						vPuzzle[t].first -= minY;
					else
						vPuzzle[t].first += minY * -1;

					if (minX > 0)
						vPuzzle[t].second -= minX;
					else
						vPuzzle[t].second += minX * -1;
				}

				sort(vPuzzle.begin(), vPuzzle.end());
				puzzleContainer.push_back(vPuzzle);
			}
		}
	}
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
	int answer = 0;

	savePuzzle(table);

	// 퍼즐 생성 출력 테스트
	// for(int i = 0; i < puzzleContainer.size(); i++) {
	//     for(int j = 0; j < puzzleContainer[i].size(); j++) {
	//         cout << "[" << puzzleContainer[i][j].first << "," << puzzleContainer[i][j].second << "] ";
	//     }
	//     cout << "\n";
	// }

	int gbSize = game_board.size();

	// board bfs
	for (int i = 0; i < gbSize; i++)
	{
		for (int j = 0; j < gbSize; j++)
		{
			if (game_board[i][j] == 0 && boardVisited[i][j] == 0)
			{

				queue<pair<int, int>> q;
				vector<pair<int, int>> vSpace;
				vector<pair<int, int>> vSpaceOrigin;

				q.push({i, j});
				vSpace.push_back({i, j});
				vSpaceOrigin.push_back({i, j});
				boardVisited[i][j] = 1;

				while (!q.empty())
				{
					int curY = q.front().first;
					int curX = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++)
					{
						int nextY = curY + dy[k];
						int nextX = curX + dx[k];

						if (nextY < 0 || nextY >= gbSize || nextX < 0 || nextX >= gbSize)
							continue;
						if (game_board[nextY][nextX] != 0 || boardVisited[nextY][nextX] == 1)
							continue;

						boardVisited[nextY][nextX] = 1;
						q.push({nextY, nextX});
						vSpace.push_back({nextY, nextX});
						vSpaceOrigin.push_back({nextY, nextX});
					}
				}

				sort(vSpace.begin(), vSpace.end(), comparePairFirst);
				int minY = vSpace[0].first;

				sort(vSpace.begin(), vSpace.end(), comparePairSecond);
				int minX = vSpace[0].second;

				for (int t = 0; t < vSpace.size(); t++)
				{
					if (minY > 0)
						vSpace[t].first -= minY;
					else
						vSpace[t].first += minY * -1;

					if (minX > 0)
						vSpace[t].second -= minX;
					else
						vSpace[t].second += minX * -1;
				}

				sort(vSpace.begin(), vSpace.end());

				// 공간과 퍼즐 모양 비교하기
				bool completed = false;
				for (int u = 0; u < puzzleContainer.size(); u++)
				{

					if (mPuzzle[u] == 0)
					{
						///
						vector<pair<int, int>> vCurPuzzle = puzzleContainer[u];
						int curPuzzleInx = u;

						for (int r = 0; r < 4; r++)
						{
							// 90도 회전하기
							for (int e = 0; e < vCurPuzzle.size(); e++)
							{
								int yy = vCurPuzzle[e].first;
								int xx = vCurPuzzle[e].second;

								vCurPuzzle[e].first = xx;
								vCurPuzzle[e].second = yy * -1;
							}

							// (0,0) 기준 맞추기
							sort(vCurPuzzle.begin(), vCurPuzzle.end(), comparePairFirst);
							int minCurY = vCurPuzzle[0].first;

							sort(vCurPuzzle.begin(), vCurPuzzle.end(), comparePairSecond);
							int minCurX = vCurPuzzle[0].second;

							for (int q = 0; q < vCurPuzzle.size(); q++)
							{
								if (minCurY > 0)
									vCurPuzzle[q].first -= minCurY;
								else
									vCurPuzzle[q].first += minCurY * -1;

								if (minCurX > 0)
									vCurPuzzle[q].second -= minCurX;
								else
									vCurPuzzle[q].second += minCurX * -1;
							}

							sort(vCurPuzzle.begin(), vCurPuzzle.end());
							// 90도 회전 끝

							// 현재 퍼즐상태가 공간에 들어갈 수 있는지 체크
							bool possible = true;
							if (vSpace.size() == vCurPuzzle.size())
							{
								for (int o = 0; o < vSpace.size(); o++)
								{
									if (vSpace[o].first != vCurPuzzle[o].first || vSpace[o].second != vCurPuzzle[o].second)
									{
										possible = false;
										break;
									}
								}
							}
							else
							{
								possible = false;
							}

							if (possible)
							{
								mPuzzle[curPuzzleInx] += 1;
								completed = true;
								answer += vSpaceOrigin.size(); // 채운 퍼즐 수 더해주기

								for (int v = 0; v < vSpaceOrigin.size(); v++)
								{
									int py = vSpaceOrigin[v].first;
									int px = vSpaceOrigin[v].second;

									game_board[py][px] = 2;
								}

								break;
							}
						}

						if (completed)
						{
							break;
						}

						///
					}
				}
			}
		}
	}

	// 보드 상태 출력 - 퍼즐 채워진 곳 = 2
	// for(int i = 0; i < game_board.size(); i++) {
	//     for(int j = 0; j < game_board[i].size(); j++) {
	//         cout <<game_board[i][j] << " ";
	//     }
	//     cout << "\n";
	// }

	return answer;
}