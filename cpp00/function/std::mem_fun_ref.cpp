#include <iostream>
#include <vector>
#include <algorithm>

class Display {
public:
    void call() {
        std::cout << "hello" << std::endl;
    }
};

int main()
{
    std::vector<Display> displays(5);
    
    std::for_each(displays.begin(), displays.end(), std::mem_fun_ref(&Display::call));

    return 0;
}