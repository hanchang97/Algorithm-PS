#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;


int Line[100005] = { 0, };
bool Visit[100005] = { 0, };

int Start, Find;

void bfs() {
	queue<int> Q;
	Q.push(Start);
	Visit[Start] = true;

	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();

		for (int i = 0; i < 3; i++) {
			int next;
			if (i == 0)
				next = cur - 1;
			else if (i == 1)
				next = cur + 1;
			else
				next = cur * 2;

			if (next < 0 || next > 100000) continue;
			if (Visit[next]) continue;

			Line[next] = Line[cur] + 1;
			Visit[next] = true;
			Q.push(next);

			if (next == Find) {
				cout << Line[next];
				return;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> Start >> Find;

	if (Start == Find) {
		cout << "0";
		return 0;
	}

	bfs();

	return 0;
}

// bfs
// 1차원 배열로 가능
// 출발, 목적지 같은 경우 체크!!
