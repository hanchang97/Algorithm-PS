#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool compare(const pair<string, int> &fir, const pair<string, int> &sec)
{
	return fir.second > sec.second;
}

vector<int> solution(string s)
{
	vector<int> answer;

	unordered_map<string, int> um;

	string temp = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 48 && s[i] <= 57)
		{
			temp += s[i];
		}
		else
		{
			if (temp.length() != 0)
			{
				um[temp] += 1;
			}
			temp = "";
		}
	}

	vector<pair<string, int>> v;
	for (auto iter = um.begin(); iter != um.end(); iter++)
	{
		v.push_back(make_pair(iter->first, iter->second));
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++)
	{
		string str = v[i].first;
		int num = atoi(str.c_str());
		answer.push_back(num);
	}

	return answer;
}