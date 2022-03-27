#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	sort(phone_book.begin(), phone_book.end());

	for (int i = 1; i < phone_book.size(); i++) {
		if (phone_book[i].find(phone_book[i - 1]) == 0) {
			answer = false;
			break;
		}
	}

	return answer;
}

// string 정렬 시 사전순으로 정렬되는 성질을 활용!!
// ex> 123 124 1256 132 ....  와 같이 정렬됨