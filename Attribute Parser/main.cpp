#include <cmath>
#include <string.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

class ClassTag{
    public:
        string name;
        bool start;
        map<string,string> mymap;
        vector<ClassTag*> next;

        void newValueMap(string key, string value){
            mymap.insert(pair<string, string>(key , value));
        }
        ClassTag *newClassTag(){
            next.push_back(new ClassTag);
            return next.back();
        };
};

int searchMain(vector<ClassTag*> MoT, string tag){
    for(unsigned int i = 0; (i < MoT.size()); i++){
        if(MoT[i]->name == tag){return i;}
    }
    return -1;
}

void lookKey(ClassTag* tag, string key){
    string hey = tag->mymap[key];
     if(!hey.empty()){
         cout << hey << endl;
     }else{
         cout << "Not Found!" << endl;
     }
}

bool searchChar(string sstr, int character ){
    char *cstr = new char[sstr.length() + 1];
    strcpy(cstr, sstr.c_str());

    char * pch_1;
    pch_1 = strrchr(cstr, character);
    long int d =  pch_1 - cstr + 1;

    if( d > 0){return true;}
    else      {return false;}
}

vector<string> string2token(string line, const char* token){
    vector<string> val_return;

    char *cstr = new char[line.length() + 1];
    strcpy(cstr, line.c_str());

    char * pch_1;
    pch_1 = strtok (cstr, token);
    while (pch_1 != NULL){
        val_return.push_back(pch_1);
        pch_1 = strtok (NULL, token);
    }
    return val_return;
}

vector<char> stringRepetitivo(string line, const char* token){
    vector<char> val_return;

    char *cstr = new char[line.length() + 1];
    strcpy(cstr, line.c_str());

    char * pch_1;
    pch_1 = strpbrk  (cstr, token);
    while (pch_1 != NULL){
        val_return.push_back(*pch_1);
        pch_1 = strpbrk (pch_1 + 1, token);
    }
    return val_return;
}
int main() {
    int N, Q;   cin >> N >> Q;
    cin.ignore();

    cout << "N:" << N << "Q:" << Q << endl;
    string sstr;
    string sMapKey;
    vector<ClassTag*> MotherOfTags;
    vector<ClassTag*> SecuenciaTags;

    bool found_close_tag;
    ClassTag *tagActual;

    for(int i = 0; i < N; i++){ // FILTRA TODA LA INFO DE UNA LINEA DE CODIGO

        /* read line*/
        getline(cin, sstr);
        //cout << "#line read: " << sstr << endl;

        /*open or close tag*/
        found_close_tag = searchChar(sstr, '/');
        if(found_close_tag){
            /*close tag*/
            //cout << "#Tag close" << endl;
            SecuenciaTags.pop_back();
            tagActual = SecuenciaTags.back();
        }
        else{
            //cout << "#Tag open" << endl;
            /*open tag*/
            if(SecuenciaTags.empty()){
                MotherOfTags.push_back(new ClassTag);
                tagActual = MotherOfTags.back();
            }else{
                tagActual = tagActual->newClassTag();
            }
            SecuenciaTags.push_back(tagActual);
            /*filter common*/
            vector<string> stringa;
            stringa = string2token(sstr, "\"<>");
            //cout << "#stoke to token [" << stringa.size() << "]" << endl;
            for(unsigned int i = 0; i < stringa.size(); i++){
                //cout << '[' << i << ']' << stringa[i] << endl;
            }
            /*new filter*/
            string key, value;
            //cout << "#new filter" << endl;
            vector<string> filter;
                for(unsigned int i = 0; i < stringa.size(); i++){
                if(i%2==0){
                     filter = string2token(stringa[i], " =");
                     key = filter.back();
                }else {
                     filter = string2token(stringa[i], "=");
                     value   = filter.back();
                     //cout << "couple is :" << key << ',' << value << endl;
                     tagActual->newValueMap(key, value);
                }
            }
            /*name tag*/
            //cout << "#name token: ";
            vector<string> nameToken;
            nameToken = string2token(sstr, "<>/ =\"");
            //cout << nameToken[0] << endl;
            tagActual->name = nameToken[0];
        }


    }


    vector<string> to_solve;
    vector<char> to_solve_c;
    for(int i = 0; i < Q; i++){
        getline(cin, sstr);


        to_solve = string2token(sstr, ".~");
        /*cout << "_______________________________" << endl;
        for(unsigned int i = 0; i < to_solve.size(); i++){
            cout << to_solve[i] << endl;
        }
        cout << "-------------------------------" << endl;*/

        to_solve_c = stringRepetitivo(sstr,".~");
        /*cout << "____stringrepetitvo_____________" << endl;
        for(unsigned int i = 0; i < to_solve_c.size(); i++){
            cout << to_solve_c[i] << endl;
        }
        cout << "-------------------------------" << endl;*/

        if(to_solve.empty() || (to_solve_c.back() == '.')){
            cout << "Not Found!" << endl;
        }else{
            vector<ClassTag*> listActual;
            listActual = MotherOfTags;
            int iteracion1;

            for(unsigned int i = 0; i < to_solve.size() - 1; i++){
                iteracion1 = searchMain(listActual, to_solve[i]);
                if(iteracion1 >= 0){
                    //cout << "hay algo:" << to_solve.size() <<  endl;
                    if( i ==  to_solve.size() - 2){
                            lookKey(listActual[iteracion1], to_solve[to_solve.size() - 1]);
                    }else{
                            listActual = listActual[iteracion1]->next;
                    }
                }else{
                    cout << "Not Found!" << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
