#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;

int solution(vector<int> citations){
    int answer = 0;
    int size = citations.size();
    int quote =0;
    int pos =0;

    for(int i=0;i<=size;i++){
        int max = *max_element(citations.begin(),citations.end());
        int pos = find(citations.begin(),citations.end(),max)-citations.begin();
        if(max == -1) return quote;
        if(quote>=max){
            return quote;
        }
        quote ++;
        citations[pos] = -1;

    }


    return answer;
}