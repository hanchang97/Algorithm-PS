#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAX 1000000000000000000

long long solution(int n, vector<int> times) {
    long long answer = MAX;
    
    sort(times.begin(), times.end());
    
    long long N = n;
    long long start = 1;
    long long end = MAX;
    
    while(start <= end){
        long long mid = (start + end) / 2;
        
        long long count = 0;
        for(int i = 0; i < times.size(); i++){
            if(mid < times[i]) break;
            count += mid / times[i];
        }
    
        if(count >= N){
            end = mid - 1;
            if(mid < answer) answer = mid;
        }
        else{
            start = mid + 1;
        }
    }
    
    return answer;
}