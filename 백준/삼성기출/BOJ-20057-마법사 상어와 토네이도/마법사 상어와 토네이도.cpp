#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};

vector<vector<pair<int, int>>> vSpread;
int percent[9] = {5, 1, 1, 7, 7, 10, 10, 2, 2};
vector<pair<int, int>> vAlpha;

int board[505][505] = {0};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<pair<int, int>> v;
	v.push_back(make_pair(0, -2));	// 5
	v.push_back(make_pair(-1, 1));	// 1
	v.push_back(make_pair(1, 1));	// 1
	v.push_back(make_pair(-1, 0));	// 7
	v.push_back(make_pair(1, 0));	// 7
	v.push_back(make_pair(-1, -1)); // 10
	v.push_back(make_pair(1, -1));	// 10
	v.push_back(make_pair(-2, 0));	// 2
	v.push_back(make_pair(2, 0));	// 2
	vSpread.push_back(v);

	for (int i = 1; i <= 3; i++)
	{
		vector<pair<int, int>> vT;
		for (int j = 0; j < 9; j++)
		{
			vT.push_back(make_pair(-1 * vSpread[i - 1][j].second, vSpread[i - 1][j].first));
		}
		vSpread.push_back(vT);
	}

	vAlpha.push_back(make_pair(0, -1));
	vAlpha.push_back(make_pair(1, 0));
	vAlpha.push_back(make_pair(0, 1));
	vAlpha.push_back(make_pair(-1, 0));

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

	int curDir = 0; // 현재 방향
	int curY = N / 2 + 1;
	int curX = N / 2 + 1;

	int spreadOut = 0; // 격자 밖으로 나간 모래의 양
	int dist = 0;

	bool terminate = false;
	while (true)
	{
		int curDist = dist / 2 + 1;
		for (int i = 1; i <= curDist; i++)
		{
			curY += dy[curDir];
			curX += dx[curDir];

			// cout << curY << " " << curX << "\n";

			if (board[curY][curX] != 0)
			{
				int moveAmount = 0; // 알파 제외하고 비율 칸으로 이동한 양
				for (int j = 0; j < 9; j++)
				{
					int nextY = curY + vSpread[curDir][j].first;
					int nextX = curX + vSpread[curDir][j].second;
					int curP = percent[j];

					if (nextY < 1 || nextY > N || nextX < 1 || nextX > N)
					{
						spreadOut += board[curY][curX] * curP / 100;
						moveAmount += board[curY][curX] * curP / 100;
					}
					else
					{
						board[nextY][nextX] += board[curY][curX] * curP / 100;
						moveAmount += board[curY][curX] * curP / 100;
					}
				}
				// 알파 위치 판단하기
				int alphaY = curY + vAlpha[curDir].first;
				int alphaX = curX + vAlpha[curDir].second;

				if (alphaY < 1 || alphaY > N || alphaX < 1 || alphaX > N)
				{
					spreadOut += board[curY][curX] - moveAmount;
				}
				else
				{
					board[alphaY][alphaX] += board[curY][curX] - moveAmount;
				}

				board[curY][curX] = 0; // 현재 칸은 날라가므로 0
			}

			if (curY == 1 && curX == 1)
			{
				terminate = true;
				break;
			}
		}

		if (terminate)
			break;

		dist++;
		curDir++;
		if (curDir > 3)
			curDir = 0;
	}

	cout << spreadOut;

	return 0;
}