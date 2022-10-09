#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct Point
{
	int y;
	int x;
};

int N, M;
int board[505][505] = {0};

int maxValue = 0;

bool compareByY(const Point &fir, const Point &sec)
{
	return fir.y < sec.y;
}

bool compareByX(const Point &fir, const Point &sec)
{
	return fir.x < sec.x;
}

vector<Point> rotateRight(vector<Point> v)
{
	vector<Point> temp;
	for (int i = 0; i < v.size(); i++)
	{
		temp.push_back(Point{v[i].x, v[i].y * -1});
	}

	sort(temp.begin(), temp.end(), compareByY);
	int minY = temp[0].y;

	sort(temp.begin(), temp.end(), compareByX);
	int minX = temp[0].x;

	// cout << "minY : " << minY << ", minX : " << minX << "\n";

	for (int i = 0; i < temp.size(); i++)
	{
		if (minY < 0)
			temp[i].y += abs(minY);
		else
			temp[i].y -= minY;

		if (minX < 0)
			temp[i].x += abs(minX);
		else
			temp[i].x -= minX;
	}

	return temp;
}

void check(vector<Point> v)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{

			int isPossible = true;
			int sum = 0;
			for (int k = 0; k < v.size(); k++)
			{
				int nextY = i + v[k].y;
				int nextX = j + v[k].x;

				if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
				{
					isPossible = false;
					break;
				}

				sum += board[nextY][nextX];
			}

			if (isPossible)
			{
				if (sum > maxValue)
					maxValue = sum;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<vector<Point>> v;
	v.push_back({Point{0, 0}, Point{0, 1}, Point{0, 2}, Point{0, 3}});
	v.push_back({Point{0, 0}, Point{0, 1}, Point{1, 0}, Point{1, 1}});
	v.push_back({Point{0, 0}, Point{1, 0}, Point{2, 0}, Point{2, 1}});
	v.push_back({Point{0, 0}, Point{1, 0}, Point{1, 1}, Point{2, 1}});
	v.push_back({Point{0, 0}, Point{0, 1}, Point{0, 2}, Point{1, 1}});

	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int a;
			cin >> a;
			board[i][j] = a;
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		vector<Point> vTemp = v[i];

		for (int j = 0; j < 4; j++)
		{
			// 90도, 180도, 270도, 360도
			vTemp = rotateRight(vTemp);
			check(vTemp);
		}

		// 좌우반전후
		for (int j = 0; j < vTemp.size(); j++)
		{
			int x = vTemp[j].x;
			vTemp[j].x = x * -1;
		}

		for (int j = 0; j < 4; j++)
		{
			vTemp = rotateRight(vTemp);
			check(vTemp);
		}
	}

	cout << maxValue;

	return 0;
}