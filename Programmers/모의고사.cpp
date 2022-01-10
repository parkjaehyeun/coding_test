#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int size = answers.size();
    int a[5] = {1,2,3,4,5};
    int b[8] = {2,1,2,3,2,4,2,5};
    int c[10] = {3,3,1,1,2,2,4,4,5,5};
    int a_count=0, b_count=0,c_count=0;
    for(int i=0;i<size;i++){
        if(answers[i]== a[i%5]){
            a_count++;
        }
        if(answers[i] == b[i%8]){
            b_count++;
        }
        if(answers[i]==c[i%10]){
            c_count++;
        }
    }
    int arr[3] = {a_count,b_count,c_count};
    int max = 0;
    for(int i=0;i<3;i++){
        if(max<=arr[i]){
            if(max<arr[i]) answer.clear();
            max= arr[i];
            answer.push_back(i+1);
        }
    }


    return answer;
}