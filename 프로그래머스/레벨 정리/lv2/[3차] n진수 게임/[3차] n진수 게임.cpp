#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map<int, char> mNumConvert;

string convert(int num, int n)
{

    if (num == 0)
        return "0";

    string str = "";

    while (num > 0)
    {
        str += mNumConvert[num % n];
        num /= n;
    }

    reverse(str.begin(), str.end());
    return str;
}

string solution(int n, int t, int m, int p)
{
    string answer = "";

    for (int i = 0; i <= 9; i++)
    {
        mNumConvert[i] = ('0' + i);
    }
    for (int i = 0; i <= 5; i++)
    {
        int num = i + 10;
        mNumConvert[num] = ('A' + i);
    }

    vector<char> vDictionary;
    int number = 0;

    while (vDictionary.size() <= 100000)
    {
        string str = convert(number, n);
        for (int i = 0; i < str.length(); i++)
        {
            vDictionary.push_back(str[i]);
        }
        number++;
    }

    int start = p;
    for (int i = 1; i <= t; i++)
    {
        answer += vDictionary[start - 1];
        start += m;
    }

    return answer;
}