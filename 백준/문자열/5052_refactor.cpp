#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int t, n;
string k;
string number[10000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++) {
		int num = 0;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> number[j];
		}
		sort(number, number + n);


		for (int k = 0; k < n; k++) {
			if (number[k + 1].find(number[k]) == 0) {
				cout << "NO" << endl;
				break;
			}
			else {
				num++;
			}
		}

		if (num == n) {
			cout << "YES" << endl;
		}
	}


	return 0;
}


// ���ڿ��� �⺻�������� sort �Լ� ����ؼ� ����
// ex>  972 9723 98 981 �̷� ������ ���ĵȴ�!!
// �̷��� ���ĵ� ��� �ڿ������� ���ξ� ��ġ�� �׷쿡�� ���̰� �� ���� �ڿ� ��ġ�ϰ� �ȴ�!!
// num�� n��ŭ�� ���� ������ n������ ���ξ� ��ġ�°� �ϳ��� ���� ���̹Ƿ� YES ���