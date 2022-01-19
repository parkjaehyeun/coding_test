#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int size = citations.size();
    int temp =0;
    sort(citations.begin(), citations.end(), less<int>());
    cout << citations[0] << " " << citations[1] ;
    for(int i=0;i<size;i++)
    {
        int index_value = citations[i];
        int ssize = size-i;

        if(index_value > ssize)
        {
            i--;
        }
        temp ++;
        if(index_value == ssize)
        {
            temp = index_value;
        }
        if(index_value <= ssize && temp>=index_value)
        {
            temp = index_value;
        }
        if(temp > ssize)
        {
            return answer;
        }
        answer= temp;
    }
    
    
    return answer;
}