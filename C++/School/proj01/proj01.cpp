// author: Nathan Dohm
// date: 09/11/17
// proj01.cpp performs addition, subtraction, multiplication, and division on
// complex numbers.

#include <iostream>
#include <string>
#include <sstream>
#include <complex>
#include <iomanip>
using namespace::std;

int main() {
    string cmp_1, cmp_2;
    double num_1, num_2, img_1, img_2;
    cout << fixed << setprecision(2);
    getline(cin, cmp_1);
    std::istringstream complex_number_one(cmp_1);
    complex_number_one >> num_1 >> img_1 >> num_2 >> img_2;
    cout << fixed << (num_1 + num_2) << " + " << (img_1 + img_2) << 'i' << endl; //addition
    cout << fixed << (num_1 - num_2) << " + " << (img_1 - img_2) << 'i' << endl; //substraction
    cout << fixed << (num_1 * num_2) - (img_1 * img_2) << " + "
    << (num_1 * img_2) + (num_2 * img_1) << 'i' << endl; //multiplication

    cout << fixed << ((num_1 * num_2) - (img_1 * -img_2))/-((num_2*num_2)+(num_2*-img_2)+(-img_2*num_2)+(img_2*-img_2)) << " + "
    << ((num_1 * -img_2) + (num_2 * img_1))/-((num_2*num_2)+(num_2*-img_2)+(-img_2*num_2)+(img_2*-img_2)) << 'i' << endl; //division

    return 0;
}
