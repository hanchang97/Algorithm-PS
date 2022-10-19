#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	unordered_map<string, string> mString;

	for (int i = 1; i <= N; i++)
	{
		string pokemon;
		cin >> pokemon;
		mString[pokemon] = to_string(i);
		mString[to_string(i)] = pokemon;
	}

	for (int i = 0; i < M; i++)
	{
		string prob;
		cin >> prob;
		cout << mString[prob] << "\n";
	}

	return 0;
}
