#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<pair<long long int, long long int>> s;
	long long int totalCount = 0;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		long long int cnt = 1;

		while (s.size() && s.top().first <= num)
		{
			totalCount += s.top().second;
			if (s.top().first == num)
			{
				cnt = s.top().second + 1;
			}
			else
			{
				cnt = 1;
			}
			s.pop();
		}
		if (s.size())
			totalCount++;

		s.push(make_pair(num, cnt));
	}

	cout << totalCount;

	return 0;
}
