#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

#define MAX 110 // board의 크기 또한 2배를 해줘야 한다..!!

int board[MAX][MAX] = {
	0,
};
int visited[MAX][MAX] = {
	0,
};

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY)
{
	int answer = 0;

	// 시작, 도착 좌표 2배
	characterX *= 2;
	characterY *= 2;

	itemX *= 2;
	itemY *= 2;

	// 사각형 2배로 늘이고 내부 1로 채우기
	for (int i = 0; i < rectangle.size(); i++)
	{
		for (int j = 0; j < rectangle[0].size(); j++)
		{
			rectangle[i][j] *= 2;
		}

		int y1 = rectangle[i][1];
		int x1 = rectangle[i][0];

		int y2 = rectangle[i][3];
		int x2 = rectangle[i][2];

		for (int k = y1; k <= y2; k++)
		{
			for (int l = x1; l <= x2; l++)
				board[k][l] = 1;
		}
	}

	// 출력 테스트
	// for(int i = 0; i < MAX; i++) {
	//     for(int j = 0; j < MAX; j++) {
	//         cout << board[i][j] << " ";
	//     }
	//     cout << "\n";
	// }

	// 테두리 제외한 부분 0으로 만들기
	for (int i = 0; i < rectangle.size(); i++)
	{
		for (int j = 0; j < rectangle[0].size(); j++)
		{
			int y1 = rectangle[i][1];
			int x1 = rectangle[i][0];

			int y2 = rectangle[i][3];
			int x2 = rectangle[i][2];

			for (int k = y1 + 1; k <= y2 - 1; k++)
			{
				for (int l = x1 + 1; l <= x2 - 1; l++)
				{
					board[k][l] = 0;
				}
			}
		}
	}

	// bfs
	queue<pair<int, int>> q;
	visited[characterY][characterX] = 1;
	q.push({characterY, characterX});

	while (!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];

			if (nextY < 0 || nextY >= MAX || nextX < 0 || nextX >= MAX)
				continue;
			if (board[nextY][nextX] == 0 || visited[nextY][nextX] == 1)
				continue;

			q.push({nextY, nextX});
			visited[nextY][nextX] = 1;
			board[nextY][nextX] = board[curY][curX] + 1;

			if (nextY == itemY && nextX == itemX)
			{
				answer = board[nextY][nextX] / 2; // 2로 다시 나눠주기
				return answer;
			}
		}
	}
}