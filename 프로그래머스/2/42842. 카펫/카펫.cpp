#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    long S = brown / 2 + 2;
    long P = brown + yellow;
    
    double tmp = (S * S) - (4 * P);
    tmp = sqrt(tmp);
    
    answer.push_back((int)(S + tmp) / 2);
    answer.push_back((int)(S - tmp) / 2);
    
    return answer;
}