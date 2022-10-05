#include <string>
#include <stack>
#include <iostream>

using namespace std;

int solution(string s)
{
	stack<char> st;
	st.push(s[0]);

	for (int i = 1; i < s.length(); i++)
	{
		char cur = s[i];
		if (!st.empty() && st.top() == cur)
		{
			st.pop();
		}
		else
		{
			st.push(cur);
		}
	}

	return st.empty();
}