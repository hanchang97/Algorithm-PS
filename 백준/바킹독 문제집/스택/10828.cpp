#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	stack<int> S;

	for (int i = 0; i < N; i++) {
		string command;
		cin >> command;

		if (command == "push") {
			int num;
			cin >> num;
			S.push(num);
		}
		else if (command == "pop") {
			if (S.empty())
				cout << "-1\n";
			else {
				cout << S.top() << "\n";
				S.pop();
			}
		}
		else if (command == "top") {
			if (S.empty())
				cout << "-1\n";
			else
				cout << S.top() << "\n";
		}
		else if (command == "size") {
			cout << S.size() << "\n";
		}
		else if (command == "empty") {
			if (S.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
	}

	return 0;
}