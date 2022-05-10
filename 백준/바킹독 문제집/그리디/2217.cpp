#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> ropeV;
	for (int i = 0; i < N; i++) {
		int r;
		cin >> r;
		ropeV.push_back(r);
	}

	sort(ropeV.begin(), ropeV.end());

	int max = 0;

	for (int i = 0; i < N; i++) {
		if (ropeV[i] * (N - i) > max) max = ropeV[i] * (N - i);
	}

	cout << max;

	return 0;
}

