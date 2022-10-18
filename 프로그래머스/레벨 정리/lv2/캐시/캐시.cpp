#include <string>
#include <vector>
#include <map>
#include <list>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities)
{
	int answer = 0;

	map<string, int> mCache;
	list<string> lCache;
	list<string>::iterator iter;

	for (int i = 0; i < cities.size(); i++)
	{
		string city = "";
		for (int j = 0; j < cities[i].length(); j++)
		{
			city += tolower(cities[i][j]);
		}

		if (mCache[city] != 0)
		{
			answer += 1;
			for (iter = lCache.begin(); iter != lCache.end(); iter++)
			{
				if (*iter == city)
					break;
			}
			lCache.erase(iter);
			lCache.push_back(city);
		}
		else
		{
			if (cacheSize > 0)
			{
				if (lCache.size() < cacheSize)
				{
					mCache[city] = 1;
					lCache.push_back(city);
				}
				else
				{
					string remove = lCache.front();
					lCache.pop_front();
					mCache[remove] = 0;
					mCache[city] = 1;
					lCache.push_back(city);
				}
			}
			answer += 5;
		}
	}

	return answer;
}