#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;

void func(int n) {
	if (n == N) {
		for (int i = 0; i < 4 * n; i++) cout << "_";
		cout << "\"����Լ��� ������?\"" << "\n";

		for (int i = 0; i < 4 * n; i++) cout << "_";
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << "\n";

		for (int i = 0; i < 4 * n; i++) cout << "_";
		cout << "��� �亯�Ͽ���." << "\n";

		return;
	}

	for (int i = 0; i < 4 * n; i++) cout << "_";
	cout << "\"����Լ��� ������?\"" << "\n";

	for (int i = 0; i < 4 * n; i++) cout << "_";
	cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << "\n";

	for (int i = 0; i < 4 * n; i++) cout << "_";
	cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << "\n";

	for (int i = 0; i < 4 * n; i++) cout << "_";
	cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << "\n";

	func(n + 1);

	for (int i = 0; i < 4 * n; i++) cout << "_";
	cout << "��� �亯�Ͽ���." << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << "\n";

	func(0);
}

// ��͸� Ȱ���� Ǯ��