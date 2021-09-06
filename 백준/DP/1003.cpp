#include <stdio.h>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

// ������ ��� ���¿��� Ƚ���� ���� �ð��ʰ�
// dp �� Ǯ�� ����


int main()
{
	pair<int, int> arr[100];  // first�� 0 ��� Ƚ�� , second�� 1 ��� Ƚ��

	arr[0] = { 1, 0 };
	arr[1] = { 0,1 };

	for (int i = 2; i <= 40; i++) {
		arr[i] = { (arr[i - 2].first + arr[i - 1].first), (arr[i - 2].second + arr[i - 1].second) };
	}

	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int n;
		scanf("%d", &n);

		printf("%d %d\n", arr[n].first, arr[n].second);
	}

	return 0;
}
