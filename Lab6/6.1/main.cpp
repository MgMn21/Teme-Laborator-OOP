#include <iostream>
#include <cmath>
using namespace std;
/*
    T.6.1 Scrieti o clasa Operatii care va avea 2 constructori cu parametrii un double respectiv o clasa NumarComplex.
    Definiti clasa NumarComplex.
    Clasa Operatii implementeaza o metodă pentru calculul modulului numartului transmis ca parametru, doule sau numar complex.
    Clasa Operatii va avea o metoda afisare, supraîncărcată, care afișează un număr real sau complex.
*/

class NumarComplex {
    public:
        double realPart;
        double imgPart;

        NumarComplex(double real, double img);
};

class Operatii {

    private:
    double realPart;
    NumarComplex *nrcomp;

    public:
        Operatii(double real);
        Operatii(NumarComplex &comp);
        double Modul(double real);
        double Modul(NumarComplex &comp);
        void Afisare(double real);
        void Afisare(NumarComplex &comp);
};

//Functions:

NumarComplex::NumarComplex(double real, double img){
    this->realPart = real;
    this->imgPart = img;
}

Operatii::Operatii(double real){
    this->realPart = real;
}

Operatii::Operatii(NumarComplex &comp){
    this->nrcomp = &comp;
}

double Operatii::Modul(double real){
    return abs(real);
}

double Operatii::Modul(NumarComplex &comp){
    return sqrt(pow(comp.realPart, 2) + pow(comp.imgPart, 2));
}

void Operatii::Afisare(double real){
    cout << "Z = " <<  real << "\n";
}

void Operatii::Afisare(NumarComplex &comp){
    cout << "Z = " << comp.realPart << " + (" << comp.imgPart << ")*i\n";
}

int main()
{
    NumarComplex comp(432.12, -123.51);
    double real = 542.95;

    cout << "\nReal:\n";
    Operatii *ops = new Operatii(real);
    cout << "Modul: " << ops->Modul(real) << endl;
    ops->Afisare(real);

    cout << "\nComplex:\n";
    ops = new Operatii(comp);
    cout << "Modul: " << ops->Modul(comp) << endl;
    ops->Afisare(comp);

    return 0;
}
