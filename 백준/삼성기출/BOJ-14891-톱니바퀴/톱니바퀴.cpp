#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int rotateInfo[5] = {0}; // inx 1 부터 사용
int K;					 // 회전 명령 횟수

vector<deque<int>> vDeque;

void clearRotateInfo()
{
	for (int i = 0; i < 5; i++)
		rotateInfo[i] = 0; // 매 회전마다 톱니들의 회전 방향 저장
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 5; i++)
	{
		deque<int> deq;
		vDeque.push_back(deq);
	}

	for (int i = 0; i < 4; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < str.length(); j++)
		{
			int num = str[j] - 48;
			vDeque[i + 1].push_back(num);
		}
	}

	//
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int num, dir;
		cin >> num; // 톱니바퀴 번호
		cin >> dir; // 회전 방향

		int right = num + 1;
		int left = num - 1;

		rotateInfo[num] = dir; // 현재 회전에서 나머지 톱니들이 회전할 수 있는지를 검사해야 한다

		while (right <= 4) // 오른쪽 방향 고려
		{
			int curPole = vDeque[right - 1][2];
			int nextPole = vDeque[right][6];

			if (curPole != nextPole)
			{
				rotateInfo[right] = rotateInfo[right - 1] * -1;
			}
			else
			{
				break;
			}

			right++;
		}

		while (left >= 1) // 왼쪽 방향 고려
		{
			int curPole = vDeque[left + 1][6];
			int nextPole = vDeque[left][2];

			if (curPole != nextPole)
			{
				rotateInfo[left] = rotateInfo[left + 1] * -1;
			}
			else
			{
				break;
			}

			left--;
		}

		// 회전하기
		for (int j = 1; j < 5; j++)
		{
			if (rotateInfo[j] == 1)
			{ // 시계 방향
				int back = vDeque[j].back();
				vDeque[j].pop_back();
				vDeque[j].push_front(back);
			}
			else if (rotateInfo[j] == -1)
			{ // 반시계 방향
				int front = vDeque[j].front();
				vDeque[j].pop_front();
				vDeque[j].push_back(front);
			}
		}

		clearRotateInfo(); // 현재 회전 끝났으므로 초기화한다
	}

	int score = 0;
	for (int i = 1; i < 5; i++)
	{
		if (i == 1)
		{
			if (vDeque[i][0] == 1)
				score += 1;
		}
		else if (i == 2)
		{
			if (vDeque[i][0] == 1)
				score += 2;
		}
		else if (i == 3)
		{
			if (vDeque[i][0] == 1)
				score += 4;
		}
		else
		{ // 4
			if (vDeque[i][0] == 1)
				score += 8;
		}
	}

	cout << score;

	return 0;
}