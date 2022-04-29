#include<iostream>
#include<queue>
#include<cmath>

using namespace std;

struct cmp {
	bool operator()(int first, int second) {
		if (abs(first) > abs(second)) return true;   // ���밪�� ���� �Ϳ� �켱������ ���� �ְڴ�!! -> �Ϲ� sort�� �ݴ�� ����!!
		else if (abs(first) == abs(second)) {
			if (first > second) return true; // ���밪�� ���ٸ� ���� ���� �� ���� �Ϳ� �켱���� ���� �ְڴ�
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