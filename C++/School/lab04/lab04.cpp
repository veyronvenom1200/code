#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

long loc_to_dec(std::string loc) {
    int ia, sum_of = 0;
    for (auto &c : loc) {
        ia = c - 'a';
        sum_of += std::pow(2, ia);
        std::cout << sum_of << std::endl;
    }
    return ia;
}

std::string abbreviated(std::string dec) {
    std::string new_dec;
    sort(dec.begin(), dec.end());
    for (int i = 0; i != dec.length(); ++i) {
        if (dec[i] == dec[i + 1]) {
            dec[i] += 1;
            dec.erase(dec.begin()+i+1);
        }
        new_dec+=dec[i];
    }
    return new_dec;
}

std::string dec_to_long(long dec) {
    long i, c = 0;
    std::string str;
    for (i = 0; c <= dec; ++i) {
        c += std::pow(2, i);
        std::cout << c << std::endl;
    }
}

int main() {
    // for (auto &b : abbreviated("accec")) {
    //     std::cout << b << std::endl;
    // }
    dec_to_long(21);
    //std::cout << dec_to_long(100) << std::endl;
}
