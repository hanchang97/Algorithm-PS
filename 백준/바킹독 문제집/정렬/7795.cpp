#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int A, B;
		cin >> A >> B;

		vector<int> vA;
		vector<int> vB;

		for (int a = 0; a < A; a++) {
			int n;
			cin >> n;
			vA.push_back(n);
		}

		for (int b = 0; b < B; b++) {
			int n;
			cin >> n;
			vB.push_back(n);
		}

		sort(vA.begin(), vA.end());
		sort(vB.begin(), vB.end());

		int answer = 0;

		for (int i = 0; i < vA.size(); i++) {
			int cur = vA[i];
			for (int j = 0; j < vB.size(); j++) {
				if (cur <= vB[j]) break;
				answer++;
			}
		}

		cout << answer << "\n";
	}

	return 0;
}

// 2 * nlogn + n^2 -> n^2
// n 최대 20000 라서 완전탐색으로 풀이