#include <iostream>

using namespace std;

class Mamifero{
private:
    string nombre;
    int    peso;
    string habitad;
    string color;
public:
    Mamifero(){}
    void setNombre(string nombre_){(nombre = nombre_);}
    void setPeso(int peso_){peso = peso_;}
    void setColor(string color_){color = color_;}
    void setHabitad(string habitad_){habitad = habitad_;}
};

class Ave{
private:
    string nombre;
    string tipoPlumas;
    int    alturaMaxima;
    string tipoPico;
public:
    Ave(){}
    void setNombre(string nombre_){(nombre = nombre_);}
    void setTipoPlumas(string tipoPlumas_){tipoPlumas = tipoPlumas_;}
    void setAlturaMaxima(int alturaMaxima_){alturaMaxima = alturaMaxima_;}
    void setTipoPico(string tipoPico_){tipoPico = tipoPico_;}

};

class Reptil{
private:
    string nombre;
    string numeroDientes;
    string tipoPiel;
    int    edadMaxima;
public:
    Reptil(){}
    void setNombre(string nombre_){(nombre = nombre_);}
    void setTipoDientes(string numeroDientes_){numeroDientes = numeroDientes_;}
    void setTipoPiel(string tipoPiel_){tipoPiel = tipoPiel_;}
    void seteEdadMaxima(int edadMaxima_){edadMaxima = edadMaxima_;}
};

int main()
{
    Mamifero mamifero[2];
    Ave ave[2];
    Reptil reptil[2];

    string input_str;
    int input_int;

    for(int i = 0; i < 2; i++){
        cout << "Ingresar Mamifero!" << endl;
        cout << "nombre:";
        cin >> input_str;
        mamifero[i].setNombre(input_str);
        cout << "peso:";
        cin >> input_int;
        mamifero[i].setPeso(input_int);
        cout << "habitad:";
        cin >> input_str;
        mamifero[i].setHabitad(input_str);
        cout << "color:";
        cin >> input_str;
        mamifero[i].setColor(input_str);

        cout << "Ingresar Ave!" << endl;
        cout << "nombre:";
        cin >> input_str;
        ave[i].setNombre(input_str);
        cout << "altura maxima:";
        cin >> input_int;
        ave[i].setAlturaMaxima(input_int);
        cout << "tipo de pico:";
        cin >> input_str;
        ave[i].setTipoPico(input_str);
        cout << "tipo plunas:";
        cin >> input_str;
        ave[i].setTipoPlumas(input_str);

        cout << "Ingresar Reptil!" << endl;
        cout << "nombre:";
        cin >> input_str;
        reptil[i].setNombre(input_str);
        cout << "edad maxima:";
        cin >> input_int;
        reptil[i].seteEdadMaxima(input_int);
        cout << "tipo de piel:";
        cin >> input_str;
        reptil[i].setTipoPiel(input_str);
        cout << "tipo de dientes:";
        cin >> input_str;
        reptil[i].setTipoDientes(input_str);
    }

    return 0;
}
