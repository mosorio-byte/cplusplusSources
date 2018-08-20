#include <cmath>
#include <string.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> string2token(string line, char* token){
    vector<string> val_return;
    char * pch_1;

    //convert string to chart
    char *cstr = new char[line.length() + 1];
    strcpy(cstr, line.c_str());

    //token line
    pch_1 = strtok (cstr, token);
    while (pch_1 != NULL){
        val_return.push_back(pch_1);
        pch_1 = strtok (NULL, token);
    }
        return val_return;
}
// "<tag3 value1 = \"value 1\" value2 = \"value 2\">"
int main()
{
    cout << ">fragment" << endl << "<tag3 value1 = \"value 1\" value2 = \"value 2\">" << endl;

    //filter common
    vector<string> stringa;
    stringa = string2token("<tag3 value1 = \"value 1\" value2 = \"value 2\">", "\"<>");
    cout << ">stoke to token" << endl;
    for(int i = 0; i < stringa.size(); i++){
        cout << '[' << i << ']' << stringa[i] << endl;
    }

    string key, value;
    //new filter
    cout << ">new filter" << endl;
    vector<string> filter;
        for(int i = 0; i < stringa.size(); i++){
        if(i%2==0){
             filter = string2token(stringa[i], " =");
             key = filter.back();
        }else {
             filter = string2token(stringa[i], "=");
             value   = filter.back();
             cout << "pear is :" << key << ',' << value << endl;
        }
        cout << '[' << i << ']' << filter.back() << endl;
    }
    return 0;
}
