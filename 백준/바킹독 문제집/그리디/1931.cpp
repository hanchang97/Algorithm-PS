#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <sstream>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		string command; // ��ɾ� �Է�
		cin >> command;

		int count; // �迭�� �� �ִ� ���� ����
		cin >> count;

		string countStr; // �迭�� �� �ִ� ���� ���ڿ�
		cin >> countStr;

		deque<string> dq;  // ���ڿ� ���� �� ���� ��

		countStr.erase(countStr.length() - 1, 1);
		countStr.erase(0, 1);

		stringstream ss(countStr);
		string token;

		while (getline(ss, token, ',')) {
			dq.push_back(token);
			//cout << "token : " << token << "\n";
		}


		bool frontIsLeft = true;
		bool isError = false;

		for (int i = 0; i < command.length(); i++) {
			if (command[i] == 'R') {
				frontIsLeft = !frontIsLeft;  // R ����� O(1) �� ó��
			}
			else {
				if (dq.size() == 0) {
					isError = true;
					break;
				}
				else {
					if (frontIsLeft)
						dq.pop_front();
					else
						dq.pop_back();
				}
			}
		}

		if (isError)
			cout << "error\n";
		else {
			cout << "[";
			if (frontIsLeft) {
				for (int t = 0; t < dq.size(); t++) {
					if (t == 0)
						cout << dq[t];
					else
						cout << "," << dq[t];
				}
			}
			else {
				for (int t = dq.size() - 1; t >= 0; t--) {
					if (t == dq.size() - 1)
						cout << dq[t];
					else
						cout << "," << dq[t];
				}
			}
			cout << "]\n";
		}

	}

	return 0;
}



// ������  R ����� �������� �ӽ� ���� �ΰ� ���� ���� ���¿��� �ݺ����� ���� �ϳ��� ���Ҹ� �������� �������� ������� ������ ���� ����
// but �� ��� ��ɾ� ���̰� 10000, �迭 ���� ���� ������ 10000 �� �Ǿ �ݺ��� ������ 1����� �Ǿ� �ð��ʰ� �߻�

// ���� flag ������ �ξ� ���� �κ��� ����������, ���������� �Ǵ� �� ������ ������ �����ν� ���� �ݺ����� ����

// ���� ���������� �����°� �ƴ� �������� ������ �߻��� �ϴ� ���� �߿��ߴ�