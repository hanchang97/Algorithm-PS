#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {

	vector<int> answer;

	vector<int> dayNeed;

	for (int i = 0; i < progresses.size(); i++) {
		int remain = 100 - progresses[i];

		int need = remain / speeds[i];
		if (remain % speeds[i] != 0) need++;

		dayNeed.push_back(need);
	}


	stack<pair<int, int>> s; // <needday,count>
	s.push({ dayNeed[0], 1 });

	for (int i = 1; i < dayNeed.size(); i++) {
		int topDay = s.top().first;
		if (dayNeed[i] <= topDay) {
			s.top().second++;
		}
		else {
			s.push({ dayNeed[i], 1 });
		}
	}

	vector<int> temp;
	while (!s.empty()) {
		temp.push_back(s.top().second);
		s.pop();
	}

	for (int i = temp.size() - 1; i >= 0; i--) {
		answer.push_back(temp[i]);
	}

	return answer;
}