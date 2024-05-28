#ifndef PROIECTV0_2_ABILITY_H
#define PROIECTV0_2_ABILITY_H
#include <iostream>

/*
 * @class Ability
 * @param type ->Shows the type of ability.
 * @param damage ->The damage that the ability can give.
 * @param cooldown ->The remaining time to use the ability again.
 * */
class Ability {
private:
    std::string type;
    int damage;
    int cooldown;

public:
    std::string name;
    Ability();
/*   @brief Constructor of the Ability class
    @param type ->Shows the type of ability.
    @param damage ->The damage that the ability can give.
    @param cooldown ->The remaining time to use the ability again.
*/
    Ability(const std::string& name,const std::string& type, int damage, int cooldown);
    Ability(const Ability& other);
    ~Ability();
    ///@brief operator= of the Ability class
    Ability& operator=(Ability other);
    friend void swap(Ability& first, Ability& second) noexcept;
    ///@brief operator<< of the Ability class
    friend std::ostream& operator<<(std::ostream& os, const Ability& ability);

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] std::string getType() const;
    [[nodiscard]] int getDamage() const;
    [[nodiscard]] int getCooldown() const;

    void activate() const;
};


#endif
