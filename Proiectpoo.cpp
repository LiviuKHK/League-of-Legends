#include "Proiectpoo.h"

//Ability class implementation
Ability::Ability() : name(""), type(""), damage(0), cooldown(0) {};
Ability::Ability(const std::string &name, const std::string &type, int damage, int cooldown) : name(name), type(type), damage(damage), cooldown(cooldown) {}
Ability::Ability(const Ability &other): name(other.name), type(other.type), damage(other.damage), cooldown(other.cooldown){}
Ability::~Ability(){cout << "Destroyed ability: " << name << endl;}

Ability &Ability::operator=(Ability other) {
    swap(*this, other);
    return *this;
}
void swap(Ability& first, Ability& second) noexcept {
    using std::swap;
    swap(first.name, second.name);
    swap(first.type, second.type);
    swap(first.damage, second.damage);
    swap(first.cooldown, second.cooldown);
}
ostream& operator<<(ostream& os, const Ability& ability) {
    os << "Name: " << ability.name << ", Type: " << ability.type << ", Damage: " << ability.damage << ", Cooldown: " << ability.cooldown;
    return os;
}

string Ability::getName() const {return name;}
string Ability::getType() const {return type;}
int Ability::getDamage() const {return damage;}
int Ability::getCooldown() const {return cooldown;}

void Ability::activate() const {std::cout << "Ability " << name << " activated!" << std::endl;}

//Item class implementetion
Item::Item(): name(""), description(""){}
Item::Item(const std::string &name, const std::string &description) : name(name), description(description) {}
Item::Item(const Item &other): name(other.name), description(other.description){}
Item::~Item() {cout << "Destroyed item: " << name << endl;}

Item &Item::operator=(Item other) {
    swap(*this, other);
    return *this;
}
void swap(Item& first, Item& second) noexcept {
    using std::swap;
    swap(first.name, second.name);
    swap(first.description, second.description);
}
ostream& operator<<(ostream& os, const Item& item) {
    os << "Name: " << item.name << ", Description: " << item.description << endl;
    return os;
}

string Item::getName() const {return name;}
string Item::getDescription() const {return description;}

//Champion class implementation
Champion::Champion() : name(""), role(""), health(0){}
Champion::Champion(const std::string &name, const std::string &role, int health): name(name), role(role), health(health) {}
Champion::Champion(const Champion &other):name(other.name), role(other.role), health(other.health){}
Champion::~Champion(){
    cout << "Destroyed champion: " << name << endl;
}

Champion &Champion::operator=(Champion other) {
    swap(*this, other);
    return *this;
}
void swap(Champion& first, Champion& second) noexcept {
    using std::swap;
    swap(first.name, second.name);
    swap(first.role, second.role);
    swap(first.health, second.health);
}
ostream& operator<<(ostream& os, const Champion& champion){
    os << "Name: " << champion.name << ", Role: " << champion.role << ", Health: " << champion.health << endl;
    return os;
}

string Champion::getName() const {return name;}
string Champion::getRole() const {return role;}
int Champion::getHealth() const {return health;}

void Champion::addAbility(const Ability &ability) {abilities.push_back(ability);}
void Champion::displayAbilities() const {
    cout << "Abilities of " << name << ":" << endl;
    for (const Ability& ability : abilities) {
        std::cout << ability;
    }
}
int Champion::calculateDamage() const {
    int totalDamage = 0;
    for (const Ability& ability : abilities) {
        totalDamage += ability.getDamage();
    }
    return totalDamage;
}
void Champion::simulateBattle(const Champion &opponent) const {
    int damageDealt = calculateDamage();
    int damageTaken = opponent.calculateDamage();

   std:: cout << name << " attacks " << opponent.name << " and deals " << damageDealt << " damage." << endl;
    std::cout << opponent.name << " counterattacks and deals " << damageTaken << " damage." << endl;

    // Simulare pentru scaderea punctelor de viata
    int remainingHealth = health - damageTaken;
    int remainingOpponentHealth = opponent.health - damageDealt;

    cout << name << " has " << remainingHealth << " health remaining." << endl;
    cout << opponent.name << " has " << remainingOpponentHealth << " health remaining." << endl;
}
void Champion::useAbility(const Ability &ability) const {
    bool abilityFound = false;
    for (const auto& ab : abilities) {
        if (ab.getName() == ability.getName()) {
            abilityFound = true;
            break;
        }
    }
    // Aruncăm excepție dacă abilitatea nu a fost găsită
    if (!abilityFound) {
        throw AbilityNotFoundException();
    }
    cout << name << " uses " << ability.name << "!" << endl;
    ability.activate();
}
Champion *Champion::clone() const {
    return new Champion(*this);
}

//Team class
void Team::addChampion(Champion* champion) {
    champions.push_back(shared_ptr<Champion>(champion));
    totalPower += champion->calculateDamage();
}

vector<string> Team::determineAdvantagedChampions() {
    if (champions.empty()) {
        cerr << "No champions in the team." << endl;
        return {}; // return an empty vector
    }

    vector<string> advantagedChampions;
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
vector<shared_ptr<Champion>> Team::champions;
int Team::totalPower = 0;

void Team::displayChampions() const {
    for (const auto& champion : champions) {
        cout << champion->getName() << endl;
    }
}
Team &Team::operator=(Team other) {
    swap(*this, other);
    return *this;
}
void swap(Team& first, Team& second) noexcept {
    using std::swap;
    swap(first.champions, second.champions);
}

//Subclasses
Assassin::Assassin(const std::string &name, const std::string &role, int health, int agility): Champion(name,role,health),agility(agility){}
void Assassin::useAbility(const Ability &ability) const {
    std::cout << name << " performs special ability " << ability.name << "!" << std::endl;
    ability.activate();
}

Tank::Tank(const std::string &name, const std::string &role,int health, int armor): Champion(name,role,health), armor(armor) {}
void Tank::useAbility(const Ability &ability) const {
    std::cout << name << " activates defensive ability " << ability.name << "!" << std::endl;
    ability.activate();
}

Mage::Mage(const std::string &name,const std::string &role, int health, int energy): Champion(name,role,health), energy(energy){}
void Mage::useAbility(const Ability &ability) const {
    std::cout << name << " activates magic ability " << ability.name << "!" << std::endl;
    ability.activate();
}

Fighter::Fighter(const std::string &name,const std::string &role, int health, int sustain): Champion(name,role,health), sustain(sustain){}

void Fighter::useAbility(const Ability &ability) const {
    std::cout << name << " activates offensive ability " << ability.name << "!" << std::endl;
    ability.activate();
}

Support::Support(const std::string &name,const std::string &role, int health, int protection): Champion(name,role,health), protection(protection){}
void Support::useAbility(const Ability &ability) const {
    std::cout << name << " activates sustaining ability " << ability.name << "!" << std::endl;
    ability.activate();
}

const char *AbilityNotFoundException::what() const noexcept {
    return "Ability not found!";
}

