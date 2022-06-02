#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
	string answer = "";

	// 구하려는 수의 자릿수
	int digitCount = number.length() - k;
	// cout<< digitCount << "\n";

	int findInx = -1;
	for (int i = digitCount; i >= 1; i--) {

		char max = '0';
		int inx = -1;

		for (int j = number.length() - i; j > findInx; j--) {

			char current = number[j];
			if (current >= max) {
				max = current;
				inx = j;
			}

		}

		findInx = inx; //현재 자릿수로 뽑힌 수의 위치, 다음 자릿수는 이 위치 전 까지 탐색 가능
		answer += max;

		// cout << "findInx : " << findInx << "\n";
	}


	return answer;
}


// 뒤에서 부터 만드려는 수의 각 자릿수 별로 최대값을 찾는 방식