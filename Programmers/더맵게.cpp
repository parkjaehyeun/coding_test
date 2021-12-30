#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<scoville.size();i++) pq.push(scoville[i]);
    while(!pq.empty())
    {
        int min = pq.top();
        if(min < K)
        {
            answer ++;
            pq.pop();
            if(pq.empty()) return -1;
            int min2 = pq.pop();
            int value = min+min2*2;
            pq.push(value);
        }
        else{
            break;
        }
    }
    return answer;
}