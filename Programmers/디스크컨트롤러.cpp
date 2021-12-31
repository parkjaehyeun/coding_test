#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(),jobs.end());
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int time =0;
    int idx=0;
    while(idx<jobs.size()|| !pq.empty())
    {
        while(idx<jobs.size() && time >= jobs[idx][0])
        {
            pq.push(make_pair(jobs[idx][1],jobs[idx][0]));
            idx ++;
        }
        if(!pq.empty())
        {
            time += pq.top().first;
            answer += (time - pq.top().second);
            pq.pop();
        }
        else
        {
            time = jobs[idx][0];
        }
    }
    answer = answer/jobs.size();
    return answer;
}