/*
 * Author: Nathan Dohm
 * Date: 11/05/17
 * proj08_twod.cpp is a C++ script that defines the declarations of proj08_twod.h
 */

#include <iostream>
using std::cout; using std::endl; using std::cin;
#include <string>
using std::string;
#include <sstream>
#include <iomanip>
#include <cmath>
#include "proj08_twod.h"

// Member functions definitions and constructor
TwoD::TwoD(double xval, double yval) {
    x = xval;
    y = yval;
}

string TwoD::to_string() {

/*
 * converts the TwoD struct into a string
 */

    std::ostringstream oss;
    oss << "(" << std::fixed << std::setprecision(2)
    << x << ", " << y << ")";
    string str = oss.str();
    return str;
}

TwoD TwoD::diff(TwoD two) {

/*
 * finds the vector difference between two TwoD structs
 */

    return TwoD((x - two.x), (y - two.y));
}

TwoD TwoD::mult(double d) {

/*
 * finds the product of two TwoD structs
 */

    return TwoD(x * d,y * d);
}

double TwoD::dot_product(TwoD two) {

/*
 * finds the dot product of two TwoD structs
 */

    return (x * two.x) + (y * two.y);
}

double TwoD::magnitude_squared() {

/*
 * finds the magnitude squared of two TwoD structs
 */

    return std::pow(x, 2) + std::pow(y, 2);
}
