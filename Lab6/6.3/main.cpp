#include <iostream>
#include <cmath>
using namespace std;
/*
    T.6.3. Scrieti o clasa Operatii care va avea 2 constructori cu parametrii doi double respectiv două clase
    NumarComplex. Clasa Operatii implementeaza metode supraîncărcate pentru calculul sumei, diferenței,
    produsului și împărțirii a două numere, double sau NumarComplex. Metodele folosite vor fi
    supraîncărcate (același nume).
*/

class NumarComplex {
    public:
        double realPart;
        double imgPart;

        NumarComplex(double real, double img);
};

class Operatii {

    private:
    double realPart_1;
    double realPart_2;
    NumarComplex *nrcomp_1;
    NumarComplex *nrcomp_2;

    public:
        Operatii(double real_1, double real_2);
        Operatii(NumarComplex &comp_1, NumarComplex &comp_2);

        double Sum(double real_1, double real_2);
        double Subtraction(double real_1, double real_2);
        double Multiply(double real_1, double real_2);
        double Divide(double real_1, double real_2);

        NumarComplex Sum(NumarComplex &comp_1, NumarComplex &comp_2);
        NumarComplex Subtraction(NumarComplex &comp_1, NumarComplex &comp_2);
        NumarComplex Multiply(NumarComplex &comp_1, NumarComplex &comp_2);
        NumarComplex Divide(NumarComplex &comp_1, NumarComplex &comp_2);

        static void Afisare(double real);
        static void Afisare(NumarComplex &comp);
};

//Functions:

//Constructors
NumarComplex::NumarComplex(double real, double img){
    this->realPart = real;
    this->imgPart = img;
}

Operatii::Operatii(double real_1, double real_2){
    this->realPart_1 = real_1;
    this->realPart_2 = real_2;
}

Operatii::Operatii(NumarComplex &comp_1, NumarComplex &comp_2){
    this->nrcomp_1 = &comp_1;
    this->nrcomp_2 = &comp_2;
}//end constructors

//Real operations:
double Operatii::Sum(double real_1, double real_2){
    return real_1 + real_2;
}

double Operatii::Subtraction(double real_1, double real_2){
    return real_1 - real_2;
}

double Operatii::Multiply(double real_1, double real_2){
    return real_1 * real_2;
}

double Operatii::Divide(double real_1, double real_2){
    return real_1 / real_2;
}

//Complex operations:
NumarComplex Operatii::Sum(NumarComplex &comp_1, NumarComplex &comp_2){
    NumarComplex temp(0, 0);
    temp.imgPart = comp_1.imgPart + comp_2.imgPart;
    temp.realPart = comp_1.realPart + comp_2.realPart;
    return temp;
}

NumarComplex Operatii::Subtraction(NumarComplex &comp_1, NumarComplex &comp_2){
    NumarComplex temp(0, 0);
    temp.imgPart = comp_1.imgPart - comp_2.imgPart;
    temp.realPart = comp_1.realPart - comp_2.realPart;
    return temp;
}


NumarComplex Operatii::Multiply(NumarComplex &comp_1, NumarComplex &comp_2){
    NumarComplex temp(0, 0);
    temp.imgPart = comp_1.imgPart * comp_2.imgPart;
    temp.realPart = comp_1.realPart * comp_2.realPart;
    return temp;
}


NumarComplex Operatii::Divide(NumarComplex &comp_1, NumarComplex &comp_2){
    NumarComplex temp(0, 0);
    temp.imgPart = comp_1.imgPart / comp_2.imgPart;
    temp.realPart = comp_1.realPart / comp_2.realPart;
    return temp;
}


void Operatii::Afisare(NumarComplex &comp){
    cout << comp.realPart << " + (" << comp.imgPart << ")*i\n";
}

void Operatii::Afisare(double real){
    cout << real << "\n";
}

int main()
{
    NumarComplex comp_1(432.12, -123.51);
    NumarComplex comp_2(-231.63, 153.32);
    double real_1 = 542.95;
    double real_2 = 42.51;

    cout<<"\n---Real---\n";
    Operatii *ops = new Operatii(real_1, real_2);
    cout<<"Z1 = "; ops->Afisare(real_1);
    cout<<"Z2 = "; ops->Afisare(real_2);
    cout<<"\nSum: "<<"Z1"<<" + "<<"Z2"<<" = "<<ops->Sum(real_1, real_2)<<endl;
    cout<<"Subtraction: "<<"Z1"<<" - "<<"Z2"<<" = "<<ops->Subtraction(real_1, real_2)<<endl;
    cout<<"Multiplication: "<<"Z1"<<" * "<<"Z2"<<" = "<<ops->Multiply(real_1, real_2)<<endl;
    cout<<"Division: "<<"Z1"<<" / "<<"Z2"<<" = "<<ops->Divide(real_1, real_2)<<endl;


    cout<<"\n---Complex---\n";
    ops = new Operatii(comp_1, comp_2);
    cout<<"Z1 = "; ops->Afisare(comp_1);
    cout<<"Z2 = "; ops->Afisare(comp_2);
    NumarComplex temp(0, 0);
    temp = ops->Sum(comp_1, comp_2);
    cout<<"\nSum: "<<"Z1"<<" + "<<"Z2"<<" = "; ops->Afisare(temp);
    temp = ops->Subtraction(comp_1, comp_2);
    cout<<"Subtraction: "<<"Z1"<<" - "<<"Z2"<<" = "; ops->Afisare(temp);
    temp = ops->Multiply(comp_1, comp_2);
    cout<<"Multiplication: "<<"Z1"<<" * "<<"Z2"<<" = "; ops->Afisare(temp);
    temp = ops->Divide(comp_1, comp_2);
    cout<<"Division: "<<"Z1"<<" / "<<"Z2"<<" = "; ops->Afisare(temp);


    return 0;
}
