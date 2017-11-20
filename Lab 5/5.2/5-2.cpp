# include <iostream>
# include "5-2.h"

using namespace std;

//Form
string Form::getColor() {
    return this -> color;
}

void Form::setColor(string color) {
    this -> color = color;
}

string Form::getName() {
    return this -> name;
}

void Form::setName(string name) {
    this -> name = name;
}
//end Form

//Rectangle
void Rectangle::setWidth(int width) {
    this -> width = width;
}

int Rectangle::getWidth() {
    return this -> width;
}
//end Rectangle
