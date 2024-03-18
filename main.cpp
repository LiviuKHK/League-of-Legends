#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Ability {
private:
    string name;
    string type;
    int damage;
    int cooldown;

public:
    Ability() : name(""), type(""), damage(0), cooldown(0) {} // Constructorul default

    Ability(string name, string type, int damage, int cooldown)
            : name(name), type(type), damage(damage), cooldown(cooldown) {} // Constructorul parametrizabil

    Ability(const Ability& other) { // Constructorul de copiere
        name = other.name;
        type = other.type;
        damage = other.damage;
        cooldown = other.cooldown;
    }

    Ability& operator=(const Ability& other) { // Operatorul =;
        if (this != &other) {
            name = other.name;
            type = other.type;
            damage = other.damage;
            cooldown = other.cooldown;
        }
        return *this;
    }

    ~Ability() { // Destructorul;
        cout << "Destroyed ability: " << name << endl;
    }

    friend ostream& operator<<(ostream& os, const Ability& ability) { // Operatorul <<;
        os << "Name: " << ability.name << ", Type: " << ability.type << ", Damage: " << ability.damage << ", Cooldown: " << ability.cooldown << endl;
        return os;
    }

    string getName() const { return name; }
    string getType() const { return type; }
    int getDamage() const { return damage; }
    int getCooldown() const { return cooldown; }
};

class Champion {
private:
    string name;
    string role;
    int health;
    vector<Ability> abilities;

public:
    Champion() : name(""), role(""), health(0) {}

    Champion(string name, string role, int health)
            : name(name), role(role), health(health) {}

    Champion(const Champion& other) {
        name = other.name;
        role = other.role;
        health = other.health;
        abilities = other.abilities;
    }

    Champion& operator=(const Champion& other) {
        if (this != &other) {
            name = other.name;
            role = other.role;
            health = other.health;
            abilities = other.abilities;
        }
        return *this;
    }

    ~Champion() {
        cout << "Destroyed champion: " << name << endl;
    }

    friend ostream& operator<<(ostream& os, const Champion& champion) {
        os << "Name: " << champion.name << ", Role: " << champion.role << ", Health: " << champion.health << endl;
        return os;
    }

    string getName() const { return name; }
    string getRole() const { return role; }
    int getHealth() const { return health; }

    void addAbility(const Ability& ability) {
        abilities.push_back(ability); // Functie membru care adauga noi abilitati in cadrul campionului;
    }

    void displayAbilities() const { // Functie membru care afiseaza abilitatie campionului;
        cout << "Abilities of " << name << ":" << endl;
        for (const Ability& ability : abilities) {
            cout << ability;
        }
    }
    int calculateDamage() const {
        int totalDamage = 0;
        for (const Ability& ability : abilities) {
            totalDamage += ability.getDamage();
        }
        return totalDamage;
    }
    void simulateBattle(const Champion& opponent) const {
        int damageDealt = calculateDamage();
        int damageTaken = opponent.calculateDamage();

        cout << name << " attacks " << opponent.name << " and deals " << damageDealt << " damage." << endl;
        cout << opponent.name << " counterattacks and deals " << damageTaken << " damage." << endl;

        // Simulare pentru scaderea punctelor de viata
        int remainingHealth = health - damageTaken;
        int remainingOpponentHealth = opponent.health - damageDealt;

        cout << name << " has " << remainingHealth << " health remaining." << endl;
        cout << opponent.name << " has " << remainingOpponentHealth << " health remaining." << endl;
    }

};

class Item {
private:
    string name;
    string description;

public:
    Item() : name(""), description("") {}

    Item(string name, string description)
            : name(name), description(description) {}

    Item(const Item& other) {
        name = other.name;
        description = other.description;
    }

    Item& operator=(const Item& other) {
        if (this != &other) {
            name = other.name;
            description = other.description;
        }
        return *this;
    }

    ~Item() {
        cout << "Destroyed item: " << name << endl;
    }

    friend ostream& operator<<(ostream& os, const Item& item) {
        os << "Name: " << item.name << ", Description: " << item.description << endl;
        return os;
    }

    string getName() const { return name; }
    string getDescription() const { return description; }
};

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

    nocturne.displayAbilities();
    shaco.displayAbilities();

    // Simulam o batalie dintre Shaco si Nocturne
    cout << "\nBattle Simulation:" << endl;
    shaco.simulateBattle(nocturne);

    return 0;

}
