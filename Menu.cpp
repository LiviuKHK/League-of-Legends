#include "Menu.h"
Menu::Menu(const std::vector<std::string> &options) {this->options = options;}

void Menu::display() const {
    std::cout << "Menu:\n";
    for (size_t i = 0; i < options.size(); ++i) {
        std::cout << i + 1 << ". " << options[i] << '\n';
    }
}

int Menu::getUserChoice() const {
    int choice;
    std::cout << "Choose an option: ";
    std::cin >> choice;
    return choice;
}

bool Menu::isValidChoice(int choice) const {
    return choice >= 1 && choice <= static_cast<int>(options.size());
}