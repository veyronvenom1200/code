#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace::std;

vector<double> sort(double incoming) {
    vector<double> outgoing;
    double quarter = 0, dime = 0, nickel = 0, penny = 0;
    while (incoming > .24) {
        ++quarter;
        incoming-=.25;
    }
    while (incoming > .09) {
        ++dime;
        incoming-=.10;
        }
    while (incoming > .04) {
        ++nickel;
        incoming-=.05;
        }
    while (incoming > 0) {
        ++penny;
        incoming-=.01;
        }
    outgoing.push_back(quarter);
    outgoing.push_back(dime);
    outgoing.push_back(nickel);
    outgoing.push_back(penny);
    return outgoing;
}

int main() {
    double change = 0;
    cin >> change;
    try {
        if (change < 0) {
            throw change;
        }
    }
    catch(double change) {
        cerr << "Change cannot be given for values less than 0." << endl;
        exit(0);
    }
    const string ia[] = {"Quarters: ", "Dimes: ", "Nickels: ", "Pennies: "};
    vector<double> change_vector = sort(change/100);
    for (int i = 0; i!= change_vector.size(); ++i) {
        cout << ia[i] << change_vector[i] << endl;
    }
    return 0;
}
