#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

#define ERASE -999999999

int N, M, T;
deque<int> board[55];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> T;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int a;
			cin >> a;
			board[i].push_front(a);
		}
	}

	// T번 명령 수행
	for (int t = 0; t < T; t++)
	{
		int x, d, k;
		cin >> x >> d >> k;
		// x 배수 원판들 d 방향 k 칸 회전하기
		int cnt = 1;
		while (x * cnt <= N)
		{
			int curY = x * cnt - 1;

			if (d == 0)
			{
				for (int i = 0; i < k; i++)
				{
					int front = board[curY].front();
					board[curY].pop_front();
					board[curY].push_back(front);
				}
			}
			else
			{
				for (int i = 0; i < k; i++)
				{
					int back = board[curY].back();
					board[curY].pop_back();
					board[curY].push_front(back);
				}
			}
			cnt++;
		}

		// 인접 부분에 같은 수 있으면 지우기
		bool isExist = false;
		int erase[52][52] = {0}; // 1이면 보드 0으로 만들기
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					int nextY = i + dy[k];
					int nextX = j + dx[k];

					if (nextY < 0 || nextY >= N)
						continue;

					if (nextX < 0)
						nextX = M - 1;
					else if (nextX >= M)
						nextX = 0;

					if (board[i][j] != ERASE && board[i][j] == board[nextY][nextX])
					{
						isExist = true;
						erase[i][j] = 1;
						erase[nextY][nextX] = 1;
					}
				}
			}
		}

		if (isExist)
		{ // 인접하면서 같은 것 존재
			for (int u = 0; u < N; u++)
			{
				for (int v = 0; v < M; v++)
				{
					if (erase[u][v] == 1)
						board[u][v] = ERASE;
				}
			}
		}
		else
		{ // 없음
			int sum = 0;
			int size = 0;
			for (int u = 0; u < N; u++)
			{
				for (int v = 0; v < M; v++)
				{
					if (board[u][v] != ERASE)
					{
						sum += board[u][v];
						size += 1;
					}
				}
			}

			double avg = (double)sum / size;
			for (int u = 0; u < N; u++)
			{
				for (int v = 0; v < M; v++)
				{
					if (board[u][v] != ERASE)
					{
						if (board[u][v] > avg)
							board[u][v] -= 1;
						else if (board[u][v] < avg)
							board[u][v] += 1;
					}
				}
			}
		}
	}

	int totalSum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] != ERASE)
				totalSum += board[i][j];
		}
	}

	cout << totalSum;

	return 0;
}