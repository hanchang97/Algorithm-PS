#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> graph[105];
bool isVisted[105] = { 0, };

int Count = 0;

void dfs(int start) {
	isVisted[start] = true;

	for (int i = 0; i < graph[start].size(); i++) {
		int nextNode = graph[start][i];

		if (isVisted[nextNode] == false) {
			Count++;
			dfs(nextNode);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int numComputer;
	int numPair;

	cin >> numComputer >> numPair;

	for (int i = 0; i < numPair; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1);

	cout << Count;

	return 0;
}

// dfs
// 1�� ��ǻ�ͺ��� �׻� �����̰� 1�� ���� ���� ī������ �Ѵ�