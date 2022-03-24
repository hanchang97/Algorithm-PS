#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> v;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	int start = 0;
	int end = 0;
	int gap = 2000000000;

	while (true) {
		int cur = v[end] - v[start];

		if (cur > M) {
			start++;
			if (cur < gap) gap = cur;

		}
		else if (cur == M) {
			if (start != end) {
				gap = M;
				break;
			}
			else {
				end++;
			}
		}
		else {
			end++;
		}

		if (end >= N || start >= N - 1) break;  // 탈출 조건이 중요!!

	}

	cout << gap;
}