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

			// ���� �ϴ� �밢�� ó��
			int y = row + 1;
			int x = i - 1;
			while (y < N && x < N && x >= 0) {
				arr[y][x]++;
				y++;
				x--;
			}

			// �ϴ� ���� ó��
			y = row + 1;
			x = i;
			while (y < N && x < N && x >= 0) {
				arr[y][x]++;
				y++;
			}

			// ���� �ϴ� �밢�� ó��
			y = row + 1;
			x = i + 1;
			while (y < N && x < N && x >= 0) {
				arr[y][x]++;
				y++;
				x++;
			}

			func(row + 1);

			// �ǵ�����

			arr[row][i]--;

			// ���� �ϴ� �밢�� ó��
			y = row + 1;
			x = i - 1;
			while (y < N && x < N && x >= 0) {
				arr[y][x]--;
				y++;
				x--;
			}

			// �ϴ� ���� ó��
			y = row + 1;
			x = i;
			while (y < N && x < N && x >= 0) {
				arr[y][x]--;
				y++;
			}

			// ���� �ϴ� �밢�� ó��
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


// ���������� 1, �ǵ������� 0 ���� �ϸ�  �� �� �̻� �ߺ��� ���� �ǵ����� �������� ������ 0�� �Ǽ� Ʋ����!
// �ߺ��Ǹ� �׸�ŭ ī���� ���ִ� ������� ����,  �������� ��δ� 1�� �߰�, �ǵ����� ��쿡�� 1�� ����
