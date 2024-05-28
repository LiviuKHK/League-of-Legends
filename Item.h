#ifndef PROIECTV0_2_ITEM_H
#define PROIECTV0_2_ITEM_H
#include <iostream>

///@class Item represents an item in the game,with a name and a description of this.
class Item {
private:
    std::string name;
    std::string description;

public:
    Item();
    /*  @brief Constructor of the Item class.
 *  @param name ->Shows the name of the item.
 *  @param description->Indicates the description and more details about the item.
*/
    Item(const std::string& name, const std::string& description);
    Item(const Item& other);
    ~Item();

    ///@brief operator= of the item class.
    Item& operator=(Item other);
    friend void swap(Item& first, Item& second) noexcept;
    ///@brief operator<< of the item class.
    friend std::ostream& operator<<(std::ostream& os, const Item& item);

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] std::string getDescription() const;
};


#endif
