#include<iostream>
#include<vector>
#include <algorithm>

void print_vector(const std::vector<int>& v)
{
    for (size_t i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << std::endl;
    }
}

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};

    std::for_each(v.begin(), v.end(), [](int i) { std::cout << i << std::endl; });
    return 0;
}