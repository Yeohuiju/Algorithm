#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static vector<vector<int>> graph;
static vector<bool> visited;
static vector<int> dist;

void bfs();

int solution(int n, vector<vector<int>> edge) {
    int answer = 1;
    
    graph.resize(n + 1);
    visited.resize(n + 1);
    fill(visited.begin(), visited.end(), false);
    dist.resize(n + 1);
    fill(dist.begin(), dist.end(), 0);
    
    for(int i = 0; i < edge.size(); i++){
        int n1 = edge[i][0];
        int n2 = edge[i][1];
        
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    
    bfs();
    sort(dist.begin(), dist.end());
    int max = dist[n];

    for(int i = n - 1; i > 0; i--){
        if(dist[i] != max)
            break;
        
        answer++;
    }
    
    return answer;
}

void bfs(){
    queue<int> myQueue;
    
    visited[1] = true;
    myQueue.push(1);
    
    while(!myQueue.empty()){
        int now = myQueue.front();
        myQueue.pop();
        
        for(int i : graph[now]){
            if(!visited[i]){
                visited[i] = true;
                myQueue.push(i);
                dist[i] = dist[now] + 1;
            }
        }
    }
}