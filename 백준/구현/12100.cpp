#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N; // ���� ũ��

int Board[21][21]; // ���� �迭

int MaxBlock = 0; // �ִ� ����



void printArr(int board[21][21]) {  // �߰��������� �˻縦 ���� �迭 ����Ʈ �Լ�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}


void slideBoard(int board[21][21], int dir) {
	if (dir == 0) { // ���� �����̵�

		//printf("dir0\n");

		for (int i = 0; i < N; i++) {  // i�� ���� ��Ÿ����

			// 1. �б�	
			vector <int> push;

			for (int j = 0; j < N; j++) {  // ���� ����� ����
				if (board[j][i] != 0) {
					push.push_back(board[j][i]);
				}
			}

			//printf("dir0 push size %d\n", push.size());

			// 2. ���� ���
			if (push.size() > 0) {
				for (int k = 0; k < push.size() - 1; k++) {
					if (push[k] == push[k + 1]) {
						push[k] *= 2;
						push[k + 1] = 0;
						k++;
					}
				}
			}

			//3. �ٽ� �б�
			vector <int> pushEnd;
			for (int k = 0; k < push.size(); k++) {
				if (push[k] != 0)
					pushEnd.push_back(push[k]);
			}

			//4. �迭 ����

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
	else if (dir == 1) { // �Ʒ��� �����̵�

		//printf("dir1\n");

		for (int i = 0; i < N; i++) {  // i�� ���� ��Ÿ����

			// 1. �б�	
			vector <int> push;

			for (int j = N - 1; j >= 0; j--) {  // ���� ����� ����
				if (board[j][i] != 0) {
					push.push_back(board[j][i]);
				}
			}

			// 2. ���� ���
			if (push.size() > 0) {
				for (int k = 0; k < push.size() - 1; k++) {
					if (push[k] == push[k + 1]) {
						push[k] *= 2;
						push[k + 1] = 0;
						k++;
					}
				}
			}

			//3. �ٽ� �б�
			vector <int> pushEnd;
			for (int k = 0; k < push.size(); k++) {
				if (push[k] != 0)
					pushEnd.push_back(push[k]);
			}

			//4. �迭 ����

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
	else if (dir == 2) { // �������� �����̵�

		//printf("dir2\n");

		for (int i = 0; i < N; i++) {  // i�� ���� ��Ÿ����

			// 1. �б�	
			vector <int> push;

			for (int j = 0; j < N; j++) {  // ���� ����� ����
				if (board[i][j] != 0) {
					push.push_back(board[i][j]);
				}
			}

			// 2. ���� ���
			if (push.size() > 0) {
				for (int k = 0; k < push.size() - 1; k++) {
					if (push[k] == push[k + 1]) {
						push[k] *= 2;
						push[k + 1] = 0;
						k++;
					}
				}
			}

			//3. �ٽ� �б�
			vector <int> pushEnd;
			for (int k = 0; k < push.size(); k++) {
				if (push[k] != 0)
					pushEnd.push_back(push[k]);
			}

			//4. �迭 ����

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
	else { // ���������� �����̵�

		//printf("dir3\n");

		for (int i = 0; i < N; i++) {  // i�� ���� ��Ÿ����

			// 1. �б�	
			vector <int> push;

			for (int j = N - 1; j >= 0; j--) {  // ���� ����� ����
				if (board[i][j] != 0) {
					push.push_back(board[i][j]);
				}
			}

			// 2. ���� ���
			if (push.size() > 0) {   //  !!!! push.size > 0 ó���� �����ָ� ������ �߻��� -> �迭�� �ε����� ������ �� ���� �־ �� �κ��� �����ϴµ�..?
				for (int k = 0; k < push.size() - 1; k++) {
					if (push[k] == push[k + 1]) {
						push[k] *= 2;
						push[k + 1] = 0;
						k++;
					}
				}
			}

			//3. �ٽ� �б�
			vector <int> pushEnd;
			for (int k = 0; k < push.size(); k++) {
				if (push[k] != 0)
					pushEnd.push_back(push[k]);
			}

			//4. �迭 ����

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
	if (count > 5) { // �ִ� 5�� �̵� / �ִ� ���� ã��

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

		// ���� �迭 ����ϱ�
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

			// ���� �ٽ� ���� ���·� ������
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

	// �Է�
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &Board[i][j]);
		}
	}
	//////////

	// �ʱ� �ִ� ����
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

// ���� - 12100 
// 1. �����¿� �����̵� 4���� ���� ��� ����� �� ��� -> ��Ʈ��ŷ
// 2. �� ������ 0���� ����
// 3. �� �� Ȥ�� ���� ���� ���� ���̿� 0�� ���� ä��� ���
// 4. ����ϰ� �ٽ� �߰��� 0�� ���� �� �����Ƿ� �������� �� ���� �о��ֱ�