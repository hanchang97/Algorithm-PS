#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

string concTwoStrings(string s1, string s2)  // 두 문자열을 연결하는 부분을 함수로 따로 빼둠
{
	return s1 + s2;
}

vector<string> solution(vector<string> record) {
	vector<string> answer;

	map<string, string> mNickName; // <id, nickname> , 해당 id의 닉네임 관리

	vector<pair<int, string>> vSave;  // Enter = 0, Leave = 1

	for (int i = 0; i < record.size(); i++) {
		vector<string> vCurrent;
		stringstream ss(record[i]);
		string token;

		while (ss >> token) vCurrent.push_back(token);

		if (vCurrent[0] == "Enter") {
			vSave.push_back({ 0, vCurrent[1] });
			mNickName[vCurrent[1]] = vCurrent[2];
		}
		else if (vCurrent[0] == "Leave") {
			vSave.push_back({ 1, vCurrent[1] });
		}
		else { // Change
			mNickName[vCurrent[1]] = vCurrent[2];
		}

	}

	for (int i = 0; i < vSave.size(); i++) {
		if (vSave[i].first == 0) {
			answer.push_back(concTwoStrings(mNickName[vSave[i].second], "님이 들어왔습니다."));
		}
		else {
			answer.push_back(concTwoStrings(mNickName[vSave[i].second], "님이 나갔습니다."));
		}
	}

	return answer;
}

// 문자열을 공백 기준 나누기
// 닉네임 최신화를 위해 map 자료구조 활용