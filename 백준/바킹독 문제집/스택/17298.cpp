#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

stack<int> S;
vector<int> V;
vector<int> result;  // �������� ���

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		V.push_back(a);
	}

	// �� ������ ������ ���� ������ -1
	result.push_back(-1);
	S.push(V[N - 1]);

	for (int i = N - 2; i >= 0; i--) {
		int current = V[i];

		while (true) {
			if (current >= S.top()) {
				S.pop();

				if (S.empty()) {
					S.push(current);
					result.push_back(-1);
					break;
				}
			}
			else {
				result.push_back(S.top());
				S.push(current);
				break;
			}
		}

	}

	for (int i = N - 1; i >= 0; i--)
		cout << result[i] << " ";

	return 0;
}

// ���û��
// ���� ������ �����ʿ� �ִ� �͵� �� ���ų� ���� ���� �ʿ� �����Ƿ� ���ÿ� ����ִٸ� �����Ѵ�!!