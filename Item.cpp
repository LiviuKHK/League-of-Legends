#include "Item.h"
#include <iostream>

Item::Item(): name(""), description(""){}
Item::Item(const std::string &name, const std::string &description) : name(name), description(description) {}
Item::Item(const Item &other): name(other.name), description(other.description){}
Item::~Item() {std::cout << "Destroyed item: " << name << std::endl;}

Item &Item::operator=(Item other) {
    swap(*this, other);
    return *this;
}
void swap(Item& first, Item& second) noexcept {
    using std::swap;
    swap(first.name, second.name);
    swap(first.description, second.description);
}
std::ostream& operator<<(std::ostream& os, const Item& item) {
    os << "Name: " << item.name << ", Description: " << item.description << std::endl;
    return os;
}

std::string Item::getName() const {return name;}
std::string Item::getDescription() const {return description;}