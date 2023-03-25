#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec{1,2,3,4,6,20,18,62,8, 8};
    for (auto j = 2; j != vec.size(); ++j) {
        int key = vec[j]; // key == 18
        int i = j - 1; // i == 5
        while ((i > 0) && (vec[i] > key)) {
            vec[i + 1] = vec[i];
            i = i - 1; // i = 5
        }
        vec[i + 1] = key;
    }

    for(auto &a : vec) {
        std::cout << a << std::endl;
    }
}
