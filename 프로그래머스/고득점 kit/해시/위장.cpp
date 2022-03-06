#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;

	map<string, int> M;

	for (int i = 0; i < clothes.size(); i++) {
		M[clothes[i][1]] += 1;
	}

	for (auto iter = M.begin(); iter != M.end(); iter++) {
		answer *= ((iter->second) + 1);
	}

	answer -= 1;  // �ƹ��͵� ���� �ʴ� ���� ����� �Ѵ�

	return answer;
}