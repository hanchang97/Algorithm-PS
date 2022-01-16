#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main() {

	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;

		list<char> L;
		list<char>::iterator cursor = L.end(); //����Ʈ ����ִ� ��� begin �� end ���� ����!!

		for (int j = 0; j < input.length(); j++) {
			if (input[j] == '<') {
				if (cursor != L.begin())
					cursor--;
			}
			else if (input[j] == '>') {
				if (cursor != L.end())
					cursor++;
			}
			else if (input[j] == '-') {
				if (cursor != L.begin()) {
					cursor--;
					cursor = L.erase(cursor);
				}
			}
			else {
				L.insert(cursor, input[j]);
			}
		}

		for (list<char>::iterator i = L.begin(); i != L.end(); i++) {
			printf("%c", *i);
		}
		printf("\n");
	}

	return 0;
}

// BOJ 1406�� ���� ���� -> ���Ḯ��Ʈ ���!