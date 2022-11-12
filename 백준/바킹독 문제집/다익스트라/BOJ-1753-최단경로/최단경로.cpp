#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

#define INF 100000000

#define Dist first
#define Node second

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E;
	cin >> V >> E;

	int S;
	cin >> S;

	vector<pair<int, int>> node[20005];
	// 그래프 정보 = index에 해당하는 정점으로부터 (거리, 정점번호) 저장
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap
	// (시작점으로부터 거리, 정점 번호) 정보가 포함된다

	int minDistArr[200005]; // 시작점으로부터 최단거리 정보 테이블

	for (int i = 1; i <= V; i++)
	{
		minDistArr[i] = INF; // 초기에 최단거리 테이블 모두 INF 로 초기화
	}

	while (E--)
	{
		int u, v, w;
		cin >> u >> v >> w;

		node[u].push_back(make_pair(w, v));
	}

	minDistArr[S] = 0; // 시작 지점까지 거리는 0으로 초기화
	pq.push(make_pair(0, S));

	while (!pq.empty())
	{
		auto cur = pq.top();
		pq.pop();

		if (minDistArr[cur.Node] != cur.Dist)
			continue; // 시작점에서 cur.Node 로의 다른 최단 거리가 존재하므로 넘어간다
		for (auto next : node[cur.Node])
		{ // cur.Node 에 연결된 정점 살피기
			if (minDistArr[cur.Node] + next.Dist >= minDistArr[next.Node])
				continue;
			// 거쳐서 가는것보다 기존 최단거리가 더 짧으면 넘어간다

			minDistArr[next.Node] = minDistArr[cur.Node] + next.Dist; // 최단거리 갱신
			pq.push(make_pair(minDistArr[next.Node], next.Node));	  // 우선순위 큐에 추가
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (minDistArr[i] == INF)
			cout << "INF\n";
		else
			cout << minDistArr[i] << "\n";
	}

	return 0;
}
