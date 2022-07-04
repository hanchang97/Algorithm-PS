#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool isEnd = false;
vector<string> answer;

int visited[10005] = {0,}; // 정렬된 tickets i번째 티켓을 사용했는지 안했는지

void dfs(string start, vector<vector<string>> &tickets, int ticketCnt){
    
    if(ticketCnt == tickets.size()){
        isEnd = true;
        return;
    }
    
    for(int i = 0; i < tickets.size(); i++){
        if(visited[i] == 0 && tickets[i][0] == start){
            
            string destination = tickets[i][1];
            
            visited[i] = 1;
            answer.push_back(destination);
            
            dfs(destination, tickets, ticketCnt + 1);
            if(isEnd) return;
            
            answer.pop_back();
            visited[i] = 0;
        }
    }
    
}

vector<string> solution(vector<vector<string>> tickets) {
    
    sort(tickets.begin(), tickets.end()); // 2차원 vector 정렬
    
    answer.push_back("ICN");
    dfs("ICN", tickets, 0);
    
    return answer;
}