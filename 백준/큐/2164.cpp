#include <stdio.h>
#include <queue>


using namespace std;

int main() {

	int n;
	scanf("%d", &n);

	queue <int> q;

	for (int i = 1; i <= n; i++)
		q.push(i);


	while (q.size() > 1) {

		q.pop();
		int front = q.front();
		q.pop();
		q.push(front);
	}

	printf("%d\n", q.front());


	return 0;
}