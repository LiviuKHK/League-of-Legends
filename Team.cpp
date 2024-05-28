#include "Team.h"
#include <memory>
#include "InvalidTeamMemberException.h"

void Team::addChampion(Champion* champion) {
    if(champions.size() >= 5){
        throw InvalidTeamMemberException();
    }
    champions.push_back(std::shared_ptr<Champion>(champion));
    totalPower += champion->calculateDamage();
}

std::vector<std::string> Team::determineAdvantagedChampions() const {
    if (champions.empty()) {
        std::cerr << "No champions in the team." << std::endl;
        return {};
    }

    std::vector<std::string> advantagedChampions;
    double totalPower = 0.0;
    for (const auto& champ : champions) {
        totalPower += champ->calculateDamage();
    }

    double averagePower = totalPower / champions.size();
    for (const auto& champ : champions) {
        if (champ->calculateDamage() >= averagePower) {
            advantagedChampions.push_back(champ->getName());
        }
    }
    return advantagedChampions;
}

void Team::displayChampions() const {
    for (const auto& champion : champions) {
        std::cout << champion->getName() << std::endl;
    }
}

Team& Team::operator=(Team other) {
    swap(*this, other);
    return *this;
}

void swap(Team& first, Team& second) noexcept {
    using std::swap;
    swap(first.champions, second.champions);
    swap(first.totalPower, second.totalPower);
}

void Team::useAbilityBasedOnType() const {
    for (const auto& champion : champions) {
        std::cout << "Using ability for " << champion->getName() << ": ";
        if (auto assassin = dynamic_cast<Assassin*>(champion.get())) {
            assassin->useAbility(Ability("Assassin Ability", "Active", 0, 0));
        } else if (auto tank = dynamic_cast<Tank*>(champion.get())) {
            tank->useAbility(Ability("Tank Ability", "Active", 0, 0));
        } else if (auto mage = dynamic_cast<Mage*>(champion.get())) {
            mage->useAbility(Ability("Mage Ability", "Active", 0, 0));
        } else if (auto fighter = dynamic_cast<Fighter*>(champion.get())) {
            fighter->useAbility(Ability("Fighter Ability", "Active", 0, 0));
        } else if (auto support = dynamic_cast<Support*>(champion.get())) {
            support->useAbility(Ability("Support Ability", "Active", 0, 0));
        } else {
            champion->useAbility(Ability("Generic Ability", "Active", 0, 0));
        }
    }
}