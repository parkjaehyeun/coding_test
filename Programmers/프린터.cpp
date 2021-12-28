#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

int cmp(int a, int b){
    if (a>b) return true;
    else return false;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;

    queue<pair<int,int>> q;
    for(int i=0;i<priorities.size();i++){
        q.push(make_pair(priorities[i],i));
    }
    sort(priorities.begin(),priorities.end(),cmp);
    
    int count =0;
    while(!q.empty()){
        int temp = q.front().first;
        if(temp != priorities[count]){
            int temp2 = q.front().second;
            q.pop();
            q.push(make_pair(temp,temp2));
        }
        else{
            cout << q.front().second << " ";
            if(q.front().second == location){
                return (count+1);
            }
            else{
                q.pop();
                count ++;
            }
        }
    }
    return answer;
}