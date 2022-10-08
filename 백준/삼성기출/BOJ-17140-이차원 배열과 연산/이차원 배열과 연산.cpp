#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int R, C, K;

int arr[101][101];

bool compare(const pair<int, int> &first, const pair<int, int> &second)
{
	if (first.second == second.second)
		return first.first < second.first;
	return first.second < second.second; // value 오름차순 정렬 위함
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// r, c -1 씩 해주기
	cin >> R;
	cin >> C;
	cin >> K;

	R--; // 배열 인덱스로 사용하기 위함
	C--;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int a;
			cin >> a;
			arr[i][j] = a;
		}
	}

	int lenR = 3; // 행 개수
	int lenC = 3; // 열 개수

	int time = 0;
	while (time <= 101)
	{

		if (arr[R][C] == K)
			break;

		if (lenR >= lenC)
		{ // 각 행에 대해 정렬
			for (int i = 0; i < 100; i++)
			{

				map<int, int> mapR;

				for (int j = 0; j < 100; j++)
				{
					if (arr[i][j] != 0)
						mapR[arr[i][j]] += 1;
				}

				vector<pair<int, int>> vR(mapR.begin(), mapR.end());
				sort(vR.begin(), vR.end(), compare);

				int curLen = vR.size() * 2;
				if (curLen > 100)
					curLen = 100;

				if (curLen > lenC)
					lenC = curLen;

				for (int k = 0; k < vR.size(); k++)
				{
					if (k > 49)
						break;

					arr[i][k * 2] = vR[k].first;
					arr[i][k * 2 + 1] = vR[k].second;
				}

				for (int k = vR.size() * 2; k < 100; k++)
				{
					arr[i][k] = 0;
				}
			}
		}
		else
		{ // 각 열에 대해 정렬
			for (int j = 0; j < 100; j++)
			{

				map<int, int> mapC;

				for (int i = 0; i < 100; i++)
				{
					if (arr[i][j] != 0)
						mapC[arr[i][j]] += 1;
				}

				vector<pair<int, int>> vC(mapC.begin(), mapC.end());
				sort(vC.begin(), vC.end(), compare);

				int curLen = vC.size() * 2;
				if (curLen > 100)
					curLen = 100;

				if (curLen > lenR)
					lenR = curLen;

				for (int k = 0; k < vC.size(); k++)
				{
					if (k > 49)
						break;

					arr[k * 2][j] = vC[k].first;
					arr[k * 2 + 1][j] = vC[k].second;
				}

				for (int k = vC.size() * 2; k < 100; k++) // 변환한 부분을 제외한 곳은 0으로 채우기
				{
					arr[k][j] = 0;
				}
			}
		}

		time++;
	}

	if (time > 100)
		cout << -1;
	else
		cout << time;

	return 0;
}