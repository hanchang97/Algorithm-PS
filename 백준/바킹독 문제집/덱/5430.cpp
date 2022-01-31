#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <sstream>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		string command; // 명령어 입력
		cin >> command;

		int count; // 배열에 들어가 있는 정수 개수
		cin >> count;

		string countStr; // 배열에 들어가 있는 정수 문자열
		cin >> countStr;

		deque<string> dq;  // 문자열 분할 후 담을 덱

		countStr.erase(countStr.length() - 1, 1);
		countStr.erase(0, 1);

		stringstream ss(countStr);
		string token;

		while (getline(ss, token, ',')) {
			dq.push_back(token);
			//cout << "token : " << token << "\n";
		}


		bool frontIsLeft = true;
		bool isError = false;

		for (int i = 0; i < command.length(); i++) {
			if (command[i] == 'R') {
				frontIsLeft = !frontIsLeft;  // R 명령을 O(1) 로 처리
			}
			else {
				if (dq.size() == 0) {
					isError = true;
					break;
				}
				else {
					if (frontIsLeft)
						dq.pop_front();
					else
						dq.pop_back();
				}
			}
		}

		if (isError)
			cout << "error\n";
		else {
			cout << "[";
			if (frontIsLeft) {
				for (int t = 0; t < dq.size(); t++) {
					if (t == 0)
						cout << dq[t];
					else
						cout << "," << dq[t];
				}
			}
			else {
				for (int t = dq.size() - 1; t >= 0; t--) {
					if (t == dq.size() - 1)
						cout << dq[t];
					else
						cout << "," << dq[t];
				}
			}
			cout << "]\n";
		}

	}

	return 0;
}



// 기존에  R 명령의 구현에서 임시 덱을 두고 현재 덱의 상태에서 반복문을 통해 하나씩 원소를 역순으로 가져오는 방식으로 실제로 덱을 뒤집
// but 이 경우 명령어 길이가 10000, 배열 내부 정수 개수가 10000 만 되어도 반복문 연산이 1억번이 되어 시간초과 발생

// 따라서 flag 변수를 두어 시작 부분이 오른쪽인지, 왼쪽인지만 판단 후 변수에 저장을 함으로써 위의 반복문을 생략

// 덱을 물리적으로 뒤집는게 아닌 논리적으로 뒤집는 발상을 하는 것이 중요했다