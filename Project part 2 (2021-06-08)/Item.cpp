#include "Item.h"

string Item::getName() {return itemName_;}
string Item::getDescription() { return itemDescription_; }
string Item::getUsage() { return usage_; }

void Item::setName(string name) { itemName_ = name; }
void Item::setDescription(string description) { itemDescription_ = description; }
void Item::setUsage(string usage) { usage_ = usage; }