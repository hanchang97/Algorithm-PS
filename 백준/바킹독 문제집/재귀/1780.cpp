#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
int arr[3000][3000] = { 0, };

int count_0 = 0;
int count_1 = 0;
int count_m1 = 0;

bool check(int y, int x, int len) {
	int start = arr[y][x];
	bool flag = true;

	for (int i = y; i < y + len; i++) {
		for (int j = x; j < x + len; j++) {
			if (start != arr[i][j]) {
				flag = false;
				break;
			}
		}
	}

	if (flag) {
		if (start == 0) count_0++;
		else if (start == 1) count_1++;
		else count_m1++;
	}

	return flag;
}

void func(int y, int x, int n) {
	if (n == 1) {
		if (arr[y][x] == 0) count_0++;
		else if (arr[y][x] == 1) count_1++;
		else count_m1++;
		return;
	}

	if (check(y, x, n)) {  // 9개 모두 같으면 쪼갤 필요 없다
		return;
	}

	int next = n / 3;

	for (int k = y; k <= y + 2 * next; k += next) { // 쪼개야 한다면 현재 시작 좌표 기준 9개로 나눈 영역의 각각 좌측 상단 좌표로 재귀 수행
		for (int t = x; t <= x + 2 * next; t += next) {
			func(k, t, next);
		}
	}

}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	func(0, 0, N);

	cout << count_m1 << "\n" << count_0 << "\n" << count_1;
}