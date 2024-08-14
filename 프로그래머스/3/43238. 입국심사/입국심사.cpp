#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    
    long long mid;
    long long sum;
    long long i = 1;
    long long j = (long long)times.back() * n;
    
    while(i <= j){       
        mid = (i + j) / 2;
        sum = 0;
        
        for(int t : times)
            sum += mid / (long long)t;
        
        if(sum >= n){
            answer = mid;
            j = mid - 1;
        }
        else
            i = mid + 1;
    }
    
    return answer;
}