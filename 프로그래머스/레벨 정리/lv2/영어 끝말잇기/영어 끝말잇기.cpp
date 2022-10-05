#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
	vector<int> answer;
	answer.push_back(0);
	answer.push_back(0);

	map<string, int> mWord;

	mWord[words[0]] += 1;

	for (int i = 1; i < words.size(); i++)
	{
		int curNum = i % n + 1;
		int curTurn = i / n + 1;

		char curStart = words[i][0];
		char preEnd = words[i - 1][words[i - 1].length() - 1];

		if (curStart != preEnd)
		{
			answer[0] = curNum;
			answer[1] = curTurn;
			break;
		}

		if (mWord[words[i]] != 0)
		{
			answer[0] = curNum;
			answer[1] = curTurn;
			break;
		}

		mWord[words[i]] += 1;
	}

	return answer;
}