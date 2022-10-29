#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;

    for(int i = 0; i < str1.length(); i++) {
       if(str1[i] >= 'A' && str1[i] <= 'Z') {
            str1[i] += 32;
        } 
    }
    
    for(int i = 0; i < str2.length(); i++) {
       if(str2[i] >= 'A' && str2[i] <= 'Z') {
            str2[i] += 32;
        } 
    }
    
    unordered_map<string, int> um1;
    unordered_map<string, int> um2;
    
    for(int i = 1; i < str1.length(); i++) {
        string temp = "";
        
        if((str1[i] >= 'a' && str1[i] <= 'z') && (str1[i-1] >= 'a' && str1[i-1] <= 'z')) {
            temp += str1[i-1];
            temp += str1[i];
            um1[temp] += 1;
        }
    }
    
    for(int i = 1; i < str2.length(); i++) {
        string temp = "";
        
        if((str2[i] >= 'a' && str2[i] <= 'z') && (str2[i-1] >= 'a' && str2[i-1] <= 'z')) {
            temp += str2[i-1];
            temp += str2[i];
            um2[temp] += 1;
        }
    }
    
    // 교집합, 합집합 개수 구하기
    int interCnt = 0;
    int unionCnt = 0;
    
    // 교
    for(auto iter = um1.begin(); iter != um1.end(); iter++ ) {
        string check = iter->first;
        int cnt1 = iter->second;
        
        if(um2[check] != 0) {
            interCnt += min(cnt1, um2[check]);
        }
    }
    
    // 합
    for(auto iter = um1.begin(); iter != um1.end(); iter++ ) {
        string check = iter->first;
        int cnt1 = iter->second;
        
        if(um2[check] != 0) {
            unionCnt += max(cnt1, um2[check]);
        }
        else {
            unionCnt += cnt1;
        }
    }
    
    for(auto iter = um2.begin(); iter != um2.end(); iter++ ) {
        string check = iter->first;
        int cnt2 = iter->second;
        
        if(um1[check] == 0) {
            unionCnt += cnt2;
        }
    }
    
    cout << interCnt << "\n";
    cout << unionCnt << "\n";
    
    if(unionCnt == 0) {
        answer = 65536;
    }
    else {
        // answer = 65536 / unionCnt * interCnt; // 이 순서로 연산하면 오답
        
        double score = (double)interCnt / unionCnt;
        answer = score * 65536;
    }
    
    return answer;
}