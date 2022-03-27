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

// string ���� �� ���������� ���ĵǴ� ������ Ȱ��!!
// ex> 123 124 1256 132 ....  �� ���� ���ĵ�