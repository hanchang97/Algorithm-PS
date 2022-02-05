#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		string str;
		getline(cin, str);

		if (str == ".")
			break;
		else {
			stack<char> S;

			for (int i = 0; i < str.length(); i++) {
				if (str[i] == '(' || str[i] == '[')
					S.push(str[i]);
				if (str[i] == ')') {
					if (!S.empty() && S.top() == '(')
						S.pop();
					else
						S.push(str[i]);
				}
				if (str[i] == ']') {
					if (!S.empty() && S.top() == '[')
						S.pop();
					else
						S.push(str[i]);
				}
			}

			if (S.empty())
				cout << "yes\n";
			else
				cout << "no\n";
		}
	}

	return 0;
}

// ���� Ȱ��
// ���ڿ��� ������� �Է��� �޾ƾ� �ϹǷ� getline(cin, string)�� ����ؾ� �ߴ� ����