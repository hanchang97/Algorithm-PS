#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int N, M;

vector<int> graph[110];
bool visited[110] = { 0, };

int Count = 0;

void dfs(int current) {
	Count++;
	visited[current] = true;

	for (int i = 0; i < graph[current].size(); i++) {
		int next = graph[current][i];

		if (visited[next] == false) {
			dfs(next);
		}
	}
}

int main() {
	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1);

	printf("%d\n", Count - 1);

	return 0;
}