#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int command_row_length = commands.size();
    for(int i=0;i<command_row_length;i++){
        vector<int> temp;
        int a = commands[i][0];
        int b= commands[i][1];
        int c = commands[i][2];
        for(int j=a-1;j<=b-1;j++){
            temp.push_back(array[j]);
        }
        sort(temp.begin(),temp.end());
        int target = temp[c-1];
        answer.push_back(target);
    }
    return answer;
}