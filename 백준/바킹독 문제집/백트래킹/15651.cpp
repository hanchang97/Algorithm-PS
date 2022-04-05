#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M;
int arr[8] = { 0, };

void func(int count) {

	if (count > M) {
		for (int j = 1; j <= M; j++) {
			cout << arr[j] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		arr[count] = i;
		func(count + 1);
	}

}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	func(1);
}

// 중복 허용이므로 숫자 사용여부 체크 필요x