#include <iostream>
#include <vector>

class Account {
public:
    int value;
};

int main() {
    // Create an array of Account objects
    Account amounts[] = { {1}, {2}, {3} };
    size_t amounts_size = 3;

    // Initialize the vector with the elements from the array
    std::vector<Account> accounts_vec(amounts, amounts + amounts_size);

    // Print the values in the vector
    size_t i = 0;
    while (i < accounts_vec.size()) {
        std::cout << "Account value: " << accounts_vec[i].value << std::endl;
        ++i;
    }

    return 0;
}