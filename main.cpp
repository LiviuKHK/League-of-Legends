#include <iostream>
#include <string>
#include <vector>
#include "Ability.h"
#include "Champion.h"
#include "Item.h"
#include "Melee.h"
#include "Tank.h"
#include "Team.h"
#include "Assassin.h"
#include "Menu.h"
#include "DuplicateAbilityException.h"
#include "InvalidTeamMemberException.h"
#include "AttackStrategy.h"
#include "RangedAttack.h"
#include "ChampionWithStrategy.h"
#include "MeleeAttack.h"

using namespace std;

// Factory Design Pattern
enum ChampionType { ASSASSIN, FIGHTER, MAGE, TANK, SUPPORT };

Champion* createChampion(ChampionType type, const std::string& name, const std::string& role, int health, int extraAttribute) {
    switch (type) {
        case ASSASSIN:
            return new Assassin(name, role, health, extraAttribute);
        case FIGHTER:
            return new Fighter(name, role, health, extraAttribute);
        case MAGE:
            return new Mage(name, role, health, extraAttribute);
        case TANK:
            return new Tank(name, role, health, extraAttribute);
        case SUPPORT:
            return new Support(name, role, health, extraAttribute);
        default:
            return nullptr;
    }
}

///@brief Show the champions of league.
void showChampions(const std::vector<Champion*>& champions) {
    std::cout << "Champions:\n";
    for (const auto& champion : champions) {
        std::cout << *champion << std::endl;
    }
}

///@brief Show abilities of champions.
void showAbilities(const std::vector<Champion*>& champions) {
    std::cout << "Abilities:\n";
    for (const auto& champion : champions) {
        std::cout << "Abilities of " << champion->getName() << ":\n";
        champion->displayAbilities();
        std::cout << std::endl;
    }
}

/*
 * @brief Simulates a battle between this champion and an opponent.
 * @param champion1 The champion
 * @param champion2 The opponent champion
 * */
void simulateBattle(const std::vector<Champion*>& champions) {
    if (champions.size() < 2) {
        std::cout << "Not enough champions for battle!\n";
        return;
    }

    std::cout << "Select two champions for battle:\n";
    for (size_t i = 0; i < champions.size(); ++i) {
        std::cout << i + 1 << ". " << champions[i]->getName() << std::endl;
    }

    int choice1, choice2;
    std::cout << "Choose first champion: ";
    std::cin >> choice1;
    std::cout << "Choose second champion: ";
    std::cin >> choice2;

    if (choice1 < 1 || choice1 > static_cast<int>(champions.size()) ||
        choice2 < 1 || choice2 > static_cast<int>(champions.size()) ||
        choice1 == choice2) {
        std::cout << "Invalid champion selection!\n";
        return;
    }

    const Champion& champion1 = *champions[choice1 - 1];
    const Champion& champion2 = *champions[choice2 - 1];

    std::cout << "\nBattle Simulation:\n";
    champion1.simulateBattle(champion2);
}

int main() {
    ///@brief Adding abilities to the first champion
    Ability ability1("Duskbringer", "Active", 90, 10);
    Ability ability2("Shroud of Darkness", "Active", 100, 15);

    ///@brief Create the champion nocturne with his abilities
    Champion* nocturne = new Assassin("Nocturne", "Assassin", 580, 20);
    nocturne->addAbility(ability1);
    nocturne->addAbility(ability2);

    ///@brief Adding abilities to the second champion
    Ability ability3("Deceive", "Active", 80, 10);
    Ability ability4("Two-Shiv Poison", "Active", 100, 12);

    ///@brief Create the second champion shaco with his abilities
    Champion* shaco = new Assassin("Shaco", "Assassin", 550, 30);
    shaco->addAbility(ability3);
    shaco->addAbility(ability4);

    cout << endl;

    ///@brief A clone implementation;
    Champion* champion1 = nocturne->clone();
    champion1->setName("Nocturne Clone");
    champion1->addAbility(Ability("Umbra Blades", "Passive", 0, 0));

    cout << "Original Champion:\n" << *nocturne << endl;
    cout << "Cloned Champion with new ability:\n" << *champion1 << endl;

    // Perform a battle simulation between the original and the cloned champion
    cout << "\nSimulating battle between original and cloned champions:\n";
    nocturne->simulateBattle(*champion1);

    ///@brief Testing the function which calculates the damage
    int totalDamage = nocturne->calculateDamage();
    cout << "Total damage of " << nocturne->getName() << ": " << totalDamage << endl;

    Item healthPotion("Health Potion", "Restores health when consumed");
    Item manaPotion("Mana Potion", "Restores mana when consumed");

    cout << "Champion 1:\n" << *nocturne << endl;
    cout << "Champion 2:\n" << *shaco << endl;

    cout << healthPotion << endl;
    cout << manaPotion << endl;
    cout << "Description: " << healthPotion.getDescription() << endl;

    ///@brief Create a team with some champions
    try {
        Team team;

        Champion* champion3 = new Assassin("Zed", "Assassin", 100, 20);
        team.addChampion(champion3);

        Champion* champion2 = new Tank("Malphite", "Tank", 200, 30);
        team.addChampion(champion2);

        team.displayChampions();

    } catch(const std::exception& e) {
        cout<< "A apărut o excepție: " << e.what() << '\n';
    }

    ///@brief Testing abilities
    Ability abilit1("Duskbringer", "Active", 90, 10);
    Ability abilit2("Shroud of Darkness", "Active", 0, 15);

    ///@brief Testing items
    Item item1("Health Potion", "Restores health when consumed");
    Item item2("Mana Potion", "Restores mana when consumed");

    ///@brief Testing champions
    shared_ptr<Champion> champio1 = make_shared<Assassin>("Nocturne", "Assassin", 580, 20);
    shared_ptr<Champion> champio2 = make_shared<Assassin>("Shaco", "Assassin", 550, 30);

    ///@brief Testing team
    auto akali = make_shared<Assassin>("Akali", "Assassin", 580, 20);
    auto malphite = make_shared<Tank>("Malphite", "Tank", 800, 30);
    auto ryze = make_shared<Mage>("Ryze", "Mage", 500, 25);
    auto darius = make_shared<Fighter>("Darius", "Fighter", 700, 35);
    auto soraka = make_shared<Support>("Soraka", "Support", 450, 15);

    ///@brief Create a team
    Team team;
    team.addChampion(akali.get());
    team.addChampion(malphite.get());
    team.addChampion(ryze.get());
    team.addChampion(darius.get());
    team.addChampion(soraka.get());

    ///@brief using abilities for each type of champions.
    team.useAbilityBasedOnType();

    ///@brief Testing the invalid member exception
    shared_ptr<Champion> garen = make_shared<Tank>("Garen", "Tank", 600, 35);
    shared_ptr<Champion> jinx = make_shared<Assassin>("Jinx", "Assassin", 500, 40);
    shared_ptr<Champion> lux = make_shared<Mage>("Lux", "Mage", 450, 25);
    shared_ptr<Champion> yi = make_shared<Fighter>("Master Yi", "Fighter", 550, 30);
    shared_ptr<Champion> sona = make_shared<Support>("Sona", "Support", 400, 20);

    Team team2;
    try {
        team2.addChampion(garen.get());
        team2.addChampion(jinx.get());
        team2.addChampion(lux.get());
        team2.addChampion(yi.get());
        team2.addChampion(sona.get());
    } catch (const InvalidTeamMemberException& e) {
            cout << "Invalid team member: " << e.what() << endl;
    }

    ///@brief Testing Duplicate ability exception.
    /*
     *
     */

    vector<string> advantagedChampionNames = team.determineAdvantagedChampions();
    for (const auto& name : advantagedChampionNames) {
        cout << "Advantaged champion: " << name << endl;
    }

    cout << endl;
    Assassin evelynn("Evelynn", "Assassin", 580, 50);

    std::vector<Champion*> champions;
    champions.push_back(nocturne);
    champions.push_back(shaco);

    ///@brief Create a new champion using Factory Pattern
    shared_ptr<Champion> galio = make_shared<Tank>("Galio", "Tank", 600, 35);

    cout << "New Champion created using Factory Pattern:\n" << *galio << endl;

    ///@brief Testing the Strategy design pattern.
    ///@brief Create a new champion
    Champion* riven = createChampion(FIGHTER, "Riven", "Fighter", 550, 30);

    ///@brief Create a melee attack strategy
    AttackStrategy* meleeAttack = new MeleeAttack();

    ///@brief Create a champion with a strategy
    ChampionWithStrategy rivenWithStrategy(riven, meleeAttack);

    ///@brief Execute attack with initial strategy (melee)
    rivenWithStrategy.executeAttack();

    ///@brief Change strategy to ranged attack
    AttackStrategy* rangedAttack = new RangedAttack();
    rivenWithStrategy.setStrategy(rangedAttack);

    ///@brief Execute attack with new strategy (ranged)
    rivenWithStrategy.executeAttack();

    delete riven;
    delete meleeAttack;
    delete rangedAttack;

    ///@brief Create a menu
    cout << "/////////////////////////////////////\n\n";
    std::vector<std::string> options = {"Show Champions", "Show Abilities", "Simulate Battle", "Create Champion","Exit"};
    Menu menu(options);

    bool exitProgram = false;
    while (!exitProgram) {
        menu.display();
        int choice = menu.getUserChoice();

        if (menu.isValidChoice(choice)) {
            switch (choice) {
                case 1:
                    showChampions(champions);
                    break;
                case 2:
                    showAbilities(champions);
                    break;
                case 3:
                    simulateBattle(champions);
                    break;
                case 4: {
                    cout << "Enter champion details:\n";
                    string name, role;
                    int health, extraAttribute;
                    cout << "Name: ";
                    cin >> name;
                    cout << "Role: ";
                    cin >> role;
                    cout << "Health: ";
                    cin >> health;
                    cout << "Extra Attribute: ";
                    cin >> extraAttribute;

                    cout << "Select champion type:\n";
                    cout << "1. Assassin\n";
                    cout << "2. Fighter\n";
                    cout << "3. Mage\n";
                    cout << "4. Tank\n";
                    cout << "5. Support\n";

                    int champChoice;
                    cin >> champChoice;

                    Champion* newChampion = createChampion(static_cast<ChampionType>(champChoice - 1), name, role, health, extraAttribute);

                    champions.push_back(newChampion);

                    break;
                }
                case 5:
                    exitProgram = true;
                    break;
                default:
                    std::cout << "Invalid choice. Please choose again.\n";
            }
        } else {
            std::cout << "Invalid choice. Please choose again.\n";
        }
    }

    cout << "/////////////////////////////////////\n";

    ///@brief Cleaning memory
    for (auto champion : champions) {
        delete champion;
    }
    return 0;
}
