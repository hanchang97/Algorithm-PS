#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, S;
vector<int> V;

int Sum = 0;
int Count = 0;

long long int Counting = 0;

void func(int inx, int sum) {
	if (inx == N) {
		if (sum == S) {
			Count++;
		}
		return;
	}

	func(inx + 1, sum); // ���� ���� ���� x
	func(inx + 1, sum + V[inx]); // ���� ���� ���� o
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		V.push_back(a);
	}

	func(0, 0);

	if (S == 0) Count--;
	// �ʱ� ���� 0���� �ΰ� �����ؼ� �ƹ� ���ҵ� �������� �ʴ� ��� �״�� 0 �� �����Ƿ� Sum�� 0 �� ���� 1���� ����� �Ѵ�

	cout << Count;
}