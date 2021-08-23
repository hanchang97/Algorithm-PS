#include <stdio.h>   
#include <deque>
#include <vector>

using namespace std;

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	int arr[5010] = { 0, };

	deque<int> dq;

	for (int i = 1; i <= n; i++)
		dq.push_back(i);


	vector <int> result;

	int order = k;
	while (1) {

		result.push_back(dq[order - 1]);   //order��° �̱�

		dq.erase(dq.begin() + order - 1, dq.begin() + order);  // order��° ������ ����

		if (dq.empty() == true)
			break;

		order = order - 1 + k;  // ������Ʈ �� �� ���� ���� ����

		while (order > dq.size())   // �� ũ�� ���� ���� �� ū ��� ó��
			order = order - dq.size();
	}


	printf("<");
	for (int i = 0; i < result.size(); i++) {
		if (i == 0)
			printf("%d", result[i]);
		else
			printf(", %d", result[i]);
	}
	printf(">");

	return 0;
}