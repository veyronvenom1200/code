/*
 * Author: Nathan Dohm
 * Date: 10/01/2017
 *
 * proj04.cpp is a file that determines the sequence of digits given a string
 * and a base. Returns false if base does not include the full string or if
 * the string is not a specific number sequence (metadrome, plaindrome,
 * katadrom, or nialpdrome), in which case it returns "nondrome".
 */

#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<string>
using std::string;

/*
 * Used for base conversion
 */

const string base_vals = "0123456789abcdefghijklmnopqrstuvwxyz";

bool base_val(string n, int base)
{

    /*
     * Converts the base(int) into a string and iterates through n(string) to
     * see if all the characters in n are in the base. If not, returns false.
     */

    string b = "";
    for (unsigned int i = 0; i != base; ++i)
    {
        b+=base_vals[i];
    }
    for (auto &a : n)
    {
        if (b.find_first_of(a) != std::string::npos) {
            ;
        } else {
            return false;
        }
    }
    return  true;
}

bool metadrome(string n, int base)
{

    /*
     * Checks to see if the string contains numbers that are strictly in sequence ("12345")
     * by iterating over string n and converting each char to an int, and
     * then compares n[i] and n[i-1].
     */

    if (base_val(n, base) == false)
    {
        return false;
    }
    for (unsigned int i = 1; i <= n.length()-1; ++i)
    {
        if ((n[i] - '0') == (n[i-1] - '0'+ 1))
        {
            ;
        } else {
            return false;
        }
    }
    return true;
}

bool plaindrome(string n, int base)
{

    /*
     * Checks to see if the string contains numbers that are in sequence ("122334")
     * by iterating over string n and converting each char to an int, and
     * then compares n[i] and n[i-1].
     */

    if (base_val(n, base) == false)
    {
        return false;
    }
    for (unsigned int i = 1; i <= n.length()-1; ++i)
    {
        if ((n[i] - '0') == (n[i-1] - '0'+ 1) || (n[i] - '0' == n[i - 1] - '0'))
        {
            ;
        } else {
            return false;
        }
    }
    return true;
}

bool katadrome(string n, int base)
{

    /*
     * Checks to see if the string contains numbers that are strictly in
     * sequence reversed ("54321") by iterating over string n and converting
     * each char to an int, ane then compares n[i] and n[i-1].
     */

    if (base_val(n, base) == false)
    {
        return false;
    }
    for (unsigned int i = 1; i <= n.length() - 1; ++i)
    {
        if ((n[i] - '0') == (n[i-1] - '0' - 1))
        {
            ;
        } else {
            return false;
        }
    }
    return true;
}

bool nialpdrome(string n, int base)
{

    /*
     * Checks to see if the string contains numbers that are in sequence
     * reversed ("5433221") by iterating over string n and converting each
     * char to an int, ane then compares n[i] and n[i-1].
     */

    if (base_val(n, base) == false)
    {
        return false;
    }
    for (unsigned int i = 1; i <= n.length() - 1; ++i)
    {
        if ((n[i] - '0') == (n[i-1] - '0' - 1) or (n[i] - '0' == n[i - 1] - '0'))
        {
            ;
        } else {
            return false;
        }
    }
    return true;
}

string classify(string n, int base)
{

    /*
     * Classifies the sequence and returns the most specific sequence that it
     * can.
     */

    if (metadrome(n, base) && plaindrome(n, base) == true)
    {
        return "metadrome";
    }
    if (katadrome(n, base) && nialpdrome(n, base) == true)
    {
        return "katadrome";
    }
    if (metadrome(n, base) == true)
    {
        return "metadrome";
    } else if (plaindrome(n, base) == true) {
        return "plaindrome";
    } else if (katadrome(n, base) == true) {
        return "katadrome";
    } else if (nialpdrome(n, base) == true) {
        return "nialpdrome";
    } else {
        return "nondrome";
    }
}

int main (){
  string num;
  long base;
  cout << boolalpha;
  cin >> num >> base;
  cout << metadrome (num, base) << " "
       << plaindrome (num, base) << " "
       << katadrome (num, base) << " "
       << nialpdrome (num, base) << " "
       << classify(num, base) << endl;
}
