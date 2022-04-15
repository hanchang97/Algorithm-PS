#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	map<int, int> m;

	int pre = 0;
	for (int i = 0; i < progresses.size(); i++) {
		int remain = 100 - progresses[i];
		int possibleDay = remain / speeds[i];
		if (remain % speeds[i] != 0) possibleDay++;
		
		if (possibleDay < pre) {
			m[pre] += 1;
		}
		else {
			pre = possibleDay;
			m[pre] += 1;
		}
	}

	for (auto iter = m.begin(); iter != m.end(); iter++) {
		answer.push_back(iter->second);
	}

	return answer;
}

// map 활용 풀이