#include <iostream>
#include <string>
#include <vector>


using namespace std;

int N, M;

int office[8][8] = { 0, };

struct Cctv {
	int y;
	int x;
	int direction;
};

vector<Cctv> cctv;

int Min = 100;

void func(int current) {
	if (current >= cctv.size()) {

		int officeTemp[8][8] = { 0, };
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < M; b++) {
				officeTemp[a][b] = office[a][b];
			}
		}

		for (int k = 0; k < cctv.size(); k++) {
			int currentCctv = officeTemp[cctv[k].y][cctv[k].x];  // 1~5
			int currentDirection = cctv[k].direction;

			int currentY = cctv[k].y;
			int currentX = cctv[k].x;

			if (currentCctv == 1) {
				if (currentDirection == 1) {  // 우
					for (int p = currentX + 1; p <= M - 1; p++) {
						if (officeTemp[currentY][p] == 6) {
							break;
						}
						if (officeTemp[currentY][p] == 0) {
							officeTemp[currentY][p] = 7;
						}
					}

				}
				else if (currentDirection == 2) {  // 하
					for (int p = currentY + 1; p <= N - 1; p++) {
						if (officeTemp[p][currentX] == 6) {
							break;
						}
						if (officeTemp[p][currentX] == 0) {
							officeTemp[p][currentX] = 7;
						}
					}
				}
				else if (currentDirection == 3) {  // 좌
					for (int p = currentX - 1; p >= 0; p--) {
						if (officeTemp[currentY][p] == 6) {
							break;
						}
						if (officeTemp[currentY][p] == 0) {
							officeTemp[currentY][p] = 7;
						}
					}
				}
				else { // 4 상
					for (int p = currentY - 1; p >= 0; p--) {
						if (officeTemp[p][currentX] == 6) {
							break;
						}
						if (officeTemp[p][currentX] == 0) {
							officeTemp[p][currentX] = 7;
						}
					}
				}

			}
			else if (currentCctv == 2) {
				if (currentDirection == 1 || currentDirection == 3) {  // 좌우
					for (int p = currentX - 1; p >= 0; p--) { // 좌
						if (officeTemp[currentY][p] == 6) {
							break;
						}
						if (officeTemp[currentY][p] == 0) {
							officeTemp[currentY][p] = 7;
						}
					}

					for (int p = currentX + 1; p <= M - 1; p++) { // 우
						if (officeTemp[currentY][p] == 6) {
							break;
						}
						if (officeTemp[currentY][p] == 0) {
							officeTemp[currentY][p] = 7;
						}
					}

				}
				else { // 상하
					for (int p = currentY - 1; p >= 0; p--) { // 상
						if (officeTemp[p][currentX] == 6) {
							break;
						}
						if (officeTemp[p][currentX] == 0) {
							officeTemp[p][currentX] = 7;
						}
					}

					for (int p = currentY + 1; p <= N - 1; p++) { // 하
						if (officeTemp[p][currentX] == 6) {
							break;
						}
						if (officeTemp[p][currentX] == 0) {
							officeTemp[p][currentX] = 7;
						}
					}

				}

			}
			else if (currentCctv == 3) {
				if (currentDirection == 1) {  // 상 우
					for (int p = currentY - 1; p >= 0; p--) { // 상
						if (officeTemp[p][currentX] == 6) {
							break;
						}
						if (officeTemp[p][currentX] == 0) {
							officeTemp[p][currentX] = 7;
						}
					}

					for (int p = currentX + 1; p <= M - 1; p++) { // 우
						if (officeTemp[currentY][p] == 6) {
							break;
						}
						if (officeTemp[currentY][p] == 0) {
							officeTemp[currentY][p] = 7;
						}
					}

				}
				else if (currentDirection == 2) {  // 우 하
					for (int p = currentX + 1; p <= M - 1; p++) { // 우
						if (officeTemp[currentY][p] == 6) {
							break;
						}
						if (officeTemp[currentY][p] == 0) {
							officeTemp[currentY][p] = 7;
						}
					}

					for (int p = currentY + 1; p <= N - 1; p++) { // 하
						if (officeTemp[p][currentX] == 6) {
							break;
						}
						if (officeTemp[p][currentX] == 0) {
							officeTemp[p][currentX] = 7;
						}
					}

				}
				else if (currentDirection == 3) {  // 하 좌
					for (int p = currentY + 1; p <= N - 1; p++) { // 하
						if (officeTemp[p][currentX] == 6) {
							break;
						}
						if (officeTemp[p][currentX] == 0) {
							officeTemp[p][currentX] = 7;
						}
					}

					for (int p = currentX - 1; p >= 0; p--) { // 좌
						if (officeTemp[currentY][p] == 6) {
							break;
						}
						if (officeTemp[currentY][p] == 0) {
							officeTemp[currentY][p] = 7;
						}
					}

				}
				else { // 4 좌 상
					for (int p = currentX - 1; p >= 0; p--) { // 좌
						if (officeTemp[currentY][p] == 6) {
							break;
						}
						if (officeTemp[currentY][p] == 0) {
							officeTemp[currentY][p] = 7;
						}
					}

					for (int p = currentY - 1; p >= 0; p--) { // 상
						if (officeTemp[p][currentX] == 6) {
							break;
						}
						if (officeTemp[p][currentX] == 0) {
							officeTemp[p][currentX] = 7;
						}
					}

				}

			}
			else if (currentCctv == 4) {
				if (currentDirection == 1) {  // 좌 상 우
					for (int p = currentX - 1; p >= 0; p--) { // 좌
						if (officeTemp[currentY][p] == 6) {
							break;
						}
						if (officeTemp[currentY][p] == 0) {
							officeTemp[currentY][p] = 7;
						}
					}

					for (int p = currentY - 1; p >= 0; p--) { // 상
						if (officeTemp[p][currentX] == 6) {
							break;
						}
						if (officeTemp[p][currentX] == 0) {
							officeTemp[p][currentX] = 7;
						}
					}

					for (int p = currentX + 1; p <= M - 1; p++) { // 우
						if (officeTemp[currentY][p] == 6) {
							break;
						}
						if (officeTemp[currentY][p] == 0) {
							officeTemp[currentY][p] = 7;
						}
					}


				}
				else if (currentDirection == 2) {  // 상 우 하
					for (int p = currentY - 1; p >= 0; p--) { // 상
						if (officeTemp[p][currentX] == 6) {
							break;
						}
						if (officeTemp[p][currentX] == 0) {
							officeTemp[p][currentX] = 7;
						}
					}

					for (int p = currentX + 1; p <= M - 1; p++) { // 우
						if (officeTemp[currentY][p] == 6) {
							break;
						}
						if (officeTemp[currentY][p] == 0) {
							officeTemp[currentY][p] = 7;
						}
					}

					for (int p = currentY + 1; p <= N - 1; p++) { // 하
						if (officeTemp[p][currentX] == 6) {
							break;
						}
						if (officeTemp[p][currentX] == 0) {
							officeTemp[p][currentX] = 7;
						}
					}

				}
				else if (currentDirection == 3) {  // 우 하 좌
					for (int p = currentX + 1; p <= M - 1; p++) { // 우
						if (officeTemp[currentY][p] == 6) {
							break;
						}
						if (officeTemp[currentY][p] == 0) {
							officeTemp[currentY][p] = 7;
						}
					}

					for (int p = currentY + 1; p <= N - 1; p++) { // 하
						if (officeTemp[p][currentX] == 6) {
							break;
						}
						if (officeTemp[p][currentX] == 0) {
							officeTemp[p][currentX] = 7;
						}
					}

					for (int p = currentX - 1; p >= 0; p--) { // 좌
						if (officeTemp[currentY][p] == 6) {
							break;
						}
						if (officeTemp[currentY][p] == 0) {
							officeTemp[currentY][p] = 7;
						}
					}

				}
				else { // 4 하 좌 상
					for (int p = currentY + 1; p <= N - 1; p++) { // 하
						if (officeTemp[p][currentX] == 6) {
							break;
						}
						if (officeTemp[p][currentX] == 0) {
							officeTemp[p][currentX] = 7;
						}
					}

					for (int p = currentX - 1; p >= 0; p--) { // 좌
						if (officeTemp[currentY][p] == 6) {
							break;
						}
						if (officeTemp[currentY][p] == 0) {
							officeTemp[currentY][p] = 7;
						}
					}

					for (int p = currentY - 1; p >= 0; p--) { // 상
						if (officeTemp[p][currentX] == 6) {
							break;
						}
						if (officeTemp[p][currentX] == 0) {
							officeTemp[p][currentX] = 7;
						}
					}

				}

			}
			else { // 5, 방향 상관없이 항상 상하좌우
				for (int p = currentY - 1; p >= 0; p--) { // 상
					if (officeTemp[p][currentX] == 6) {
						break;
					}
					if (officeTemp[p][currentX] == 0) {
						officeTemp[p][currentX] = 7;
					}
				}

				for (int p = currentY + 1; p <= N - 1; p++) { // 하
					if (officeTemp[p][currentX] == 6) {
						break;
					}
					if (officeTemp[p][currentX] == 0) {
						officeTemp[p][currentX] = 7;
					}
				}

				for (int p = currentX - 1; p >= 0; p--) { // 좌
					if (officeTemp[currentY][p] == 6) {
						break;
					}
					if (officeTemp[currentY][p] == 0) {
						officeTemp[currentY][p] = 7;
					}
				}

				for (int p = currentX + 1; p <= M - 1; p++) { // 우
					if (officeTemp[currentY][p] == 6) {
						break;
					}
					if (officeTemp[currentY][p] == 0) {
						officeTemp[currentY][p] = 7;
					}
				}

			}

		}

		int cnt = 0;
		for (int t = 0; t < N; t++) {
			for (int u = 0; u < M; u++) {
				if (officeTemp[t][u] == 0)
					cnt++;
			}
		}

		if (cnt < Min) Min = cnt;

		return;
	}


	for (int i = 1; i <= 4; i++) {
		cctv[current].direction = i;
		func(current + 1);
	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> office[i][j];

			if (office[i][j] >= 1 && office[i][j] <= 5) {
				cctv.push_back({ i, j, 1 });
			}
		}
	}

	func(0);

	cout << Min;
}

//  백트랙킹 활용
//  상하좌우 체크하는 부분을 함수로 빼면 중복부분을 줄일 수 있을 듯