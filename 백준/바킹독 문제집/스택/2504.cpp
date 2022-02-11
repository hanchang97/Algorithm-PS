#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string exp;
	cin >> exp;

	stack<int> S;


	for (int i = 0; i < exp.length(); i++) {  // ���� �Ұ�ȣ = -2,  ���� ���ȣ = -3
		if (exp[i] == '(' || exp[i] == '[') {
			if (exp[i] == '(')
				S.push(-2);
			else
				S.push(-3);
		}
		else {
			if (S.empty()) {  // ���� �� ���¿��� ������ ��ȣ ������ ������ �� ���� x
				cout << "0";
				return 0;
			}
			else {
				if (S.top() == -2 || S.top() == -3) { // ���� ��ȣ �� �ٷ� ������ ���
					if (S.top() == -2 && exp[i] == ')') {
						S.pop();
						S.push(2);
					}
					else if (S.top() == -3 && exp[i] == ']') {
						S.pop();
						S.push(3);
					}
					else {
						cout << "0";
						return 0;
					}
				}
				else {  // �ݴ�  ��ȣ �տ� ���� �ִ� ���
					int value = S.top();
					S.pop();

					if (!S.empty() && S.top() == -2 && exp[i] == ')') {
						S.pop();
						S.push(value * 2);
					}
					else if (!S.empty() && S.top() == -3 && exp[i] == ']') {
						S.pop();
						S.push(value * 3);
					}
					else {
						cout << "0";
						return 0;
					}
				}
			}
		}

		if (S.size() >= 2) {
			int temp1 = S.top();
			S.pop();
			int temp2 = S.top();
			S.pop();

			if (temp1 >= 0 && temp2 >= 0) {
				S.push(temp1 + temp2);
			}
			else {
				S.push(temp2);
				S.push(temp1);
			}

		}
	}

	if (S.size() == 1 && S.top() > 0)
		cout << S.top();
	else
		cout << "0";


	return 0;
}

// ���� Ȱ��
// ���̾ ���� �ݴ� ��ȣ ���� ���� ��� �� ���ÿ� �� ���� �ִ� ������� ����