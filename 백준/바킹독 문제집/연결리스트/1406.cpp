#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

char s[100010];

int main() {

	scanf("%s", s);
	string input = s;

	list<char> L;

	for (int i = 0; i < input.length(); i++) {
		L.insert(L.end(), input[i]);
	}

	list<char>::iterator cursor = L.end();

	int N;
	scanf("%d", &N);
	string enter;
	getline(cin, enter);  // enter �� �� ����ֱ� -> �׳� cin ����ϸ� enter�� �� ����ִ� �� -> cin�� ����or���� �Է� �� ���� �������� ���� ����� �޾Ƶ��̱� ����

	for (int i = 0; i < N; i++) {
		string command;
		getline(cin, command);

		if (command[0] == 'L') {
			if (cursor != L.begin())
				cursor--;
		}
		else if (command[0] == 'D') {
			if (cursor != L.end())
				cursor++;
		}
		else if (command[0] == 'B') {
			if (cursor != L.begin()) {
				cursor--;  // Ŀ���� ���� ���ڸ� ����� ���̹Ƿ� ������ �� ĭ �̵��ؾ� �Ѵ�
				cursor = L.erase(cursor);
			}
		}
		else if (command[0] == 'P') {
			L.insert(cursor, command[2]);
		}

	}

	for (list<char>::iterator iter = L.begin(); iter != L.end(); iter++) {
		printf("%c", *iter);
	}

	return 0;
}



/* version2

#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string init;
  cin >> init;
  list<char> L;
  for (auto c : init) L.push_back(c);
  auto cursor = L.end();
  int q;
  cin >> q;
  while (q--) {
	char op;
	cin >> op;
	if (op == 'P') {
	  char add;
	  cin >> add;
	  L.insert(cursor, add);
	}
	else if (op == 'L') {
	  if (cursor != L.begin()) cursor--;
	}
	else if (op == 'D') {
	  if (cursor != L.end()) cursor++;
	}
	else { // 'B'
	  if (cursor != L.begin()) {
		cursor--;
		cursor = L.erase(cursor);
	  }
	}
  }
  for (auto c : L) cout << c;
}

*/