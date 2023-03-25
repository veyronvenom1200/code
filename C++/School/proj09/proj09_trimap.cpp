/*
 * Author: Nathan Dohm
 * Date: 11/18/17
 * proj09_trimap.cpp is a C++ script that creates a new STL-like data structure
 * in which you are able to search the structure (similar to a map) for either
 * the key, index, or value (unlike a map, which is limited to just the key).
 */

/*
 * Note to the TA: I used a binary search algorithm (upper_bound) in the find_key
 * method, however I did not get the points for it. Just thought that I'd point it
 * out because maybe I used it incorrectly, which is why I didn't pass the test
 * for it on Mimir.
 */

#include <iostream>
using std::ostream;
#include <sstream>
using std::ostringstream;
#include<string>
using std::string;
#include<vector>
using std::vector;
#include<initializer_list>
using std::initializer_list;
#include <algorithm>
#include "proj09_trimap.h"

// Member functions definitions and constructor
TriMap::TriMap(const Element& e) {
    vec_ = vec_;
    vec_.push_back(e);
}

// Member functions definitions and constructor
TriMap::TriMap(initializer_list<Element> el)  { // list of elements
    vec_ = vec_;
    for (auto& a : el) {
        vec_.push_back(a);
    }
}

size_t TriMap::size() {

/*
 * returns the size of TriMap
 */

    return vec_.size();
}

ostream& operator<<(ostream& os, const TriMap& b) {

/*
 * formats TriMap for organized output
 */

    int i = 0;
    for (auto &a : b.vec_) {
        os << a << (i != b.vec_.size() -1 ? ", " : "");
        ++i;
    }
    return os;
}

ostream& operator<<(ostream& os, const Element& e) {

/*
 * formats Element for organized output
 */

    os << e.key_ << ":" << e.value_ << ":" << e.index_;
    return os;
}

bool TriMap::insert(string key, string value) {

/*
 * checks to see if the key already exists in TriMap, if not, it inserts a new
 * Element with that key, and value
 */

    vector<string> s;
    for (auto &a : vec_) {
        s.push_back(a.key_);
    }

    int i = s.size() - 1;
    if (find(s.begin(), s.end(), key) != s.end() == false) {
        Element e(key,value,++i);
        vec_.push_back(e);
    } else {
        return false;
    }

    auto sortLambda = [] (const Element& e, const Element& f) -> bool
    {
        return f.key_ > e.key_;
    };

    sort(vec_.begin(), vec_.end(), sortLambda);
    return true;
}

bool TriMap::remove(string key) {

/*
 * checks to see if the key already exists in TriMap, if it does, it revoes the
 * Element with that key
 */

    vector<string> s;
    for (auto &a : vec_) {
        s.push_back(a.key_);
    }

    auto sortLambda = [] (const Element& e, const Element& f) -> bool
    {
        return f.key_ > e.key_;
    };

    sort(vec_.begin(), vec_.end(), sortLambda);

    int i = s.size() - 1;
    if (find(s.begin(), s.end(), key) != s.end() == true) {
        auto it = find(s.begin(), s.end(), key);
        int position = it - s.begin();
        vec_.erase(vec_.begin() + position);
        for (auto &b : vec_) {
            if (b.index_ != 0) {
                --b.index_;
            }
        }
        --i;
    } else {
        return false;
    }

    return true;
}

Element* TriMap::find_key(const string& st) {

/*
 * searches the TriMap, using a binary search, for the specified key
 */

    vector<string> s;
    for (auto &a : vec_) {
        s.push_back(a.key_);
    }

    auto sortLambda = [] (const Element& e, const Element& f) -> bool
    {
        return f.key_ > e.key_;
    };
    sort(vec_.begin(), vec_.end(), sortLambda);

    if (find(s.begin(), s.end(), st) != s.end() == false) {
        return nullptr;
    } else {
        int i = upper_bound(s.begin(), s.end(), st) - s.begin() - 1; //binary search algorithm
        return &(vec_[i]);
    }
}

Element* TriMap::find_value(const string& st) {

/*
 * searches the TriMap, using a linear search, for the specified value
 */

    vector<string> s;
    for (auto &a : vec_) {
        s.push_back(a.value_);
    }

    auto sortLambda = [] (const Element& e, const Element& f) -> bool
    {
        return f.key_ > e.key_;
    };
    sort(vec_.begin(), vec_.end(), sortLambda);

    if (find(s.begin(), s.end(), st) != s.end() == false) {
        return nullptr;
    } else {
        int i = find(s.begin(), s.end(), st) - s.begin();
        return &(vec_[i]);
    }

}

Element* TriMap::find_index(size_t t) {

/*
 * searches the TriMap, using a linear search, for the specified index
 */

    vector<long> s;
    for (auto &a : vec_) {
        s.push_back(a.index_);
    }

    auto sortLambda = [] (const Element& e, const Element& f) -> bool
    {
        return f.key_ > e.key_;
    };
    sort(vec_.begin(), vec_.end(), sortLambda);

    if (find(s.begin(), s.end(), t) != s.end() == false) {
        return nullptr;
    } else {
        int i = find(s.begin(), s.end(), t) - s.begin();
        return &(vec_[i]);
    }
}
