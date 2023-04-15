#include <iostream>
#include <vector>

class class1
{
public:
    virtual void print() const {
        std::cout << "Class1" << std::endl;
    }
    virtual class1* clone() const {
        return new class1(*this);
    }
};

class class2 : public class1
{
public:
    void print() const {
        std::cout << "Class2" << std::endl;
    }
    class2* clone() const {
        return new class2(*this);
    }
};

void my_copy(const class1& a, std::vector<class1*>& f) {
    f.push_back(a.clone());
}


int main()
{
    class1 a, b;
    class2 c, d;

    std::vector<class1*> f;

    my_copy(a, f);
    my_copy(b, f);
    my_copy(c, f);
    my_copy(d, f);

    for (const class1* i : f) {
        std::cout << typeid(*i).name() << std::endl;
    }

    for (const class1* i : f) {
        delete i;
    }

    return 0;
}
