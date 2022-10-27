#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> node[3005];
int visited[3005] = {0};
unordered_map<int, int> cycle;

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

int bfs(int startNode)
{
	int visited2[3005] = {0};
	int dist = 0;

	visited2[startNode] = 1;
	queue<pair<int, int>> q; // first = node, second = dist
	q.push(make_pair(startNode, 0));

	while (!q.empty())
	{
		int cNode = q.front().first;
		int cd = q.front().second;
		q.pop();

		for (int i = 0; i < node[cNode].size(); i++)
		{
			int nNode = node[cNode][i];
			int nd = cd + 1;

			if (visited2[nNode])
				continue;

			visited2[nNode] = 1;
			q.push(make_pair(nNode, nd));

			if (cycle[nNode] != 0)
			{
				dist = nd;
				break;
			}
		}

		if (dist > 0)
			break;
	}

	return dist;
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

	// for(auto iter = cycle.begin(); iter != cycle.end(); iter++) {
	//     cout << iter->first << " ";
	// }

	vector<int> vDist;

	// 각 정점과 사이클 사이 최단거리 찾기 - bfs
	for (int i = 1; i <= N; i++)
	{
		if (cycle[i] == 0)
		{
			int dist = bfs(i);
			vDist.push_back(dist);
		}
		else
		{
			vDist.push_back(0);
		}
	}

	for (int i = 0; i < vDist.size(); i++)
	{
		cout << vDist[i] << " ";
	}

	return 0;
}
