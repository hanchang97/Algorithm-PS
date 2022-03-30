#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0;
	int TotalLen = s.length();

	int minLen = TotalLen;
	int cutlen = 1;
	while (cutlen <= TotalLen / 2) {

		string current = "";
		string check = "";

		string zipStr = "";

		int lastIndex = 0;
		int combo = 1;
		for (int i = 0; i <= TotalLen - 1; i += cutlen) {
			if (i == 0) {
				current = s.substr(i, cutlen);
			}
			else {
				check = s.substr(i, cutlen);

				if (current == check) {
					combo++;
				}
				else {
					if (combo > 1) {
						zipStr += to_string(combo);
					}
					zipStr += current;
					combo = 1;
				}
				current = check;
			}

			lastIndex = i;
		}

		if (combo > 1) zipStr += to_string(combo);
		zipStr += current;

		if (zipStr.length() < minLen) minLen = zipStr.length();

		cutlen++;
		//cout << "zip : " << zipStr << "\n";
	}

	answer = minLen;
	return answer;
}

// 압축 시 10개 이상이 압축되는 경우를 생각했어야 한다!!