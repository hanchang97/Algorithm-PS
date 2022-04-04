#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;

	map<string, int> mapClothes;

	for (int i = 0; i < clothes.size(); i++) {
		mapClothes[clothes[i][1]]++;
	}

	for (auto iter = mapClothes.begin(); iter != mapClothes.end(); iter++) {
		answer *= (iter->second) + 1;
	}

	return answer - 1;  // � �ʵ� �������� �ʴ� ����� �� 1������ ����!
}