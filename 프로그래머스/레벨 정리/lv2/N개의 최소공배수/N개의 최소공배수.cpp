#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> arr)
{
	int answer = 0;

	sort(arr.begin(), arr.end());

	int start = arr[arr.size() - 1];

	while (true)
	{
		bool isPossible = true;
		for (int i = 0; i < arr.size(); i++)
		{
			if (start % arr[i] != 0)
			{
				isPossible = false;
				break;
			}
		}

		if (isPossible)
		{
			answer = start;
			break;
		}
		else
		{
			start++;
		}
	}

	return answer;
}