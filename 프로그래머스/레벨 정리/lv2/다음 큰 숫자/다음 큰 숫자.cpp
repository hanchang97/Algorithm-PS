#include <string>
#include <vector>
#include <iostream>

using namespace std;

int getOneCount(int n)
{
	int count = 0;
	while (n >= 1)
	{
		if (n % 2 == 1)
			count++;
		n /= 2;
	}
	return count;
}

int solution(int n)
{
	int answer = 0;

	int nCount = getOneCount(n);

	int start = n + 1;
	while (true)
	{
		if (nCount == getOneCount(start))
		{
			answer = start;
			break;
		}
		start++;
	}

	return answer;
}