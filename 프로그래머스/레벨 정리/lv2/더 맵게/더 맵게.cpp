#include <string>
#include <vector>
#include <queue>

using namespace std;

struct cmp
{ // min heap
    bool operator()(int fir, int sec)
    {
        return fir > sec;
    }
};

int solution(vector<int> scoville, int K)
{

    priority_queue<int, vector<int>, cmp> pq;

    for (int i = 0; i < scoville.size(); i++)
    {
        pq.push(scoville[i]);
    }

    int count = 0;
    bool isPossible = false;

    while (!pq.empty())
    {
        int first = pq.top();
        pq.pop();

        if (first >= K)
        {
            isPossible = true;
            break;
        }

        if (pq.empty())
        {
            break;
        }

        int second = 0;
        if (!pq.empty())
        {
            second = pq.top();
            pq.pop();
        }

        pq.push(first + second * 2);
        count++;
    }

    if (isPossible)
        return count;
    else
        return -1;
}