#pragma once
#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

class EntreeUtilisateur
{
public:
	char getEntreeValide() {
		return direction_[trouverIndexDirection(entree_)];
	}

	void setEntree(string entree) {
		entree_ = entree;
	}

	int trouverIndexDirection(string entree) {
		for (int i = 0; i < entree_.size(); i++) {
			entree_[i] = tolower(entree_[i]);
		}

		for (int i = 0; i < directions_.size(); i++) {
			std::size_t found = entree_.find(directions_[i]);
			if (found != std::string::npos) {
				return i;
			}
		}
		return directions_.size() + 1;
	}

private:
	string entree_;
	vector<string> directions_= { "ouest","nord","est","sud" };
	string direction_ = "ONEST";
};

