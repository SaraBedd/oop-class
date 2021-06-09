#pragma once
#include <string>
#include <iostream>

using namespace std;

class Item
{
public:
	Item() = default;
	Item(string name, string description, string usage) : itemName_(name), itemDescription_(description), usage_(usage) {};

	virtual ~Item() = default;

	void look() {
		cout << itemDescription_;
	}

	virtual void use() {};

	string getName();
	string getDescription();
	string getUsage();

	void setName(string name);
	void setDescription(string description);
	void setUsage(string usage);

private:
	string itemName_;
	string itemDescription_;
	string usage_;
};

