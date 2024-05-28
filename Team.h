#ifndef PROIECTV0_2_TEAM_H
#define PROIECTV0_2_TEAM_H
#include "Champion.h"
#include "Assassin.h"
#include "Fighter.h"
#include "Support.h"
#include "Mage.h"
#include "Tank.h"
#include <vector>
#include <memory>

///@class Team represent a team formed by 5 champions,with different tasks.
class Team {
private:
    std::vector<std::shared_ptr<Champion>> champions;
    int totalPower;

public:
    Team() : totalPower(0) {}

    void addChampion(Champion* champion);
    ///@brief function that let us know what champions are advantaged in the game.
    [[nodiscard]] std::vector<std::string> determineAdvantagedChampions() const;
    ///@brief function that shows the champions.
    void displayChampions() const;

    Team& operator=(Team other);
    friend void swap(Team& first, Team& second) noexcept;

    ///@brief Function that shows the utility of ability based on the type of the champion.
    void useAbilityBasedOnType() const;
};

#endif //PROIECTV0_2_TEAM_H
