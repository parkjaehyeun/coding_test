#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int in =1;
    int out =0;
    int time =1;
    int nw =truck_weights[0];
    queue<int> q;
    q.push(time);
    
    while(!q.empty())
    {
        time ++;
        int duration = time - q.front();
        if(duration == bridge_length)
        {
            q.pop();
            nw -= truck_weights[out];
            out ++;
        }
        if(in == truck_weights.size()) continue;
        if(nw+truck_weights[in]<=weight)
        {
            q.push(time);
            nw += truck_weights[in];
            in ++;
        }
    }
    answer = time;
    return answer;
}