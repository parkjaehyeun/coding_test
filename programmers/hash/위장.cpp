#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map <string,int> umap;
    vector <string> cates;
    for(int i=0;i<clothes.size();i++){
        string cate = clothes[i][1];
        auto id = umap.find(cate);
        if(umap.end() != id){
            umap[cate] ++;
        }
        else{
            umap[cate] = 1;
            cates.push_back(cate);
        }
    }
    for(int i=0;i<cates.size();i++){
        string cate = cates[i];
        answer *= umap[cate]+1;
    }
    answer --;
    return answer;
}