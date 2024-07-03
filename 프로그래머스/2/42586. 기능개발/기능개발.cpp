#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int day = 0;
    int idx = 0;
    
    while (idx < progresses.size()){
        progresses[idx] += speeds[idx] * day;
        
        while (progresses[idx] < 100){
            progresses[idx] += speeds[idx];
            day++;
        }
        
        answer.push_back(1);
        idx++;
        
        while(progresses[idx] + speeds[idx] * day >= 100 && idx < progresses.size()){
            answer.back()++;
            idx++;
        }
    }
 
    return answer;
}