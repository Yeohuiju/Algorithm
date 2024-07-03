#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int open = 0;
    
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '(')
            open++;
        else
            open--;
        
        if (open < 0){
            answer = false;
            break;
        }
    }
    
    if (open != 0)
        answer = false;

    return answer;
}