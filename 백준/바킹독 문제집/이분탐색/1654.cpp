#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int K, N;
	cin >> K >> N;

	vector<long long int> V;

	for (int i = 0; i < K; i++) {
		long long int n;
		cin >> n;

		V.push_back(n);
	}

	sort(V.begin(), V.end());

	long long int start = 1;
	long long int end = V[K - 1];

	int answer = 0;
	while (start <= end) {
		long long int mid = (start + end) / 2;

		long long int count = 0;
		for (int i = 0; i < V.size(); i++) {
			count += V[i] / mid;
		}

		if (count >= N) {
			answer = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	cout << answer;
}