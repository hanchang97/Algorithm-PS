#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(string msg)
{
    vector<int> answer;

    map<string, int> mDic;
    for (int i = 'A'; i <= 'Z'; i++) // A~Z 는 기본으로 사전에 추가하기
    {
        char c = i;
        string t = "";
        t += c;
        mDic[t] = i - 'A' + 1;
    }

    int addNum = 27; // 사전에 추가하는 경우 부여받을 다음 번호
    int len = msg.length();
    int inx = 0;
    while (inx < len)
    {
        int tempInx = inx;
        string tempStr = "";
        tempStr += msg[inx];

        tempInx++;
        while (tempInx < len && mDic[tempStr] != 0)
        {
            tempStr += msg[tempInx];
            tempInx++;
        }

        // cout << "answer " << tempStr << "\n";

        // 현재입력이 사전에 존재하는데 마지막 문자에 도달한 경우
        if (mDic[tempStr] != 0)
        {
            answer.push_back(mDic[tempStr]);
            break;
        }

        mDic[tempStr] = addNum; // 사전 추가
        addNum++;

        tempStr.pop_back(); // 현재입력은 마지막 문자 하나 빼주기
        answer.push_back(mDic[tempStr]);

        inx = inx + tempStr.length();
    }

    return answer;
}