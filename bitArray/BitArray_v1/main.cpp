#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#define LIMIT_SIZE 33554432
using namespace std;

/* pseudo code
    a[0] = S (modulo 2^31)
    for i = 1 to N-1
    a[i] = a[i-1]*P+Q (modulo 2^31)
*/

void saveFile(vector<unsigned long int> a, string name){
    fstream fs;
    string path = name + ".txt";
    fs.open (path , std::fstream::in | std::fstream::out | std::fstream::app);
    for(unsigned long int i = 1; i < a.size(); i++){
        fs << a[i] << '\n';
    }
    fs.close();
}

int main() {
    unsigned long int N, S, P, Q; // = 3 1 1 1
    cin >> N >> S >> P >> Q;
    unsigned int powresult = pow(2,31);
    std::vector<unsigned long int>::iterator it;
    unsigned long int Count = 0;
    unsigned long int Before;
    vector<unsigned long int> a;
    a.push_back( S % powresult );
    try{
        int tips2 = N % LIMIT_SIZE;
        int tips = N / LIMIT_SIZE;
        cout << "tips:" << tips << endl;
        cout << "tips2:" << tips2 << endl;

        for(int i = 0; i < tips; i++){
            for(int j = 1; j < (LIMIT_SIZE - 1); j++){
                a.push_back((a[j - 1] * P + Q) % powresult);
            }
            it = std::unique (a.begin(), a.end());
            a.resize(std::distance(a.begin(),it));
            Count += a.size();
            Before = a.back();
            saveFile(a, "test" + i);
            a.clear();
        }
        if(tips2 > 0){
            a.push_back(Before % powresult);
            for(int i = 1; i < tips2; i++){
                a.push_back((a[i - 1] * P + Q) % powresult);
            }
            it = std::unique (a.begin(), a.end());
            a.resize(std::distance(a.begin(),it));
            Count += a.size();
            a.clear();
        }
    }
    catch (std::bad_alloc& ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
        std::cerr << "size: " << a.size() << '\n';
        std::cerr << "int: " << a[a.size()-1] << '\n';
        std::cerr << "int: " << a[a.size()-2] << '\n';

    }
    cout << Count << endl;

    return 0;
}
