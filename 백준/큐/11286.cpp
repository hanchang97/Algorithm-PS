#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int main() {

	priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {

		int a;
		scanf("%d", &a);

		if (a == 0) {
			if (pq.empty()) {
				printf("0\n");
			}
			else {
				printf("%d\n", pq.top().second);
				pq.pop();
			}
		}
		else {
			pair<int, int> pa;
			pa.first = abs(a);
			pa.second = a;

			pq.push(pa);
		}

	}

	


	return 0;
}
