#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N;
int arrNum[12] = {0};
int opCnt[4] = {0};
vector<int> vOp; // 덧셈 1, 뺄셈 2, 곱셈 3, 나눗셈 4
int visited[12] = {0};

int maxResult = -1000000000;
int minResult = 1000000000;

void getResult(int sum, int remain)
{
	if (remain == 0)
	{

		if (sum > maxResult)
			maxResult = sum;
		if (sum < minResult)
			minResult = sum;

		return;
	}
	else
	{
		for (int i = 0; i < vOp.size(); i++)
		{
			if (visited[i] == 0)
			{
				visited[i] = 1;
				int tempSum = sum;
				if (vOp[i] == 1)
				{
					tempSum += arrNum[N - remain];
				}
				else if (vOp[i] == 2)
				{
					tempSum -= arrNum[N - remain];
				}
				else if (vOp[i] == 3)
				{
					tempSum *= arrNum[N - remain];
				}
				else
				{
					if (tempSum < 0)
					{
						tempSum *= -1;
						tempSum /= arrNum[N - remain];
						tempSum *= -1;
					}
					else
					{
						tempSum /= arrNum[N - remain];
					}
				}
				getResult(tempSum, remain - 1);
				visited[i] = 0;
			}
		}
	}
}

int main()
{

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		arrNum[i] = num;
	}

	for (int i = 0; i < 4; i++)
	{
		int num;
		cin >> num;
		opCnt[i] = num;
	}

	for (int i = 0; i < 4; i++)
	{
		int cnt = opCnt[i];

		int op = 0;
		if (i == 0)
			op = 1;
		else if (i == 1)
			op = 2;
		else if (i == 2)
			op = 3;
		else
			op = 4;

		while (cnt > 0)
		{
			vOp.push_back(op);
			cnt--;
		}
	}

	// for (int i = 0; i < vOp.size(); i++) cout << vOp[i] << " ";

	getResult(arrNum[0], vOp.size());

	cout << maxResult << "\n";
	cout << minResult;

	return 0;
}