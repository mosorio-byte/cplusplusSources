#include <iostream>
#include <fstream>

using namespace std;

class NumeroIrracional {
public:
    double parteEntera;
    double parteImaginaria;

    NumeroIrracional(){}
    NumeroIrracional(double a, double b){
        parteEntera = a;
        parteImaginaria = b;
    }

};

NumeroIrracional operator +(const NumeroIrracional& x, const NumeroIrracional& y){
    NumeroIrracional result;
    result.parteEntera = x.parteEntera + y.parteEntera;
    result.parteImaginaria = x.parteImaginaria + y.parteImaginaria;
    return result;
}

NumeroIrracional operator -(const NumeroIrracional& x, const NumeroIrracional& y){
    NumeroIrracional result;
    result.parteEntera = x.parteEntera - y.parteEntera;
    result.parteImaginaria = x.parteImaginaria - y.parteImaginaria;
    return result;
}

NumeroIrracional operator *(const NumeroIrracional& x, const NumeroIrracional& y){
    NumeroIrracional result;
    result.parteEntera = (x.parteEntera*y.parteEntera)-(x.parteImaginaria*y.parteImaginaria);
    result.parteImaginaria = (x.parteEntera*y.parteImaginaria)+(x.parteImaginaria*y.parteEntera);
    return result;
}

NumeroIrracional operator /(const NumeroIrracional& x, const NumeroIrracional& y){
    NumeroIrracional result;
    result.parteEntera = ((x.parteEntera*y.parteEntera)+(x.parteImaginaria*y.parteImaginaria))/((y.parteEntera*y.parteEntera)+(y.parteImaginaria*y.parteImaginaria));
    result.parteImaginaria = ((x.parteImaginaria*y.parteEntera)-(x.parteEntera*y.parteImaginaria))/((y.parteEntera*y.parteEntera)+(y.parteImaginaria*y.parteImaginaria));
    return result;
}
int main()
{
    ofstream out_file;
    out_file.open("log.txt");

    NumeroIrracional a(4,3);
    NumeroIrracional b(1,9);
    NumeroIrracional r;
    r = a + b;
    cout << "suma: " << r.parteEntera << "+" << r.parteImaginaria << "i" << endl;
    out_file << "suma: " << r.parteEntera << "+" << r.parteImaginaria << "i" << endl;
    r = a - b;
    cout << "resta: " << r.parteEntera << "+" << r.parteImaginaria << "i" << endl;
    out_file << "resta: " << r.parteEntera << "+" << r.parteImaginaria << "i" << endl;
    r = a * b;
    cout << "multiplicacion: " << r.parteEntera << "+" << r.parteImaginaria << "i" << endl;
    out_file << "multiplicacion: " << r.parteEntera << "+" << r.parteImaginaria << "i" << endl;
    r = a / b;
    cout << "division: " << r.parteEntera << "+" << r.parteImaginaria << "i" << endl;
    out_file << "division: " << r.parteEntera << "+" << r.parteImaginaria << "i" << endl;

    out_file.close();
    return 0;
}
