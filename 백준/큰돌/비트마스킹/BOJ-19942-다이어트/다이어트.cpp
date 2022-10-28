#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int N;
int minCondition[4] = {0};
int info[20][5] = {0};

unordered_map<int, vector<vector<int>>> mV;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < 4; i++)
	{
		int a;
		cin >> a;
		minCondition[i] = a;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int a;
			cin >> a;
			info[i][j] = a;
		}
	}

	int minCost = 999999999;
	bool isAnswerExist = false;

	for (int i = 1; i < (1 << N); i++)
	{
		vector<int> vTemp;
		int tempArr[5] = {0};
		for (int j = 0; j < N; j++)
		{
			if (i & (1 << j))
			{
				vTemp.push_back(j + 1);
				for (int k = 0; k < 5; k++)
				{
					tempArr[k] += info[j + 1][k];
				}
			}
		}

		bool isPossible = true;
		for (int p = 0; p < 4; p++)
		{
			if (tempArr[p] < minCondition[p])
			{
				isPossible = false;
				break;
			}
		}

		if (isPossible)
		{
			isAnswerExist = true;
			if (tempArr[4] <= minCost)
			{
				minCost = tempArr[4];
				mV[minCost].push_back(vTemp);
			}
		}
	}

	if (isAnswerExist)
	{
		sort(mV[minCost].begin(), mV[minCost].end());

		cout << minCost << "\n";
		for (int i = 0; i < mV[minCost][0].size(); i++)
		{
			cout << mV[minCost][0][i] << " ";
		}
	}
	else
	{
		cout << -1 << "\n";
	}

	return 0;
}
