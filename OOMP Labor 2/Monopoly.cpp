#include "Monopoly.h"
#include "Property.h"

Monopoly::Monopoly(int _price_for_house, std::string _name, std::vector <Field*> _properties)
	: price_for_house{ _price_for_house }, properties {_properties}, name{ _name } {}

Monopoly::Monopoly() {}

Monopoly::~Monopoly() {}

void Monopoly::setProperties(Field* property) {

	properties.push_back(property);
}