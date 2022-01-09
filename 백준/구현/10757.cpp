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

	// 입력한 두 문자열 길이
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


	// 일의 자리수부터 넣기,  index 0 = 1의 자리 수
	for (int i = 0; i <= firstStrlen - 1; i++) {
		int num = firstStr[firstStrlen - 1 - i] - 48;  // '0' = 48
		firstV.push_back(num);
	}

	for (int i = 0; i <= secondStrlen - 1; i++) {
		int num = secondStr[secondStrlen - 1 - i] - 48;
		secondV.push_back(num);
	}

	// 길이 작은 vector 빈 공간 0으로 채우기
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


	vector<int> result;  // 결과 담을 정수형 벡터
	result.push_back(0);  // 

	for (int i = 0; i < len; i++) {
		int fir = firstV[i];
		int sec = secondV[i];
		int res = result[i];

		int sum = fir + sec + res;

		if (sum > 9) { // 자리 올림 발생 -> 다음 자리 1추가
			result[i] = sum % 10;
			result.push_back(1);
		}
		else {
			result[i] = sum;
			result.push_back(0);  // 자리 올림 발생x -> 다음 자리 0 추가
		}
	}

	int resultLen = result.size();
	for (int i = 0; i <= resultLen - 1; i++) {  // 역순 출력 <-  index 0 = 1의 자리 수

		if (i == 0) {
			if (result[resultLen - 1] == 1)
				printf("1");
		}
		else
			printf("%d", result[resultLen - 1 - i]);
	}


	return 0;
}

// BOJ 10757 - 큰 수 A+B
// 수학
// 구현
// 사칙연산
// 임의 정밀도 / 큰 수 연산


// c++ string 클래스를 사용
// string 클래스는 기존c의 printf가 아닌 cout으로 출력 가능