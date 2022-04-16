#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

string concTwoStrings(string s1, string s2)  // �� ���ڿ��� �����ϴ� �κ��� �Լ��� ���� ����
{
	return s1 + s2;
}

vector<string> solution(vector<string> record) {
	vector<string> answer;

	map<string, string> mNickName; // <id, nickname> , �ش� id�� �г��� ����

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
			answer.push_back(concTwoStrings(mNickName[vSave[i].second], "���� ���Խ��ϴ�."));
		}
		else {
			answer.push_back(concTwoStrings(mNickName[vSave[i].second], "���� �������ϴ�."));
		}
	}

	return answer;
}

// ���ڿ��� ���� ���� ������
// �г��� �ֽ�ȭ�� ���� map �ڷᱸ�� Ȱ��