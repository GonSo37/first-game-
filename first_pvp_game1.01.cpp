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
    virtual string SetName()
    {
        return "0";
    }
    virtual double GetAttack()
    {
        return 0;
    };
    virtual string GetAttackName()
    {
        return "0";
    }
    virtual double SetHP(double hp)
    {
        return 0;
    }

};
class Dog : public Animals
{
    double HP = 5 + rand() % 20;
    string name = "Dog";
    double attack = 3.2;
    string attackName = "bite";
public:
    double SetHP(double hp) override
    {
        this->HP = hp;
        return HP;
    }
    string GetName() override
    {

        return this->name;
    }
    double GetHP() override
    {
        return this->HP;
    }
    string SetName() override
    {
        cin >> this->name;
        return this->name;

    }
    double GetAttack() override
    {
        return this->attack;
    }
    string GetAttackName() override
    {
        return this->attackName;
    }
};
class Cat : public Animals
{
    double HP = 5 + rand() % 15;
    string name = "Cat";
    double attack = 2.8;
    string attackName = "claws";
public:
    double SetHP(double hp) override
    {
        this->HP = hp;
        return HP;
    }
    string GetName() override
    {
        return this->name;
    }
    double GetHP() override
    {
        return this->HP;
    }
    string SetName() override
    {
        cin >> this->name;
        return this->name;

    }
    double GetAttack() override
    {
        return this->attack;
    }
    string GetAttackName() override
    {
        return this->attackName;
    }
};
class Bird : public Animals
{
    double HP = 5 + rand() % 10;
    string name = "Bird";
    double attack = 2.7;
    string attackName = "flapping wings";
public:
    double SetHP(double hp) override
    {
        this->HP = hp;
        return HP;
    }
    string GetName() override
    {
        return this->name;
    }
    double GetHP() override
    {
        return this->HP;
    }
    string SetName() override
    {
        cin >> this->name;
        return this->name;
    }
    double GetAttack() override
    {
        return this->attack;
    }
    string GetAttackName() override
    {
        return this->attackName;
    }
};

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
        cout << endl;
        cout << "Player #" << i + 1 << endl;
        cout << "Write a number of animal: "; cin >> numAn;
        if (numAn == 1)
        {
            cout << "You took " << dog[i].GetName() << endl;
            cout << "Write your pet's new name: " << endl;
            dog[i].SetName();
            chooseObject[i] = &dog[i];
        }
        else if (numAn == 2) {
            cout << "You took " << cat[i].GetName() << endl;
            cout << "Write your pet's new name: " << endl;
            chooseObject[i] = &cat[i];
            cat[i].SetName();
        }
        else if (numAn == 3)
        {
            cout << "You took " << bird[i].GetName() << endl;
            cout << "Write your pet's new name: " << endl;
            chooseObject[i] = &bird[i];
            bird[i].SetName();
        }
        else
        {
            cout << "You wrote the wrong number!" << endl
                << "Try again: ";
            cin >> numAn;
        }
    }
    system("cls");
    cout << "Will now fight: " << endl;
    for (int i = 0; i < sizeOfPl; i++)
    {
        cout << "player #" << i + 1 << " with her " << chooseObject[i]->GetName() << ". HP = " << chooseObject[i]->GetHP() << endl;

    }
    cout << "===========================" << endl;

    int random = rand() % 10;
    int player1, player2;
    if (random <= 5)
    {
        cout << "The first one will attack player #1" << endl;

        player1 = 0;
        player2 = 1;

    }
    else
    {
        cout << "The first one will attack player #2" << endl;
        player2 = 0;
        player1 = 1;
    }
    for (; chooseObject[0]->GetHP() > 0 && chooseObject[1]->GetHP() > 0; )
    {
        double damage;
        cout << "what do you want to do?" << endl;
        cout << "Abilities your pet: " << endl
            << "1) " << chooseObject[player1]->GetAttackName() << endl;
        cin >> numAn;
        if (numAn == 1)
        {
            cout << chooseObject[player1]->GetName() << " attack " << chooseObject[player2]->GetName() << " by using " << chooseObject[player1]->GetAttackName() << " on " << chooseObject[player1]->GetAttack() << endl;
            damage = chooseObject[player2]->GetHP() - chooseObject[player1]->GetAttack();
            chooseObject[player2]->SetHP(damage);
            cout << "Now " << chooseObject[player2]->GetName() << " have " << chooseObject[player2]->GetHP() << endl;
        }
        int replacement;
        replacement = player1;
        player1 = player2;
        player2 = replacement;


    }

    return 0;
}
