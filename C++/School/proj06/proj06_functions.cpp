/*
 * Author: Nathan Dohm
 * Date: October 21, 2017
 *
 * proj06.cpp is a C++ script that performs cellular automation on a given vector,
 * and a given string with the specified rule for the vector (i.e. rule 30)
 */

#include <iostream>
using std::cout; using std::endl;
#include <fstream>
#include <string>
using std::string; using std::stoi;
#include <vector>
using std::vector;
#include <cmath>
#include "proj06_automata.h"

string to_binary(int val) {

    /*
     * Converts a given integer into its binary equivalent.
     */

    string bin;

    if (val > 255 or val < 0) {
        bin = "00000000";
        return bin;
    }

    while (val > 1) {
        if (val%2 == 1) {
            bin+='1';
            val /=2;
        } else {
            bin+='0';
            val /= 2;
        }
    }
    bin+='1';

    int n = bin.length();
    while (n != 8) {
        bin += '0';
        n += 1;
   }
    for (int i=0; i<n/2; i++) { // flips the string bin to get the correct binary string
       std::swap(bin[i], bin[n-i-1]);
    }

   return bin;
}

int dec(string bin) {

    /*
     * Converts a given binary into its decimal equivalent.
     */

    long decimal = 0;
    int n = bin.length();

    for (int i=0; i<n/2; i++) {
       std::swap(bin[i], bin[n-i-1]);
    }

    for (int i = 0; i <= bin.length(); ++i) {
        if (bin[i] == '1') {
            decimal += std::pow(2, i);
        } else {
            ;
        }
    }

    return decimal;
}

int next_val (const vector<int> &v, const string &binary_rule_string) {

    /*
     * Finds the next value of the new vector for the specified rule.
     */

    string to_dec = "";
    for (auto &a : v) {
        to_dec += std::to_string(a);
    }

    int index = binary_rule_string.length() - dec(to_dec) - 1; // uses function dec to determine what rule to follow for the vector
    int a = binary_rule_string[index] - '0';
    return a;
}

vector<int> one_iteration(const vector<int> &v, const string &binary_rule_string) {

    /*
     * Iterates over the given vector, following the guidelines of the specified
     * rule, creating a completely new vector using cellular automation with vectors
     * of size 3.
     */

    vector<int> new_v = v;
    vector<int> final_v = {};
    new_v.insert(new_v.begin(), '0');
    new_v.push_back('0');
    for (int i = 0; i != binary_rule_string.length(); ++i) { // creates new vectors of length 3 in order to determine what rule will be applied
        vector<int> v2 = {};
        v2.push_back(new_v[i]);
        v2.push_back(new_v[i+1]);
        v2.push_back(new_v[i+2]);
        final_v.push_back(next_val(v2, binary_rule_string));
    }
    final_v.erase(final_v.begin() + final_v.size() -1); // erases the last element in final_v
    return final_v;
}

string vector_to_string(const vector<int> &v) {

    /*
     * Converts vector to a string
     */

    string final = "";
    for (auto &i : v) {
        final += std::to_string(i) + ',';
    }
    final.pop_back();
    return final;
}

void read_vector(vector<int> &v, string file_str) {

    /*
     * Reads a file and creates and fills empty vector v from given values on
     * the file.
     */

    string line;
    std::ifstream my_file(file_str);
    if (v.empty() == false) {
        return;
    }
    if (my_file.is_open()) {
        std::getline(my_file, line);
        for (auto &i : line) {
            if (i == ' ') {
                ;
            } else {
                v.push_back(i - '0'); // converts i to an int
            }
        }
    }
}
