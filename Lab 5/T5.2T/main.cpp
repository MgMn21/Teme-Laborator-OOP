/*
    T.5.2 Scrieti o clasa Desert care gestioneaza un produs alimentar de acest tip. Extindeti clasa la Prajitura si TortAniversare.
    Definiti 1-3 membrii variabile specifici fiecarui tip de clasa.
    Definiti o metoda membru in Desert.
    Suprascrieti metoda respectiva in cele doua sub-clase, Prajitura si TortAniversare si folositi in ea membrii variabile din Prajitura si sub-clasa respectiva (Prajitura si TortAniversare).
**/

#include <iostream>
#include <string.h>

using namespace std;

//Class declarations:
class Desert {

    protected:
        int price;
        string name;

    public:
        Desert(int pret, string nume);
        string getName();
        void setName(string nume);
        int getPrice();
        void setPrice(int pret);
        void printWeigth();

};//end Desert

class Prajitura:public Desert {

    int weight;

    public:
        Prajitura(int pret, string nume, int greutate):Desert(pret, nume) { this->weight = greutate; };
        void setWeigth(int greutate);
        int getWeigth();
        void printWeigth();//over

};//end Prajitura

class TortAniversare:public Desert {

    int weight;

    public:
        TortAniversare(int pret, string nume, int greutate):Desert(pret, nume) { this->weight = greutate; };
        void setWeigth(int greutate);
        int getWeigth();
        void printWeigth();

};//end TortAniversare
//end Class Declarations

//Class functions:

//Desert:
Desert::Desert(int pret, string nume) {

    this->price = pret;
    this->name = nume;

}//end Constructor

void Desert::setName(string nume) {

    this->name = nume;

}//end setName

string Desert::getName() {

    return this->name;

}
//end getName
int Desert::getPrice() {

    return this->price;

}//end getPrice

void Desert::setPrice(int pret) {

    this->price = pret;

}//end setPrice

void Desert::printWeigth() {

    cout << ">> Weight: N/A" << '\n';

}//end printWeight
//end Desert

//Prajitura
void Prajitura::setWeigth(int greutate) {

    this->weight = greutate;

}//end setWeight

int Prajitura::getWeigth() {

    return this->weight;

}//end getWeight

void Prajitura::printWeigth() {

    cout << ">> Weigth of " << getName() << " is " << getWeigth() << "g \n";

}//end printWeight
//end Prajitura

//TortAniversare
void TortAniversare::setWeigth(int greutate) {

    this->weight = greutate;

}

int TortAniversare::getWeigth() {

    return this->weight;

}

void TortAniversare::printWeigth() {

    cout << ">> Weigth of " << getName() << " is " << getWeigth() << "g \n";

}
//end TortAniversare
//end functions

int main()
{
    //Desert
    cout << "-----------------------------------------------------------" << endl;
    Desert *temp = new Desert(0, "N/A");
    cout << ">> Desert name: " << temp->getName() << '\n';
    cout << ">> Desert price: " << temp->getPrice() << "$ \n";
    temp->printWeigth();
    cout << endl;
    //Prajitura
    Prajitura *cake = new Prajitura(3, "Muffin", 200);
    cout << ">> Desert name: " << cake->getName() << '\n';
    cout << ">> Desert price: " << cake->getPrice() << "$ \n";
    cake->printWeigth();
    cout << endl;
    //Tort
    TortAniversare *bigCake = new TortAniversare(40, "Chocolate caramel cake", 2500);
    cout << ">> Desert name: " << bigCake->getName() << '\n';
    cout << ">> Desert price: " << bigCake->getPrice() << "$ \n";
    bigCake->printWeigth();
    cout << "-----------------------------------------------------------" << endl;

}
