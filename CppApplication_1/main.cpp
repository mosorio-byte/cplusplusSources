#include <iostream>  
#include <vector>
#include <vector>
using namespace std;  
 
class test{
    int i;
    double d;
    char c;
    test(){
    }
    test(int i_) : i(i_){
        
    }
};
void print() {  
    cout << endl;  
}  

template <typename T> void print(const T& t) {  
    cout << t << endl;  
}  
template <typename First, typename... Rest> void print(const First& first, const Rest&... rest) {  
    cout << first << ", ";  
    print(rest...); // recursive call using pack expansion syntax  
}  
// function to call if operator new can't allocate enough memory or error arises
void outOfMemHandler()
{
    std::cerr << "Unable to satisfy request for memory\n";
    std::abort();
}
    
int main()  
{  
    print(); // calls first overload, outputting only a newline  
    print(1); // calls second overload  
  
    // these call the third overload, the variadic template,   
    // which uses recursion as needed.  
    print(10, 20);  
    print(100, 200, 300);  
    print("first", 2, "third", 3.14159);  
    
    cout << endl;
    for(int i = 0; i < 10; i++){
        cout << i;
    }
    cout << endl;
    for(int i = 9; i !=-1; i--){
        cout << i;
    }
    vector<vector<int>> matriz;
    vector<int> input(4,100);
    for(int i = 0; i < 10; i++){        
        matriz.push_back(input);
    }
    for(int i = 0;i < 10;i++){
        for(int j = 0; j < 4; j++){
            cout << matriz[i][j] << " "; 
        }
        cout << endl;
    }
    
    std::vector<int> myvector;
  int sum (0);
  myvector.push_back (100);
  myvector.push_back (200);
  myvector.push_back (300);

  while (!myvector.empty())
  {
    cout << myvector.back() << endl;
    sum+=myvector.back();
    myvector.pop_back();
  }
   cout << "The elements of myvector add up to " << sum << '\n';
    //set the new_handler
    std::set_new_handler(outOfMemHandler);

    //Request huge memory size, that will cause ::operator new to fail
    int *pBigDataArray = new int[1000000000L];
        
    vector<int*> int_pointer;
    cout << "size int: " << sizeof(int) << endl;
    for(int i = 0; i < 10; i++){
        int_pointer.push_back(new int(i));
    }
    for(int i = 0; i < 10; i++){
        cout << int_pointer[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < 0; i++){
        cout << "for 0" << endl;
    }
    
    return 0;
}  