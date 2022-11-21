#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dy[4] = {0, 0, 1, 1};
int dx[4] = {0, 1, 1, 0};

int solve(int m, int n, vector<string> &board)
{
    int cnt = 0;
    int check[31][31] = {0};

    // 아래로 내리기 - 빈 공간 = '0'
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (board[i][j] == '0')
                continue;
            int move = 0;
            int tempY = i + 1;
            while (true)
            {
                if (tempY >= m)
                    break;
                if (board[tempY][j] != '0')
                    break;
                tempY++;
                move++;
            }

            if (move >= 1)
            { // 내릴 수 있는 경우
                board[i + move][j] = board[i][j];
                board[i][j] = '0';
            }
        }
    }

    // 지울곳 체크하기
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (board[i][j] == '0')
                continue; // 빈 공간
            if (board[i][j] != board[i + dy[1]][j + dx[1]])
                continue;
            if (board[i][j] != board[i + dy[2]][j + dx[2]])
                continue;
            if (board[i][j] != board[i + dy[3]][j + dx[3]])
                continue;

            for (int k = 0; k < 4; k++)
            {
                check[i + dy[k]][j + dx[k]] = 1;
            }
        }
    }

    // 지우기
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (check[i][j] != 0)
            {
                board[i][j] = '0';
                cnt++;
            }
        }
    }

    return cnt;
}

int solution(int m, int n, vector<string> board)
{
    int answer = 0;

    while (true)
    {
        int add = solve(m, n, board);
        answer += add;
        if (add == 0)
            break;
    }

    return answer;
}