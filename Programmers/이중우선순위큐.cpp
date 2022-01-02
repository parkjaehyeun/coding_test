#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>, less<int>> max;
    priority_queue<int , vector<int>, greater<int>> min;
    int count =0;
    for(int i=0;i<operations.size();i++)
    {
        if(count ==0)
        {
            while(!min.empty()) min.pop();
            while(!max.empty()) max.pop();
        }
        char command = operations[i][0];
        string tnumber = operations[i].substr(2);
        if(command == 'D')
        {
            if(tnumber[0] == '-' && !min.empty())
            {
                min.pop();
                count --;
            }
            else if(tnumber [0] != '-' && !max.empty())
            {
                max.pop();
                count --;
            }
        }
        else
        {
            if(tnumber[0] == '-')
            {
                int number = stoi(tnumber.substr(1));
                number *= -1;
                max.push(number);
                min.push(number);
                count ++;
            }
            else
            {
                int number = stoi(tnumber);
                max.push(number);
                min.push(number);
                count ++;
            }
        }
    }
    if(count <=0) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(max.top());
        answer.push_back(min.top());
    }
    
    return answer;
}