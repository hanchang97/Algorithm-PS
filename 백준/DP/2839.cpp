#include <stdio.h>

using namespace std;


int main() {

	int table[5010];

	int N;
	scanf("%d", &N);

	table[3] = 1;
	table[4] = -1;
	table[5] = 1;
	table[6] = 2;
	table[7] = -1;

	if (N >= 8) {
		for (int i = 8; i <= N; i++) {

			int a = table[i - 3] + table[3];
			int b = table[i - 5] + table[5];

			if (table[i - 3] != -1 && table[i - 5] != -1) {
				if (a < b)
					table[i] = a;
				else
					table[i] = b;
			}
			else if (table[i - 3] == -1 && table[i - 5] != -1) {
				table[i] = table[i - 5] + table[5];
			}
			else if (table[i - 3] != -1 && table[i - 5] == -1) {
				table[i] = table[i - 3] + table[3];
			}
		}
	}

	printf("%d\n", table[N]);


	// N = 특정 수에 3 또는 5를 더해서 완성이 된다

	return 0;
}
