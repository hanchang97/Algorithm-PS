#include <string>
#include <stack>
#include <iostream>

using namespace std;

bool solution(string s)
{
	bool answer = true;

	stack<char> charStack;

	for (int i = 0; i < s.length(); i++)
	{
		if (charStack.empty())
			charStack.push(s[i]);
		else
		{
			if (s[i] == ')' && charStack.top() == '(')
			{
				charStack.pop();
			}
			else
			{
				charStack.push(s[i]);
			}
		}
	}

	answer = charStack.empty();

	return answer;
}