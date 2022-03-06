#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

bool cmp1(const pair<string, int>& a, const pair<string, int>& b) {
	return a.second > b.second;
}

bool cmp2(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	map<string, int> m;

	for (int i = 0; i < genres.size(); i++) {
		m[genres[i]] += plays[i];
	}

	int GenreCount = m.size();

	vector<pair<string, int>> v1;
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		v1.push_back({ iter->first, iter->second });
	}

	sort(v1.begin(), v1.end(), cmp1);

	for (int j = 0; j < v1.size(); j++) {
		m[v1[j].first] = j;
	}

	///////////

	vector<pair<int, int>> arr[100];
	for (int i = 0; i < genres.size(); i++) {
		int inx = m[genres[i]];
		arr[inx].push_back({ plays[i], i });
	}


	for (int i = 0; i < GenreCount; i++) {
		sort(arr[i].begin(), arr[i].end(), cmp2);
	}

	for (int i = 0; i < GenreCount; i++) {
		if (arr[i].size() < 2) {
			answer.push_back(arr[i][0].second);
		}
		else {
			answer.push_back(arr[i][0].second);
			answer.push_back(arr[i][1].second);
		}
	}

	return answer;
}