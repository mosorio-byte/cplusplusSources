#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#define LIMIT_SIZE_RAM 1048576
#define LIMIT_SIZE_HDD 1048576

using namespace std;
/* pseudo code
    a[0] = S (modulo 2^31)
    for i = 1 to N-1
    a[i] = a[i-1]*P+Q (modulo 2^31)
*/

void saveFile(vector<unsigned int> a, string name){
    fstream fs;
    fs.open (name , std::fstream::in | std::fstream::out | std::fstream::app);
    for(unsigned int i = 0; i < a.size(); i++){
        fs << a[i] << ' ';
    }
    fs.close();
}

int main() {
    unsigned int N, S, P, Q; // = 3 1 1 1
    cin >> N >> S >> P >> Q;
    unsigned int powresult = pow(2,31);
    std::vector<unsigned int>::iterator it;
    vector<unsigned int> a;    

    try{
        int tips2 = N % LIMIT_SIZE_RAM;
        int tips  = N / LIMIT_SIZE_RAM;
        
        cout << "tips:" << tips << endl;
        cout << "tips2:" << tips2 << endl;
        
        for(int i = 0; i < tips; i++){
            
            a.push_back( S % powresult );      
            
            for(int j = 1; j < (LIMIT_SIZE_RAM - 1); j++){
                a.push_back((a[j - 1] * P + Q) % powresult);
            }
            
            S = a.back();
            //saveFile(a, "before" + std::to_string(i) + ".txt");
            it = std::unique (a.begin(), a.end());
            a.resize(std::distance(a.begin(),it));                      
            saveFile(a, "test" + std::to_string(i) + ".txt");
            cout << "test" + std::to_string(i) + ".txt: " << a.size() << ", " << a.back() << endl;
            a.clear();
        }
        if(tips2 > 0){            
            a.push_back(S % powresult);
            for(int j = 1; j < tips2; j++){
                a.push_back((a[j - 1] * P + Q) % powresult);
            }
            //saveFile(a, "beforer.txt");
            it = std::unique (a.begin(), a.end());
            a.resize(std::distance(a.begin(),it));      
            if(tips != 0){
                saveFile(a, "testr.txt");                
            }else{
                cout << a.size() << endl;
                return 0;
            }
            
            cout << "testr.txt: " << a.size() << ", " <<  a.back() << endl;      
            a.clear();
        }
        //leer
        cout << "read: " << tips <<endl;
        for(int k = 0; k < tips; k++){
            fstream fs;
            fs.open ("test" + std::to_string(k) + ".txt" , std::fstream::in);
            unsigned long int temp;
            while (fs >> temp)          // loop getting single characters
                a.push_back(temp); 
            fs.close(); 
            //remove("test" + std::to_string(k) + ".txt");
        }
        fstream fs;
        fs.open ("testr.txt" , std::fstream::in);
        unsigned int temp;
        while (fs >> temp)          // loop getting single characters
            a.push_back(temp); 
        fs.close(); 
        it = std::unique (a.begin(), a.end());
        a.resize(std::distance(a.begin(),it));  
    }
    catch (std::bad_alloc& ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
        std::cerr << "size: " << a.size() << '\n';
        std::cerr << "int: " << a[a.size()-1] << '\n';
    }
       
    cout << a.size() << endl;

    return 0;
}
