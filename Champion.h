#ifndef PROIECTV0_2_CHAMPION_H
#define PROIECTV0_2_CHAMPION_H
#include <iostream>
#include <vector>
#include "Ability.h"

///@class Class Champion is an entity reprezenting a champion in the game.
class Champion {
protected:
    std::string role;
    int health;
    std::vector<Ability> abilities;

public:
    std::string name;
    Champion();
    /*  @brief Constructor of the Champion class.
 *  @param name ->Shows the name of the champion.
 *  @param role ->Shows the type of the champion.
 *  @param health ->Shows the health of the champion.
*/
    Champion(const std::string& name, const std::string& role, int health);
    Champion(const Champion& other);
    ~Champion();

    ///@brief operator= of the class Champion
    Champion& operator=(Champion& other);
    friend void swap(Champion& first, Champion& second) noexcept;
    ///@brief operator<< of the class Champion
    friend std::ostream& operator<<(std::ostream& os, const Champion& champion);

    void setName(const std::string& newName);
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] std::string getRole() const;
    [[nodiscard]] int getHealth() const;

    ///@brief Function addAbility add an ability to the champion
    void addAbility(const Ability& ability);
    ///@brief Function displayAbilities shows the abilities of the champion
    void displayAbilities() const;
    ///@brief calculateDamage is a function which calculates the damage from abilities of the champion
    [[nodiscard]] int calculateDamage() const;
    ///@brief simulateBattle calculate the damage dealt in a fight between 2 champions,or who win.
    virtual void simulateBattle(const Champion& opponent) const;
    virtual void useAbility(const Ability& ability) const;
    [[nodiscard]] virtual Champion* clone() const;

};
#endif