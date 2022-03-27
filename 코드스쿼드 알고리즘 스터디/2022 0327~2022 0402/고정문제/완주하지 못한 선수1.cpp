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

// 2번째 방법보다는 시간 조금 더 소요되고, 메모리도 더 사용