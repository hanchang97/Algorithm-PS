#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<pair<char, bool>> S;  // '(' 이면서 true 라면 레이저에 해당하는 여는 괄호!

	string expression;
	cin >> expression;

	int stick = 0;
	int ansStick = 0;

	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] == '(') { // 여는 괄호인 경우
			if (S.empty()) {
				S.push(make_pair('(', true));
				stick++;
			}
			else {
				S.top().second = false;

				S.push(make_pair('(', true));
				stick++;
			}
		}
		else {
			if (S.top().second == true) { // 레이저 괄호 인 경우
				S.pop();
				stick--;
				ansStick += stick;
			}
			else {
				S.pop();
				stick--;
				ansStick += 1;
			}
		}
	}

	cout << ansStick;

	return 0;
}

// 스택 활용
// 레이저가 쏘는 경우 현재 존재하는 막대 개수 만큼 조각 개수 추가
// 여는 괄호의 경우 레이저에 해당하는 것인지, 막대에 해당하는 것인지를 구분할 수 있게 구현
// 닫는 괄호가 레이저에 해당하는 여는 괄호를 만나면 현재 존재하는 막대 개수만큼 조각 개수 추가 후 스택 상단 pop
// 닫는 괄호가 막대에 해당하는 여는 괄호를 만나면 존재하는 막대개수 하나 감소시키고 조각 개수는 한 개 추가, 동일하게 스택 상단 pop
// 한 막대가 끝나면 그 막대의 마지막 레이저 이후 한 조각이 남으므로 하나를 추가시켜주는 것!
// 여는 괄호가 스택에 들어가기 전 현재 스택 상단이 여는 괄호라면 해당 여는 괄호(상단)는 레이저가 아닌 막대기에 해당하는 여는 괄호다
