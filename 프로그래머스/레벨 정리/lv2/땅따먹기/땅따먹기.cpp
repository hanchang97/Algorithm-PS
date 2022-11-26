#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int table[100005][4];

int solution(vector<vector<int>> land)
{
    int answer = 0;

    for (int i = 0; i < land[0].size(); i++)
    {
        table[0][i] = land[0][i];
    }

    for (int i = 1; i < land.size(); i++)
    {
        for (int j = 0; j < land[i].size(); j++)
        {
            int preMax = 0;
            for (int k = 0; k < land[i].size(); k++)
            {
                if (k != j)
                {
                    if (table[i - 1][k] > preMax)
                        preMax = table[i - 1][k];
                }
            }
            table[i][j] = preMax + land[i][j];
        }
    }

    int lastInx = land.size() - 1;
    answer = max({table[lastInx][0], table[lastInx][1],
                  table[lastInx][2], table[lastInx][3]});

    return answer;
}