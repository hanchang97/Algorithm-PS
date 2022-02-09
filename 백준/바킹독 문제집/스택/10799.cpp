#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<pair<char, bool>> S;  // '(' �̸鼭 true ��� �������� �ش��ϴ� ���� ��ȣ!

	string expression;
	cin >> expression;

	int stick = 0;
	int ansStick = 0;

	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] == '(') { // ���� ��ȣ�� ���
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
			if (S.top().second == true) { // ������ ��ȣ �� ���
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

// ���� Ȱ��
// �������� ��� ��� ���� �����ϴ� ���� ���� ��ŭ ���� ���� �߰�
// ���� ��ȣ�� ��� �������� �ش��ϴ� ������, ���뿡 �ش��ϴ� �������� ������ �� �ְ� ����
// �ݴ� ��ȣ�� �������� �ش��ϴ� ���� ��ȣ�� ������ ���� �����ϴ� ���� ������ŭ ���� ���� �߰� �� ���� ��� pop
// �ݴ� ��ȣ�� ���뿡 �ش��ϴ� ���� ��ȣ�� ������ �����ϴ� ���밳�� �ϳ� ���ҽ�Ű�� ���� ������ �� �� �߰�, �����ϰ� ���� ��� pop
// �� ���밡 ������ �� ������ ������ ������ ���� �� ������ �����Ƿ� �ϳ��� �߰������ִ� ��!
// ���� ��ȣ�� ���ÿ� ���� �� ���� ���� ����� ���� ��ȣ��� �ش� ���� ��ȣ(���)�� �������� �ƴ� ����⿡ �ش��ϴ� ���� ��ȣ��
