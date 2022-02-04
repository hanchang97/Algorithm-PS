#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int t, n;
string k;
string number[10000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++) {
		int num = 0;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> number[j];
		}
		sort(number, number + n);


		for (int k = 0; k < n; k++) {
			if (number[k + 1].find(number[k]) == 0) {
				cout << "NO" << endl;
				break;
			}
			else {
				num++;
			}
		}

		if (num == n) {
			cout << "YES" << endl;
		}
	}


	return 0;
}


// 문자열을 기본조건으로 sort 함수 사용해서 정렬
// ex>  972 9723 98 981 이런 순서로 정렬된다!!
// 이렇게 정렬된 경우 자연스럽게 접두어 겹치는 그룹에서 길이가 긴 것이 뒤에 위치하게 된다!!
// num이 n만큼의 값을 가지면 n번동안 접두어 겹치는게 하나도 없는 것이므로 YES 출력