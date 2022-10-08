#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int N;

struct cmp
{
	bool operator()(int first, int second)
	{
		return first < second;
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	priority_queue<int, vector<int>, cmp> pq;

	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		if (n == 0)
		{
			if (pq.empty())
				cout << "0\n";
			else
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
		{
			pq.push(n);
		}
	}

	return 0;
}