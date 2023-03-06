#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    unsigned long int N, S, P, Q; // = 3 1 1 1
    cin >> N >> S >> P >> Q;
    unsigned int powresult = pow(2,31);
    
    vector<unsigned long int> a;
    a.push_back(S % powresult);
    
    for(int i = 1; i < N; i++){        
        a.push_back((a[i - 1] * P + Q) % powresult);
    }
    
    std::vector<unsigned long int>::iterator it;
    it = std::unique (a.begin(), a.end());
    a.resize(std::distance(a.begin(),it));
    cout << a.size() << endl;
    
    return 0;
}