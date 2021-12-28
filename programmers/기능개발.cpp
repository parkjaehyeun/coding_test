#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    queue<int> q1;
    for(int i=0;i<progresses.size();i++){
        q.push(progresses[i]);
        q1.push(speeds[i]);
    }
    int count =1;
    int tanswer =0;
    while(1){
        if(q.empty()) break;
        int temp_pro = q.front();
        int temp_sp = q1.front();
        if((temp_pro + temp_sp*count) >=100){
            q.pop();
            q1.pop();
            tanswer ++;
            continue;
        }
        else{
            count++;
            if(tanswer>0){
                answer.push_back(tanswer);
                tanswer =0;
            }
        }
    }
    
    if(tanswer !=0) answer.push_back(tanswer);
    return answer;
}