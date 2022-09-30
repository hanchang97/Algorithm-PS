#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

string S, T;
bool isPossible = false;

void doRecursion(string t)
{
	if (t == S)
	{
		isPossible = true;
		return;
	}
	else if (t.length() == 0)
	{
		return;
	}
	else
	{
		if (t.back() == 'A')
		{
			doRecursion(t.substr(0, t.length() - 1));
		}
		if (t.front() == 'B')
		{
			reverse(t.begin(), t.end());
			doRecursion(t.substr(0, t.length() - 1));
		}
	}
}

int main()
{
	cin >> S;
	cin >> T;

	doRecursion(T);

	isPossible ? cout << 1 : cout << 0;

	return 0;
}
