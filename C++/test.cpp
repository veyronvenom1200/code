#include <iostream>
using namespace std;

class Box {
private:
	// int area() {
	// 	return length * width;
	// };
public:
	static int b;
	int length;
	int width;
	// Box() {
	// 	length = 10;
	// 	width = 20;
	// 	// area();
	// }
};

class SmallBox::Box {
public:
    void setSmallWidth(double wid);
    double getSmallWidth(void);
};

double SmallBox::getSmallWidth(void) {
    return width;
}

void SmallBox::setSmallWidth(double wid) {
    width = wid;
}

int Box::b = 0;

int main() {
	int a{4}; //literal
	a = 5;

    SmallBox box;

	Box box1{1, 2};
	box1.b = 2;
	Box box2{1, 2};

	std::cout << box1.b;
	std::cout << box2.b;

}
