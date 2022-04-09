#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

bool compare1(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

bool compare2(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	map<string, int> map_genre;

	for (int i = 0; i < genres.size(); i++) {
		map_genre[genres[i]] += plays[i];
	}

	int genreCount = map_genre.size();


	vector<pair<string, int>> v1;
	for (auto iter = map_genre.begin(); iter != map_genre.end(); iter++) {
		v1.push_back({ iter->first, iter->second });
	}
	sort(v1.begin(), v1.end(), compare1);  // 총 재생수에 따라 장르 정렬 (내림차순)


	for (int i = 0; i < v1.size(); i++) {
		map_genre[v1[i].first] = i;  // 장르별 순서 값 할당
	}

	vector<vector<pair<int, int>>> v2; // <genres inx, plays value>
	for (int i = 0; i < genreCount; i++) {
		vector<pair<int, int>> vv;
		v2.push_back(vv);
	}

	for (int i = 0; i < genres.size(); i++) {
		int inx = map_genre[genres[i]];  // 장르 순서 구하기
		v2[inx].push_back({ i, plays[i] });
	}

	for (int i = 0; i < v2.size(); i++) {
		sort(v2[i].begin(), v2[i].end(), compare2);  // 각 장르에 속한 노래 재생 수 내림차순 정렬
	}


	for (int i = 0; i < v2.size(); i++) {
		answer.push_back(v2[i][0].first);
		if (v2[i].size() >= 2)
			answer.push_back(v2[i][1].first);
	}

	return answer;
}