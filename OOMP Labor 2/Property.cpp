#include "Property.h"

Property::Property(std::string _name, int _value, Monopoly* _monopoly, Player* _owner) 
	: Field(_name), value{ _value }, monopoly{ _monopoly }, owner{ _owner } {}

Property::~Property() {}

int Property::get_Rent()
{
	return 1;
}

void Property::enter(Player player, int fields_to_go)
{
}
