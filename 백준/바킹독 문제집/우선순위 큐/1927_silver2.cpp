#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq; // ÃÖ¼Ò Èü

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		if (n == 0) {
			if (pq.size() == 0) {
				cout << 0 << "\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(n);
		}
	}

	return 0;
}