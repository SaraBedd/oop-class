#pragma once
#include "Item.h"

class BasicItem : public Item
{
public:
	using Item::Item;

	void use() override {
		cout << getUsage();
	}
};

