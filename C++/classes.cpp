#include <iostream>
using namespace std;

class Rectangle {
    int width, height;
public:
    void set_values (int, int);
    int area() {return width * height;}

} rect; //similar to int a; kindof like a trailing closure

//:: is the scope operator
void Rectangle::set_values(int x, int y) {
    width = x;
    height = y;
}

int main() {
    rect.set_values(4, 5);
    cout << rect.area();
    return 0;
}

