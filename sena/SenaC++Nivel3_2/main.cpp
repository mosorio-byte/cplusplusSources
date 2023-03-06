#include <iostream>
#include <math.h>

using namespace std;

class Operaciones{
private:
    int i;
    int d;
public:
    Operaciones(){}
    Operaciones(int i_, int d_){
        i = i_;
        d = d_;
    }
    int Suma(){return i + d;}

    int Suma(int i_, int i2_ ){return i_ + i2_;}
    double Suma(double d_, double d2_ ){return d_ + d2_;}
    int Suma(char c_, char c2_ ){return (c_ - 0x30) + (c2_-0x30);}

    int Multiplicacion(int i_, int i2_ ){return i_ * i2_;}
    double Multiplicacion(double d_, double d2_ ){return d_ * d2_;}
    int Multiplicacion(char c_, char c2_ ){return (c_ - 0x30) * (c2_-0x30);}

    int Division(int i_, int i2_ ){return i_ / i2_;}
    double Division(double d_, double d2_ ){return d_ / d2_;}
    int Division(char c_, char c2_ ){return (c_ - 0x30) / (c2_-0x30);}

    int Potenciacion(int i_, int i2_ ){return pow(i_,i2_);}
    double Potenciacion(double d_, double d2_ ){return pow(d_,d2_);}
    int Potenciacion(char c_, char c2_ ){ return pow((c_ - 0x30),(c2_-0x30));}
};

int main()
{
    Operaciones opr;
    Operaciones opr1(1,2);
    cout << "Operaciones!" << endl;
    cout <<  opr1.Suma() << endl;
    cout <<  opr.Suma(5.5, 5.5) << endl;
    cout <<  opr.Suma('5', '5') << endl;

    cout <<  opr.Multiplicacion(1, 3) << endl;
    cout <<  opr.Multiplicacion(1.1, 3.1) << endl;
    cout <<  opr.Multiplicacion('1', '3' ) << endl;

    cout <<  opr.Division(15, 3 ) << endl;
    cout <<  opr.Division(15.15, 3.0 ) << endl;
    cout <<  opr.Division('9', '3' ) << endl;

    cout <<  opr.Potenciacion(6, 3 ) << endl;
    cout <<  opr.Potenciacion(6.3, 3.3 ) << endl;
    cout <<  opr.Potenciacion('6', '3' ) << endl;
    return 0;
}
