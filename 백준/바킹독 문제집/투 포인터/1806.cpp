#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, S;

vector<int> v;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	int start = 0;
	int end = 0;
	int currentSum = v[0];
	int len = 1000000;

	while (true) {

		if (currentSum < S) {
			end++;
			if (end >= N) break;
			currentSum += v[end];
		}
		else {
			if (end - start + 1 < len) {
				len = end - start + 1;
			}
			currentSum -= v[start];
			start++;
			if (start > end) break;
		}

	}

	if (len == 1000000) cout << "0";
	else cout << len;

}

// start, end 각각 break 조건을 잘 생각해야 하는 문제!!