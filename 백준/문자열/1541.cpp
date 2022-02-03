#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ANS = 0;

int getTen(int n) {
	int result = 1;

	while (n--) {
		result *= 10;
	}

	return result;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string expression;
	cin >> expression;

	bool isMinusAppear = false;
	bool previousSignIsPlus = true;

	vector<int> numTempV;

	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] == '-' || expression[i] == '+' || i == expression.length() - 1) {

			if (i == expression.length() - 1)
				numTempV.push_back(expression[i] - 48);

			int curNum = 0;
			for (int j = 0; j < numTempV.size(); j++) {
				curNum += numTempV[j] * getTen(numTempV.size() - 1 - j);
			}

			numTempV.clear();

			if (previousSignIsPlus) {
				if (isMinusAppear)
					ANS -= curNum;
				else
					ANS += curNum;
			}
			else {
				ANS -= curNum;
			}

			if (expression[i] == '-') {
				isMinusAppear = true;
				previousSignIsPlus = false;
			}
			else {
				previousSignIsPlus = true;
			}
		}
		else {
			numTempV.push_back(expression[i] - 48);
		}
	}

	cout << ANS;

	return 0;
}


// 마이너스가 한 번이라도 나오면 그 이후에 나오는 +연산을 모두 -연산으로 바꾼다!!!
// 부호 만나면 부호 왼쪽 수의 계산을 진행