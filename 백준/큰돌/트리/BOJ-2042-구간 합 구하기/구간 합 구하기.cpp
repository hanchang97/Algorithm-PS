#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M, K;
long long int segmentTree[4000005] = {0};
long long int arr[1000005];

long long int init(int start, int end, int node)
{
	if (start == end)
	{
		return segmentTree[node] = arr[start];
	}

	int mid = (start + end) / 2;
	return segmentTree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long int getSum(int start, int end, int node, int left, int right)
{
	if (start > right || end < left)
		return 0;
	if (start >= left && end <= right)
		return segmentTree[node];

	int mid = (start + end) / 2;
	return getSum(start, mid, node * 2, left, right) + getSum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, long long int value)
{
	if (start > index || end < index)
		return;

	segmentTree[node] += value;
	if (start == end)
		return;

	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, value);
	update(mid + 1, end, node * 2 + 1, index, value);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
	{
		long long int a;
		cin >> a;
		arr[i] = a;
	}

	init(0, N - 1, 1);

	for (int i = 0; i < (M + K); i++)
	{
		long long int a, b, c;
		cin >> a >> b >> c;
		b--;
		if (a == 1)
		{ // 업데이트
			long long int gap = c - arr[b];
			update(0, N - 1, 1, b, gap);
			arr[b] = c; // 입력 배열의 상태도 맞춰서 업데이트 해줘야 한다..!!!
		}
		else
		{ // 구간합 출력
			c--;
			cout << getSum(0, N - 1, 1, b, c) << "\n";
		}
	}

	return 0;
}
