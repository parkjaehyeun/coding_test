#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int p_size = phone_book.size();;
    sort(phone_book.begin(),phone_book.end());
    for(int i=0;i<phone_book.size()-1;i++){
        string target = phone_book[i];
        if(phone_book[i] == phone_book[i+1].substr(0,phone_book[i].size())) return false;
    }
    return answer;
}
