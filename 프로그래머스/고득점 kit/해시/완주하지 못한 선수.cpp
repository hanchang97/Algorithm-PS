#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	map<string, int> M;

	for (int i = 0; i < completion.size(); i++) {
		M[completion[i]] += 1;
	}

	for (int i = 0; i < participant.size(); i++) {
		M[participant[i]] -= 1;
		if (M[participant[i]] < 0) {
			answer = participant[i];
			break;
		}
	}

	return answer;
}