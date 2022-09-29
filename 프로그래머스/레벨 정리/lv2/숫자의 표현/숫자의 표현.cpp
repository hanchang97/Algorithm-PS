#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n)
{
	int answer = 0;

	for (int i = 1; i <= n; i++)
	{
		int sum = i;
		int current = i;
		while (true)
		{
			if (sum == n)
			{
				answer++;
				break;
			}
			else if (sum > n)
			{
				break;
			}
			else
			{
				sum += (++current);
			}
		}
	}

	return answer;
}