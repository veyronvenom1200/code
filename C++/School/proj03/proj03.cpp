// author: Nathan Dohm
// date: 09/24/17
// proj03.cpp checks for the greatest prime factor, the sum of the divisors,
// the k hyperperfect, and the b smooth value of a given input (n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

long biggest_prime(long n) { // finds the greatest prime number of n
    long large=0;

    for (int i=2; n!=1; ++i) {
        while (n%i==0) {
            n/=i;
            large=i;
        }
    }
    return large;
}

long sum_of_divisors(long n) { // finds the sum of the divisors of n
    std::vector<long> l;
    long sum_of_divisors = 0;
    for (long i = 1; i <= n + 1; ++i) {
        if (n%i == 0) {
            if (i > std::sqrt(n)) {
                return sum_of_divisors;
            }
            sum_of_divisors += i;
            sum_of_divisors += n/i;

        }
    }
    return sum_of_divisors;
}

long k_hyperperfect(long n, long kmax) { // finds the k hyperperfect value of n
    long sum = sum_of_divisors(n), k;
    sum = sum - n - 1;
    for (long k = 2; k<= kmax; ++k) {
        if ((sum * k + 1 == n)) {
            return k;
        }
    }
    n = 0;
    return n;
}

bool b_smooth(long n, long b) { // finds the b smooth value of n
    if (b >= biggest_prime(n)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    unsigned long long n, kmax, b;
    std::cin >> n >> kmax >> b;
    std::cout << biggest_prime(n) << ' ' << sum_of_divisors(n) << ' ' << k_hyperperfect(n, kmax);
    std::cout << ' ' << std::boolalpha << b_smooth(n, b) << std::endl;
}
