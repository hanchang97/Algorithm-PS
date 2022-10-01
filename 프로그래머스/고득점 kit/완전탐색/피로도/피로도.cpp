#include <string>
#include <vector>
#include <iostream>

using namespace std;

int maxCount = 0;
bool visited[8] = {0,};
int dungeonSize = 0;

int energyNeed[8] = {0,};
int energyConsumption[8] = {0,};

void getResult(int energyRemain, int count)
{
	for (int i = 0; i < dungeonSize; i++)
	{
		if (visited[i] == false)
		{
			bool minus = false; // 방문 후 실제로 에너지 소모했는지를 체크하기 위함
			visited[i] = true;

			if (energyRemain >= energyNeed[i])
			{
				count++;
				if (count > maxCount)
					maxCount = count;
				energyRemain -= energyConsumption[i];
				minus = true;
			}

			getResult(energyRemain, count);

			// 복구 작업
			visited[i] = false;
			count--;
			if (minus)
				energyRemain += energyConsumption[i];
		}
	}
}

int solution(int k, vector<vector<int>> dungeons)
{

	dungeonSize = dungeons.size();

	for (int i = 0; i < dungeons.size(); i++)
	{
		energyNeed[i] = dungeons[i][0];
		energyConsumption[i] = dungeons[i][1];
	}

	getResult(k, 0);

	return maxCount;
}