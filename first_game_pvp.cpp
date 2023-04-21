#include <iostream>

using namespace std;
class Animals
{
private:

public:
    virtual string glos()
    {
        return "0";
    };
    virtual string GetName()
    {
        return "0";
    };

};
class Dog : public Animals
{
    string name = "Dog";
public:
    string glos() override
    {
        return "Gaw";
    }
    string GetName() override
    {
        return this->name;
    }
};
class Cat : public Animals
{
    string name = "Cat";
public:
    string glos() override
    {
        return "meaw";

    }
    string GetName() override
    {
        return this->name;
    }
};
class Bird : public Animals
{
    string name = "Bird";
public:
    string glos() override
    {
        return "Koo-Koooooo";
    }
    string GetName() override
    {
        return this->name;
    }
};
void Object(Animals& object)
{
    cout << "You want take " << object.GetName() << "?" << endl;

    cout << object.GetName() << " make sounds: " << object.glos() << "!" << endl;

}
int main()
{
    Dog dog;
    Cat cat;
    Bird bird;
    Animals* chooseObject;
    cout << "choose your animal: " << endl
        << "1) " << dog.GetName() << endl
        << "2) " << cat.GetName() << endl
        << "3) " << bird.GetName() << endl;
    int numAn;

    cout << "Write a number of animal: "; cin >> numAn;
    while (numAn >= 4 || numAn <= 0)
    {
        cout << "You wrote the wrong number!" << endl
            << "Try again: "; cin >> numAn;
    }
    if (numAn == 1)
    {
        cout << "you took " << dog.GetName() << endl;
        chooseObject = &dog;
    }
    else if (numAn == 2) {
        cout << "You took " << cat.GetName() << endl;
        chooseObject = &cat;
    }
    else if (numAn == 3)
    {
        cout << "You took " << bird.GetName() << endl;
        chooseObject = &bird;
    }
    Object(&chooseObject);
    return 0;
}
