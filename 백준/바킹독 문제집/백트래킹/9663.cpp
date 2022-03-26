#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
int Case = 0;
int arr[15][15] = { 0, };

void func(int row) {
	if (row == N) {
		Case++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (arr[row][i] == 0) {

			arr[row][i]++;

			// 좌측 하단 대각선 처리
			int y = row + 1;
			int x = i - 1;
			while (y < N && x < N && x >= 0) {
				arr[y][x]++;
				y++;
				x--;
			}

			// 하단 직선 처리
			y = row + 1;
			x = i;
			while (y < N && x < N && x >= 0) {
				arr[y][x]++;
				y++;
			}

			// 우측 하단 대각선 처리
			y = row + 1;
			x = i + 1;
			while (y < N && x < N && x >= 0) {
				arr[y][x]++;
				y++;
				x++;
			}

			func(row + 1);

			// 되돌리기

			arr[row][i]--;

			// 좌측 하단 대각선 처리
			y = row + 1;
			x = i - 1;
			while (y < N && x < N && x >= 0) {
				arr[y][x]--;
				y++;
				x--;
			}

			// 하단 직선 처리
			y = row + 1;
			x = i;
			while (y < N && x < N && x >= 0) {
				arr[y][x]--;
				y++;
			}

			// 우측 하단 대각선 처리
			y = row + 1;
			x = i + 1;
			while (y < N && x < N && x >= 0) {
				arr[y][x]--;
				y++;
				x++;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	func(0);

	cout << Case;
}


// 지나간곳은 1, 되돌릴때는 0 으로 하면  두 번 이상 중복된 곳이 되돌리는 과정에서 무조건 0이 되서 틀렸음!
// 중복되면 그만큼 카운팅 해주는 방식으로 수정,  지나가는 경로는 1씩 추가, 되돌리는 경우에는 1씩 감소
