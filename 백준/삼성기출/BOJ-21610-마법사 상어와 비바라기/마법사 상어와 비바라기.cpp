#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N, M;
int board[55][55] = {0};	   // 각 칸은 물의 양을 나타낸다
int cloud[55][55] = {0};	   // 1 = 구름 존재
vector<pair<int, int>> vCloud; // 구름 좌표 정보 저장

int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1}; // inx 1부터 고려하기
int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

int dyCross[4] = {-1, -1, 1, 1}; // 4개의 대각선 방향 처리하기 위함
int dxCross[4] = {-1, 1, -1, 1};

int convertPoint(int p)
{ // 좌표 경계 벗어난 경우를 위함
	if (p < 0)
	{
		while (p < 0)
		{
			p += N;
		}
	}
	else if (p >= N)
	{
		while (p >= N)
		{
			p -= N;
		}
	}
	return p;
}

int main()
{

	cin >> N;
	cin >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int a;
			cin >> a;
			board[i][j] = a;
		}
	}

	// 초기 구름 설정
	vCloud.push_back(make_pair(N - 1, 0));
	vCloud.push_back(make_pair(N - 1, 1));
	vCloud.push_back(make_pair(N - 2, 0));
	vCloud.push_back(make_pair(N - 2, 1));

	for (int i = 0; i < M; i++)
	{
		int di, si;
		cin >> di;
		cin >> si;

		// 구름 이동
		for (int j = 0; j < vCloud.size(); j++)
		{
			int curY = vCloud[j].first;
			int curX = vCloud[j].second;

			curY += dy[di] * si;
			curX += dx[di] * si;

			vCloud[j].first = convertPoint(curY); // 이동 후 경계 벗어난 경우 처리해주기
			vCloud[j].second = convertPoint(curX);

			// 구름 배열 업데이트
			cloud[vCloud[j].first][vCloud[j].second] = 1;
		}

		// for (int j = 0; j < vCloud.size(); j++)
		// {
		//     cout << vCloud[j].first << " " << vCloud[j].second << "\n";
		// }

		// 구름 칸 물 1씩 증가시키기
		for (int j = 0; j < vCloud.size(); j++)
		{
			int curY = vCloud[j].first;
			int curX = vCloud[j].second;

			board[curY][curX] += 1;
		}

		// 구름 칸 각 좌표별로 대각선에 물 존재하는 칸 개수 세고 더해주기
		for (int j = 0; j < vCloud.size(); j++)
		{
			int curY = vCloud[j].first;
			int curX = vCloud[j].second;

			for (int k = 0; k < 4; k++)
			{
				int crossY = curY + dyCross[k];
				int crossX = curX + dxCross[k];

				if (crossY < 0 || crossY >= N || crossX < 0 || crossX >= N)
					continue;

				if (board[crossY][crossX] > 0)
					board[curY][curX] += 1;
			}
		}

		// for (int l = 0; l < N; l++)
		// {
		//     for (int m = 0; m < N; m++)
		//     {
		//        cout << board[l][m] << " ";
		//     }
		//     cout << "\n";
		// }

		// 구름 벡터 초기화 후 새로운 구름 만들기
		vCloud.clear();

		for (int l = 0; l < N; l++)
		{
			for (int m = 0; m < N; m++)
			{
				if (cloud[l][m])
				{
					cloud[l][m] = 0; // 원래 구름칸 0으로 만들기
					continue;
				}
				if (board[l][m] < 2)
					continue;

				board[l][m] -= 2;
				vCloud.push_back(make_pair(l, m));
			}
		}
	}

	// 총합 구하기
	int total = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			total += board[i][j];
		}
	}

	cout << total << "\n";

	return 0;
}