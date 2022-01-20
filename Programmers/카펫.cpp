#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<pair<int,int>> v;
    if(yellow ==1)
    {
        answer.push_back(3);
        answer.push_back(3);
        return answer;
    }
    for(int i=1;i<yellow;i++)
    {
        if(yellow%i==0)
        {
            v.push_back(make_pair(yellow/i,i));
        }
    }
    for(int i=0;i<v.size();i++)
    {
        int one = v[i].first;
        int two = v[i].second;
        if(brown == (one+2)*2 + two*2)
        {
            answer.push_back(one+2);
            answer.push_back(two+2);
            return answer;
        }
    }
    return answer;
}