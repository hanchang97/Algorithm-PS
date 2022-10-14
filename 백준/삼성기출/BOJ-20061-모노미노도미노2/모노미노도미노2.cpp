#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int N;

int greenBoard[6][4] = {0};
int blueBoard[4][6] = {0};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	int totalScore = 0;

	for (int n = 0; n < N; n++)
	{
		int t, y, x; // 블록 타입, 행, 열
		cin >> t >> y >> x;

		int greenT = t;
		int blueT = t;

		// 초록색
		if (greenT == 2)
		{ // 열 2개 고려
			int ny = 0;
			while (true)
			{
				if (ny > 5)
					break;
				if (greenBoard[ny][x] || greenBoard[ny][x + 1])
					break;
				ny++;
			}

			greenBoard[ny - 1][x] = 1;
			greenBoard[ny - 1][x + 1] = 1;
		}
		else
		{
			int ny = 0;
			while (true)
			{
				if (ny > 5)
					break;
				if (greenBoard[ny][x])
					break;
				ny++;
			}

			if (greenT == 1)
			{ // 1X1
				greenBoard[ny - 1][x] = 1;
			}
			else
			{ // 2X1
				greenBoard[ny - 1][x] = 1;
				greenBoard[ny - 2][x] = 1;
			}
		}

		// 파란색
		if (blueT == 3)
		{ // 행 2개 고려
			int nx = 0;
			while (true)
			{
				if (nx > 5)
					break;
				if (blueBoard[y][nx] || blueBoard[y + 1][nx])
					break;
				nx++;
			}

			blueBoard[y][nx - 1] = 1;
			blueBoard[y + 1][nx - 1] = 1;
		}
		else
		{
			int nx = 0;
			while (true)
			{
				if (nx > 5)
					break;
				if (blueBoard[y][nx])
					break;
				nx++;
			}

			if (blueT == 1)
			{ // 1X1
				blueBoard[y][nx - 1] = 1;
			}
			else
			{ // 1X2
				blueBoard[y][nx - 1] = 1;
				blueBoard[y][nx - 2] = 1;
			}
		}

		// 초록, 파랑 일반칸 검사하기
		// 초록
		for (int i = 2; i < 6; i++)
		{
			int blockCnt = 0;
			for (int j = 0; j < 4; j++)
			{
				if (greenBoard[i][j] == 1)
					blockCnt++;
			}

			if (blockCnt == 4)
			{
				totalScore++;
				for (int k = 0; k < 4; k++) // i행 지우기
				{
					greenBoard[i][k] = 0;
				}

				for (int u = i; u > 0; u--)
				{ // 지운 i행에 맞춰 1칸씩 내리기
					for (int v = 0; v < 4; v++)
					{
						greenBoard[u][v] = greenBoard[u - 1][v]; // 내리기
						greenBoard[u - 1][v] = 0;				 // 원래 행 지우기
					}
				}
			}
		}

		//파랑
		for (int j = 2; j < 6; j++)
		{
			int blockCnt = 0;
			for (int i = 0; i < 4; i++)
			{
				if (blueBoard[i][j] == 1)
					blockCnt++;
			}

			if (blockCnt == 4)
			{
				totalScore++;
				for (int k = 0; k < 4; k++) // j열 지우기
				{
					blueBoard[k][j] = 0;
				}

				for (int v = j; v > 0; v--)
				{ // 지운 j열에 맞춰 1칸씩 오른쪽으로
					for (int u = 0; u < 4; u++)
					{
						blueBoard[u][v] = blueBoard[u][v - 1]; // 오른쪽 밀기
						blueBoard[u][v - 1] = 0;			   // 원래 행 지우기
					}
				}
			}
		}

		// 초록, 파랑 특별영역 검사하기
		// 초록
		int greenSpecialCnt = 0;
		for (int i = 0; i <= 1; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (greenBoard[i][j] == 1)
				{
					greenSpecialCnt++;
					break;
				}
			}
		}

		if (greenSpecialCnt >= 1)
		{
			for (int i = 1; i <= greenSpecialCnt; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					greenBoard[6 - i][j] = 0;
				}
			}

			for (int i = 5; i >= greenSpecialCnt; i--)
			{
				for (int j = 0; j < 4; j++)
				{
					greenBoard[i][j] = greenBoard[i - greenSpecialCnt][j];
					greenBoard[i - greenSpecialCnt][j] = 0;
				}
			}
		}

		// 파랑
		int blueSpecialCnt = 0;
		for (int j = 0; j <= 1; j++)
		{
			for (int i = 0; i < 4; i++)
			{
				if (blueBoard[i][j] == 1)
				{
					blueSpecialCnt++;
					break;
				}
			}
		}

		if (blueSpecialCnt >= 1)
		{
			for (int j = 1; j <= blueSpecialCnt; j++)
			{
				for (int i = 0; i < 4; i++)
				{
					blueBoard[i][6 - j] = 0;
				}
			}

			for (int j = 5; j >= blueSpecialCnt; j--)
			{
				for (int i = 0; i < 4; i++)
				{
					blueBoard[i][j] = blueBoard[i][j - blueSpecialCnt];
					blueBoard[i][j - blueSpecialCnt] = 0;
				}
			}
		}
	}

	int totalBlockCnt = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (greenBoard[i][j] == 1)
				totalBlockCnt++;
		}
	}
	for (int j = 0; j < 6; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			if (blueBoard[i][j] == 1)
				totalBlockCnt++;
		}
	}

	cout << totalScore << "\n"
		 << totalBlockCnt;

	return 0;
}