// author: Nathan Dohm
// date: 09/11/17
// proj02.cpp finds the max number of possible divisors of a number, and then
// returns that number and prints whether the number is highly composite or not.

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int input;
    std::vector<int> high;
    std::cin >> input;
    if (input <= 0)
    {
        std::cerr << "Error" << std::endl; // use cerr to avoid buffer
        return -1; // 'return -1' (or any non-zero number) means failure
    }
    for (int count = 1; count != input + 1; ++count)
    {
        std::vector<int> divisors;
        for (int a = 1; a != count + 1; ++a) // used to find the the number with the most divisors
        {
            if (count % a == 0)
            {
                divisors.push_back(a);
            }
        }
        high.push_back(divisors.size()); // adds the size of the divisor vector to the high vector
                                         // high contains the ammoutn of divisors in all the numbers before and including input
    }
    auto max = max_element(begin(high), end(high)); // finds max element in vector high
    auto index = distance(high.begin(), max_element (high.begin(),high.end())); // finds the index of the max element (the high composite)
    if (index + 1 == input)
    {
        std::cout << "True" << ' ' << index + 1 << ' ' << *max << std::endl;
    } else {
        std::cout << "False" << ' ' << input << ' ' << index + 1 << ' ' << *max << std::endl;
    }
    return 0;
}
