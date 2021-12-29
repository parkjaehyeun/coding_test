#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<pair<int,int>> s;
    for(int i=0;i<prices.size();i++) answer.push_back(0);
    s.push(make_pair(prices[0],0));
    for(int i=1;i<prices.size();i++)
    {
        while(!s.empty() &&s.top().first > prices[i])
        {
            int idx = s.top().second;
            answer[idx] = (i-idx);
            s.pop();
        }
        s.push(make_pair(prices[i],i));
    }
    for(int i=0;i<prices.size();i++)
    {
        if(answer[i]==0)
        {
            answer[i] = prices.size()-i-1;
        }
    }
    return answer;
}