#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

stack<int> S;
vector<int> V;
vector<int> result;  // 역순으로 담기

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		V.push_back(a);
	}

	// 맨 마지막 원소의 경우는 무조건 -1
	result.push_back(-1);
	S.push(V[N - 1]);

	for (int i = N - 2; i >= 0; i--) {
		int current = V[i];

		while (true) {
			if (current >= S.top()) {
				S.pop();

				if (S.empty()) {
					S.push(current);
					result.push_back(-1);
					break;
				}
			}
			else {
				result.push_back(S.top());
				S.push(current);
				break;
			}
		}

	}

	for (int i = N - 1; i >= 0; i--)
		cout << result[i] << " ";

	return 0;
}

// 스택사용
// 현재 수보다 오른쪽에 있는 것들 중 같거나 작은 것은 필요 없으므로 스택에 들어있다면 제거한다!!