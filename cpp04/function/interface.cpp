#include <iostream>

class Iinterface
{
    public:
        virtual void print() = 0;
};

class derived1 : public Iinterface
{
    public:
        void print()
        {
            std::cout << "info" << std::endl;
        }
};

class derived2 : public Iinterface
{
    public:
        void print()
        {
            std::cout << "info2" << std::endl;
        }
};

int main()
{
    derived1 d1;
    derived2 d2;
    Iinterface *i;;

    i = &d1;
    i->print();
    i = &d2;
    i->print();
}