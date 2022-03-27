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

	func(inx + 1, sum); // 현재 원소 선택 x
	func(inx + 1, sum + V[inx]); // 현재 원소 선택 o
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
	// 초기 합을 0으로 두고 시작해서 아무 원소도 선택하지 않는 경우 그대로 0 이 나오므로 Sum이 0 인 경우는 1개를 빼줘야 한다

	cout << Count;
}