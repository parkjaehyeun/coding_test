#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> temps;
    int zero_count =1;
    for(int i=0;i<numbers.size();i++)
    {
        if(numbers[i]!=0){
            zero_count=0;
        }
    }
    if(zero_count ==1){
        answer += "0";
        return answer;
    }
    for(int i=0;i<numbers.size();i++)
    {
        string temp = to_string(numbers[i]);
        temp += temp+temp;
        temps.push_back(temp);
    }
    sort(temps.rbegin(),temps.rend());
    for(int i=0;i<temps.size();i++)
    {
        answer += temps[i].substr(temps[i].size()-temps[i].size()/3);
    }
    return answer;
}