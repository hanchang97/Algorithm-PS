#include <stdio.h>
#include <vector>
#include <queue>


using namespace std;



int main() {

	int table[100] = { 0, };

	table[0] = 0;
	table[1] = 1;

	int n;
	scanf("%d", &n);

	if (n == 1) {
		printf("1");
		return 0;
	}
	else {
		for(int i = 2; i<=n; i++){
			table[i] = table[i - 1] + table[i - 2];
		}
	}

	printf("%d\n", table[n]);
	

	return 0;
}