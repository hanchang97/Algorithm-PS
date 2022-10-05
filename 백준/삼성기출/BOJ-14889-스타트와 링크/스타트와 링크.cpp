#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N;
int arr[25][25] = {0};
int visited[25] = {0};

int minGap = 1000000;

void getResult(int toChoose, int num)
{
	if (toChoose == 0)
	{

		int sum = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (visited[i] == visited[j])
				{ // i,j 같은 경우는 0이라 상관x
					if (visited[i])
						sum += arr[i][j];
					else
						sum -= arr[i][j];
				}
			}
		}

		int gap = abs(sum);
		if (gap < minGap)
			minGap = gap;

		return;
	}
	else
	{
		for (int i = num; i < N; i++)
		{
			visited[i] = 1;
			getResult(toChoose - 1, i + 1);
			visited[i] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int num;
			cin >> num;
			arr[i][j] = num;
		}
	}

	getResult(N / 2, 0);

	cout << minGap;

	return 0;
}