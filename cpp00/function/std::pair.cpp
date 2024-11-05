// #include <iostream>
// #include <utility> // For std::pair

// class Account {
// public:
//     int value;
// };

// int main() {
//     // Create an Account object
//     Account account = { 1 };

//     // Create a pair containing an index and the Account object
//     std::pair<size_t, Account> indexed_account = std::make_pair(0, account); // Index 0 and Account with value 1

//     // Print the index and value in the pair
//     std::cout << "Index: " << indexed_account.first << ", Account value: " << indexed_account.second.value << std::endl;

//     return 0;
// }

/**************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <utility> // For std::pair

class Account {
public:
    int value;
};

using accounts_t = std::vector<Account>;

int main() {
    // Create an array of Account objects
    Account amounts[] = { {1}, {2}, {3} };
    size_t amounts_size = 3;

    // Initialize the vector with the elements from the array
    accounts_t accounts(amounts, amounts + amounts_size);

    // Create a vector of pairs, where each pair contains an index and an Account object
    std::vector<std::pair<size_t, Account>> indexed_accounts; // a vectore with "pair" of size_t and Account
	size_t i = 0;
	while (i < accounts.size()) 
	{
		indexed_accounts.push_back(std::make_pair(i, accounts[i]));//make the pair and push to the vector
		++i;
	}

    // Use an iterator to iterate over the vector of pairs
    std::vector<std::pair<size_t, Account>>::iterator it = indexed_accounts.begin(); //initialize the "it" iterator to the beginning of the vector
    while (it != indexed_accounts.end()) //if the iterator is not at the end of the vector it keep loop
	{
        std::cout << "Index: " << it->first << ", Account value: " << it->second.value << std::endl;
        ++it;
    }

    return 0;
}