#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;

	sort(people.begin(), people.end());

	int start = 0;
	int end = people.size() - 1;

	// start, end 같아지는 경우를 따로 처리 할 필요 없음
	while (start <= end) {
		if (people[start] + people[end] <= limit)
			start++;
		end--;
		answer++;
	}

	return answer;
}

// O(N)