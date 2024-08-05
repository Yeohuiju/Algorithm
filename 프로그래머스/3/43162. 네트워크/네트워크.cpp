#include <string>
#include <vector>

using namespace std;

static vector<vector<int>> graph;
static vector<bool> processed;
static int result;

void dfs(int s);

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    graph.resize(n);
    processed.resize(n);
    fill(processed.begin(), processed.end(), false);
    result = 0; 
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(computers[i][j] && i != j)
                graph[i].push_back(j);
        }
    }
    
    for(int i = 0; i < n; i++){
        if(!processed[i]){
            result++;
            dfs(i);
        }
    }
    
    answer = result;
    
    return answer;
}

void dfs(int s){
    processed[s] = true;
    
    for(int i : graph[s]){
        if(!processed[i])
            dfs(i);
    }
}