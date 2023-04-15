#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class car
{
public:
    car(const std::string &brand, const std::string &model)
    {
        m_brand = brand;
        m_model = model;
    }

    virtual ~car() {}

protected:
    std::string m_brand;
    std::string m_model;
};

class Toyota : public car
{
public:
    Toyota(std::string m) : car("Toyota", m) {}
    ~Toyota()
    {
        std::cout << "Марка: Toyota, модель: " << m_model << std::endl;
    }
};

class Mazda : public car
{
public:
    Mazda(std::string m) : car("Mazda", m) {}
    ~Mazda()
    {
        std::cout << "Марка: Mazda, модель: " << m_model << std::endl;
    }
};

class Mitsubishi : public car
{
public:
    Mitsubishi(std::string m) : car("Mitsubishi", m) {}
    ~Mitsubishi()
    {
        std::cout << "Марка: Mitsubishi, модель: " << m_model << std::endl;
    }
};

class Nissan : public car
{
public:
    Nissan(std::string m) : car("Nissan", m) {}
    ~Nissan()
    {
        std::cout << "Марка: Nissan, модель: " << m_model << std::endl;
    }
};

class Subaru : public car
{
public:
    Subaru(std::string m) : car("Subaru", m) {}
    ~Subaru()
    {
        std::cout << "Марка: Subaru, модель: " << m_model << std::endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    std::vector<car *> cars;
    std::ifstream infile("car.txt");
    std::string brand, model;

    while (infile >> brand >> model)
    {
        if (brand == "Toyota")
        {
            cars.push_back(new Toyota(model));
        }
        else if (brand == "Mazda")
        {
            cars.push_back(new Mazda(model));
        }
        else if (brand == "Mitsubishi")
        {
            cars.push_back(new Mitsubishi(model));
        }
        else if (brand == "Nissan")
        {
            cars.push_back(new Nissan(model));
        }
        else if (brand == "Subaru")
        {
            cars.push_back(new Subaru(model));
        }
    }

    for (int i = 0; i < cars.size(); i++)
    {
        delete cars[i];
    }

    infile.close();

    return 0;
}