#include "Monopoly.h"
#include "Property.h"

Monopoly::Monopoly(std::string sName, int iPrFoHo)
	: name{ sName }, price_for_house{ iPrFoHo }
{}

Monopoly::Monopoly() {}

Monopoly::~Monopoly() {}
