#include <iostream>
#include <queue>
#include <deque>
#include <vector>
using namespace std;

int Count = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N;
	cin >> M;

	vector<int> V;
	for (int i = 0; i < M; i++) {  // ã������ �� vector
		int num;
		cin >> num;
		V.push_back(num);
	}

	deque<int> Dq;
	for (int i = 1; i <= N; i++)
		Dq.push_back(i);

	for (int i = 0; i < M; i++) {
		int currentFind = V[i];
		int currentIndex = -1;

		for (int j = 0; j < Dq.size(); j++) {
			if (currentFind == Dq[j]) {
				currentIndex = j;
				break;
			}
		}

		int move = 0;
		if (currentIndex >= Dq.size() - currentIndex) {
			move = Dq.size() - currentIndex;
			for (int k = 0; k < move; k++) {
				Dq.push_front(Dq.back());
				Dq.pop_back();
			}
		}
		else {
			move = currentIndex;
			for (int k = 0; k < move; k++) {
				Dq.push_back(Dq.front());
				Dq.pop_front();
			}
		}

		Dq.pop_front();
		Count += move;
	}

	cout << Count;

	return 0;
}


// ���� ã������ ���� ����, ���������� ���� �� �� �̵��ϸ� �� �տ� �������� ��!