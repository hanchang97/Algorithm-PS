#include<iostream>
#include<queue>
#include<cmath>

using namespace std;

struct cmp {
	bool operator()(int first, int second) {
		if (abs(first) > abs(second)) return true;   // 절대값이 작은 것에 우선순위를 높게 주겠다!! -> 일반 sort와 반대로 생각!!
		else if (abs(first) == abs(second)) {
			if (first > second) return true; // 절대값이 같다면 원래 값이 더 작은 것에 우선순위 높게 주겠다
			else return false;
		}
		else return false;
	}
};

int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	priority_queue<int, vector<int>, cmp> pq;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		if (n == 0) {
			if (pq.empty()) cout << 0 << "\n";
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