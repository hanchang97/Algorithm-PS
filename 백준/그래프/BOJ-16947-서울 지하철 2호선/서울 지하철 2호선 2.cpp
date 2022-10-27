#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> node[3005];
int visited[3005] = {0};
unordered_map<int, int> cycle;
unordered_map<int, int> mDist;

vector<int> vDist;

int findNode;

int N;

void dfs(int curNode, int parentNode)
{
	if (visited[curNode] == 1)
	{
		findNode = curNode;
		cycle[curNode] = 1;
		return;
	}

	visited[curNode] = 1;

	for (int i = 0; i < node[curNode].size(); i++)
	{
		int nextNode = node[curNode][i];

		if (nextNode == parentNode)
			continue;
		dfs(nextNode, curNode);

		if (curNode == findNode)
		{
			findNode = -1;
			return;
		}

		if (findNode < 0)
		{
			return;
		}

		if (findNode > 0)
		{
			cycle[curNode] = 1;
			return;
		}
	}
}

void bfs(int startNode)
{
	int visited2[3005] = {0};

	visited2[startNode] = 1;
	queue<pair<int, int>> q; // first = node, second = dist
	q.push(make_pair(startNode, 0));

	mDist[startNode] = 0;

	while (!q.empty())
	{
		int cNode = q.front().first;
		int cd = q.front().second;
		q.pop();

		for (int i = 0; i < node[cNode].size(); i++)
		{
			int nNode = node[cNode][i];

			if (visited2[nNode])
				continue;

			visited2[nNode] = 1;
			int nd = cd + 1;
			if (cycle[nNode] != 0)
				nd = 0;
			q.push(make_pair(nNode, nd));
			mDist[nNode] = nd;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}

	// 사이클 먼저 찾기 - dfs
	findNode = 0;
	dfs(1, 1);

	// 각 정점과 사이클 사이 최단거리 찾기 - bfs
	bfs(cycle.begin()->first);

	for (int i = 1; i <= N; i++)
	{
		cout << mDist[i] << " ";
	}

	return 0;
}
