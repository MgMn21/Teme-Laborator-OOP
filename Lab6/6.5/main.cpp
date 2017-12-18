#include <iostream>
#include <cmath>
using namespace std;
/*
    T.6.4. Rescrieți clasa Operații de la T.6.4. care să folosească metode statice, supraîncărcate, cu doi
    parametrii (două numere double respectiv două NumarComplex) și să calculeze suma, diferența,
    produsul și împărțirea parametrilor.
*/

class NumarComplex {
    private:
        double realPart;
        double imgPart;

    public:
        NumarComplex(double real, double img);
        double operator~();
        NumarComplex operator^(int power);
        void Afisare();
};

NumarComplex::NumarComplex(double real, double img){
    this->realPart = real;
    this->imgPart = img;
}

double NumarComplex::operator~(){
    return sqrt(pow(realPart, 2) + pow(imgPart, 2));
}

        /*
            Z^x = (a + b*i)^x = [r * e^(i*alpha)]^x = r^x * e^(i*x*alpha) = r^x[cos(x*alpha) + i*sin(x*alpha)] din formula lui Euler
            unde r = |Z| si alpha = arctg(b/a)
            de aici avem partea reala = r*cos(x*alpha)
                         partea imaginara = r*sin(x*alpha);
        */
NumarComplex NumarComplex::operator^(int power){
    NumarComplex temp(0, 0);
    double r = pow(sqrt(pow(this->realPart, 2) + pow(this->imgPart, 2)), power);
    double alpha = power*atan(this->imgPart / this->realPart);
    temp.realPart = r*cos(alpha);
    temp.imgPart = r*sin(alpha);
    return temp;
}

void NumarComplex::Afisare(){
    cout << this->realPart << " + (" << this->imgPart << ")*i\n";
}

int main()
{
    NumarComplex comp(-23.5, 62.76);

    cout<<"--Complex Number--\n"<<"\nZ = ";
    comp.Afisare();
    cout<<"Modul: "<<~comp<<endl;
    NumarComplex temp(0, 0);
    double x;
    cout<<"\nPower:\n>>>";
    cin>>x;
    temp = comp^x;
    cout<<"\nZ^"<<x<<" =";
    temp.Afisare();

    return 0;
}
