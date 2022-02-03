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


// ���̳ʽ��� �� ���̶� ������ �� ���Ŀ� ������ +������ ��� -�������� �ٲ۴�!!!
// ��ȣ ������ ��ȣ ���� ���� ����� ����