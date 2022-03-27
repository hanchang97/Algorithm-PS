#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<int> v;

	for (int i = 1; i <= N; i++) {
		if (i <= M) v.push_back(0);
		else v.push_back(1);
	}

	do {
		for (int i = 0; i < N; i++)
			if (v[i] == 0)
				cout << i + 1 << " ";
		cout << "\n";
	} while (next_permutation(v.begin(), v.end()));
}

// next_permutation을 활용한 풀이!!!