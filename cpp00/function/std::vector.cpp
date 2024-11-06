#include <iostream>
#include <vector>

class Account {
public:
    int value;
};

// int main() {
//     // Create an array of Account objects
//     Account amounts[] = { {1}, {2}, {3}, {4}, {5} };
//     size_t amounts_size = sizeof(amounts) / sizeof(amounts[0]);

//     // Initialize the vector with the elements from the array
//     std::vector<Account> accounts_vec(amounts, amounts + amounts_size);

//     accounts_vec.push_back({6});

//     // Print the values in the vector
//     size_t i = 0;
//     while (i < accounts_vec.size()) {
//         std::cout << "Account value: " << accounts_vec[i].value << std::endl;
//         ++i;
//     }

//     return 0;
// }

int main()
{
    Account amount[] = {1, 2, 3, 4, 5};
    size_t amount_size = sizeof(amount) / sizeof(amount[0]);

    size_t i = 0;
    while (i < amount_size) {
        std::cout << "Amount value: " << amount[i].value << std::endl;
        ++i;
    }
}