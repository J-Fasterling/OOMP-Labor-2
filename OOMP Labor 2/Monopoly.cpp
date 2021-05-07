#include "Monopoly.h"
#include "Property.h"

Monopoly::Monopoly(int _price_for_house, std::string _name, std::vector <Property> _properties)
	: price_for_house{ _price_for_house }, properties {_properties}, name{ _name } {}

Monopoly::~Monopoly() {}
