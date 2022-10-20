#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right)
{
	vector<int> answer;

	int ly = left / n;
	int lx = left % n;

	int ry = right / n;
	int rx = right % n;

	ly++;
	lx++;
	ry++;
	rx++;

	if (ly == ry)
	{
		for (int i = lx; i <= rx; i++)
		{
			if (i <= ly)
			{
				answer.push_back(ly);
			}
			else
			{
				answer.push_back(i);
			}
		}
	}
	else
	{
		for (int i = lx; i <= n; i++)
		{ // ly행
			if (i <= ly)
			{
				answer.push_back(ly);
			}
			else
			{
				answer.push_back(i);
			}
		}
		for (int y = ly + 1; y <= ry - 1; y++)
		{ // 중간
			for (int j = 1; j <= n; j++)
			{
				if (j <= y)
				{
					answer.push_back(y);
				}
				else
				{
					answer.push_back(j);
				}
			}
		}
		for (int i = 1; i <= rx; i++)
		{ // ry행
			if (i <= ry)
			{
				answer.push_back(ry);
			}
			else
			{
				answer.push_back(i);
			}
		}
	}

	return answer;
}