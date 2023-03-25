#include <iostream>
#include <string>
using namespace::std;

int main() {
    long input, persistence = 0;
    cin >> input;
    if (input <= 0) {
        cerr << "Error" << endl;
        return -1;
    }
    string add = to_string(input);
    while (std::stoi(add) > 9) {
        int added = 0;
        for (auto &i : add) {
            int ia = i - '0';
            added += ia;
        }
        add = std::to_string(added);
        ++persistence;
    }
    cout << persistence << ' ' << add << endl;;
    return 0;
}
