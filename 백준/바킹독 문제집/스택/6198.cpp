#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

stack<int> S;
vector<int> V;

long long Count = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int possibleBuilding = 0;

	for (int i = 0; i < N; i++) {

		int a;
		cin >> a;

		if (i == 0)
			S.push(a);
		else {
			while (true) {
				if (a < S.top()) {
					possibleBuilding++;
					Count += possibleBuilding;
					S.push(a);
					break;
				}
				else {
					S.pop();

					if (possibleBuilding > 0)
						possibleBuilding--;

					if (S.empty()) {
						S.push(a);
						break;
					}
				}
			}
		}
	}

	cout << Count;

	return 0;
}


// 왼쪽 빌딩부터 스택에 push
// 매 빌딩이 들어올때 들어온 빌딩을 볼 수 있는 왼쪽의 빌딩들의 개수를 세고 전체 개수에 더해주는 흐름
// 들어올 빌딩보다 스택의 top이 커질때까지 pop 반복