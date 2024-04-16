#ifndef C___PROIECTPOO_H
#define C___PROIECTPOO_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

class Ability {
private:
    std::string type;
    int damage;
    int cooldown;

public:
    std::string name;
    Ability();
    Ability(const string& name,const string& type, int damage, int cooldown);
    Ability(const Ability& other);
    ~Ability();

    Ability& operator=(Ability other);
    friend void swap(Ability& first, Ability& second) noexcept;
    friend ostream& operator<<(ostream& os, const Ability& ability);

    string getName() const;
    string getType() const;
    int getDamage() const;
    int getCooldown() const;

    void activate() const;
};

class Item {
private:
    string name;
    string description;

public:
    Item();
    Item(const string& name,const string& description);
    Item(const Item& other);
    ~Item();

    Item& operator=(Item other);
    friend void swap(Item& first, Item& second) noexcept;
    friend ostream& operator<<(ostream& os, const Item& item);

    string getName() const;
    string getDescription() const;
};

class Champion {
private:
    string role;
    int health;
    vector<Ability> abilities;

public:
    string name;
    Champion();
    Champion(const string& name, const string& role, int health);
    Champion(const Champion& other);
    ~Champion();

    Champion& operator=(Champion other);
    friend void swap(Champion& first, Champion& second) noexcept;
    friend ostream& operator<<(ostream& os, const Champion& champion);

    string getName() const;
    string getRole() const;
    int getHealth() const;
    void addAbility(const Ability& ability);
    void displayAbilities() const;
    int calculateDamage() const;
    void simulateBattle(const Champion& opponent) const;

    virtual void useAbility(const Ability& ability) const;
    virtual Champion* clone() const;
};

class Team {
private:
    static int totalPower;
    static vector<shared_ptr<Champion>> champions;

public:
    static void addChampion(Champion* champion);
    static vector<string> determineAdvantagedChampions();
    void displayChampions() const;

    Team& operator=(Team other);
    friend void swap(Team& first, Team& second) noexcept;
};

//Subclasses
class Assassin : public Champion{
public:
    Assassin(const std::string& name, const std::string& role, int health, int agility);
    void useAbility(const Ability& ability) const override;
private:
    int agility;
};

class Tank : public Champion{
public:
    Tank(const std::string& name, const std::string& role, int health,int armor);
    void useAbility(const Ability& ability) const override;
private:
    int armor;
};

class Mage : public Champion{
public:
    Mage(const std::string& name, const std::string& role, int health, int energy);
    void useAbility(const Ability& ability) const override;
private:
    int energy;
};

class Fighter : public Champion{
public:
    Fighter(const std::string& name, const std::string& role, int health, int sustain);
    void useAbility(const Ability& ability) const override;
private:
    int sustain;
};

class Support : public Champion{
public:
    Support(const std::string& name,const std::string& role, int health, int protection);
    void useAbility(const Ability& ability) const override;
private:
    int protection;
};

class AbilityNotFoundException : public std::exception {
public:
    const char* what() const noexcept override;
};

#endif
