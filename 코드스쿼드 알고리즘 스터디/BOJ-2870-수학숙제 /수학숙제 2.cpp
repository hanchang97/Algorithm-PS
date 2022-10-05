#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool compare(string a, string b)
{
	if (a.length() == b.length())
		return a < b;
	return a.length() < b.length();
}

int main()
{
	int N;
	cin >> N;

	vector<string> v;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		string temp = "";
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] >= '0' && str[j] <= '9')
			{
				temp += str[j];
			}
			else
			{
				if (temp.length() >= 1)
				{
					v.push_back(temp);
					temp = "";
				}
			}
		}

		if (temp.length() >= 1) // 숫자로 끝나는 경우를 위함
			v.push_back(temp);
	}

	for (int i = 0; i < v.size(); i++) // 0 제거
	{
		int inx = v[i].length() - 1;
		for (int j = 0; j < v[i].length(); j++)
		{
			if (v[i][j] != '0')
			{
				inx = j;
				break;
			}
		}

		v[i] = v[i].substr(inx);
	}

	// v 오름차순 정렬하기
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";

	return 0;
}