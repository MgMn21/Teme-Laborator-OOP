#include <iostream>
#include <cmath>
using namespace std;
/*
    T.6.2. Rescrieti clasa Operatii de la T.6.1. astfel incit sa existe o metoda statica, supraincarcată pentru
    calculul modulului unui double respectiv al unui număr complex. Analog, o metodă statică pentru
    afișarea numărului real sau complex.
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
        static double Modul(double real);
        static double Modul(NumarComplex &comp);
        static void Afisare(double real);
        static void Afisare(NumarComplex &comp);
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
