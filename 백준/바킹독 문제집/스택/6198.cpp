#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

stack<int> S;
vector<int> V;

long long Count = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int possibleBuilding = 0;

	for (int i = 0; i < N; i++) {

		int a;
		cin >> a;

		if (i == 0)
			S.push(a);
		else {
			while (true) {
				if (a < S.top()) {
					possibleBuilding++;
					Count += possibleBuilding;
					S.push(a);
					break;
				}
				else {
					S.pop();

					if (possibleBuilding > 0)
						possibleBuilding--;

					if (S.empty()) {
						S.push(a);
						break;
					}
				}
			}
		}
	}

	cout << Count;

	return 0;
}


// ���� �������� ���ÿ� push
// �� ������ ���ö� ���� ������ �� �� �ִ� ������ �������� ������ ���� ��ü ������ �����ִ� �帧
// ���� �������� ������ top�� Ŀ�������� pop �ݺ�