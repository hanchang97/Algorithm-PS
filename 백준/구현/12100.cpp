#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N; // 보드 크기

int Board[21][21]; // 보드 배열

int MaxBlock = 0; // 최대 블럭값



void printArr(int board[21][21]) {  // 중간과정에서 검사를 위한 배열 프린트 함수
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}


void slideBoard(int board[21][21], int dir) {
	if (dir == 0) { // 위로 슬라이드

		//printf("dir0\n");

		for (int i = 0; i < N; i++) {  // i는 열을 나타낸다

			// 1. 밀기	
			vector <int> push;

			for (int j = 0; j < N; j++) {  // 위쪽 행부터 생각
				if (board[j][i] != 0) {
					push.push_back(board[j][i]);
				}
			}

			//printf("dir0 push size %d\n", push.size());

			// 2. 점수 계산
			if (push.size() > 0) {
				for (int k = 0; k < push.size() - 1; k++) {
					if (push[k] == push[k + 1]) {
						push[k] *= 2;
						push[k + 1] = 0;
						k++;
					}
				}
			}

			//3. 다시 밀기
			vector <int> pushEnd;
			for (int k = 0; k < push.size(); k++) {
				if (push[k] != 0)
					pushEnd.push_back(push[k]);
			}

			//4. 배열 갱신

			for (int k = 0; k < N; k++) {
				if (k < pushEnd.size()) {
					board[k][i] = pushEnd[k];
				}
				else {
					board[k][i] = 0;
				}
			}

		}
		//printArr(board);

	}
	else if (dir == 1) { // 아래로 슬라이드

		//printf("dir1\n");

		for (int i = 0; i < N; i++) {  // i는 열을 나타낸다

			// 1. 밀기	
			vector <int> push;

			for (int j = N - 1; j >= 0; j--) {  // 위쪽 행부터 생각
				if (board[j][i] != 0) {
					push.push_back(board[j][i]);
				}
			}

			// 2. 점수 계산
			if (push.size() > 0) {
				for (int k = 0; k < push.size() - 1; k++) {
					if (push[k] == push[k + 1]) {
						push[k] *= 2;
						push[k + 1] = 0;
						k++;
					}
				}
			}

			//3. 다시 밀기
			vector <int> pushEnd;
			for (int k = 0; k < push.size(); k++) {
				if (push[k] != 0)
					pushEnd.push_back(push[k]);
			}

			//4. 배열 갱신

			for (int k = 0; k < N; k++) {
				if (k < pushEnd.size()) {
					board[N - k - 1][i] = pushEnd[k];
				}
				else {
					board[N - k - 1][i] = 0;
				}
			}

		}
		//printArr(board);

	}
	else if (dir == 2) { // 왼쪽으로 슬라이드

		//printf("dir2\n");

		for (int i = 0; i < N; i++) {  // i는 행을 나타낸다

			// 1. 밀기	
			vector <int> push;

			for (int j = 0; j < N; j++) {  // 위쪽 행부터 생각
				if (board[i][j] != 0) {
					push.push_back(board[i][j]);
				}
			}

			// 2. 점수 계산
			if (push.size() > 0) {
				for (int k = 0; k < push.size() - 1; k++) {
					if (push[k] == push[k + 1]) {
						push[k] *= 2;
						push[k + 1] = 0;
						k++;
					}
				}
			}

			//3. 다시 밀기
			vector <int> pushEnd;
			for (int k = 0; k < push.size(); k++) {
				if (push[k] != 0)
					pushEnd.push_back(push[k]);
			}

			//4. 배열 갱신

			for (int k = 0; k < N; k++) {
				if (k < pushEnd.size()) {
					board[i][k] = pushEnd[k];
				}
				else {
					board[i][k] = 0;
				}
			}

		}
		//printArr(board);

	}
	else { // 오른쪽으로 슬라이드

		//printf("dir3\n");

		for (int i = 0; i < N; i++) {  // i는 행을 나타낸다

			// 1. 밀기	
			vector <int> push;

			for (int j = N - 1; j >= 0; j--) {  // 위쪽 행부터 생각
				if (board[i][j] != 0) {
					push.push_back(board[i][j]);
				}
			}

			// 2. 점수 계산
			if (push.size() > 0) {   //  !!!! push.size > 0 처리를 안해주면 오류가 발생함 -> 배열에 인덱스에 음수가 들어갈 수도 있어서 이 부분을 감지하는듯..?
				for (int k = 0; k < push.size() - 1; k++) {
					if (push[k] == push[k + 1]) {
						push[k] *= 2;
						push[k + 1] = 0;
						k++;
					}
				}
			}

			//3. 다시 밀기
			vector <int> pushEnd;
			for (int k = 0; k < push.size(); k++) {
				if (push[k] != 0)
					pushEnd.push_back(push[k]);
			}

			//4. 배열 갱신

			for (int k = 0; k < N; k++) {
				if (k < pushEnd.size()) {
					board[i][N - k - 1] = pushEnd[k];
				}
				else {
					board[i][N - k - 1] = 0;
				}
			}

		}
		//printArr(board);

	}
}



void getResult(int board[21][21], int count) {
	if (count > 5) { // 최대 5번 이동 / 최대 블럭값 찾기

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (MaxBlock < board[i][j]) {
					MaxBlock = board[i][j];
				}
			}
		}

		//printf("Max %d\n", MaxBlock);

	}
	else {

		// 현재 배열 기억하기
		int temp[21][21];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				temp[i][j] = board[i][j];
			}
		}
		////

		for (int i = 0; i < 4; i++) {

			//printf("count : %d dir : %d\n", count, i);
			slideBoard(board, i);

			getResult(board, count + 1);

			// 보드 다시 이전 상태로 돌리기
			for (int k = 0; k < N; k++) {
				for (int l = 0; l < N; l++) {
					board[k][l] = temp[k][l];
				}
			}
			//////////

		}
	}
}

int main() {

	// 입력
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &Board[i][j]);
		}
	}
	//////////

	// 초기 최대 블럭값
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (MaxBlock < Board[i][j]) {
				MaxBlock = Board[i][j];
			}
		}
	}
	//////////


	getResult(Board, 1);


	printf("%d\n", MaxBlock);


	return 0;
}

// 백준 - 12100 
// 1. 상하좌우 슬라이드 4방향 으로 모든 경우의 수 고려 -> 백트랙킹
// 2. 빈 공간은 0으로 간주
// 3. 한 행 혹은 열의 점수 계산시 사이에 0이 없게 채우고 계산
// 4. 계산하고 다시 중간에 0이 생길 수 있으므로 마지막에 한 번더 밀어주기