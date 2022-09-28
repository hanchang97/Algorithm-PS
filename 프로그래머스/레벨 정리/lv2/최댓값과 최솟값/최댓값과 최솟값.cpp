#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s)
{

	string answer = "";

	vector<string> vString;
	vector<int> vInt;

	// 공백 기준으로 문자열 분할
	stringstream ss1(s);
	string token;

	while (ss1 >> token)
	{
		vString.push_back(token);
	}

	// for(int i = 0; i < vString.size(); i++)
	//     cout << vString[i] << "\n";

	// 각 문자열 정수로 변환 후 벡터에 넣기
	for (int i = 0; i < vString.size(); i++)
	{
		string cur = vString[i];
		int num = atoi(cur.c_str());
		vInt.push_back(num);
	}

	sort(vInt.begin(), vInt.end());

	answer += to_string(vInt[0]);
	answer += " ";
	answer += to_string(vInt[vInt.size() - 1]);

	return answer;
}