#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int N, M;
int board[51][51] = {0};
vector<pair<int, int>> vAllChicken;
vector<pair<int, int>> vAllHouse;
vector<int> vVisited;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int minDist = 10000000;

int getDistance()
{
	int dist = 0;

	for (int i = 0; i < vAllHouse.size(); i++)
	{
		int houseY = vAllHouse[i].first;
		int houseX = vAllHouse[i].second;
		int curMin = 10000000;

		for (int j = 0; j < vVisited.size(); j++)
		{
			if (vVisited[j] == 1)
			{
				int chickenY = vAllChicken[j].first;
				int chickenX = vAllChicken[j].second;

				int curDist = abs(houseY - chickenY) + abs(houseX - chickenX);
				if (curDist < curMin)
					curMin = curDist;
			}
		}

		dist += curMin;
	}

	return dist;
}

void getResult(int toChoose, int startInx)
{
	if (toChoose == 0)
	{
		int dist = getDistance();
		if (dist < minDist)
			minDist = dist;
		return;
	}
	else
	{
		for (int i = startInx; i < vAllChicken.size(); i++)
		{
			vVisited[i] = 1;
			getResult(toChoose - 1, i + 1);
			vVisited[i] = 0;
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

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int a;
			cin >> a;
			if (a == 2)
			{
				vAllChicken.push_back(make_pair(i, j));
				a = 0;
				vVisited.push_back(0);
			}
			else if (a == 1)
			{
				vAllHouse.push_back(make_pair(i, j));
			}
			board[i][j] = a;
		}
	}

	getResult(M, 0);

	cout << minDist;

	return 0;
}