#include <iostream>
#include <string>
#include <vector>
#include "Proiectpoo.h"

using namespace std;

// Demonstrare dynamic_cast pentru downcast cu sens
void downcastDemo(const Champion& champion) {
    cout << "Downcast demo:" << endl;

    // Convertem pointerul la Champion într-un pointer la Assassin
    const Assassin* assassin = dynamic_cast<const Assassin*>(&champion);
    if (assassin) {
        cout << "Champion is an Assassin." << endl;
        assassin->useAbility(Ability("Backstab", "Active", 50, 12));
    } else {
        cout << "Champion is not an Assassin." << endl;
    }

}

int main() {
    // Creare abilitati
    Ability ability1("Duskbringer", "Active", 90, 10);
    Ability ability2("Shroud of Darkness", "Active", 0, 15);

    // Cream primul campion,Nocturne,caruia ii adaugam abilitati
    Champion nocturne("Nocturne", "Assassin", 580);
    nocturne.addAbility(ability1);
    nocturne.addAbility(ability2);

    // Creare abilitati
    Ability ability3("Deceive", "Active", 80, 10);
    Ability ability4("Two-Shiv Poison", "Active", 100, 12);

    // cream al doilea campion,Shaco, si ii adaugam abilitatile
    Champion shaco("Shaco", "Assassin", 550);
    shaco.addAbility(ability3);
    shaco.addAbility(ability4);

    cout << endl;

    cout << "Information about Shaco:" << endl;
    cout << "Name: " << shaco.getName() << endl;
    cout << "Role: " << shaco.getRole() << endl;
    cout << "Health: " << shaco.getHealth() << endl;
    shaco.displayAbilities(); // Afișează abilitățile campionului Shaco
    cout << endl;
    cout << "Information about abilities:" << endl;
    cout << "Name: " << ability3.getName() << endl;
    cout << "Type: " << ability3.getType() << endl;
    cout << "Damage: " << ability3.getDamage() << endl;
    cout << "Cooldown: " << ability3.getCooldown() << endl;
    cout << "Name: " << ability4.getName() << endl;
    cout << "Type: " << ability4.getType() << endl;
    cout << "Damage: " << ability4.getDamage() << endl;
    cout << "Cooldown: " << ability4.getCooldown() << endl;
    cout<<endl;
    cout << "Information about Nocturne:" << endl;
    cout << "Name: " << nocturne.getName() << endl;
    cout << "Role: " << nocturne.getRole() << endl;
    cout << "Health: " << nocturne.getHealth() << endl;
    nocturne.displayAbilities(); // Afișează abilitățile campionului Shaco
    cout << endl;
    cout << "Information about abilities:" << endl;
    cout << "Name: " << ability1.getName() << endl;
    cout << "Type: " << ability1.getType() << endl;
    cout << "Damage: " << ability1.getDamage() << endl;
    cout << "Cooldown: " << ability1.getCooldown() << endl;
    cout << "Name: " << ability2.getName() << endl;
    cout << "Type: " << ability2.getType() << endl;
    cout << "Damage: " << ability2.getDamage() << endl;
    cout << "Cooldown: " << ability2.getCooldown() << endl;

    Champion champion1("Nocturne", "Assassin", 580);

    Champion champion2 = champion1; // Testare constructor de copiere;
    Champion champion3;
    champion3 = champion1; // Testare operator de copiere;

    int totalDamage = nocturne.calculateDamage(); // Testare functie de damage,calculand astfel cat damage poate da daca foloseste abilitatie atribuite;
    cout << "Total damage of " << nocturne.getName() << ": " << totalDamage << endl;

    Item healthPotion("Health Potion", "Restores health when consumed");
    Item manaPotion("Mana Potion", "Restores mana when consumed");

    cout << "Champion 1:\n" << nocturne << endl;
    cout << "Champion 2:\n" << shaco << endl;

    cout << healthPotion << endl;
    cout << manaPotion << endl;
    cout << "Description: " << healthPotion.getDescription() << endl;

    // Simulam o batalie dintre Shaco si Nocturne
    cout << "\nBattle Simulation:" << endl;
    shaco.simulateBattle(nocturne);
    cout<<endl;

    try {
        Team team;

        // Creează și adaugă campionul Zed
        Champion* champion1 = new Assassin("Zed", "Assassin", 100, 20);
        team.addChampion(champion1);

        // Creează și adaugă campionul Malphite
        Champion* champion2 = new Tank("Malphite", "Tank", 200, 30);
        Team::addChampion(champion2);

        // Afiseaza campionii adaugati in echipa
        team.displayChampions();

    } catch(const std::exception& e) {
        cout<< "A apărut o excepție: " << e.what() << '\n';
    }

    // Testare abilități
    Ability abilit1("Duskbringer", "Active", 90, 10);
    Ability abilit2("Shroud of Darkness", "Active", 0, 15);

    // Testare iteme
    Item item1("Health Potion", "Restores health when consumed");
    Item item2("Mana Potion", "Restores mana when consumed");

    // Testare campioni
    shared_ptr<Champion> champio1 = make_shared<Champion>("Nocturne", "Assassin", 580);
    shared_ptr<Champion> champio2 = make_shared<Champion>("Shaco", "Assassin", 550);

    // Testare echipă
    Team team;
    Team::addChampion(champio1.get());
    Team::addChampion(champio2.get());

    cout << "Champions in the team:" << endl;
    team.displayChampions();
    cout << endl;

    // Determinăm campionii avantajați
    vector<string> advantagedChampionNames = Team::determineAdvantagedChampions();
    for (const auto& name : advantagedChampionNames) {
        cout << "Advantaged champion: " << name << endl;
    }

    cout<<endl;
    Assassin evelynn("Evelynn", "Assassin", 580, 50);

    // Apelăm funcția demo pentru downcast
    downcastDemo(nocturne);
    cout<<endl;

    return 0;

    return 0;
}