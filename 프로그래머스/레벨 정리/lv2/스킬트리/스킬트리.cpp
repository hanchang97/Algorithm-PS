#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;

    unordered_map<char, int> mSkill;
    for (int i = 0; i < skill.length(); i++)
    {
        mSkill[skill[i]] = i + 1; // index + 1
    }

    for (int i = 0; i < skill_trees.size(); i++)
    {
        string curSkills = skill_trees[i];
        unordered_map<char, int> mSkillUsed;
        bool isPossible = true;

        for (int j = 0; j < curSkills.length(); j++)
        {
            char curSkill = curSkills[j];

            if (mSkill[curSkill] >= 1) // 스킬에 포함된 문자라면
            {
                int curSkillInx = mSkill[curSkill] - 1;
                mSkillUsed[curSkill] = 1;

                if (curSkillInx > 0)
                {
                    if (mSkillUsed[skill[curSkillInx - 1]] == 0) // 선행 스킬 습득했는지 체크
                    {
                        isPossible = false;
                        break;
                    }
                }
            }
        }

        if (isPossible)
            answer++;
    }

    return answer;
}