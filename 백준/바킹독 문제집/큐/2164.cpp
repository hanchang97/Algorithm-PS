#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	queue <int> q;

	for (int i = 1; i <= n; i++)
		q.push(i);

	while (q.size() > 1) {
		q.pop();
		int front = q.front();
		q.pop();
		q.push(front);
	}

	cout << q.front();

	return 0;
}