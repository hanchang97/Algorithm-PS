#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

#define EMPTY 999999999

int N, M;
int board[21][21] = {0};

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

struct Point
{
	int y;
	int x;
};

struct GroupInfo
{
	int inx;
	int size;
	int rCount;
	int sty;
	int stx;
};

bool cmpGroupInfo(const GroupInfo &fir, const GroupInfo &sec)
{
	if (fir.size == sec.size)
	{
		if (fir.rCount == sec.rCount)
		{
			if (fir.sty == sec.sty)
			{
				return fir.stx > sec.stx;
			}
			return fir.sty > sec.sty;
		}
		return fir.rCount > sec.rCount;
	}
	return fir.size > sec.size;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int a;
			cin >> a;
			board[i][j] = a;
		}
	}

	int totalScore = 0;

	while (true)
	{
		bool isGroupExist = false;
		// 가장 큰 그룹 찾기
		vector<vector<Point>> vGroup;
		vector<GroupInfo> vGroupInfo;

		int totalVisited[21][21] = {0};

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int visited[21][21] = {0};

				if (board[i][j] == -1 || board[i][j] == 0 || board[i][j] == EMPTY)
					continue; // 검정, 무지개, 빈칸 패스
				if (totalVisited[i][j] == 1)
					continue;

				int curNormal = board[i][j]; // 현재 기준 일반 블록, 일반블록 기준으로만 bfs 수행

				// 그룹 만들고 블록 개수 2개 이상인지 판단하기
				visited[i][j] = 1;
				totalVisited[i][j] = 1;
				queue<Point> q;
				q.push(Point{i, j});
				vector<Point> vCurGroup;
				vCurGroup.push_back(Point{i, j});

				int rCount = 0; // 무지개 수

				while (!q.empty())
				{
					int cy = q.front().y;
					int cx = q.front().x;
					q.pop();

					for (int k = 0; k < 4; k++)
					{
						int ny = cy + dy[k];
						int nx = cx + dx[k];
						if (ny < 0 || ny >= N || nx < 0 || nx >= N)
							continue;
						if (visited[ny][nx] || board[ny][nx] == -1 || board[ny][nx] == EMPTY)
							continue;
						// 검정 포함하면 안됨

						if (board[ny][nx] == curNormal || board[ny][nx] == 0)
						{ // 현재 블록이랑 같거나 무지개
							visited[ny][nx] = 1;
							vCurGroup.push_back(Point{ny, nx});
							q.push(Point{ny, nx});
							if (board[ny][nx] == 0)
								rCount++;
							else
								totalVisited[ny][nx] = 1;
						}
					}
				}

				if (vCurGroup.size() >= 2)
				{
					isGroupExist = true;
					vGroup.push_back(vCurGroup);
					int inx = vGroup.size() - 1;
					int size = vCurGroup.size();
					vGroupInfo.push_back(GroupInfo{inx, size, rCount, i, j});
				}
			}
		}

		if (!isGroupExist) // 그룹 안생기면 종료
			break;

		// 그룹 크기, 무지개 수, 기준 블록 행, 열 큰 순서대로 정렬
		sort(vGroupInfo.begin(), vGroupInfo.end(), cmpGroupInfo);

		// 그룹 제거
		int removeInx = vGroupInfo[0].inx;
		totalScore += vGroup[removeInx].size() * vGroup[removeInx].size(); // 제거할 그룹의 블록 수만큼 점수 누적

		// cout << "remove////\n";
		for (int g = 0; g < vGroup[removeInx].size(); g++)
		{
			int ry = vGroup[removeInx][g].y;
			int rx = vGroup[removeInx][g].x;
			board[ry][rx] = EMPTY;

			// cout << ry << ", " << rx << "\n";
		}

		// 중력
		for (int i = N - 1; i >= 0; i--)
		{ // 역순 판단
			for (int j = N - 1; j >= 0; j--)
			{
				if (board[i][j] == -1 || board[i][j] == EMPTY)
					continue;
				int emptyY = i;
				while (true)
				{
					if (emptyY + 1 >= N)
						break;
					if (board[emptyY + 1][j] != EMPTY)
						break;
					emptyY++;
				}
				if (emptyY > i)
				{ // 중력에 의해 이동했다
					board[emptyY][j] = board[i][j];
					board[i][j] = EMPTY;
				}
			}
		}

		// 90도 반시계 회전
		int tempBoard[21][21] = {0};
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				tempBoard[N - 1 - j][i] = board[i][j];
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				board[i][j] = tempBoard[i][j];
			}
		}

		// 중력
		for (int i = N - 1; i >= 0; i--)
		{ // 역순 판단
			for (int j = N - 1; j >= 0; j--)
			{
				if (board[i][j] == -1 || board[i][j] == EMPTY)
					continue;
				int emptyY = i;
				while (true)
				{
					if (emptyY + 1 >= N)
						break;
					if (board[emptyY + 1][j] != EMPTY)
						break;
					emptyY++;
				}
				if (emptyY > i)
				{ // 중력에 의해 이동했다
					board[emptyY][j] = board[i][j];
					board[i][j] = EMPTY;
				}
			}
		}
	}

	cout << totalScore;

	return 0;
}