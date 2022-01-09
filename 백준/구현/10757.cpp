#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> firstV;
vector<int> secondV;

string firstStr;
string secondStr;

int main() {

	cin >> firstStr;
	cin >> secondStr;

	/*cout << firstStr << "\n";
	cout << secondStr;*/

	// �Է��� �� ���ڿ� ����
	int firstStrlen = firstStr.length();
	int secondStrlen = secondStr.length();
	int len = 0;

	bool isFirstMoreLong;
	int lenGap = 0;

	if (firstStrlen >= secondStrlen) {
		isFirstMoreLong = true;
		len = firstStrlen;
		lenGap = firstStrlen - secondStrlen;
	}
	else {
		isFirstMoreLong = false;
		len = secondStrlen;
		lenGap = secondStrlen - firstStrlen;
	}


	// ���� �ڸ������� �ֱ�,  index 0 = 1�� �ڸ� ��
	for (int i = 0; i <= firstStrlen - 1; i++) {
		int num = firstStr[firstStrlen - 1 - i] - 48;  // '0' = 48
		firstV.push_back(num);
	}

	for (int i = 0; i <= secondStrlen - 1; i++) {
		int num = secondStr[secondStrlen - 1 - i] - 48;
		secondV.push_back(num);
	}

	// ���� ���� vector �� ���� 0���� ä���
	if (isFirstMoreLong) {
		for (int count = 1; count <= lenGap; count++) {
			secondV.push_back(0);
		}
	}
	else {
		for (int count = 1; count <= lenGap; count++) {
			firstV.push_back(0);
		}
	}


	vector<int> result;  // ��� ���� ������ ����
	result.push_back(0);  // 

	for (int i = 0; i < len; i++) {
		int fir = firstV[i];
		int sec = secondV[i];
		int res = result[i];

		int sum = fir + sec + res;

		if (sum > 9) { // �ڸ� �ø� �߻� -> ���� �ڸ� 1�߰�
			result[i] = sum % 10;
			result.push_back(1);
		}
		else {
			result[i] = sum;
			result.push_back(0);  // �ڸ� �ø� �߻�x -> ���� �ڸ� 0 �߰�
		}
	}

	int resultLen = result.size();
	for (int i = 0; i <= resultLen - 1; i++) {  // ���� ��� <-  index 0 = 1�� �ڸ� ��

		if (i == 0) {
			if (result[resultLen - 1] == 1)
				printf("1");
		}
		else
			printf("%d", result[resultLen - 1 - i]);
	}


	return 0;
}

// BOJ 10757 - ū �� A+B
// ����
// ����
// ��Ģ����
// ���� ���е� / ū �� ����


// c++ string Ŭ������ ���
// string Ŭ������ ����c�� printf�� �ƴ� cout���� ��� ����