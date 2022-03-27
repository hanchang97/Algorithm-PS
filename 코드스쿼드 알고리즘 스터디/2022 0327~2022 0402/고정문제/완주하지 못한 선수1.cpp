#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	map<string, int> map_p;
	map<string, int> map_c;

	for (int i = 0; i < participant.size(); i++) map_p[participant[i]]++;
	for (int i = 0; i < completion.size(); i++) map_c[completion[i]]++;

	for (int i = 0; i < participant.size(); i++) {
		if (map_p[participant[i]] != map_c[participant[i]]) {
			answer = participant[i];
			break;
		}
	}

	return answer;
}

// 2��° ������ٴ� �ð� ���� �� �ҿ�ǰ�, �޸𸮵� �� ���