#include <iostream>
#include <vector>

class Account {
public:
    int value;
};

int main()
{
    std::vector<int> arr;
    arr = {1, 2, 3, 4, 5};

    std::vector<int>::iterator first = arr.begin();
    std::vector<int>::iterator last = arr.end();

    while(first != last) {
        std::cout << *first << std::endl;
        first++;
    }

}