#include <iostream>
using std::cout; using std::cin; using std::endl; using std::fixed;
#include<iomanip>
using std::setprecision;

int main() {
    long days;
    double start = 39.33;
    cout << fixed << setprecision(2);
    cin >> days;
    double km = (days * (14.24 * 86400)) + start*(149598000);
    double mile = (days * (8.85 * 86400)) + start*(92955800);
    cout << fixed << km << endl;
    cout << fixed << mile << endl;
    cout << fixed << ((km * 1000)/299792458)/1800 << endl;
    return 0;
}
