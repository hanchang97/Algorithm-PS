#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

struct Data {
	int start;
	int end;
};

bool compare(Data first, Data second) {
	if (first.end < second.end) return true;
	else if (first.end > second.end) return false;
	else {
		if (first.start < second.start) return true;
		else return false;
	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	vector<Data> dataV;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;

		dataV.push_back(Data{ x,y });
	}

	sort(dataV.begin(), dataV.end(), compare);  // 끝나는 시간이 빠른 순 정렬, 같다면 시작 시간 빠른 순 정렬

	/*for (int i = 0; i < N; i++) {
		cout << dataV[i].start << " " << dataV[i].end << "\n";
	}*/

	int answer = 1;
	int currentTime = dataV[0].end;

	for (int i = 1; i < N; i++) {
		if (currentTime > dataV[i].start) continue;

		answer++;
		currentTime = dataV[i].end;
	}

	cout << answer;

	return 0;
}