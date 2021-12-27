#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string,int> umap;
    int p_num = participant.size();
    for(int i=0;i<p_num;i++){
        if(umap.end() != umap.find(participant[i])){
            umap[participant[i]]+=1;
        }
        else{
            umap.insert(make_pair(participant[i],1));
        }
    }
    int c_num = completion.size();
    for(int i=0;i<c_num;i++){
        if(umap.end()!=umap.find(completion[i])){
            umap[completion[i]] --;
        }
        if(umap[completion[i]]==0){
            umap.erase(completion[i]);
        }
    }
    unordered_map <string,int>::iterator it;
    for(it=umap.begin();it!=umap.end();it++){
        answer += it->first;
    }
    return answer;
}
