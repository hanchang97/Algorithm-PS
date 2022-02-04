#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool compare(string s1, string s2) {
	return s1.length() < s2.length();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<string> V;
	set<string> S;

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		for (int i = 0; i < N; i++) {
			string str;
			cin >> str;
			V.push_back(str);
		}

		sort(V.begin(), V.end(), compare);


		bool isAnswer = true;

		for (int i = 0; i < V.size(); i++) {
			string a = V[i];

			if (S.find(a) == S.end()) {
				string temp = a;
				while (temp.length() > 0) {
					if (S.find(temp) != S.end()) {
						isAnswer = false;
						break;
					}
					temp.pop_back();
				}

				if (temp.length() == 0)
					S.insert(a);

			}
			else {
				isAnswer = false;
				break;
			}
		}

		if (isAnswer)
			cout << "YES\n";
		else
			cout << "NO\n";


		V.clear();
		S.clear();
	}


	return 0;
}


// 전화번호부가 0으로 시작하는 경우도 있으므로 숫자가 아닌 문자열로 입력을 받도록 한다
// 현재 문자열에서 맨 뒤를 하나씩 제거해가면서 set에 있는지 판단하고 모두 없다면 해당 문자열을 set에 넣기
// 문자열 길이가 짧은 것이 앞에 오도록 정렬을 해야함
// 반례를 대비하기 위함
// ex> 1 2 999999 9  로 입력하면 정렬 안할 시에는 YES로 나온다
// -> 문자열 길수록 뒤에 있어야 문자 하나씩 제거하면서 접두어 판단할 때 자기보다 짧은 문자열과의 중복을 정상적으로 처리 가능