#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int count =0;
    vector<int> temp;
    //0없음 1있음 2여분있음
    for(int i=0;i<n;i++) temp.push_back(1);
    for(int i=0;i<lost.size();i++) temp[lost[i]-1] --;
    for(int i=0;i<reserve.size();i++) temp[reserve[i]-1] ++;
    
    if(temp[0]==2 && temp[1] ==0)
    {  
        temp[0]=1;
        temp[1]=1;
    }

    for(int i=1;i<n;i++)
    {
        if(temp[i]==2 && temp[i-1] ==0)
        {
            temp[i-1] =1;
            temp[i]=1;
            continue;    
        }
        if(temp[i]==2 && temp[i+1] ==0)
        {
            temp[i+1] =1;
            temp[i]=1;
        }
        
    }
    for(int i=0;i<n;i++)
    {
        if(temp[i]>0) answer ++;
    }
    return answer;
}