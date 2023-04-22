#include <iostream>
#include <ctime>
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
    virtual double GetHP()
    {
        return 0;
    }

};
class Dog : public Animals
{
    double HP = 5 + rand() % 20;
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
    double GetHP()
    {
        return this->HP;
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

    cout << object.GetName() << " make sounds: " << object.glos() << "!" << endl;
    cout << "Your pet have " << object.GetHP() << " heat points" << endl;

}
int main()
{
    srand(time(0));
    const int sizeOfPl = 2;
    Dog dog[sizeOfPl];
    Cat cat[sizeOfPl];
    Bird bird[sizeOfPl];
    Animals* chooseObject[sizeOfPl];
    for (int i = 0; i < sizeOfPl; i++)
    {
        chooseObject[i] = 0;
    }
    cout << "FARM FITHER" << endl << endl;
    cout << "choose your animal: " << endl;
       cout << "1) " << dog[0].GetName() << endl
        << "2) " << cat[0].GetName() << endl
        << "3) " << bird[0].GetName() << endl;
    int numAn;
    cout << "===========================" << endl;
    for (int i = 0; i < sizeOfPl; i++)
    {
        cout << "Player #" << i + 1 << endl;
        cout << "Write a number of animal: "; cin >> numAn;
        while (numAn >= 4 || numAn <= 0)
        {
            cout << "You wrote the wrong number!" << endl
                << "Try again: "; cin >> numAn;
        }
        if (numAn == 1)
        {
            cout << "You took " << dog[i].GetName() << endl;
            chooseObject[i] = &dog[i];
        }
        else if (numAn == 2) {
            cout << "You took " << cat[i].GetName() << endl;
            chooseObject[i] = &cat[i];
        }
        else if (numAn == 3)
        {
            cout << "You took " << bird[i].GetName() << endl;
            chooseObject[i] = &bird[i];
        }
        Object(*chooseObject[i]);
        
        
    }

    return 0;
}
