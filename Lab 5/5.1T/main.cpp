/*
    T.5.1 Modificati exemplul anterior si scrieti o metoda calculArie(), membru al clasei Form, care calculeaza aria figurii geometrice.
    Ce ar trebui sa returneze ? Pentru fiecare clasa extinsa, supraincarcati metoda calculArie.
**/

#include <iostream>

using namespace std;

class Form {

    private:
        string color;

    protected:
        string name;
        void setColor(string color) {

            this -> color = color;

        }

    public:
        Form(string name) {

            this -> name = name;

        }
        string getName() {

            return this -> name;

        }
        void setName(string name) {

            this -> name = name;

        }
        void calculArie() {

            cout << "Not available in Form.\n";

        }

};

class Rectangle:public Form {

    protected:
        int width;
        int height;

    public:
        Rectangle(string name, int width, int height) :Form(name) {

            this -> width = width;
            this -> height = height;

        }
        void setWidth(int width) {

            this -> width = width;

        }
        int getWidth() {

            return this -> width;

        }
        int getHeight() {

            return this -> height;

        }
        void calculArie() {

            cout << "Rectangle " << getName() << " area: " << width * height << '\n';

        }


};

class Square:public Form {

    protected:
        int side;

    public:
        Square(string name, int side) :Form(name) {

            this -> side = side;

        }
        void setSide(int side) {

            this -> side = side;

        }
        int getSide() {

            return this -> side;

        }
        void calculArie() {

            cout << "Square " << getName() << " area: " << side * side << '\n';

        }

};
int main()
{
    Form *f = new Form("forma1");
    cout << "Forma: " << f -> getName() << '\n';

    f -> calculArie();
    cout << '\n';

    Rectangle *r = new Rectangle("rectangle 1", 1, 2);
    cout << "Rectangle name: "<< r -> getName() << "\nWidth: " << r -> getWidth() << "\nHeight: " << r -> getHeight() << '\n';

    r -> calculArie();
    cout << '\n';

    Square *s = new Square("square 1", 20);
    cout << "Square name: " << s -> getName() << "\nSide: " << s -> getSide() << '\n';

    s -> calculArie();
    cout << '\n';

    return 0;
}
