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


	for (int i = 0; i < exp.length(); i++) {  // 여는 소괄호 = -2,  여는 대괄호 = -3
		if (exp[i] == '(' || exp[i] == '[') {
			if (exp[i] == '(')
				S.push(-2);
			else
				S.push(-3);
		}
		else {
			if (S.empty()) {  // 스택 빈 상태에서 닫히는 괄호 나오면 무조건 식 성립 x
				cout << "0";
				return 0;
			}
			else {
				if (S.top() == -2 || S.top() == -3) { // 여는 괄호 후 바로 닫히는 경우
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
				else {  // 닫는  괄호 앞에 값이 있는 경우
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

// 스택 활용
// 연이어서 열고 닫는 괄호 형태 값을 계산 후 스택에 그 값을 넣는 방식으로 구현