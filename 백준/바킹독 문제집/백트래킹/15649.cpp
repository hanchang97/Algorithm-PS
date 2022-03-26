#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M;
int arr[10] = { 0, };
bool isUsed[10] = { 0, };

void func(int currentC) {
	if (currentC == M) {
		for (int i = 0; i < M; i++) cout << arr[i] << " ";
		cout << "\n";
	}

	for (int j = 1; j <= N; j++) {
		if (!isUsed[j]) {
			arr[currentC] = j;
			isUsed[j] = true;
			func(currentC + 1);
			isUsed[j] = false; // currentC 자리에 j를 사용완료 했으므로 다시 false 처리 해주기!
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	func(0);
}