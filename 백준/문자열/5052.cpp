#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool compare(string s1, string s2) {
	return s1.length() < s2.length();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<string> V;
	set<string> S;

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		for (int i = 0; i < N; i++) {
			string str;
			cin >> str;
			V.push_back(str);
		}

		sort(V.begin(), V.end(), compare);


		bool isAnswer = true;

		for (int i = 0; i < V.size(); i++) {
			string a = V[i];

			if (S.find(a) == S.end()) {
				string temp = a;
				while (temp.length() > 0) {
					if (S.find(temp) != S.end()) {
						isAnswer = false;
						break;
					}
					temp.pop_back();
				}

				if (temp.length() == 0)
					S.insert(a);

			}
			else {
				isAnswer = false;
				break;
			}
		}

		if (isAnswer)
			cout << "YES\n";
		else
			cout << "NO\n";


		V.clear();
		S.clear();
	}


	return 0;
}


// ��ȭ��ȣ�ΰ� 0���� �����ϴ� ��쵵 �����Ƿ� ���ڰ� �ƴ� ���ڿ��� �Է��� �޵��� �Ѵ�
// ���� ���ڿ����� �� �ڸ� �ϳ��� �����ذ��鼭 set�� �ִ��� �Ǵ��ϰ� ��� ���ٸ� �ش� ���ڿ��� set�� �ֱ�
// ���ڿ� ���̰� ª�� ���� �տ� ������ ������ �ؾ���
// �ݷʸ� ����ϱ� ����
// ex> 1 2 999999 9  �� �Է��ϸ� ���� ���� �ÿ��� YES�� ���´�
// -> ���ڿ� ����� �ڿ� �־�� ���� �ϳ��� �����ϸ鼭 ���ξ� �Ǵ��� �� �ڱ⺸�� ª�� ���ڿ����� �ߺ��� ���������� ó�� ����