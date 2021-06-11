/****************************************************************************************************************************************************************************************
Description:		Header file of BasicItem class
File:				BasicItem.h
Author(s):			Sara Beddouch, Maya Kurdi-Teylouni
Created on:			June 08 2021
****************************************************************************************************************************************************************************************/
#pragma once
#include "Item.h"

class BasicItem : public Item
{
public:
	using Item::Item;

	void use() override;
};

