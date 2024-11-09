#include <iostream>
#include <utility> // For std::pair

class Account {
public:
    int value;
};

int main() {

    Account account;
    
    account.value = 1000;

    // Create a pair containing an index and the Account object
    std::pair<size_t, Account> indexed_account;

    indexed_account.first = 0; // Set the index
    indexed_account.second = account; // Set the Account object

    //Print the index and value in the pair (single)
    std::cout << "Index: " << indexed_account.first << ", Account value: " << indexed_account.second.value << std::endl;
}

/**************************************************************************************************************************************/

// //MULTIPLE PAIRS
// #include <iostream>
// #include <utility> // For std::pair
// #include <vector>  // For std::vector

// class Account {
// public:
//     int value;
// };

// int main() {
//     // Create a vector to store multiple pairs
//     std::vector<std::pair<size_t, Account>> indexed_accounts;

//     // Create and initialize multiple Account objects
//     for (size_t i = 0; i < 5; ++i)
//     {
//         Account account; // Create an Account object
//         account.value = 100 + i; // Set the value

//         // Create a pair and add it to the vector
//         indexed_accounts.push_back(std::make_pair(i, account));
//     }

//     // Print the index and value for each pair
//     for (size_t i = 0; i < indexed_accounts.size(); i++)
//     {
//         std::cout << "Index: " << indexed_accounts[i].first << ", Account value: " << indexed_accounts[i].second.value << std::endl;
//     }

//     return 0;
// }