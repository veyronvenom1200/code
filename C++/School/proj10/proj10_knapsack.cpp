/*
 * Author: Nathan Dohm
 * Date: 11/29/17
 * proj10_knapsack.cpp is a C++ script that goes about solving the classic
 * Knapsack problem.
 */

#include <iostream>
using std::ostream;
#include <string>
using std::string;
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include "proj10_package.h"
#include "proj10_knapsack.h"

Knapsack::Knapsack(size_t wlimit) {

/*
 * Knapsack contructor
 */

    this->weight_limit_ = wlimit;
    data_ = new Package[capacity_];
}

Knapsack::Knapsack(size_t wlimit, size_t cap) {

/*
 * Knapsack contructor
 */

    this->weight_limit_ = wlimit;
    this->capacity_ = cap;
    data_ = new Package[capacity_] {};
}

Knapsack::Knapsack(const Knapsack& s) {

/*
 * Knapsack copy contructor
 */

    capacity_ = s.capacity_;
    data_ = new Package[capacity_] {};
    weight_limit_ = s.weight_limit_;
    size_ = s.size_;
    std::copy(s.data_, s.data_ + s.capacity_, data_);

}

Knapsack::~Knapsack() {

/*
 * Knapsack destructor
 */

    delete[] data_;
}

Knapsack& Knapsack::operator=(const Knapsack k) {

/*
 * Knapsack assignment operator
 */

        Package *new_data_ = new Package[capacity_ * 2] {};
        data_ = k.data_;
        for (auto e = 0; e != size_; ++e) {
            new_data_[e] = data_[e];
            std::cout << data_[e];
        }
        std::swap(data_, new_data_);
        delete[] new_data_;
        return *this;
}

long Knapsack::capacity() const {

/*
 * returns the Knapsack's capacity
 */

    return capacity_;
}

long Knapsack::size() const {

/*
 * returns the Knapsack's size
 */

    return size_;
}

long Knapsack::weight_limit() const {

/*
 * returns the Knapsack's weight_limit
 */

    return weight_limit_;
}

bool Knapsack::empty() const {

/*
 * checks to see if the Knapsack is empty
 */
    if (size_ == 0) {
        return true;
    } else {
        return false;
    }
}

bool Knapsack::add(const Package &p) {

/*
 * adds Packages to the Knapsack
 */

    long w = 0;

    for (auto i = 0; i != size_; ++i) {
        w+= data_[i].weight_;
    }

    if (size_ < capacity_) { // adds elements if the max capacity_ is not exceeded
        data_[size_] = p;
        if (w + data_[size_].weight_ > weight_limit_) { // if the weight_limit is exceeded, returns false
            return false;
        }
        ++size_;
        return true;
    } else {
        capacity_ *= 2;
        Package *new_data_ = new Package[capacity_] {};
        for (auto e = 0; e != size_; ++e) {
            new_data_[e] = data_[e];
        }
        std::swap(data_, new_data_);
        delete[] new_data_;
        data_[size_] = p;
        ++size_;
        return true;
    }
}

long Knapsack::priority() const {

/*
 * adds up the priorities of all of the Packages contained within the Knapsack
 */

    long p = 0;
    for (auto i = 0; i != size_; ++i) {
        p += data_[i].priority_;
    }
    return p;
}

long Knapsack::weight() const {

/*
 * adds up the weight of all of the Packages contained within the Knapsack
 */

    long w = 0;
    for (auto i = 0; i != size_; ++i) {
        w += data_[i].weight_;
    }
    return w;
}

ostream& operator<<(ostream &out, Knapsack &ks) {
    for (auto i = 0; i < ks.size_; ++i) {
        out << ks.data_[i] << (i != ks.size_ -1 ? ", " : "");
    }
    return out;
}

void solve_KS(string s, Knapsack& ks) {

/*
 * adds Packages to a Knapsack based on data read from a file
 */

    string line;
    std::vector<Package> vec;
    std::ifstream myfile(s);
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {
            std::vector<int> v2;
            std::istringstream is(line);
            int n;
            while (is >> n) {
                v2.push_back(n);
            }
            Package p({v2[0], v2[1]});
            vec.push_back(p);
    }
    myfile.close();
  } else {
    throw std::runtime_error("Whoops");
  }

  std::sort(vec.begin(), vec.end(), package_compare);
  for (auto &a : vec) {
    if (ks.add(a)) {
        ;
        } else {
            break;
        }
    }
}
