#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace::std;

void reverseStr(string &str)
{
    int n = str.length();

    // Swap character starting from two
    // corners
    for (int i=0; i<n/2; i++)
       swap(str[i], str[n-i-1]);
   cout << str << endl;
}

void binary(int dec)
{
    string bin;
    while (dec > 1)
    {
        if (dec%2 == 1)
        {
            bin+='1';
            dec /=2;
        } else {
            bin+='0';
            dec /= 2;
        }
    }
    bin+='1';
    reverseStr(bin);
}

int dec(string bin)
{
    long decimal = 0;
    int n = bin.length();
    for (int i=0; i<n/2; i++)
    {
       swap(bin[i], bin[n-i-1]);
    }
    for (int i = 0; i <= bin.length(); ++i)
    {
        if (bin[i] == '1') {
            decimal += std::pow(2, i);
        } else {
            ;
        }
    }
    return decimal;
}

int main() {
    binary(46);
    cout << dec("101110") << endl;
    return 0;
}
