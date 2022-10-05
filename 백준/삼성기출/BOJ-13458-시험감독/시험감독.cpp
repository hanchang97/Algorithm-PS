#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N;
int B, C; // B = 총감독관, C = 부감독관
long long int total;
vector<int> vApply;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		vApply.push_back(a);
	}

	cin >> B;
	cin >> C;

	for (int i = 0; i < vApply.size(); i++)
	{
		int cur1 = vApply[i];

		total += 1;
		cur1 -= B;

		if (cur1 > 0)
		{
			int cnt = cur1 / C;
			if (cur1 % C == 0)
			{
				total += cnt;
			}
			else
			{
				total += (cnt + 1);
			}
		}
	}

	cout << total;

	return 0;
}