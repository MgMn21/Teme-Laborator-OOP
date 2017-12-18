#include <iostream>
#include <cmath>
using namespace std;

/*
    T.8.1 Rescrieți Exemplu 8.1 pentru a calcula în plus și minimul dintre două numere complexe.
    Minimul dintre două numere complexe îl considerăm in acest exemplu ca punctul care are reprezentarea în plan mai apropiată de origine.
*/

// function template

class NumarComplex {
    private:
        double realPart;
        double imgPart;
    public:
        NumarComplex(){
            this->realPart = 0;
            this->imgPart = 0;
        }
        NumarComplex(double real, double img){
            this->realPart = real;
            this->imgPart = img;
        }
        bool operator<(NumarComplex &comp){
            return (sqrt(pow(this->realPart, 2) + pow(this->imgPart, 2))) < (sqrt(pow(comp.realPart, 2) + pow(comp.imgPart, 2)));
        }

        bool operator>(NumarComplex &comp){
            return (sqrt(pow(this->realPart, 2) + pow(this->imgPart, 2))) > (sqrt(pow(comp.realPart, 2) + pow(comp.imgPart, 2)));
        }
        void Afisare(){
            cout << this->realPart << " + (" << this->imgPart << ")*i\n";
        }

};


template <class T>
    T GetMax (T a, T b) {
        T result;
        result = (a>b)? a : b;
        return (result);
    }
template <class T>
    T GetMin (T a, T b){
        T result;
        result = (a<b)? a : b;
        return (result);
    }

int main () {

    NumarComplex comp_1(23.12, -53.1);
    NumarComplex comp_2(64.9, 28.52);
    NumarComplex temp;

    cout<<"Z1 = "; comp_1.Afisare();
    cout<<"Z2 = "; comp_2.Afisare();
    temp = GetMax<NumarComplex>(comp_1, comp_2);
    cout<<"\nMax(Z1, Z2) = "; temp.Afisare();
    temp = GetMin<NumarComplex>(comp_1, comp_2);
    cout<<"\nMin(Z1, Z2) = "; temp.Afisare();

/*
    int i=5, j=6, k;
    long l=10, m=5, n;
    k=GetMax<int>(i,j);
    n=GetMax<long>(l,m);
    cout << k << endl;
    cout << n << endl;
    return 0;
*/
}
