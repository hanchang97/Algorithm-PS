#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(string s)
{
	int answer = 0;

	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		if (i != 0)
		{
			char ch = s[0];
			s.erase(0, 1);
			s += ch;
		}
		stack<char> st;
		for (int j = 0; j < len; j++)
		{
			if (s[j] == ')')
			{
				if (!st.empty() && st.top() == '(')
				{
					st.pop();
				}
				else
				{
					st.push(s[j]);
				}
			}
			else if (s[j] == '}')
			{
				if (!st.empty() && st.top() == '{')
				{
					st.pop();
				}
				else
				{
					st.push(s[j]);
				}
			}
			else if (s[j] == ']')
			{
				if (!st.empty() && st.top() == '[')
				{
					st.pop();
				}
				else
				{
					st.push(s[j]);
				}
			}
			else
			{
				st.push(s[j]);
			}
		}
		if (st.empty())
			answer++;
	}

	return answer;
}