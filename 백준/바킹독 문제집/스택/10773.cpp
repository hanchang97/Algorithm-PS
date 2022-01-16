#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	stack<int> S;

	int Sum = 0;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		if (num == 0) {
			if (!S.empty()) {
				Sum -= S.top();
				S.pop();
			}
		}
		else {
			Sum += num;
			S.push(num);
		}
	}

	cout << Sum << "\n";

	return 0;
}