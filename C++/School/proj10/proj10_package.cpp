/*
 * Author: Nathan Dohm
 * Date: 11/29/17
 * proj10_packages.cpp is a C++ script that aides proj10_knapsack.cpp in solving
 * the classic Knapsack problem.
 */

#include <iostream>
using std::ostream;
#include <string>
using std::string;
#include "proj10_package.h"

ostream& operator<<(ostream &out, Package &p) {
    out << p.weight_ << ":" << p.priority_;
    return out;
}

bool package_compare(const Package &p1, const Package &p2) {

/*
 *  sorts the Packages in the Knapsack based on priority_/weight_
 */

   return (double)p1.priority_/(double)p1.weight_ > (double)p2.priority_/(double)p2.weight_;
}
