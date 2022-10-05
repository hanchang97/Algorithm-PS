#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool compare(string a, string b)
{
	if (a.length() == b.length())
		return a < b;
	return a.length() < b.length();
}

int main()
{
	int N;
	cin >> N;

	vector<string> v;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		string temp = "";
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] >= '0' && str[j] <= '9')
			{ // 숫자인 경우
				if (str[j] == '0')
				{ // 0 인경우
					if (j - 1 >= 0)
					{ // 인덱스 검사
						if (str[j - 1] >= '0' && str[j - 1] <= '9' && temp != "")
						{ // 현재 유효한 숫자뒤에 나온 0 이라면 포함시켜야 함
							temp += "0";
							continue; // 현재 0에 대한 작업 끝났음
						}
					}
					if (j + 1 < str.length())
					{
						if (str[j + 1] >= '0' && str[j + 1] <= '9')
							continue; // 0 뒤가 숫자라면 현재 0은 무시됨
						else
							temp += "0"; // 0 뒤에 숫자가 없음 -> 0 단독으로 추가
					}
					else
					{
						temp += "0"; // 맨 마지막 위치에 0 단독으로 존재하는 경우
					}
				}
				else
				{ // 1~9 는 temp에 바로 이어주기
					temp += str[j];
				}
			}
			else
			{ // 숫자가 아닌 경우
				if (temp.length() >= 1)
				{
					v.push_back(temp); // 지금까지 만든 숫자 있으면 vector에 넣어주고 숫자 문자열 초기화하기
				}
				temp = "";
			}
		}

		if (temp.length() >= 1)
		{ // 마지막문자가 숫자였다면 여기서 한 번 검사해줘야 한다
			v.push_back(temp);
		}
	}

	// v 오름차순 정렬하기
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";

	return 0;
}