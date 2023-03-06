/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: manuel.osorio
 *
 * Created on 26 de junio de 2018, 10:52 AM
 */

#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";


int strangerthinks(vector<vector<int>> matriz, int max_i, int max_j, string word1, string word2){
    cout << "<->" << endl;
    int comp1,comp2; string spell = "";
    for(int i = max_i; i != 0; i--){
           for(int j = max_j; j != -1; j--){               
               if(matriz[i][j]==matriz[i][j-1] && matriz[i][j]==matriz[i-1][j] && matriz[i][j]!=0){
                   cout << "case 1: " << matriz[i][j] << " arriba: " <<matriz[i-1][j] << " al lado: " << matriz[i][j-1] << endl;
                   comp1 = strangerthinks( matriz, i-1, j,  word1, word2);
                   comp2 = strangerthinks( matriz, i,  j-1, word1, word2);                   
                   if(comp1 > comp2)
                       return comp1 + spell.size();
                   return comp2 + spell.size();
               }else if(matriz[i][j]==matriz[i-1][j] && matriz[i][j]!=0){ // arriba 
                   cout << "case 2: " << matriz[i][j] << " arriba: " <<matriz[i-1][j] << endl;
                   if(word1[i-1] == word2[j-1]){
                       spell += word1[i-1];                      
                   }
                   break;
               }else if(matriz[i][j]==matriz[i][j-1] && matriz[i][j]!=0){ // al lado
                   cout << "case 3: "  << matriz[i][j] << " al lado: " <<matriz[i][j-1] << endl;
                   if(word1[i-1] == word2[j-1]){
                       spell += word1[i-1];                      
                   }                  
               }else if(matriz[i][j]>matriz[i-1][j-1]){ // diagonal
                   cout << "case 4: " << matriz[i][j] << " diagonal: " <<matriz[i-1][j-1] << endl;
                   if(word1[i-1] == word2[j-1]){
                       spell += word1[i-1];                      
                   }
                   max_j = j-1;
                   break;
               }               
           }            
    }
    return spell.size();
}
void counterspell(Spell *spell) {
    if(Fireball* d = dynamic_cast<Fireball*>(spell))
    {
        //std::cout << "downcast from Fireball to d successful\n";        
        d->revealScrollName(); d->revealFirepower();
    }else if(Frostbite* d = dynamic_cast<Frostbite*>(spell))
    {
        //std::cout << "downcast from Frostbite to d successful\n";
        d->revealScrollName(); d->revealFrostpower();
    }else if(Thunderstorm* d = dynamic_cast<Thunderstorm*>(spell))
    {
        //std::cout << "downcast from Thunderstorm to d successful\n";
        d->revealScrollName(); d->revealThunderpower();
    }else if(Waterbolt* d = dynamic_cast<Waterbolt*>(spell))
    {
        //td::cout << "downcast from Waterbolt to d successful\n";
        d->revealScrollName(); d->revealWaterpower();
    }else if(Spell* d = dynamic_cast<Spell*>(spell))
    {        
        std::string new_spells = d->revealScrollName();
        std::string journal = SpellJournal::read();        
        vector<char> out_spell_list;
             
        vector<vector<int>> lcs;
        vector<int>         input(journal.size()+1,0);
        
        for(int i = 0; i< new_spells.size()+1; i++)
        {            
            lcs.push_back(input);
        }
        
        for(int i = 1; i < new_spells.size() + 1; i++){
            for(int j = 1; j < journal.size() + 1; j++){
                if(new_spells[i-1] == journal[j-1]){                    
                    lcs[i][j] = lcs[i-1][j-1] + 1;                    
                }else{
                    if(lcs[i-1][j] > lcs[i][j-1]){
                        lcs[i][j] = lcs[i-1][j];
                    }else{
                        lcs[i][j] = lcs[i][j-1];                                      
                    }
                }
            }
        }

            for(int i = 0; i < lcs.size(); i++){
                for(int j = 0; j < lcs[0].size(); j++){
                    cout << lcs[i][j] << " ";
                }
                cout << endl;
            }
        cout << "----------------------------" << endl;
            
        cout << strangerthinks( lcs, new_spells.size(), journal.size(), new_spells, journal) << endl;
/*        
        size_t found;           
        size_t error;
        std::string out_spell = "";
        for(int i = 0; i < new_spells.size(); i++){
            found = journal.find(new_spells[i]);
            if(found!=std::string::npos)
            {
                error = out_spell.find(new_spells[i]);
                if(error == std::string::npos)
                    out_spell += journal[found];          
            }
        }             
        
        cout << out_spell << ' '<< out_spell.size() << endl;
        for(int i = 0; i < out_spell_list.size(); i++){
            cout << out_spell_list[i];
        }
 */
    }
}       
class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        //cout << "T:" << T << endl;
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}