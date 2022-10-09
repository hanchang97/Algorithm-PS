#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N, M, x, y, K;
int board[25][25] = {0};

int dy[5] = {0, 0, 0, -1, 1};
int dx[5] = {0, 1, -1, 0, 0};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cin >> M;
	cin >> y;
	cin >> x;
	cin >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int a;
			cin >> a;
			board[i][j] = a;
		}
	}

	vector<int> vDir = {0, 3, 4, 2, 5, 1, 6};	// inx 1 부터 동 서 북 남 위 아래, 원소는 해당 방향에 위치한 면의 번호
	vector<int> vValue = {0, 0, 0, 0, 0, 0, 0}; // inx는 면의 번호, 원소는 해당 면의 현재 값

	for (int k = 0; k < K; k++)
	{
		int dir;
		cin >> dir;

		int nextY = y + dy[dir];
		int nextX = x + dx[dir];

		if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
			continue;

		y += dy[dir];
		x += dx[dir];

		int dir1num = vDir[1];
		int dir2num = vDir[2];
		int dir3num = vDir[3];
		int dir4num = vDir[4];
		int dir5num = vDir[5];
		int dir6num = vDir[6];

		if (dir == 1)
		{ // 동쪽 굴리기
			vDir[6] = dir1num;
			vDir[5] = dir2num;
			vDir[1] = dir5num;
			vDir[2] = dir6num;
		}
		else if (dir == 2)
		{ // 서쪽 굴리기
			vDir[5] = dir1num;
			vDir[6] = dir2num;
			vDir[2] = dir5num;
			vDir[1] = dir6num;
		}
		else if (dir == 3)
		{ // 북쪽 굴리기
			vDir[6] = dir3num;
			vDir[5] = dir4num;
			vDir[3] = dir5num;
			vDir[4] = dir6num;
		}
		else
		{ // dir == 4 남쪽 굴리기
			vDir[5] = dir3num;
			vDir[6] = dir4num;
			vDir[4] = dir5num;
			vDir[3] = dir6num;
		}

		if (board[y][x] == 0)
		{
			board[y][x] = vValue[vDir[6]];
		}
		else
		{
			vValue[vDir[6]] = board[y][x];
			board[y][x] = 0;
		}

		cout << vValue[vDir[5]] << "\n";
	}

	return 0;
}