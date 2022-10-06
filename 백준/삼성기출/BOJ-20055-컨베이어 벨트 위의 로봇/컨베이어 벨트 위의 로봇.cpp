#include <string>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int N, K;
int robotCnt = 1;

map<int, int> mRobot; // <id, inx + 1>

struct Data
{
	int remain;
	int robotId;
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	cin >> K;

	deque<Data> deqData;

	for (int i = 0; i < 2 * N; i++)
	{
		int a;
		cin >> a;
		deqData.push_back(Data{a, 0});
	}

	int step = 0;
	int log = 0;

	while (true)
	{
		step++;

		// 벨트 회전
		Data last = deqData.back();
		deqData.pop_back();
		deqData.push_front(last);

		for (int i = 0; i < deqData.size(); i++)
		{ // 벨트 위에 있는 로봇 위치 갱신
			if (deqData[i].robotId != 0)
			{
				if (i == N - 1)
				{ // 내리는 위치 도달
					mRobot.erase(deqData[i].robotId);
					deqData[i].robotId = 0;
				}
				else
				{
					mRobot[deqData[i].robotId] = i + 1;
				}
			}
		}

		map<int, int>::iterator iter;
		for (iter = mRobot.begin(); iter != mRobot.end(); iter++)
		{ // 로봇 회전
			int robotId = iter->first;
			int inx = (iter->second) - 1; // map에 index 저장 시 1을 더해서 저장했으므로 -1 해주기

			int nextInx = inx + 1;
			if (nextInx >= 2 * N)
				nextInx = 0;

			// 다음 칸에 로봇 없으면서 내구성이 1이상인 경우
			if (deqData[nextInx].robotId == 0 && deqData[nextInx].remain >= 1)
			{
				deqData[inx].robotId = 0;
				deqData[nextInx].robotId = robotId;
				deqData[nextInx].remain -= 1;
				mRobot[robotId] = nextInx + 1; // inx 저장은 1더한값 해주기
			}
		}

		// N-1 로 이동한 로봇 있다면 내려주기
		if (deqData[N - 1].robotId != 0)
		{
			mRobot.erase(deqData[N - 1].robotId);
			deqData[N - 1].robotId = 0;
		}

		// 로봇 올리기
		if (deqData[0].robotId == 0 && deqData[0].remain >= 1)
		{
			deqData[0].robotId = robotCnt;
			deqData[0].remain -= 1;
			mRobot[robotCnt] = 1;
			robotCnt++;
		}

		// 내구도 0  체크
		int zeroCnt = 0;
		for (int i = 0; i < deqData.size(); i++)
		{
			if (deqData[i].remain <= 0)
			{
				zeroCnt++;
			}
		}

		if (zeroCnt >= K)
			break;
	}

	cout << step << "\n";

	return 0;
}