#include <iostream>
#include <ctime>
#include <random>
using namespace std;

/*
    T.8.3. Scrieți o metodă care returnează în mod aleator un int, double, long sau o clasă număr complex.
*/

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
        void Afisare(){
            cout << this->realPart << " + (" << this->imgPart << ")*i\n";
        }
};

template<typename T>
    T random(){
        return (T)rand();
    }

template<>                          //suprascriere pt nr complex
    NumarComplex random(){
        NumarComplex comp(rand()%999, rand()%999);
        return comp;
    }

int main()
{
    srand(time(NULL));

    int option = rand()%4;
    switch(option){
    case 0:
        cout<<"Random int: "<<random<int>();
        break;
    case 1:
        cout<<"Random long: "<<random<long>();
        break;
    case 2:
        cout<<"Random double: "<<random<double>();
        break;
    case 3:
        cout<<"Random complex: ";
        NumarComplex temp;
        temp = random<NumarComplex>();
        temp.Afisare();
        break;
    }

    return 0;
}
