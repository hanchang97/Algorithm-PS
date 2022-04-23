#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	vector<bool> fallCheck;

	map<int, int> M; // <index, value>

	for (int i = 0; i < prices.size(); i++) {
		if (i < prices.size() - 1) M[i] = 0;
		fallCheck.push_back(false);
	}

	for (int i = 1; i < prices.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (prices[j] <= prices[i] && fallCheck[j] == false) {
				M[j]++;
			}
			else {
				if (fallCheck[j] == false)
					M[j]++;
				fallCheck[j] = true;
			}
		}
	}

	for (auto iter = M.begin(); iter != M.end(); iter++) {
		answer.push_back(iter->second);
	}

	answer.push_back(0);

	return answer;
}


// n^2 복잡도여서 효율성 검사 통과 실패