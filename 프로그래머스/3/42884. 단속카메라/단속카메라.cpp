#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end());
    
    int end = routes[0][1];
    answer++;
    
    for(int i = 1; i < routes.size(); i++){
        if(routes[i][1] < end){
            end = routes[i][1];
            continue;
        }
        
        if(routes[i][0] <= end)
            continue;
        
        answer++;
        end = routes[i][1];
    }
    
    return answer;
}