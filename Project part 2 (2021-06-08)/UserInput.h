/****************************************************************************************************************************************************************************************
Description:		Header file of UserInput class
File:				UserInput.h
Author(s):			Sara Beddouch, Maya Kurdi-Teylouni
Created on:			May 28 2021
****************************************************************************************************************************************************************************************/
#pragma once
#include <string>
#include <vector>
#include <string>
#include <algorithm>

#include "/src/vcpkg/packages/boost-algorithm_x64-windows/include/boost/algorithm/string/case_conv.hpp"
#include "/src/vcpkg/packages/boost-algorithm_x64-windows/include/boost/algorithm/string.hpp"

#include "Room.h"
#include "LightSwitch.h"

using namespace std;
using namespace boost;

class UserInput
{
public:
	UserInput() = default;

	int getIndex();

	string getInput();

	void setInput(string input);

	void toLower();

	bool charToIndex();

	bool stringToIndex();

	bool isIndexValid();

private:
	string input_ = "";
	int index_ = 0;
};