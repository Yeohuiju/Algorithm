#include <string>
#include <vector>
#include <algorithm>

bool compare(int a, int b){
    return a > b;
}

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end(), compare);
    
    for(int i = 0; i < people.size(); i++){
        if(limit - people[i] >= people.back())
            people.pop_back();
        
        answer++;
    }
    
    return answer;
}