#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int N, L, R;

int board[51][51] = {0};
int visited[51][51] = {0};

bool isMoveGenerated = false;
int moveCount = 0;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void clearVisited()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visited[i][j] = 0;
		}
	}
}

void move(int y, int x)
{
	queue<pair<int, int>> q;
	vector<pair<int, int>> v; // 연합 국가 좌표들 저장 -> 인구 이동 계산 시 사용
	q.push(make_pair(y, x));
	v.push_back(make_pair(y, x));

	while (!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];

			if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
				continue;
			if (visited[nextY][nextX] != 0)
				continue;

			int gap = abs(board[curY][curX] - board[nextY][nextX]); // 연합 조건
			if (gap < L || gap > R)
				continue;

			visited[nextY][nextX] = 1;
			q.push(make_pair(nextY, nextX));
			v.push_back(make_pair(nextY, nextX));
			isMoveGenerated = true;
		}
	}

	if (isMoveGenerated)
	{ // 연합 존재
		int sum = 0;
		for (int j = 0; j < v.size(); j++)
		{
			sum += board[v[j].first][v[j].second];
		}

		sum /= v.size();

		for (int j = 0; j < v.size(); j++)
		{
			board[v[j].first][v[j].second] = sum;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	cin >> L;
	cin >> R;

	// 입력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int a;
			cin >> a;
			board[i][j] = a;
		}
	}

	while (true)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (visited[i][j] == 0)
				{
					visited[i][j] = 1; // 방문체크
					move(i, j);
				}
			}
		}

		if (!isMoveGenerated)
			break; // 인구 이동 발생 안했다면 종료

		isMoveGenerated = false;
		moveCount++;
		clearVisited(); // 방문 체크 배열 초기화
	}

	cout << moveCount << "\n";

	return 0;
}