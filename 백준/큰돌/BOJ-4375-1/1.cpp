#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);

	int N;

	while (scanf("%d", &N) != EOF)
	{
		int answer = 1;
		int count = 1;

		while (true)
		{
			if (answer % N == 0)
			{
				cout << count << "\n";
				break;
			}
			else
			{
				answer = answer * 10 + 1;
				answer %= N;
				count++;
			}
		}
	}

	return 0;
}
