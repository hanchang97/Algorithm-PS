#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string removeZero(string s)
{
	string removed = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '1')
			removed += "1";
	}

	return removed;
}

string convert(int num)
{
	string converted = "";
	while (num >= 1)
	{
		if (num % 2 == 0)
			converted += "0";
		else
			converted += "1";
		num /= 2;
	}

	reverse(converted.begin(), converted.end());
	return converted;
}

vector<int> solution(string s)
{

	vector<int> answer;

	int convertCount = 0;
	int removeCount = 0;

	while (true)
	{
		convertCount++;

		string removed = removeZero(s);
		removeCount += (s.length() - removed.length());

		string convertedStr = convert(removed.length());
		if (convertedStr == "1")
			break;

		s = convertedStr;
	}

	answer.push_back(convertCount);
	answer.push_back(removeCount);

	return answer;
}