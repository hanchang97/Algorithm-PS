#include <string>
#include <vector>
#include <iostream>

using namespace std;

int arr[100005] = {
	0,
};

int solution(int n)
{
	int answer = 0;

	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		arr[i] = ((arr[i - 1] % 1234567) + (arr[i - 2] % 1234567)) % 1234567;
	}

	answer = arr[n];

	return answer;
}