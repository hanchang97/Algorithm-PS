#include <stdio.h>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

// 문제에 재귀 형태에서 횟수를 세면 시간초과
// dp 로 풀이 가능


int main()
{
	pair<int, int> arr[100];  // first는 0 출력 횟수 , second는 1 출력 횟수

	arr[0] = { 1, 0 };
	arr[1] = { 0,1 };

	for (int i = 2; i <= 40; i++) {
		arr[i] = { (arr[i - 2].first + arr[i - 1].first), (arr[i - 2].second + arr[i - 1].second) };
	}

	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int n;
		scanf("%d", &n);

		printf("%d %d\n", arr[n].first, arr[n].second);
	}

	return 0;
}
