/*
    T.5.2 Analog cu T.5.1, scrieti o metoda perimetru.
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
        void perimetru() {

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
        void perimetru() {

            cout << "Rectangle " << getName() << " perimeter: " << 2 * width + 2 * height << '\n';

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
        void perimetru() {

            cout << "Rectangle " << getName() << " perimeter: " << 4 * side << '\n';

        }

};
int main()
{
    Form *f = new Form("form 1");
    cout << "Forma: " << f -> getName() << '\n';

    f -> calculArie();
    f -> perimetru();
    cout << '\n';

    Rectangle *r = new Rectangle("rectangle 1", 1, 2);
    cout << "Rectangle name: "<< r -> getName() << "\nWidth: " << r -> getWidth() << "\nHeight: " << r -> getHeight() << '\n';

    r -> calculArie();
    r -> perimetru();
    cout << '\n';

    Square *s = new Square("square 1", 20);
    cout << "Square name: " << s -> getName() << "\nSide: " << s -> getSide() << '\n';

    s -> calculArie();
    s -> perimetru();
    cout << '\n';

    return 0;
}
