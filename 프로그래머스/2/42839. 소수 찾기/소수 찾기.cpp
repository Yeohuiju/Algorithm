#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPrime(int n);

int solution(string numbers) {
    int answer = 0;
    int len = numbers.length();
    
    vector<char> vect(numbers.begin(), numbers.end());
    set<int> nums;
    
    for(int l = 1; l <= len; l++){
        vector<bool> mask(len, false);
        fill(mask.end() - l, mask.end(), true);
        
        do {
            vector<char> now;
            
            for (int i = 0; i < len; i++) {
                if (mask[i])
                    now.push_back(vect[i]);
            }
            
            sort(now.begin(), now.end());
            do {
                string s(now.begin(), now.end());
                nums.insert(stoi(s));
                
                nums.insert(stoi(s));
                
            } while (next_permutation(now.begin(), now.end()));
        } while (next_permutation(mask.begin(), mask.end()));
    }
    
    for (set<int>::iterator it = nums.begin(); it != nums.end(); ++it){
        if(isPrime(*it))
            answer++;
    }
    
    return answer;
}   

bool isPrime(int n){
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0)
            return false;
    }
    
    return true;
}