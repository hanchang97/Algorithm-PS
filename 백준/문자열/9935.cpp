#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str1;
	string bombStr;

	cin >> str1;
	cin >> bombStr;

	vector<char> v;

	for (int i = 0; i < str1.length(); i++) {
		v.push_back(str1[i]);

		if (v.size() >= bombStr.length()) {
			bool erase = true;
			for (int j = 0; j < bombStr.length(); j++) {
				if (v[v.size() - 1 - j] != bombStr[bombStr.length() - 1 - j]) {
					erase = false;
					break;
				}
			}

			if (erase) {
				for (int k = 0; k < bombStr.length(); k++)
					v.pop_back();
			}
		}
	}

	if (v.size() == 0)
		cout << "FRULA";
	else {
		for (int i = 0; i < v.size(); i++)
			cout << v[i];
	}


	return 0;
}


// find �� erase �� �Ź� O(n)�� �ҿ�ǹǷ� �ð��ʰ� �߻�
// �� ��� ������ ������ �Ϻ� �����Ͽ� Ǯ��
// vector�� �� ������ ���� ����( pop_back )�� O(1)